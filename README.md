**Program:** Pencarian Golden Ratio secara Serial dan Paralel dengan (C++)


**Langkah Kompilasi:**

1. **Buat File C++:**
   - Gunakan editor teks atau IDE untuk membuat file baru dengan ekstensi `.cpp` (misalnya, `QSuickShort.cpp`).
2. **Tempelkan Kode:**
   - Salin dan tempelkan kode OpenMP yang disediakan ke dalam file yang baru dibuat.
3. **Simpan File:**
   - Simpan file dengan nama file yang sesuai (misalnya, `penjumlahan_paralel.cpp`).
4. **Kompilasi Kode:**
   - Buka terminal atau command prompt dan navigasikan ke direktori tempat Anda menyimpan file C++.
   - Gunakan perintah berikut untuk mengkompilasi kode. Ganti `your_compiler` dengan compiler Anda yang sebenarnya (misalnya, `g++` untuk GCC):

     ```bash
     your_compiler -fopenmp QuickShort.cpp -o QuickShort
     ```
     

     - Flag `-fopenmp` mengaktifkan fitur OpenMP selama kompilasi.
     - Outputnya akan berupa file executable bernama `QuickShort`.

5. **Jalankan Program:**
   - Jalankan program dengan mengetikkan perintah berikut di terminal:

     ```bash
     ./QuickShort
     ```

   - Program akan mencetak hasil penjumlahan yang dihitung di konsol.

**Contoh Output:**

```
Durasi Pengurutan Serial: 0.315051 detik
Durasi Pengurutan Paralel: 0.300272 detik
```
