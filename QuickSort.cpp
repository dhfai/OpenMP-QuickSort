#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>


std::vector<long long> generateFibonacci(int N) {
    std::vector<long long> fibonacci(N);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i < N; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    return fibonacci;
}


std::vector<double> calculateGoldenRatios(const std::vector<long long>& fibonacci) {
    std::vector<double> ratios;
    for (size_t i = 2; i < fibonacci.size(); ++i) {
        double ratio = static_cast<double>(fibonacci[i]) / fibonacci[i - 1];
        ratios.push_back(ratio);
    }
    return ratios;
}


int partition(std::vector<double>& arr, int low, int high) {
    double pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSortSerial(std::vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortSerial(arr, low, pi - 1);
        quickSortSerial(arr, pi + 1, high);
    }
}


void quickSortParallel(std::vector<double>& arr, int low, int high, int depth) {
    if (low < high) {
        int pi = partition(arr, low, high);

        if (depth > 0) {
            #pragma omp parallel sections
            {
                #pragma omp section
                {
                    quickSortParallel(arr, low, pi - 1, depth - 1);
                }
                #pragma omp section
                {
                    quickSortParallel(arr, pi + 1, high, depth - 1);
                }
            }
        } else {
            quickSortSerial(arr, low, pi - 1);
            quickSortSerial(arr, pi + 1, high);
        }
    }
}

int main() {
    const int N = 1000000; 
    std::vector<long long> fibonacci = generateFibonacci(N);

    
    std::vector<double> ratios = calculateGoldenRatios(fibonacci);

    std::vector<double> ratiosSerial = ratios;
    std::vector<double> ratiosParallel = ratios;

    
    auto start_serial = std::chrono::high_resolution_clock::now();
    quickSortSerial(ratiosSerial, 0, ratiosSerial.size() - 1);
    auto end_serial = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_serial = end_serial - start_serial;

    
    auto start_parallel = std::chrono::high_resolution_clock::now();
    int max_depth = omp_get_max_threads();
    quickSortParallel(ratiosParallel, 0, ratiosParallel.size() - 1, max_depth);
    auto end_parallel = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_parallel = end_parallel - start_parallel;

    std::cout << "Durasi Pengurutan Serial: " << duration_serial.count() << " detik" << std::endl;
    std::cout << "Durasi Pengurutan Paralel: " << duration_parallel.count() << " detik" << std::endl;

    return 0;
}

