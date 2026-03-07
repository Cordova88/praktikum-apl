#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int MAX_USER = 100;
const int MAX_LEGENDS = 30;
const int MAXLIST = 20;

struct User {
    string usn;
    string pw;
    string role;
};

struct karakter {
    string nama;
    string classs;
    string best_weapon;
    float pick_rate;
    float win_rate;
};
struct Tier_List {
    string judul;
    char tier[MAX_LEGENDS];
};


int main() {

    User dataUser[MAX_USER];
    karakter legend[MAX_LEGENDS];
    Tier_List tier_list[MAXLIST];
    int jumlahUser = 1;
    int jumlahLegend = 11;
    int jumlahtier = 0;;
    int percobaan = 3;
    int pilihan;
    dataUser[0] = {"admin", "admin123", "admin"};

    legend[0] = {"Alter", "Skirmisher", "SMG", 14.5, 52};
    legend[1] = {"Ash", "Skirmisher", "SMG", 0.4, 49.4};
    legend[2] = {"Bangalore", "Assault", "SMG", 7.4, 49.1};
    legend[3] = {"Fuse", "Assault", "SMG", 1.1, 48.8};
    legend[4] = {"Horizon", "Skirmisher", "AR", 3.6, 47.5};
    legend[5] = {"Loba", "Support", "AR", 2.8, 51.7};
    legend[6] = {"Newcastle", "Support", "SG", 0.6, 48.1};
    legend[7] = {"Seer", "Recon", "AR", 1.3, 48.7};
    legend[8] = {"valkyrie", "Recon", "AR", 9.2, 54.4};
    legend[9] = {"Wattson", "Controller", "SMG", 0.2, 51.7};
    legend[10] = {"Wraith", "Skirmisher", "SMG", 0.6, 47.5};

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
                cout << "\nMasukkan Username: ";
                cin >> usn;
                cout << "Masukkan Password: ";
                cin >> pw;

                bool loginBerhasil = false;
                for (int i = 0; i < jumlahUser; i++) {
                    if (dataUser[i].usn == usn && dataUser[i].pw == pw) {
                        loginBerhasil = true;
                        cout << "\nLogin berhasil! Selamat datang, " << dataUser[i].usn << " (" << dataUser[i].role << ")\n";

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
                                    case 1: // Tambah Legend
                                        cout << "\nTambah Legend\n";
                                        cout << "Nama: ";
                                        cin >> legend[jumlahLegend].nama;
                                        cout << "Class: ";
                                        cin >> legend[jumlahLegend].classs;
                                        cout << "Best Weapon: ";
                                        cin >> legend[jumlahLegend].best_weapon;
                                        cout << "Pick Rate: ";
                                        cin >> legend[jumlahLegend].pick_rate;
                                        cout << "Win Rate: ";
                                        cin >> legend[jumlahLegend].win_rate;
                                        jumlahLegend++;
                                        cout << "Legend berhasil ditambahkan!\n";
                                        
                                    break;

                                    case 2: // Tampilkan Legend
                                        cout << "\nLegend\n";
                                        if (jumlahLegend == 0) {
                                            cout << "Belum ada legend yang dapat ditampilkan.\n";
                                        } else {
                                            cout << "\n Data Legend \n";
                                            cout << "|" << setw(12) << left << "Nama" << "|" << setw(12) << left << "Class" << "|" << setw(12) << left << "Best Weapon" << "|" << setw(10) << left << " Pick Rate" << "|" << setw(10) << left << " Win Rate |\n";
                                            cout << "==============================================================\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "| " << setw(10) << left << legend[i].nama << " | " << setw(10) << left << legend[i].classs << " | " << setw(10) << left << legend[i].best_weapon << " | " << setw(0) << left << legend[i].pick_rate << setw(5)<< "%" << " | " << setw(0) << left << legend[i].win_rate << "% |"  << "\n";
                                        }
                                        cout << "==============================================================\n";
                                        }
                                        break;
                                    case 3: // Edit Legend
                                        cout << "\nEdit Legend\n";
                                        if (jumlahLegend == 0) {
                                            cout << "Belum ada legend yang dapat diedit.\n";
                                        } else {
                                            cout << "\n Data Legend \n";
                                            cout << "|" << setw(12) << left << "Nama" << "|" << setw(12) << left << "Class" << "|" << setw(12) << left << "Best Weapon" << "|" << setw(10) << left << " Pick Rate" << "|" << setw(10) << left << " Win Rate |\n";
                                            cout << "==============================================================\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "| " << setw(10) << left << legend[i].nama << " | " << setw(10) << left << legend[i].classs << " | " << setw(10) << left << legend[i].best_weapon << " | " << setw(0) << left << legend[i].pick_rate << setw(5)<< "%" << " | " << setw(0) << left << legend[i].win_rate << "% |"  << "\n";
                                        }
                                        cout << "==============================================================\n";
                                            int index;
                                            cout << "\nPilih nomor legend yang ingin diedit: ";
                                            cin >> index;
                                            if (index < 1 || index > jumlahLegend) {
                                                cout << "Pilihan tidak valid.\n";
                                            } else {
                                                index--;
                                                cout << "\nEdit Legend: " << legend[index].nama << "\n";
                                                cout << "\nNama: ";
                                                cin >> legend[index].nama;
                                                cout << "Class: ";
                                                cin >> legend[index].classs;
                                                cout << "Best Weapon: ";
                                                cin >> legend[index].best_weapon;
                                                cout << "Pick Rate: ";
                                                cin >> legend[index].pick_rate;
                                                cout << "Win Rate: ";
                                                cin >> legend[index].win_rate;
                                                cout << "\nLegend berhasil diedit!\n";
                                            }
                                        }
                                        break;
                                    case 4: // Hapus Legend
                                        cout << "\nHapus Legend\n";
                                        if (jumlahLegend == 0) {
                                            cout << "Belum ada legend yang dapat dihapus\n";
                                        } else {
                                            cout << "\n Data Legend \n";
                                            cout << "|" << setw(12) << left << "Nama" << "|" << setw(12) << left << "Class" << "|" << setw(12) << left << "Best Weapon" << "|" << setw(10) << left << " Pick Rate" << "|" << setw(10) << left << " Win Rate |\n";
                                            cout << "==============================================================\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "| " << setw(10) << left << legend[i].nama << " | " << setw(10) << left << legend[i].classs << " | " << setw(10) << left << legend[i].best_weapon << " | " << setw(0) << left << legend[i].pick_rate << setw(5)<< "%" << " | " << setw(0) << left << legend[i].win_rate << "% |"  << "\n";
                                        }
                                        cout << "==============================================================\n";
                                            int index;
                                            cout << "\nPilih nomor legend yang ingin dihapus: ";
                                            cin >> index;
                                            if (index < 1 || index > jumlahLegend) {
                                                cout << "Pilihan tidak valid.\n";
                                            } else {
                                                for (int i = index - 1; i < jumlahLegend - 1; i++) {
                                                    legend[i] = legend[i + 1];
                                                }
                                                jumlahLegend--;
                                                cout << "\nLegend berhasil dihapus!\n";
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
                        else if(dataUser[i].role == "user") {
                            int menu_user;
                            do {
                                cout << "\n===== MENU USER =====\n";
                                cout << "1. Tampilkan Legend\n";
                                cout << "2. Buat Tier List\n";
                                cout << "3. Lihat Tier List\n";
                                cout << "4. Edit Tier List\n";
                                cout << "5. Hapus Tier List\n";
                                cout << "6. Logout\n";
                                cout << "Pilih menu: ";
                                cin >> menu_user;
                                switch (menu_user) {
                                    case 1: // tampilkan legend
                                        
                                        cout << "\nData Legend\n";
                                        if (jumlahLegend == 0) {
                                            cout << "Belum ada legend yang dapat ditampilkan.\n";
                                        } else {
                                            cout << "|" << setw(12) << left << "Nama" << "|" << setw(12) << left << "Class" << "|" << setw(12) << left << "Best Weapon" << "|" << setw(10) << left << " Pick Rate" << "|" << setw(10) << left << " Win Rate |\n";
                                            cout << "==============================================================\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "| " << setw(10) << left << legend[i].nama << " | " << setw(10) << left << legend[i].classs << " | " << setw(10) << left << legend[i].best_weapon << " | " << setw(0) << left << legend[i].pick_rate << setw(5)<< "%" << " | " << setw(0) << left << legend[i].win_rate << "% |"  << "\n";
                                        }
                                        cout << "==============================================================\n";
                                        }
                                        break;

                                    case 2: // buat tier list
                                        cout << "\nBuat Tier List\n";
                                        cout << "Masukkan judul tier list: ";
                                        cin >> ws;
                                        getline(cin, tier_list[jumlahtier].judul);
                                        cout << "\nMasukkan tier setiap legend (S/A/B/C/D):\n";
                                        for ( int i = 0; i < jumlahLegend; i++) {
                                            cout << "Tier legend " << setw(5) << left << legend[i].nama << ": ";
                                            cin >> tier_list[jumlahtier].tier[i];
                                        }
                                        cout << "Tier list berhasil dibuat!\n";
                                        jumlahtier++;
                                        cin.get();
                                        break;

                                    case 3: // lihat tier list
                                        cout << "\nLihat Tier List\n";
                                        if (jumlahtier == 0) {
                                            cout << "Belum ada tier list yang dapat ditampilkan.\n";
                                            break;
                                        }else {
                                        for (int i = 0; i < jumlahtier; i++) {
                                            cout << i + 1 << ". " << tier_list[i].judul;
                                        }
                                        cout << endl;
                                        int index_list;
                                        cout << "\nPilih tier list yang ingin dilihat: ";
                                        cin >> index_list;
                                        index_list--;

                                        cout << "\n Tier List: " << tier_list[index_list].judul << "\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << setw(10) << left << legend[i].nama << " = " << setw(2)<< tier_list[index_list].tier[i] << "\n";
                                            }
                                        }
                                        break;

                                    case 4: // edit tier list
                                        cout << "\nDaftar Tier List.\n";
                                        if (jumlahtier == 0) {
                                            cout << "Belum ada tier list yang dapat diedit.\n";
                                            break;
                                        } else {
                                        for (int i = 0; i < jumlahtier; i++) {
                                                cout << i + 1 << ". " << tier_list[i].judul;
                                        }
                                        cout << endl;
                                        int index_edit;
                                        cout << "\nPilih tier list yang ingin diedit: ";
                                        cin >> index_edit;
                                        index_edit--;

                                        cout << "\nMasukkan tier baru setiap legend (S/A/B/C/D):\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "Masukkan tier Baru " << legend[i].nama << setw(5) << ": ";
                                            cin >> tier_list[index_edit].tier[i];
                                            }
                                        }
                                        cout << "\nTier list berhasil diedit\n";
                                        cin.get();
                                        break;

                                    case 5: // Hapus Tier List
                                        cout << "\nDaftar Tier List.\n";
                                        if (jumlahtier == 0) {
                                            cout << "Belum ada tier list yang dapat dihapus.\n";
                                            break;
                                        } else {
                                        for (int i = 0; i < jumlahtier; i++) {
                                                cout << i + 1 << ". " << tier_list[i].judul << "\n";
                                        }
                                        int index_hapus;
                                        cout << "\nPilih tier list yang ingin dihapus: ";
                                        cin >> index_hapus;
                                        index_hapus--;

                                        for (int i = index_hapus; i < jumlahtier - 1; i++) {
                                            tier_list[i] = tier_list[i + 1];
                                            }
                                        }
                                        jumlahtier--;
                                        cout << "\nTier list berhasil dihapus\n";
                                        cin.get();
                                        break;

                                    default:
                                        cout << "Pilihan tidak valid. Silakan coba lagi\n";
                                }
                            } while (menu_user != 6);
                        }
                        break;
                    }
                }

                if (!loginBerhasil) {
                    percobaan--;
                    cout << "Login gagal! Sisa percobaan: " << percobaan << "\n";
                    if (percobaan == 0) {
                        cout << "Anda telah kehabisan percobaan login. Program SELESAI.\n";
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

                cout << "Selamat Registrasi berhasil! Silahkan Login\n";
                break;
            }
            case 3:
                cout << endl;
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!\n";
                cout << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}