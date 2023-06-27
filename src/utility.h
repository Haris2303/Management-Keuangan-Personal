#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

string report;


namespace utility {

    #include "var.h"
    using namespace var;

    // Transaction
    struct Transaksi {
        string tanggal;
        string kategori;
        float jumlah;
        bool isPemasukan;
    };

    vector<Transaksi> riwayatTransaksi;

    void catatPemasukan() {
        cout << "Masukkan jumlah uang yang ingin Anda masukkan: ";
        cin >> pemasukkan;
        cout << "Masukkan tanggal transaksi (DD/MM/YYYY): ";
        cin >> tanggal;

        // tampilkan kategori transaksi
        cout << "==== KATEGORI TRANSAKSI ====" << endl;
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

        saldo += pemasukkan;
        jumlah_pemasukkan += pemasukkan;
        pengeluaran_harian += pemasukkan;

        Transaksi transaksi;
        transaksi.tanggal = tanggal;
        transaksi.kategori = jenis_kategori;
        transaksi.jumlah = pemasukkan;
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

        // tampilkan kategori transaksi
        cout << "==== KATEGORI TRANSAKSI ====" << endl;
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
        // cin.ignore(); // Mengabaikan karakter newline (\n) di buffer
        // getline(cin, kategori);

        saldo -= pengeluaran;
        jumlah_pengeluaran += pengeluaran;
        pengeluaran_harian += pengeluaran;

        Transaksi transaksi;
        transaksi.tanggal = tanggal;
        transaksi.kategori = jenis_kategori;
        transaksi.jumlah = pengeluaran;
        transaksi.isPemasukan = false;

        riwayatTransaksi.push_back(transaksi);

        cout << "Pengeluaran berhasil dicatat." << endl;
    }

    // method transaksi
    void transaksi() {
        // tampilkan pilhan pemasukkan atau pengeluaran
        cout << "==== PILIH TRANSAKSI ====" << endl;
        cout << "1. Pemasukkan" << endl;
        cout << "2. Pengeluaran" << endl;
        cout << "3. Kembali" << endl;
        cout << "Pilih (1-3)? :";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                catatPemasukan();
                break;
            case '2':
                catatPengeluaran();
                break;
            case '3':
                break;
            default:
                break;
        }
    }

    // method analisis keuangan
    void analisisKeuangan() {
        float rasio = (jumlah_pengeluaran / saldo) * 100;
        if(rasio > 60) {
            cout << "Anda harus mengontrol keuangan!" << endl;
        } else {
            cout << "Keuangan anda terkendali!" << endl;
        }
    }

    // method targetKeuangan
    void targetKeuangan() {
        // cek target 
        if(notif_target > 0) {
            cout << "Anda telah mempunyai target!" << endl;
            // cek target
            if(var::notif_target > 0) {
                // cek apakah target terpenuhi
                if(var::notif_target < var::saldo) { 
                    cout << "Anda telah mencapai target pemasukan!" << endl;
                    // hapus notif target
                    notif_target = 0;
                }
                else { cout << "Target saat ini belum tercapai" << endl; }
            }
        } else {
            // Masukkan jumlah saldo target
            cout << "Masukkan saldo target: ";
            cin >> target;

            // set notif target
            notif_target = target;

            cout << "Target anda telah tercatat!";
        }
        cout << notif_target << endl;
    }

    // method laporan
    void laporan() {
        stringstream ss;
        ss << "==== LAPORAN KEUANGAN ====\n";
        ss << "Saldo terkini: Rp " << saldo << "\n";
        ss << "Total pemasukan: Rp " << jumlah_pemasukkan << "\n";
        ss << "Total pengeluaran: Rp " << jumlah_pengeluaran << "\n";

        report = ss.str();
        cout << report << endl;
    }
}
