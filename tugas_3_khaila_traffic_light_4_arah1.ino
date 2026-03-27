// --- KONFIGURASI PIN ---
// Utara
int uM = 2, uK = 3, uH = 4;
// Timur
int tM = 5, tK = 6, tH = 7;
// Selatan
int sM = 8, sK = 9, sH = 10;
// Barat
int bM = 11, bK = 12, bH = 13;

void setup() {
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  // Kondisi default: Semua lampu dalam kondisi MERAH
  semuaMerah(); 
  delay(2000); // Tahan 2 detik biar kamu bisa lihat semua MERAH di awal
}

// Fungsi untuk memaksa semua lampu menjadi MERAH
void semuaMerah() {
  // Matikan semua Hijau dan Kuning
  digitalWrite(uH, LOW); digitalWrite(uK, LOW);
  digitalWrite(tH, LOW); digitalWrite(tK, LOW);
  digitalWrite(sH, LOW); digitalWrite(sK, LOW);
  digitalWrite(bH, LOW); digitalWrite(bK, LOW);
  
  // Nyalakan semua Merah
  digitalWrite(uM, HIGH);
  digitalWrite(tM, HIGH);
  digitalWrite(sM, HIGH);
  digitalWrite(bM, HIGH);
}

// Fungsi efek kedip 3 kali dan menyala selama 2 detik
void kedipKuning(int pinKuning) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinKuning, HIGH);
    delay(333); // 333ms nyala
    digitalWrite(pinKuning, LOW);
    delay(333); // 333ms mati
  }
  // Total durasi (333+333) * 3 = 1998ms (~2 detik)
}

// Gunakan fungsi untuk modularisasi
void aktifkanSimpang(int pinH, int pinK, int pinM) {
  digitalWrite(pinM, LOW);   // Matikan merah di sisi ini
  digitalWrite(pinH, HIGH);  // Lampu Hijau: Menyala selama 5 detik
  delay(5000); 
  
  digitalWrite(pinH, LOW);   // Hijau mati
  kedipKuning(pinK);         // Lampu Kuning: Diberikan efek kedip 3 kali
  
  digitalWrite(pinM, HIGH);  // Lampu Merah: Menyala kembali setelah hijau selesai
  // Jeda 1 detik dalam Kondisi Default (Semua Merah) sebelum simpang lain nyala
  delay(1000);               
}

void loop() {
  // Lampu hijau menyala bergiliran searah jarum jam: Utara -> Timur -> Selatan -> Barat
  aktifkanSimpang(uH, uK, uM); 
  aktifkanSimpang(tH, tK, tM); 
  aktifkanSimpang(sH, sK, sM); 
  aktifkanSimpang(bH, bK, bM); 
}