#include <iostream>
#include "var.h"
#include "utility.h"

using namespace std;

int main(int argc, char const *argv[])
{
    
    do {
        // cek target
        if(var::notif_target > 0) {
            // cek apakah target terpenuhi
            if(var::notif_target < 0) cout << "Anda telah mencapai target pemasukan!" << endl;
            else cout << "Target saat ini belum tercapai" << endl;
        }

        // munculkan menu pilihan
        cout << "==== APLIKASI KEUANGAN ====" << endl;
        cout << "1. Transaksi" << endl;
        cout << "2. Analisis Keuangan" << endl;
        cout << "3. Target Keuangan" << endl;
        cout << "4. Laporan" << endl;
        cout << "5. Keluar" << endl;

        // masukkan pilihan menu
        cout << "Pilih menu (1-5): ";
        cin >> var::pilihan;

        switch (var::pilihan) {
            case '1':
                utility::transaksi();
                break;
            case '2':
                utility::analisisKeuangan();
                break;

            case '3':
                utility::targetKeuangan();
                break;

            case '4':
                utility::laporan();
                break;

            case '5':
                cout << "Terima kasih. Sampai jumpa lagi!" << endl;
                return 0;

            default:
                cout << "Input tidak valid. Silakan pilih menu 1-5." << endl;
                break;
        }

    } while(true);
}
