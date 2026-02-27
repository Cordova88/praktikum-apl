#include <iostream>
using namespace std;

string usn;
string pw;
int jam;
int menit;
int detik;
int pilihan;
int waktu;
int percobaan;

int main(){
    percobaan = 3;
    
    while (percobaan > 0){
        cout << endl;
        cout << "Masukan Username: ";
        cin >> usn;
        cout << "Masukan Password: ";
        cin >> pw;
        cout << endl;

        if (usn == "Cordova" && pw == "055"){
            cout << string(30, '=') << endl;
            cout <<  endl;
            cout << "Login Berhasil!" << endl;
            cout << endl;
            cout << string(30, '=') << endl;
            break;
        } else {
            percobaan--;
            cout << "Login Gagal! Sisa Percobaan: " << percobaan << endl;
            cout << string(30, '=') << endl;
            cout << endl;
        }
        if (percobaan == 0){
            cout << string(35, '^') << endl;
            cout << "Percobaan Habis!, Program Selesai" << endl;
            cout << string(35, '=') << endl;
            cout << endl;
            return 0;
        }
    }
    do{
        cout << endl;
        cout << "Pilih Menu" << endl;
        cout << "___________________" << endl;
        cout << "|1. Konversi Waktu|" << endl;
        cout << "|2. Keluar        |" << endl;
        cout << "===================" << endl;
        cout << endl;
        cout << "Masukan Pilihan: ";
        cin >> pilihan;
        cout << endl;
        
        if (pilihan == 1){
            do{
                cout << endl;
                cout << " Pilih Konversi Waktu" << endl;
                cout << "=============================" << endl;
                cout << "|1. Jam   -> Menit dan Detik|" << endl;
                cout << "|2. Menit -> Jam dan Detik  |" << endl;
                cout << "|3. Detik -> Jam dan Menit  |" << endl;
                cout << "|4. Kembali                 |" << endl;
                cout << "=============================" << endl;
                cout << endl;
                cout << "Masukan Pilihan: ";
                cin >> waktu;
                cout << endl;

                if (waktu == 1){
                    cout << "Masukan Jam: ";
                    cin >> jam;
                    menit = jam * 60;
                    detik = jam * 3600;
                    cout << jam << " Jam = " << menit << " Menit" << endl;
                    cout << jam << " Jam = " << detik << " Detik" << endl;
                    cout << string(50, '=') << endl;
                } else if (waktu == 2){
                    cout << "Masukan Menit: ";
                    cin >> menit;
                    jam = menit / 60;
                    detik = menit * 60;
                    cout << menit << " Menit = " << jam << " Jam" << endl;
                    cout << menit << " Menit = " << detik << " Detik" << endl;
                    cout << string(50, '=') << endl;
                } else if (waktu == 3){
                    cout << "Masukan Detik: ";
                    cin >> detik;
                    jam = detik / 3600;
                    menit = detik / 60;
                    cout << detik << " Detik = " << jam << " Jam" << endl;
                    cout << detik << " Detik = " << menit << " Menit" << endl;
                    cout << string(50, '=') << endl;
                } else if (waktu < 0 ||waktu > 4) {
                    cout << string(30, '+') << endl;
                    cout << "Pilihan Tidak Valid" << endl;
                    cout << string(30, '+') << endl;
                }
            } while (waktu != 4);
        } else if (pilihan < 0 ||pilihan > 2) {
            cout << string(30, '+') << endl;
            cout << "Pilihan Tidak Valid" << endl;
            cout << string(30, '+') << endl;
        }
    } while (pilihan != 2);
    cout << string(30, '^') << endl;
    cout << "Program Selesai, terima Kasih" << endl;
    cout << string(30, '=') << endl;
    cout << endl;
    
    return 0;
}