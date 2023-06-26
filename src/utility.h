#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace utility {

    #include "var.h"
    using namespace var;

    struct Transaksi {
        float jumlah_pemasukkan;
        float jumlah_pengeluaran;
        float saldo;
        string jenis_kategori;
        string tanggal;
    };

    fstream fileLaporan;

    // method transaksi
    void transaksi() {
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
                jenis_kategori = "Belanja Kebutuhan";
                break;
            case '2':
                jenis_kategori = "Uang Kuliah";
                break;
            case '3':
                jenis_kategori = "Biaya Hiburan";
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
        jumlah_pemasukkan += pemasukkan;
        jumlah_pengeluaran -= pengeluaran;

        Transaksi transaksi;
        transaksi.jumlah_pemasukkan = jumlah_pemasukkan;
        transaksi.jumlah_pengeluaran = jumlah_pengeluaran;
        transaksi.saldo = saldo;
        transaksi.jenis_kategori = jenis_kategori;
        transaksi.tanggal = tanggal;

        // open file laporan
        fileLaporan.open("data/laporan.bin", ios::app | ios::in | ios::out | ios::binary);

        // catat laporan
        fileLaporan.write(reinterpret_cast<char*>(&transaksi), sizeof(Transaksi));

        // close file 
        fileLaporan.close();

        cout << "Transaksi berhasil dicatat." << endl;
    }

    // method analisis keuangan
    void analisisKeuangan() {}

    // method targetKeuangan
    void targetKeuangan() {}

    // method laporan
    void laporan() {}
}
