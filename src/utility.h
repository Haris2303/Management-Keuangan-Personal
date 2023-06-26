#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

namespace utility {

    #include "var.h"
    using namespace var;

    struct Transaksi {
        double jumlah_pemasukkan;
        double jumlah_pengeluaran;
        double saldo;
        string jenis_kategori;
        string tanggal;
    };

    struct Saldo {
        double dana;
    };

    Transaksi laporanTransaksi;
    Saldo dana;

    double readSaldo() {
        double saldoAkhir = 0;

        fstream fileLaporan;

        // open file
        fileLaporan.open("data/laporan.txt", ios::in | ios::out | ios::binary);

        int count = 0;
        // baca file
        while(!fileLaporan.eof()) {

            if (count != 0) {
                saldoAkhir += laporanTransaksi.saldo;
            }

            fileLaporan.read(reinterpret_cast<char*>(&laporanTransaksi), sizeof(Transaksi));

            count++;
        }

        fileLaporan.close();

        return saldoAkhir;
    }

    // method transaksi
    void transaksi() {

        fstream fileLaporan;
        fstream fileSaldo;

        // open file laporan
        fileLaporan.open("data/laporan.txt", ios::app | ios::in | ios::out | ios::binary);

        // masukkan tanggal transaksi
        
        cout << "Masukkan tanggal transaksi (DD/MM/YYYY): ";
        cin >> laporanTransaksi.tanggal;

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
        
        // catat laporan
        fileLaporan.write(reinterpret_cast<char*>(&laporanTransaksi), sizeof(Transaksi));

        // close file laporan
        fileLaporan.close();

        cout << "Transaksi berhasil dicatat." << endl;
    }

    // method analisis keuangan
    void analisisKeuangan() {
        fstream fileLaporan;
        double jumlahPengeluaran;
        double rasio;
        fileLaporan.open("data/laporan.txt", ios::in | ios::out | ios::binary);
        int count = 0;
        while(!fileLaporan.eof()) { 
            if (count != 0) jumlah_pengeluaran += laporanTransaksi.jumlah_pengeluaran;
            fileLaporan.read(reinterpret_cast<char*>(&laporanTransaksi), sizeof(Transaksi));
        }
        
        rasio = (jumlahPengeluaran / readSaldo()) * 100;

        cout << "rasio: " << fixed << setprecision(2) << rasio << endl;

    }

    // method targetKeuangan
    void targetKeuangan() {}

    // method laporan
    void laporan() {

        double saldoAkhir = 0;

        fstream fileLaporan;
        fstream fileSaldo;

        // open file
        fileLaporan.open("data/laporan.txt", ios::in | ios::out | ios::binary);

        cout << " ==== LAPORAN KEUANGAN ==== " << endl;

        int count = 0;
        // baca file
        while(!fileLaporan.eof()) {

            if (count != 0) {
                cout << "\nTransaksi ke - " << count << endl;
                cout << "Jenis Kategori \t\t: " << laporanTransaksi.jenis_kategori << endl;
                cout << "Jumlah Pemasukkan\t: " << laporanTransaksi.jumlah_pemasukkan << endl;
                cout << "Jumlah Pengeluaran\t: " << laporanTransaksi.jumlah_pengeluaran << endl;
                cout << "Saldo \t\t\t: " << laporanTransaksi.saldo << endl;
                cout << "Tanggal \t\t: " << laporanTransaksi.tanggal << endl;

                saldoAkhir += laporanTransaksi.saldo;
            }

            fileLaporan.read(reinterpret_cast<char*>(&laporanTransaksi), sizeof(Transaksi));

            count++;
        }

        fileLaporan.close();

        cout << "\nSaldo Saat ini: " << fixed << setprecision(0) << saldoAkhir << endl;
    }
}
