#include <iostream>
#include <cstdlib>
using namespace std;

#ifdef _WIN32
    #define CLEAR system("cls")
#else
    #define CLEAR system("clear")
#endif

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
                                            cout << "| Nama      | Class     | Best Weapon   | Pick Rate     | Win Rate \n";
                                            cout << "===================================================================\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "| " << legend[i].nama << "      | " << legend[i].classs << "    | " << legend[i].best_weapon << "   | " << legend[i].pick_rate << "%" << "      | " << legend[i].win_rate << "%"  << "\n";
                                        }
                                        cout << "===================================================================\n";
                                        }
                                        break;
                                    case 3: // Edit Legend
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
                                                cout << "Pick Rate: ";
                                                cin >> legend[index].pick_rate;
                                                cout << "Win Rate: ";
                                                cin >> legend[index].win_rate;
                                                cout << "Legend berhasil diedit!\n";
                                            }
                                        }
                                        break;
                                    case 4: // Hapus Legend
                                        cout << "Hapus Legend\n";
                                        if (jumlahLegend == 0) {
                                            cout << "Belum ada legend yang dapat dihapus.\n";
                                        }else {
                                            cout << "Daftar Legend:\n";
                                            for (int i = 0; i < jumlahLegend; i++) {
                                                cout << i + 1 << ". " << legend[i].nama << "\n";
                                            }
                                            int index;
                                            cout << "Pilih nomor legend yang ingin dihapus: ";
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
                        else if(dataUser[i].role == "user") {
                            int menu_user;
                            do {
                                cout << "\n===== MENU USER =====\n";
                                cout << "1. Tampilkan Legend\n";
                                cout << "2. Buat Tier List\n";
                                cout << "3. Lihat Tier List\n";
                                cout << "4. Edit Tier List\n";
                                cout << "5. Hapus Tier List\n";
                                cout << "6. LogOut\n";
                                cout << "Pilih menu: ";
                                cin >> menu_user;
                                switch (menu_user) {
                                    case 1: // tampilkan legend
                                        
                                        cout << "\nLegend\n";
                                        if (jumlahLegend == 0) {
                                            cout << "Belum ada legend yang dapat ditampilkan.\n";
                                        } else {
                                            cout << "| Nama      | Class     | Best Weapon   | Pick Rate     | Win Rate \n";
                                            cout << "===================================================================\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "| " << legend[i].nama << "      | " << legend[i].classs << "    | " << legend[i].best_weapon << "   | " << legend[i].pick_rate << "%" << "      | " << legend[i].win_rate << "%"  << "\n";
                                        }
                                        cout << "===================================================================\n";
                                        }
                                        break;
                                    case 2: // buat tier list
                                        cout << "Buat Tier List\n";
                                        cout << "Masukkan judul tier list: ";
                                        cin >> ws;
                                        getline(cin, tier_list[jumlahtier].judul);
                                        for ( int i = 0; i < jumlahLegend; i++) {
                                            cout << "Masukkan tier untuk legend " << legend[i].nama << " (S/A/B/C/D): ";
                                            cin >> tier_list[jumlahtier].tier[i];
                                        }
                                        cout << "Tier list berhasil dibuat!\n";
                                        jumlahtier++;
                                        cin.get();
                                        break;
                                    case 3: // lihat tier list
                                        cout << "Lihat Tier List\n";
                                        for (int i = 0; i < jumlahtier; i++) {
                                            cout << i + 1 << ". " << tier_list[i].judul << "\n";
                                        }
                                        int index_list;
                                        cout << "Pilih tier list yang ingin dilihat: ";
                                        cin >> index_list;
                                        index_list--;

                                        cout << "\n Tier List: " << tier_list[index_list].judul << "\n";
                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "Legend: " << legend[i].nama << " - Tier: " << tier_list[index_list].tier[i] << "\n";
                                            cin.get();
                                        }
                                        break;
                                    case 4: // edit tier list
                                        cout << "Daftar Tier List.\n";
                                        for (int i = 0; i < jumlahtier; i++) {
                                                cout << i + 1 << ". " << tier_list[i].judul << "\n";
                                        }
                                        int index_edit;
                                        cout << "Pilih tier list yang ingin diedit: ";
                                        cin >> index_edit;
                                        index_edit--;

                                        for (int i = 0; i < jumlahLegend; i++) {
                                            cout << "Masukkan tier Baru " << legend[i].nama << " (S/A/B/C/D): ";
                                            cin >> tier_list[index_edit].tier[i];
                                        }
                                        cout << "\nTier list berhasil diedit\n";
                                        cin.get();
                                        break;
                                    case 5: // Hapus Tier List
                                        cout << "Daftar Tier List.\n";
                                        for (int i = 0; i < jumlahtier; i++) {
                                                cout << i + 1 << ". " << tier_list[i].judul << "\n";
                                        }
                                        int index_hapus;
                                        cout << "Pilih tier list yang ingin dihapus: ";
                                        cin >> index_hapus;
                                        index_hapus--;

                                        for (int i = index_hapus; i < jumlahtier - 1; i++) {
                                            tier_list[i] = tier_list[i + 1];
                                        }
                                        jumlahtier--;
                                        cout << "\nTier list berhasil dihapus\n";
                                        cin.get();
                                        break;

                                    default:
                                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
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