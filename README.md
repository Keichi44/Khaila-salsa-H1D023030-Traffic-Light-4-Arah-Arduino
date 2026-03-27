# Project 1: Kendali GPIO Traffic Light 4 Arah

Repository ini dibuat untuk memenuhi Tugas 3 Praktikum Pemrograman Sistem Tertanam. Proyek ini mensimulasikan sistem lampu lalu lintas 4 persimpangan menggunakan mikrokontroler Arduino Uno.

# Identitas
- Nama:Khaila Salsa
- NIM: H1D023030
- Mata Kuliah:Pemrograman Sistem Tertanam

# Spesifikasi Sistem
Sistem ini dirancang dengan aturan operasional sebagai berikut:
1. Otomatis & Looping: Sistem berjalan terus-menerus secara berulang.
2. Rotasi Searah Jarum Jam: Urutan menyala adalah Utara, Timur, Selatan, Barat.
3. Fail-Safe (Kondisi Default): Semua lampu dalam kondisi **MERAH** sebelum satu sisi aktif. Tidak ada lebih dari satu sisi yang hijau secara bersamaan.
4. Timing Presisi:
   - Lampu Hijau menyala selama 5 detik.
   - Lampu Kuning berkedip 3 kali dengan total durasi 2 detik.
   - Lampu Merah menyala kembali setelah transisi selesai.
5. Modularisasi Kode: Menggunakan fungsi `aktifkanSimpang()` untuk efisiensi dan kebersihan kode.

# Link Simulasi
- Tinkercad: https://www.tinkercad.com/things/hFMNGCxCV4b-tugas-3khailatraffic-light-4-arah
