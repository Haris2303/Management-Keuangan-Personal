#include <iostream>
#include "var.h"
#include "utility.h"

using namespace std;

int main()
{
    
    do {

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
                system("clear");
                utility::transaksi();
                break;
            case '2':
                system("clear");
                utility::analisisKeuangan();
                break;
            case '3':
                system("clear");
                utility::targetKeuangan();
                break;
            case '4':
                system("clear");
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
