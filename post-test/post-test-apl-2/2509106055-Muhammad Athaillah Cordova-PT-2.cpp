#include <iostream>
#include <cstdlib>
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
    string nama_asli;
    string home_world;
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
    int jumlahLegend = 0;
    int jumlahtier = 0;;
    int percobaan = 3;
    int pilihan;
    dataUser[0].usn = "admin";
    dataUser[0].pw = "admin123";
    dataUser[0].role = "admin";

    do {

        cout << "Akun: \n";
        for (int i = 0; i < jumlahUser; i++) {
            cout << "Username: " << dataUser[i].usn << ", Password: " << dataUser[i].pw << ", Role: " << dataUser[i].role << "\n";
        }
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
                                    case 1:
                                        
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
                                    case 2:
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
                                    case 3:
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
                                    case 4:
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
                                    case 5:
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