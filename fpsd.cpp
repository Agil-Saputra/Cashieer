#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <iomanip>

using namespace std;

// Struktur data untuk film
struct Film {
    string judul;
    string genre;
    int durasi;
    string tanggalTayang;
    float rating;
    float hargaTiket;
};
void delay(void)
{
    int delay;
    delay = 2; // berarti setiap delay di pangil maka akan keluar 1 persatu
    while (delay < 100000000) {
        delay++;
    }
} // agar dapat terus mengulang dan bertambah

void loading()
{
   system("COLOR 0e");
   system("cls");
   
   printf ("\n\n\n\n\n\n\n\n\n\n\n\n");
   printf (" \t\t\t\t\t\t\t\t\t\t\t");
   cout << "Selamat Datang Di Bioskop Kami..." << endl;
   printf(" \t\t\t\t\t\t\t\t\t\t\t");
   
   for (int i = 0; i < 30; i++)
   {
       printf("%c", 254);
       delay();
       
    }
   system("cls");
}

// Struktur data untuk kursi
struct Kursi {
    int nomorKursi;
    bool status; // Tersedia (true) atau terisi (false)
    char tipeKursi; // 'R' (Reguler) atau 'V' (VIP)
};

// Deklarasi global
vector<Film> daftarFilm; // Daftar film
vector<Kursi> daftarKursi; // Daftar kursi
queue<pair<Film, vector<Kursi>>> antrianPemesanan; // Antrian pemesanan tiket

// Fungsi input data film
void inputFilm() {
    Film film;

    cout << "Masukkan data film:\n";
    cout << "Judul: "; cin.ignore(); getline(cin, film.judul);
    cout << "Genre: "; getline(cin, film.genre);
    cout << "Durasi (menit): "; cin >> film.durasi;
    cout << "Tanggal Tayang (YYYY-MM-DD): "; cin >> film.tanggalTayang;
    cout << "Rating: "; cin >> film.rating;
    cout << "Harga Tiket: "; cin >> film.hargaTiket;

    daftarFilm.push_back(film);
}

// Fungsi output data film
void outputFilm() {
    if (daftarFilm.empty()) {
        cout << "Data film masih kosong!" << endl;
        return;
    }
    
    const int width = 20;
     int numWidth = 5; // Lebar untuk nomor urut
    cout << "\n========================================================================================================================" << endl;
    cout << left << setw(numWidth) << "| No." << setw(width) << "| Judul" << setw(width) << "| Genre" << setw(width) << "| Durasi" 
         << setw(width) << "| Tanggal Tayang" << setw(width) << "| Rating" << setw(width) << "| Harga Tiket |" << endl;
    cout << "========================================================================================================================" << endl;

	int nomor = 1;
    for (const auto& film : daftarFilm) {
         cout << left << "| " << setw(numWidth - 2) << nomor++
			 << "| " << setw(width - 2) << film.judul 
             << "| " << setw(width - 2) << film.genre
             << "| " << setw(width - 7) << film.durasi << "menit"
             << "| " << setw(width - 2) << film.tanggalTayang 
             << "| " << setw(width - 2) << film.rating 
             << "| Rp" << setw(width - 10) << film.hargaTiket << "|" << endl;
    }
    cout << "========================================================================================================================" << endl;
}


// Fungsi sorting data film (berdasarkan judul)
void sortFilm() {
    sort(daftarFilm.begin(), daftarFilm.end(), [](const Film& f1, const Film& f2) {
        return f1.judul < f2.judul;
    });
}

// Fungsi searching data film (berdasarkan judul, genre, rating, atau tanggal tayang)
Film searchFilm(string query) {
    for (const Film& film : daftarFilm) {
        if (film.judul.find(query) != string::npos ||
            film.genre.find(query) != string::npos ||
            to_string(film.rating).find(query) != string::npos ||
            film.tanggalTayang.find(query) != string::npos) {
            return film;
        }
    }

    return Film(); // Film tidak ditemukan
}

// Fungsi input data kursi
void inputKursi() {
    int jumlahKursi;

    cout << "Masukkan jumlah kursi: ";
    cin >> jumlahKursi;

    for (int i = 0; i < jumlahKursi; i++) {
        Kursi kursi;

        cout << "\nKursi #" << i + 1 << ":\n";
        cout << "Nomor Kursi: ";
        cin >> kursi.nomorKursi;
        cout << "Status | 0 = terisi | 1 = tersedia |: ";
        cin >> kursi.status;
        cout << "Tipe Kursi | Regular/VIP |: ";
        cin >> kursi.tipeKursi;

        daftarKursi.push_back(kursi);
    }
}

// Fungsi output data kursi
void outputKursi() {
    if (daftarKursi.empty()) {
        cout << "Data kursi masih kosong!" << endl;
        return;
    }

    cout << "\nDaftar Kursi:\n";
    for (const Kursi& kursi : daftarKursi) {
        cout << "| Nomor: " << kursi.nomorKursi << "| Status: " << (kursi.status ? "Tersedia" : "Terisi") << "| Tipe: " << kursi.tipeKursi << endl;
    }
}

// Fungsi pemesanan tiket
void pesanTiket() {
    if (daftarFilm.empty()) {
        cout << "Belum ada data film yang dimasukkan." << endl;
        return;
    }

    int indexFilm;
    outputFilm();
    cout << "Pilih film (masukkan nomor): "; cin >> indexFilm;
    indexFilm--; // Kurangi 1 karena index dimulai dari 0

    if (indexFilm < 0 || indexFilm >= daftarFilm.size()) {
        cout << "Nomor film tidak valid!" << endl;
        return;
    }

    Film filmTerpilih = daftarFilm[indexFilm];
    int jumlahKursi;
    cout << "Berapa banyak kursi yang ingin Anda pesan: "; cin >> jumlahKursi;

    if (jumlahKursi > daftarKursi.size()) {
        cout << "Maaf, Kursi Sudah Habis Terpesan." << endl;
        return;
    }

    vector<Kursi> kursiTerpilih;
    for (int i = 0; i < jumlahKursi; i++) {
        int nomorKursi;
        cout << "Masukkan nomor kursi ke-" << i + 1 << ": "; cin >> nomorKursi;

        bool found = false;
        for (Kursi& kursi : daftarKursi) {
            if (kursi.nomorKursi == nomorKursi && kursi.status) {
                kursi.status = false; // Ubah status kursi menjadi terisi
                kursiTerpilih.push_back(kursi);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Kursi dengan nomor " << nomorKursi << " tidak tersedia." << endl;
            // Mengembalikan status kursi yang sudah terisi sebelumnya
            for (Kursi& kursi : kursiTerpilih) {
                kursi.status = true;
            }
            return;
        }
    }

    // Masukkan ke dalam antrian pemesanan
    antrianPemesanan.push(make_pair(filmTerpilih, kursiTerpilih));

    cout << "\nPemesanan tiket berhasil!" << endl;
}

// Fungsi untuk menampilkan antrian pemesanan tiket
void displayAntrianPemesanan() {
    if (antrianPemesanan.empty()) {
        cout << "Antrian pemesanan tiket masih kosong." << endl;
        return;
    }

    int count = 1;
    cout << "\nAntrian Pemesanan Tiket:\n";
    queue<pair<Film, vector<Kursi>>> tempQueue = antrianPemesanan; // Make a copy of the queue

    while (!tempQueue.empty()) {
        pair<Film, vector<Kursi>> entry = tempQueue.front();
        Film film = entry.first;
        vector<Kursi> kursi = entry.second;

        cout << count << ". " << film.judul << " - Tanggal Tayang: " << film.tanggalTayang << " - Jumlah Kursi: " << kursi.size() << endl;
       
        // Menampilkan booking tiket
        cout << "   Kursi: ";
        for (size_t i = 0; i < kursi.size(); ++i) {
            cout << kursi[i].nomorKursi;
            if (i < kursi.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;

        tempQueue.pop();
        count++;
    }
}

// Fungsi untuk menyimpan data film ke dalam file
void saveFilmsToFile() {
    ofstream file("films.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk penyimpanan data film." << endl;
        return;
    }

    for (const Film& film : daftarFilm) {
        file << film.judul << "|" << film.genre << "|" << film.durasi << "|" << film.tanggalTayang << "|" << film.rating << "|" << film.hargaTiket << "\n";
    }

    file.close();
    cout << "Data film berhasil disimpan ke dalam file 'films.txt'." << endl;
}

// Fungsi untuk menyimpan data kursi ke dalam file
void saveSeatsToFile() {
    ofstream file("seats.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk penyimpanan data kursi." << endl;
        return;
    }

    for (const Kursi& kursi : daftarKursi) {
        file << kursi.nomorKursi << "|" << kursi.status << "|" << kursi.tipeKursi << "\n";
    }

    file.close();
    cout << "Data kursi berhasil disimpan ke dalam file 'seats.txt'." << endl;
}

// Fungsi utama
int main() {
    int pilihan;
    loading();

    do {
    	cout << "\n\t\t\t\t\t\t\t\t\t| ============================================================= |\n";
        cout << "\t\t\t\t\t\t\t\t\t|                Selamat Datang Di Bioskop Kami                 |\n";
        cout << "\t\t\t\t\t\t\t\t\t| ============================================================= |\n";
        cout << "\t\t\t\t\t\t\t\t\t| 1.  Isi data film\t\t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 2.  Cek film \t\t\t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 3.  List film \t\t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 4.  Cari Ketersediaan film \t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 5.  Pesan kursi \t\t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 6.  Cek Ketersediaan Kursi \t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 7.  Pemesanan Tiket Film \t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 8.  Cek antrian pemesanan tiket \t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 9.  Print film \t\t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 10. Print kursi \t\t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| 11. Exit \t\t\t\t\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t| ============================================================= |\n";
        cout << "Pilih menu : "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputFilm();
                break;
            case 2:
                outputFilm();
                break;
            case 3:
                sortFilm();
                cout << "Data film telah diurutkan berdasarkan judul." << endl;
                break;
            case 4: {
                string query;
                cout << "Masukkan Film yang Ingin dicari | Judul | Genre | Rating | Tanggal Tayang |: "; cin >> query;
                Film hasilPencarian = searchFilm(query);
                if (hasilPencarian.judul.empty()) {
                    cout << "Film tidak ditemukan." << endl;
                } else {
                    cout << "\nHasil Pencarian:\n";
                    cout << hasilPencarian.judul << " | " << hasilPencarian.genre << " | "
                         << hasilPencarian.durasi << " menit | " << hasilPencarian.tanggalTayang
                         << " | Rating: " << hasilPencarian.rating << " | Harga: Rp" << hasilPencarian.hargaTiket << endl;
                }
                break;
            }
            case 5:
                inputKursi();
                break;
            case 6:
                outputKursi();
                break;
            case 7:
                pesanTiket();
                break;
            case 8:
                displayAntrianPemesanan();
                break;
            case 9:
                saveFilmsToFile();
                break;
            case 10:
                saveSeatsToFile();
                break;
            case 11:
                cout << "Terima kasih telah menggunakan layanan kami." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 11);

    return 0;
}
