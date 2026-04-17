#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
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
    int id;
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

void pause() {
    cout << "\nTekan Enter untuk melanjutkan...";
    getche();
    cout << endl;
}

void RegisterUser(User dataUser[], int *jumlahUser) {
    if (*jumlahUser >= MAX_USER) {
    cout << "Maaf, kapasitas pengguna sudah penuh.\n";
    pause();
    return;
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
        pause();
        return;
    }
    dataUser[*jumlahUser].usn = usn;
    dataUser[*jumlahUser].pw = pw;
    dataUser[*jumlahUser].role = role;
    (*jumlahUser)++;
    cout << "\nSelamat Registrasi berhasil! Silahkan Login\n";
    pause();
}

int LoginUser(User dataUser[], int *jumlahUser){

    string usn, pw;

    cout << "Username: ";
    cin >> usn;

    cout << "Password: ";
    cin >> pw;

    for(int i = 0; i < *jumlahUser; i++){
        if(dataUser[i].usn == usn && dataUser[i].pw == pw){
            return i;
        }
    }

    return -1;
}

void menu_login() {
    cout << "\n===== MENU LOGIN =====\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

void menuAdmin() {
    cout << "\n===== MENU ADMIN =====\n";
    cout << "1. Tambah Legend\n";
    cout << "2. Lihat Daftar legend\n";
    cout << "3. Edit Legend\n";
    cout << "4. Hapus Legend\n";
    cout << "5. Urutkan Class Legend\n";
    cout << "6. Urutkan Pick Rate Legend\n";
    cout << "7. Urutkan Win Rate Legend\n";
    cout << "8. Cari ID Legend\n";
    cout << "9. Cari Nama Legend\n";
    cout << "0. Logout\n";
    cout << "Pilih menu: ";
}

void menuUser() {
    cout << "\n===== MENU USER =====\n";
    cout << "1. Lihat Daftar Legend\n";
    cout << "2. Urutkan Class Legend\n";
    cout << "3. Urutkan Pick Rate Legend\n";
    cout << "4. Urutkan Win Rate Legend\n";
    cout << "5. Cari ID Legend\n";
    cout << "6. Cari Nama Legend\n";
    cout << "7. Buat Tier List\n";
    cout << "8. Lihat Tier List\n";
    cout << "9. Edit Tier List\n";
    cout << "10. Hapus Tier List\n";
    cout << "0. Logout\n";
    cout << "Pilih menu: ";
}

void TambahLegend(karakter legend[], int *jumlahLegend) {
    cout << "\nTambah Legend\n";
    cout << "Nama: ";
    cin >> legend[*jumlahLegend].nama;
    cout << "Class: ";
    cin >> legend[*jumlahLegend].classs;
    cout << "Best Weapon: ";
    cin >> legend[*jumlahLegend].best_weapon;
    cout << "Pick Rate: ";
    cin >> legend[*jumlahLegend].pick_rate;
    cout << "Win Rate: ";
    cin >> legend[*jumlahLegend].win_rate;
    (*jumlahLegend)++;
    cout << "Legend berhasil ditambahkan!\n";
    pause();
}

void DaftarLegend(karakter legend[], int &jumlahLegend) {
    cout << "\nLegend\n";
    if (jumlahLegend == 0) {
        cout << "Belum ada legend yang dapat ditampilkan.\n";
        pause();
    } else {
        cout << "\n Data Legend \n";
        cout << "|" << setw(12) << left << "Nama" << "|" << setw(12) << left << "Class" << "|" << setw(12) << left << "Best Weapon" << "|" << setw(10) << left << " Pick Rate" << "|" << setw(10) << left << " Win Rate |\n";
        cout << "==============================================================\n";
    for (int i = 0; i < jumlahLegend; i++) {
        cout << "| " << setw(10) << left << legend[i].nama << " | " << setw(10) << left << legend[i].classs << " | " << setw(10) << left << legend[i].best_weapon << " | " << setw(0) << left << legend[i].pick_rate << setw(5)<< "%" << " | " << setw(0) << left << legend[i].win_rate << "% |"  << "\n";
    }
    cout << "==============================================================\n";
    pause();
    }
}

void EditLegend(karakter legend[], int *jumlahLegend) {
    cout << "\nEdit Legend\n";
    if (*jumlahLegend == 0) {
        cout << "Belum ada legend yang dapat diedit.\n";
        pause();
    } else {
        cout << "\n Data Legend \n";
        cout << "|" << setw(12) << left << "Nama" << "|" << setw(12) << left << "Class" << "|" << setw(12) << left << "Best Weapon" << "|" << setw(10) << left << " Pick Rate" << "|" << setw(10) << left << " Win Rate |\n";
        cout << "==============================================================\n";
    for (int i = 0; i < *jumlahLegend; i++) {
        cout << "| " << setw(10) << left << legend[i].nama << " | " << setw(10) << left << legend[i].classs << " | " << setw(10) << left << legend[i].best_weapon << " | " << setw(0) << left << legend[i].pick_rate << setw(5)<< "%" << " | " << setw(0) << left << legend[i].win_rate << "% |"  << "\n";
    }
    cout << "==============================================================\n";
        int index;
        cout << "\nPilih nomor legend yang ingin diedit: ";
        cin >> index;
        if (index < 1 || index > *jumlahLegend) {
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
            pause();
        }
    }
}   

void HapusLegend(karakter legend[], int *jumlahLegend) {
    cout << "\nHapus Legend\n";
    if (*jumlahLegend == 0) {
        cout << "Belum ada legend yang dapat dihapus\n";
        pause();
    } else {
        cout << "\n Data Legend \n";
        cout << "|" << setw(12) << left << "Nama" << "|" << setw(12) << left << "Class" << "|" << setw(12) << left << "Best Weapon" << "|" << setw(10) << left << " Pick Rate" << "|" << setw(10) << left << " Win Rate |\n";
        cout << "==============================================================\n";
    for (int i = 0; i < *jumlahLegend; i++) {
        cout << "| " << setw(10) << left << legend[i].nama << " | " << setw(10) << left << legend[i].classs << " | " << setw(10) << left << legend[i].best_weapon << " | " << setw(0) << left << legend[i].pick_rate << setw(5)<< "%" << " | " << setw(0) << left << legend[i].win_rate << "% |"  << "\n";
    }
    cout << "==============================================================\n";
        int index;
        cout << "\nPilih nomor legend yang ingin dihapus: ";
        cin >> index;
        if (index < 1 || index > *jumlahLegend) {
            cout << "Pilihan tidak valid.\n";
        } else {
            for (int i = index - 1; i < *jumlahLegend - 1; i++) {
                legend[i] = legend[i + 1];
            }
            (*jumlahLegend)--;
            cout << "\nLegend berhasil dihapus!\n";
            pause();
        }
    }
}

void BuatTier(Tier_List tier_list[], int *jumlahtier, karakter legend[], int jumlahLegend){
    cout << "\nBuat Tier List\n";
    cout << "Masukkan judul tier list: ";
    cin >> ws;
    getline(cin, tier_list[*jumlahtier].judul);
    cout << "\nMasukkan tier setiap legend (S/A/B/C/D):\n";
    for ( int i = 0; i < jumlahLegend; i++) {
        cout << "Tier legend " << setw(5) << left << legend[i].nama << ": ";
        cin >> tier_list[*jumlahtier].tier[i];
    }
    (*jumlahtier)++;
    cout << "Tier list berhasil dibuat!\n";
    pause();
}

void LihatTIer(Tier_List tier_list[], int &jumlahtier, karakter legend[], int jumlahLegend){
    cout << "\nDaftar Tier List\n";
    if (jumlahtier == 0) {
        cout << "Belum ada tier list yang dapat ditampilkan.\n";
        pause();
        return;
    }else {
    for (int i = 0; i < jumlahtier; i++) {
        cout << i + 1 << ". " << tier_list[i].judul << "\n";
    }
    cout << endl;
    int index_list;
    cout << "\nPilih tier list yang ingin dilihat: ";
    cin >> index_list;
    if (index_list < 1 || index_list > jumlahtier) {
        cout << "Pilihan tidak valid.\n";
        pause();
        return;
    } else {
    index_list--;

    cout << "\n Tier List: " << tier_list[index_list].judul << "\n";
    for (int i = 0; i < jumlahLegend; i++) {
        cout << setw(10) << left << legend[i].nama << " = " << setw(2)<< tier_list[index_list].tier[i] << "\n";
            }
            pause();
        }
    }
}

void EditTier(Tier_List tier_list[], int *jumlahtier, karakter legend[], int jumlahLegend){
    cout << "\nDaftar Tier List.\n";
    if (*jumlahtier == 0) {
        cout << "Belum ada tier list yang dapat diedit.\n";
        pause();
        return;
    } else {
    for (int i = 0; i < *jumlahtier; i++) {
            cout << i + 1 << ". " << tier_list[i].judul <<"\n";
    }
    cout << endl;
    int index_edit;
    cout << "\nPilih tier list yang ingin diedit: ";
    cin >> index_edit;
    if (index_edit < 1 || index_edit > *jumlahtier) {
        cout << "Pilihan tidak valid.\n";
        pause();
        return;
    } else {
    index_edit--;

    cout << "\nMasukkan tier baru setiap legend (S/A/B/C/D):\n";
    for (int i = 0; i < jumlahLegend; i++) {
        cout << "Masukkan Tier baru " << setw(5) << left << legend[i].nama << ": ";
        cin >> tier_list[index_edit].tier[i];
            }
        }
    }
    cout << "\nTier list berhasil diedit\n";
    pause();
}

void HapusTier(Tier_List tier_list[], int *jumlahtier, karakter legend[], int jumlahLegend){
    cout << "\nDaftar Tier List.\n";
    if (*jumlahtier == 0) {
        cout << "Belum ada tier list yang dapat dihapus.\n";
        pause();
        return;
    } else {
    for (int i = 0; i < *jumlahtier; i++) {
            cout << i + 1 << ". " << tier_list[i].judul << "\n";
    }
    int index_hapus;
    cout << "\nPilih tier list yang ingin dihapus: ";
    cin >> index_hapus;
    if (index_hapus < 1 || index_hapus > *jumlahtier) {
        cout << "Pilihan tidak valid.\n";
        pause();
        return;
    } else {
    index_hapus--;

    for (int i = index_hapus; i < *jumlahtier - 1; i++) {
        tier_list[i] = tier_list[i + 1];
            }
        }
    }
    (*jumlahtier)--;
    cout << "\nTier list berhasil dihapus\n";
    pause();
}

void sortClass(karakter legend[], int jumlahLegend) {
    for(int i = 0; i < jumlahLegend - 1; i++) {
        for(int j = 0; j < jumlahLegend - i - 1; j++) {
            if(legend[j].classs > legend[j + 1].classs) {
                swap(legend[j], legend[j + 1]);
            }
        }
    }
    cout << "\nLegend berhasil diurutkan berdasarkan Class!\n";
    pause();
}

void sortPickrate(karakter legend[], int jumlahLegend) {
    for(int i = 0; i < jumlahLegend - 1; i++) {
        int max = i;
        for(int j = i + 1; j < jumlahLegend; j++) {
            if(legend[j].pick_rate > legend[max].pick_rate) {
                max = j;
            }
        }
        swap(legend[max], legend[i]);
    }
    cout << "\nLegend berhasil diurutkan berdasarkan Pick Rate tertinggi!\n";
    pause();
}

void sortWinRate(karakter legend[], int jumlahLegend) {
    for(int i =  0; i < jumlahLegend; i++){
        karakter key = legend[i];
        int j = i - 1;
        while(j >= 0 && legend[j].win_rate < key.win_rate) {
            swap(legend[j + 1], legend[j]);
            j--;
        }
        legend[j + 1] = key;
    }
    cout << "\nLegend berhasil diurutkan berdasarkan Win Rate tertinggi!\n";
    pause();
}

void searchid(karakter Legend[], int jumlahLegend){
    int cari_id;
    cout << "\nMasukkan ID legend yang ingin dicari: ";
    cin >> cari_id;

    int low = 0; 
    int high = jumlahLegend - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (Legend[mid].id == cari_id) {
            cout << "\nLegend ditemukan:\n";
            cout << "ID: " << Legend[mid].id << "\n";
            cout << "Nama: " << Legend[mid].nama << "\n";
            cout << "Class: " << Legend[mid].classs << "\n";
            cout << "Best Weapon: " << Legend[mid].best_weapon << "\n";
            cout << "Pick Rate: " << Legend[mid].pick_rate << "%\n";
            cout << "Win Rate: " << Legend[mid].win_rate << "%\n";
            pause();
            return;
        } else if (Legend[mid].id < cari_id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "\nID Legend " << cari_id << " tidak ditemukan.\n";
    pause();
}

void searchnama(karakter Legend[], int jumlahLegend){
    string cari_nama;
    cout << "\nMasukkan nama legend yang ingin dicari: ";
    cin >> cari_nama;

    for (int i = 0; i < jumlahLegend; i++) {
        if (Legend[i].nama == cari_nama) {
            cout << "\nLegend ditemukan:\n";
            cout << "ID: " << Legend[i].id << "\n";
            cout << "Nama: " << Legend[i].nama << "\n";
            cout << "Class: " << Legend[i].classs << "\n";
            cout << "Best Weapon: " << Legend[i].best_weapon << "\n";
            cout << "Pick Rate: " << Legend[i].pick_rate << "%\n";
            cout << "Win Rate: " << Legend[i].win_rate << "%\n";
            pause();
            return;
        }
    }
    cout << "\nLegend " << cari_nama << " tidak ditemukan.\n";
    pause();
}

void logout() {
    cout << "Logout berhasil. Kembali ke menu utama.\n";
    pause();
}

int main() {

    User dataUser[MAX_USER];
    karakter legend[MAX_LEGENDS];
    Tier_List tier_list[MAXLIST];
    int jumlahUser = 1;
    int jumlahLegend = 11;
    int jumlahtier = 0;;
    int percobaan = 3;
    int pilihan;
    int indexUser = -1 ;
    dataUser[0] = {"admin", "admin123", "admin"};

    legend[0] = {101, "Alter", "Skirmisher", "SMG", 14.5, 52};
    legend[1] = {102, "Ash", "Skirmisher", "SMG", 0.4, 49.4};
    legend[2] = {103, "Bangalore", "Assault", "SMG", 7.4, 49.1};
    legend[3] = {104, "Fuse", "Assault", "SMG", 1.1, 48.8};
    legend[4] = {105, "Horizon", "Skirmisher", "AR", 3.6, 47.5};
    legend[5] = {106, "Loba", "Support", "AR", 2.8, 51.7};
    legend[6] = {107, "Newcastle", "Support", "SG", 0.6, 48.1};
    legend[7] = {108, "Seer", "Recon", "AR", 1.3, 48.7};
    legend[8] = {109, "valkyrie", "Recon", "AR", 9.2, 54.4};
    legend[9] = {1010,"Wattson", "Controller", "SMG", 0.2, 51.7};
    legend[10] = {1011,"Wraith", "Skirmisher", "SMG", 0.6, 47.5};

    do {
        menu_login();
        cin >> pilihan; 

        switch (pilihan) {
            case 1: {
                indexUser = LoginUser(dataUser, &jumlahUser);
                if(indexUser != -1){
                    cout << "\nLogin berhasil! Selamat datang, "
                        << dataUser[indexUser].usn << " (" << dataUser[indexUser].role << ")\n";
                        pause();                       

                        if (dataUser[indexUser].role == "admin") {
                            int menu_admin;
                            do{
                                menuAdmin();
                                cin >> menu_admin;
                                switch (menu_admin) {
                                    case 1:
                                        TambahLegend(legend, &jumlahLegend);
                                    break;

                                    case 2:
                                        DaftarLegend(legend, jumlahLegend);
                                        break;

                                    case 3:
                                        EditLegend(legend, &jumlahLegend);
                                        break;

                                    case 4:
                                        HapusLegend(legend, &jumlahLegend);
                                        break;

                                    case 5:
                                        sortClass(legend, jumlahLegend);
                                        break;

                                    case 6:
                                        sortPickrate(legend, jumlahLegend);
                                        break;

                                    case 7:
                                        sortWinRate(legend, jumlahLegend);
                                        break;

                                    case 8:
                                        searchid(legend, jumlahLegend);
                                        break;

                                    case 9:
                                        searchnama(legend, jumlahLegend);
                                        break;

                                    case 0:
                                        logout();
                                        break;
                                    default:
                                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                                        pause();
                                }
                            } while (menu_admin != 0);
                        }

                        else if(dataUser[indexUser].role == "user") {
                            int menu_user;
                            do {
                                menuUser();
                                cin >> menu_user;
                                switch (menu_user) {
                                    case 1:
                                        DaftarLegend(legend, jumlahLegend);
                                        break;

                                    case 2:
                                        sortClass(legend, jumlahLegend);
                                        break;

                                    case 3:
                                        sortPickrate(legend, jumlahLegend);
                                        break;

                                    case 4:
                                        sortWinRate(legend, jumlahLegend);
                                        break;

                                    case 5:
                                        searchid(legend, jumlahLegend);
                                        break;

                                    case 6:
                                        searchnama(legend, jumlahLegend);
                                        break;

                                    case 7:
                                        BuatTier(tier_list, &jumlahtier, legend, jumlahLegend);
                                        break;

                                    case 8: 
                                        LihatTIer(tier_list, jumlahtier, legend, jumlahLegend);
                                        break;

                                    case 9:
                                        EditTier(tier_list, &jumlahtier, legend, jumlahLegend);
                                        break;

                                    case 10:
                                        HapusTier(tier_list, &jumlahtier, legend, jumlahLegend);
                                        break;
                                    case 0:
                                        logout();
                                        break;

                                    default:
                                        cout << "Pilihan tidak valid. Silakan coba lagi\n";
                                        pause();
                                }
                            } while (menu_user != 0);
                        }
                        break;
                    }
                }

                if (indexUser == -1) {
                    percobaan--;
                    cout << "Login gagal! Sisa percobaan: " << percobaan << "\n";
                    pause();
                    if (percobaan == 0) {
                        cout << endl;
                        cout << "Anda telah kehabisan percobaan login. Program SELESAI.\n";
                        cout << endl;
                        exit(0);
                    }
                }
                break;
            case 2: {
                RegisterUser(dataUser, &jumlahUser);
                break;
            }
            case 0:
                cout << endl;
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!\n";
                cout << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                pause();
        }
    } while (pilihan != 0);

    return 0;
}