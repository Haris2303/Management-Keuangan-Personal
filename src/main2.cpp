// #include <iostream>
// #include <string>
// #include <sstream>
// #include <iomanip> // Untuk mengatur format output
// #include <vector> // Untuk menyimpan riwayat transaksi
// using namespace std;

// // Input Variables
// int pilihan;
// float pemasukan, pengeluaran;
// string tanggal, target, kategori;

// // Process Variables
// float saldo = 0, jumlah_pengeluaran = 0, jumlah_pemasukan = 0;
// float pengeluaran_bulanan = 0, pengeluaran_mingguan = 0, pengeluaran_harian = 0;
// bool notif_target = false;

// // Transaction History
// struct Transaksi {
//     string tanggal;
//     string kategori;
//     float jumlah;
//     bool isPemasukan;
// };

// vector<Transaksi> riwayatTransaksi;

// // Output Variable
// string laporan;
// int pin;

// void catatPemasukan() {
//     cout << "Masukkan jumlah uang yang ingin Anda masukkan: ";
//     cin >> pemasukan;
//     cout << "Masukkan tanggal transaksi (DD/MM/YYYY): ";
//     cin >> tanggal;
//     cout << "Masukkan kategori transaksi: ";
//     cin >> kategori;

//     saldo += pemasukan;
//     jumlah_pemasukan += pemasukan;
//     pengeluaran_harian += pemasukan;

//     Transaksi transaksi;
//     transaksi.tanggal = tanggal;
//     transaksi.kategori = kategori;
//     transaksi.jumlah = pemasukan;
//     transaksi.isPemasukan = true;

//     riwayatTransaksi.push_back(transaksi);

//     cout << "Pemasukan berhasil dicatat." << endl;
// }

// void catatPengeluaran() {
//     pengeluaran = 0; // Reset variabel pengeluaran
//     cout << "Masukkan jumlah uang yang ingin Anda keluarkan: ";
//     cin >> pengeluaran;
//     cout << "Masukkan tanggal transaksi (DD/MM/YYYY): ";
//     cin >> tanggal;
//     cout << "Masukkan kategori transaksi: ";
//     cin.ignore(); // Mengabaikan karakter newline (\n) di buffer
//     getline(cin, kategori);

//     saldo -= pengeluaran;
//     jumlah_pengeluaran += pengeluaran;
//     pengeluaran_harian += pengeluaran;
//     pengeluaran_mingguan += pengeluaran;
//     pengeluaran_bulanan += pengeluaran;

//     Transaksi transaksi;
//     transaksi.tanggal = tanggal;
//     transaksi.kategori = kategori;
//     transaksi.jumlah = pengeluaran;
//     transaksi.isPemasukan = false;

//     riwayatTransaksi.push_back(transaksi);

//     cout << "Pengeluaran berhasil dicatat." << endl;
// }

// void tampilkanLaporan() {
//     float rasio = (jumlah_pengeluaran / jumlah_pemasukan) * 100;

//     stringstream ss;
//     ss << "==== LAPORAN KEUANGAN ====\n";
//     ss << "Saldo terkini: Rp " << saldo << "\n";
//     ss << "Total pemasukan: Rp " << jumlah_pemasukan << "\n";
//     ss << "Total pengeluaran: Rp " << jumlah_pengeluaran << "\n";
//     ss << "Rasio pengeluaran terhadap pemasukan: " << rasio << "%\n";

//     if (notif_target) {
//         ss << "Anda telah mencapai target pengeluaran atau pemasukan!\n";
//     }

//     laporan = ss.str();
//     cout << laporan << endl;
// }

// void tampilkanRiwayatKeuangan() {
//     cout << "==== RIWAYAT KEUANGAN ====" << endl;

//     for (size_t i = 0; i < riwayatTransaksi.size(); i++) {
//         const Transaksi& transaksi = riwayatTransaksi[i];
//         cout << "Tanggal: " << transaksi.tanggal << endl;
//         cout << "Kategori: " << transaksi.kategori << endl;
//         cout << "Jumlah: Rp " << transaksi.jumlah << endl;
//         cout << "Jenis: " << (transaksi.isPemasukan ? "Pemasukan" : "Pengeluaran") << endl;
//         cout << "-------------------------" << endl;
//     }
// }

// bool verifikasiPIN() {
//     cout << "Masukkan PIN Anda: ";
//     cin >> pin;

//     // Ganti dengan kode verifikasi PIN sesuai kebutuhan Anda
//     // Di sini, kita asumsikan PIN yang valid adalah 1234
//     if (pin == 1234) {
//         return true; // PIN valid
//     } else {
//         return false; // PIN tidak valid
//     }
// }

// int main() {
//     if (!verifikasiPIN()) {
//         cout << "PIN tidak valid. Aplikasi ditutup." << endl;
//         return 0;
//     }

//     cout << "Apakah Anda memiliki target pengeluaran atau pemasukan? (y/n): ";
//     string jawaban;
//     cin >> jawaban;

//     if (jawaban == "y") {
//         cout << "Masukkan target Anda: ";
//         cin >> target;
//         cout << "Masukkan tanggal target (DD/MM/YYYY): ";
//         cin >> tanggal;

//         notif_target = true;
//     }

//     while (true) {
//         cout << "==== APLIKASI KEUANGAN ====" << endl;
//         cout << "1. Pemasukan" << endl;
//         cout << "2. Pengeluaran" << endl;
//         cout << "3. Laporan Keuangan" << endl;
//         cout << "4. Riwayat Keuangan" << endl;
//         cout << "5. Keluar" << endl;
//         cout << "Pilih menu (1-5): ";
//         cin >> pilihan;

//         switch (pilihan) {
//             case 1:
//                 catatPemasukan();
//                 break;

//             case 2:
//                 catatPengeluaran();
//                 break;

//             case 3:
//                 tampilkanLaporan();
//                 break;

//             case 4:
//                 tampilkanRiwayatKeuangan();
//                 break;

//             case 5:
//                 cout << "Terima kasih. Sampai jumpa lagi!" << endl;
//                 return 0;

//             default:
//                 cout << "Input tidak valid. Silakan pilih menu 1-5." << endl;
//                 break;
//         }
//     }

//     return 0;
// }

