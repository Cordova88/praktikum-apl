#include <iostream>
#include <cstdlib>
using namespace std;

string username;
string password;
int jam;
int menit;
int detik;
int pilihan;
int waktu;
int percobaan;

int main(){
    // system("cls");
    percobaan = 3;
    
    while (percobaan > 0){
        cout << "Masukan Username: ";
        cin >> username;
        cout << "Masukan Password: ";
        cin >> password;
        cout << endl;

        if (username == "Cordova" && password == "055"){
            cout << "Login Berhasil!" << endl;
            cout << endl;
            break;
        } else {
            percobaan--;
            cout << "Login Gagal! Sisa Percobaan: " << percobaan << endl;
            cout << endl;
        }
        if (percobaan == 0){
            cout << "Percobaan Habis!, Program Otomatis Keluar" << endl;
            return 0;
        }
    }
    do{
        cout << "Pilih Menu" << endl;
        cout << "1. Konversi Waktu" << endl;
        cout << "2. Keluar" << endl;
        cout << endl;
        cout << "Masukan Pilihan: ";
        cin >> pilihan;
        cout << endl;
        
        if (pilihan == 1){
            do{
                cout << endl;
                cout << "Pilih Konversi Waktu" << endl;
                cout << "1. Jam -> Menit dan Detik" << endl;
                cout << "2. Menit -> Jam dan Detik" << endl;
                cout << "3. Detik -> Jam dan Menit" << endl;
                cout << "4. Kembali" << endl;
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
                } else if (waktu == 2){
                    cout << "Masukan Menit: ";
                    cin >> menit;
                    jam = menit / 60;
                    detik = menit * 60;
                    cout << menit << " Menit = " << jam << " Jam" << endl;
                    cout << menit << " Menit = " << detik << " Detik" << endl;
                } else if (waktu == 3){
                    cout << "Masukan Detik: ";
                    cin >> detik;
                    jam = detik / 3600;
                    menit = detik / 60;
                    cout << detik << " Detik = " << jam << " Jam" << endl;
                    cout << detik << " Detik = " << menit << " Menit" << endl;
                } else {
                    cout << "Pilihan Tidak Valid" << endl;
                }
            } while (waktu != 4);
        } else {
            cout << "Pilihan Tidak Valid" << endl;
        }
    } while (pilihan != 2);
    
    return 0;
}