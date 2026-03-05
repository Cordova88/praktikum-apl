#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_USER = 100;
const int MAX_LEGENDS = 50;

struct User {
    string usn;
    string pw;
    string role;
};

struct karakter {
    string nama;
    string classs;
    string best_weapon;
    string nama_asli;
    string home_world;
};
struct tier_list {
    string judul;
};


int main() {

    User dataUser[MAX_USER];
    karakter legend[MAX_LEGENDS];
    int jumlahUser = 1;
    int jumlahLegend = 0;
    int percobaan = 3;
    int pilihan;
    dataUser[0].usn = "admin";
    dataUser[0].pw = "admin123";
    dataUser[0].role = "admin";

    do {

        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan; 

        switch (pilihan) {
            case 1: {
                string usn, pw;
                cout << "Masukkan Username: ";
                cin >> usn;
                cout << "Masukkan Password: ";
                cin >> pw;

                bool loginBerhasil = false;
                for (int i = 0; i < jumlahUser; i++) {
                    if (dataUser[i].usn == usn && dataUser[i].pw == pw) {
                        loginBerhasil = true;
                        cout << "Login berhasil! Selamat datang, " << dataUser[i].usn << " (" << dataUser[i].role << ")\n";

                        if (dataUser[i].role == "admin") {
                            int menu_admin;
                            do{
                                cout << "\n===== MENU ADMIN =====\n";
                                cout << "1. Tambah Legend\n";
                                cout << "2. Tampilkan legend\n";
                                cout << "3. Edit Legend\n";
                                cout << "4. Hapus Legend\n";
                                cout << "5. Logout\n";
                                cout << "Pilih menu: ";
                                cin >> menu_admin;
                                switch (menu_admin) {
                                    case 1:
                                        cout << "\nTambah Legend\n";
                                        cout << "Nama: ";
                                        cin >> legend[jumlahLegend].nama;
                                        cout << "Class: ";
                                        cin >> legend[jumlahLegend].classs;
                                        cout << "Best Weapon: ";
                                        cin >> legend[jumlahLegend].best_weapon;
                                        cout << "Nama Asli: ";
                                        cin >> legend[jumlahLegend].nama_asli;
                                        cout << "Home World: ";
                                        cin >> legend[jumlahLegend].home_world;
                                        jumlahLegend++;
                                        cout << "Legend berhasil ditambahkan!\n";
                                        cin.get();
                                    break;

                                    case 2:
                                        cout << "\nLegend\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "Nama: " << legend[i].nama << "\n";
                                            cout << "Class: " << legend[i].classs << "\n";
                                            cout << "Best Weapon: " << legend[i].best_weapon << "\n";
                                            cout << "Nama Asli: " << legend[i].nama_asli << "\n";
                                            cout << "Home World: " << legend[i].home_world << "\n";
                                            cout << "-------------------------\n";
                                            cin.get();
                                        }
                                        break;
                                    case 3:
                                        cout << "Edit Legend\n";
                                        if (jumlahLegend == 0) {
                                            cout << "Belum ada legend yang dapat diedit.\n";
                                        }else {
                                            cout << "Daftar Legend:\n";
                                            for (int i = 0; i < jumlahLegend; i++) {
                                                cout << i + 1 << ". " << legend[i].nama << "\n";
                                            }
                                            int index;
                                            cout << "Pilih nomor legend yang ingin diedit: ";
                                            cin >> index;
                                            if (index < 1 || index > jumlahLegend) {
                                                cout << "Pilihan tidak valid.\n";
                                            } else {
                                                index--;
                                                cout << "Edit Legend: " << legend[index].nama << "\n";
                                                cout << "Nama: ";
                                                cin >> legend[index].nama;
                                                cout << "Class: ";
                                                cin >> legend[index].classs;
                                                cout << "Best Weapon: ";
                                                cin >> legend[index].best_weapon;
                                                cout << "Nama Asli: ";
                                                cin >> legend[index].nama_asli;
                                                cout << "Home World: ";
                                                cin >> legend[index].home_world;
                                                cout << "Legend berhasil diedit!\n";
                                            }
                                        }
                                        break;
                                    case 4:
                                        cout << "Fitur hapus legend belum tersedia.\n";
                                        if (jumlahLegend == 0) {
                                            cout << "Belum ada legend yang dapat diedit.\n";
                                        }else {
                                            cout << "Daftar Legend:\n";
                                            for (int i = 0; i < jumlahLegend; i++) {
                                                cout << i + 1 << ". " << legend[i].nama << "\n";
                                            }
                                            int index;
                                            cout << "Pilih nomor legend yang ingin diedit: ";
                                            cin >> index;
                                            if (index < 1 || index > jumlahLegend) {
                                                cout << "Pilihan tidak valid.\n";
                                            } else {
                                                for (int i = index - 1; i < jumlahLegend - 1; i++) {
                                                    legend[i] = legend[i + 1];
                                                }
                                                jumlahLegend--;
                                                cout << "Legend berhasil dihapus!\n";
                                            }
                                        }
                                        break;
                                    case 5:
                                        cout << "Logout berhasil. Kembali ke menu utama.\n";
                                        break;
                                    default:
                                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                                }
                            } while (menu_admin != 5);
                        }
                    }
                }

                if (!loginBerhasil) {
                    percobaan--;
                    cout << "Login gagal! Sisa percobaan: " << percobaan << "\n";
                    if (percobaan == 0) {
                        cout << "Anda telah kehabisan percobaan login. Program akan keluar.\n";
                        exit(0);
                    }
                }
                break;
            }
            case 2: {
                if (jumlahUser >= MAX_USER) {
                    cout << "Maaf, kapasitas pengguna sudah penuh.\n";
                    break;
                }

                string usn, pw, role;
                cout << "Masukkan Username: ";
                cin >> usn;
                cout << "Masukkan Password: ";
                cin >> pw;
                cout << "Masukkan role (admin/user): ";
                cin >> role;

                if (role != "admin" && role != "user") {
                    cout << "Role tidak valid. Harus 'admin' atau 'user'.\n";
                    break;
                }

                dataUser[jumlahUser].usn = usn;
                dataUser[jumlahUser].pw = pw;
                dataUser[jumlahUser].role = role;
                jumlahUser++;

                cout << "Registrasi berhasil! Anda dapat login sekarang.\n";
                break;
            }
            case 3:
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);

}