#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "var.h"

using namespace std;

string report;

#include "var.h"
using namespace var;

namespace utility {

    // Input Variables
    int pilihan;
    float pemasukan, pengeluaran;
    string tanggal, target, kategori;

    // Transaction History
    struct Transaksi {
        string tanggal;
        string kategori;
        float jumlah;
        bool isPemasukan;
    };

    vector<Transaksi> riwayatTransaksi;

    void catatPemasukan() {
        cout << "Masukkan jumlah uang yang ingin Anda masukkan: ";
        cin >> pemasukan;
        cout << "Masukkan tanggal transaksi (DD/MM/YYYY): ";
        cin >> tanggal;
        cout << "Masukkan kategori transaksi: ";
        cin >> kategori;

        saldo += pemasukan;
        jumlah_pemasukkan += pemasukan;
        pengeluaran_harian += pemasukan;

        Transaksi transaksi;
        transaksi.tanggal = tanggal;
        transaksi.kategori = kategori;
        transaksi.jumlah = pemasukan;
        transaksi.isPemasukan = true;

        riwayatTransaksi.push_back(transaksi);

        cout << "Pemasukan berhasil dicatat." << endl;
    }

    void catatPengeluaran() {
        pengeluaran = 0; // Reset variabel pengeluaran
        cout << "Masukkan jumlah uang yang ingin Anda keluarkan: ";
        cin >> pengeluaran;
        cout << "Masukkan tanggal transaksi (DD/MM/YYYY): ";
        cin >> tanggal;
        cout << "Masukkan kategori transaksi: ";
        cin.ignore(); // Mengabaikan karakter newline (\n) di buffer
        getline(cin, kategori);

        saldo -= pengeluaran;
        jumlah_pengeluaran += pengeluaran;
        pengeluaran_harian += pengeluaran;

        Transaksi transaksi;
        transaksi.tanggal = tanggal;
        transaksi.kategori = kategori;
        transaksi.jumlah = pengeluaran;
        transaksi.isPemasukan = false;

        riwayatTransaksi.push_back(transaksi);

        cout << "Pengeluaran berhasil dicatat." << endl;
    }

    // method transaksi
    void transaksi() {

        fstream fileLaporan;

        // masukkan tanggal transaksi
        cout << "Masukkan tanggal transaksi (DD/MM/YYYY): ";
        cin >> tanggal;

        // tampilkan kategori transaksi
        cout << "==== APLIKASI KEUANGAN ====" << endl;
        cout << "1. Belanja Kebutuhan" << endl;
        cout << "2. Uang Kuliah" << endl;
        cout << "3. Biaya Hiburan" << endl;

        // masukkan kategori transaksi
        cout << "Pilih kategori transaksi (1-3): ";
        cin >> kategori;

        switch (kategori) {
            case '1':
                laporanTransaksi.jenis_kategori = "Belanja Kebutuhan";
                break;
            case '2':
                laporanTransaksi.jenis_kategori = "Uang Kuliah";
                break;
            case '3':
                laporanTransaksi.jenis_kategori = "Biaya Hiburan";
                break;
            default:
                cout << "Kategori tidak ditemukkan!" << endl;
                break;
        }

        // masukkan jumlah pemasukkan
        cout << "Masukkan jumlah pemasukkan: ";
        cin >> pemasukkan;

        // masukkan jumlah pengeluaran
        cout << "Masukkan jumlah pengeluaran: ";
        cin >> pengeluaran;

        saldo += pemasukkan;
        saldo -= pengeluaran;

        laporanTransaksi.saldo = saldo;
        
        laporanTransaksi.jumlah_pemasukkan += pemasukkan;
        laporanTransaksi.jumlah_pengeluaran -= pengeluaran;

        cout << "Transaksi berhasil dicatat." << endl;
    }

    // method analisis keuangan
    void analisisKeuangan() {

    }

    // method targetKeuangan
    void targetKeuangan() {}

    // method laporan
    void laporan() {
        stringstream ss;
        ss << "==== LAPORAN KEUANGAN ====\n";
        ss << "Saldo terkini: Rp " << saldo << "\n";
        ss << "Total pemasukan: Rp " << jumlah_pemasukkan << "\n";
        ss << "Total pengeluaran: Rp " << jumlah_pengeluaran << "\n";

        if (notif_target) {
            ss << "Anda telah mencapai target pengeluaran atau pemasukan!\n";
        }

        report = ss.str();
        cout << laporan << endl;
    }
}
