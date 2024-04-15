#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Struktur data untuk simpul (node) pada double linked list
struct Node {
    int nip;
    string nama;
    string golongan;
    double gajiPokok;
    double tunjanganAnak;
    double tunjanganIstri;
    double uangMakan;
    double transport;
    int absensi;
    double totalGaji;
    Node* prev;
    Node* next;
};

// Head dan tail untuk menandai awal dan akhir dari double linked list
Node* head = nullptr;
Node* tail = nullptr;

// Fungsi untuk menambah data pegawai di depan double linked list
void tambahDataDepan(int nip, string nama, string golongan, bool punyaIstri, int jumlahTanggunganAnak, int absensi) {
    Node* newNode = new Node;
    newNode->nip = nip;
    newNode->nama = nama;
    newNode->golongan = golongan;

    // Set gaji pokok sesuai dengan golongan
    if (golongan == "3A")
        newNode->gajiPokok = 1750000;
    else if (golongan == "3B")
        newNode->gajiPokok = 2000000;
    else if (golongan == "3C")
        newNode->gajiPokok = 2500000;
    else if (golongan == "3D")
        newNode->gajiPokok = 3000000;

    // Jika punya istri, hitung tunjangan istri
    if (punyaIstri)
        newNode->tunjanganIstri = 200000;
    else
        newNode->tunjanganIstri = 0;

    // Jika punya istri, hitung tunjangan anak
    if (punyaIstri)
        newNode->tunjanganAnak = jumlahTanggunganAnak * 0.05 * newNode->gajiPokok;
    else
        newNode->tunjanganAnak = 0;

    // Set uang makan dan transport awal
    newNode->uangMakan = 30000;
    newNode->transport = 30000;

    // Set absensi
    newNode->absensi = absensi;

    // Hitung total gaji
    newNode->totalGaji = newNode->gajiPokok + newNode->tunjanganIstri + newNode->tunjanganAnak + newNode->uangMakan * newNode->absensi;

    newNode->prev = nullptr;
    
    // Jika belum ada data pada linked list
    if (head == nullptr) {
        head = tail = newNode;
        newNode->next = nullptr;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    cout << "Data berhasil ditambahkan di depan." << endl;
}

// Fungsi untuk menambah data pegawai di belakang double linked list
void tambahDataBelakang(int nip, string nama, string golongan, bool punyaIstri, int jumlahTanggunganAnak, int absensi) {
    Node* newNode = new Node;
    newNode->nip = nip;
    newNode->nama = nama;
    newNode->golongan = golongan;

    // Set gaji pokok sesuai dengan golongan
    if (golongan == "3A")
        newNode->gajiPokok = 1750000;
    else if (golongan == "3B")
        newNode->gajiPokok = 2000000;
    else if (golongan == "3C")
        newNode->gajiPokok = 2500000;
    else if (golongan == "3D")
        newNode->gajiPokok = 3000000;

    // Jika punya istri, hitung tunjangan istri
    if (punyaIstri)
        newNode->tunjanganIstri = 200000;
    else
        newNode->tunjanganIstri = 0;

    // Jika punya istri, hitung tunjangan anak
    if (punyaIstri)
        newNode->tunjanganAnak = jumlahTanggunganAnak * 0.05 * newNode->gajiPokok;
    else
        newNode->tunjanganAnak = 0;

    // Set uang makan dan transport awal
    newNode->uangMakan = 30000;
    newNode->transport = 30000;

    // Set absensi
    newNode->absensi = absensi;

    // Hitung total gaji
    newNode->totalGaji = newNode->gajiPokok + newNode->tunjanganIstri + newNode->tunjanganAnak + newNode->uangMakan * newNode->absensi;

    newNode->next = nullptr;
    
    // Jika belum ada data pada linked list
    if (head == nullptr) {
        head = tail = newNode;
        newNode->prev = nullptr;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Data berhasil ditambahkan di belakang." << endl;
}

// Fungsi untuk menghapus data pegawai dari depan double linked list
void hapusDataDepan() {
    if (head == nullptr) {
        cout << "Tidak ada data pegawai." << endl;
        return;
    }

    Node* temp = head;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    cout << "Data pegawai berhasil dihapus dari depan." << endl;
}

// Fungsi untuk menghapus data pegawai dari belakang double linked list
void hapusDataBelakang() {
    if (head == nullptr) {
        cout << "Tidak ada data pegawai." << endl;
        return;
    }

    Node* temp = tail;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    cout << "Data pegawai berhasil dihapus dari belakang." << endl;
}

// Fungsi untuk menghitung total gaji semua pegawai
double hitungTotalGaji() {
    double totalGaji = 0;
    Node* current = head;

    while (current != nullptr) {
        totalGaji += current->totalGaji;
        current = current->next;
    }

    return totalGaji;
}

// Fungsi untuk menampilkan data semua pegawai
void tampilkanSemuaData() {
    if (head == nullptr) {
        cout << "Tidak ada data pegawai." << endl;
        return;
    }

    cout << left << setw(12) << "NIP"
         << setw(20) << "Nama Pegawai"
         << setw(10) << "Golongan"
         << setw(15) << "Gaji Pokok"
         << setw(15) << "Tunj. Anak"
         << setw(15) << "Tunj. Istri"
         << setw(15) << "Uang Makan"
         << setw(15) << "Transport"
         << setw(15) << "Total Gaji" << endl;

    cout << setfill('-') << setw(130) << "-" << endl; // Garis pembatas atas

    Node* current = head;

    while (current != nullptr) {
        cout << setfill(' ') << left << setw(12) << current->nip
             << setw(20) << current->nama
             << setw(10) << current->golongan
             << setw(15) << fixed << setprecision(2) << current->gajiPokok
             << setw(15) << fixed << setprecision(2) << current->tunjanganAnak
             << setw(15) << fixed << setprecision(2) << current->tunjanganIstri
             << setw(15) << fixed << setprecision(2) << current->uangMakan
             << setw(15) << fixed << setprecision(2) << current->transport
             << setw(15) << fixed << setprecision(2) << current->totalGaji << endl;

        current = current->next;
    }

    cout << setfill('-') << setw(130) << "-" << endl; // Garis pembatas bawah
}

int main() {
    int pilihan;
    int nip;
    string nama, golongan;
    bool punyaIstri;
    int jumlahTanggunganAnak;
    int absensi;

    do {
        cout << "\nMenu:\n"
             << "1. Tambah Data Pegawai di Depan\n"
             << "2. Tambah Data Pegawai di Belakang\n"
             << "3. Hapus Data Pegawai dari Depan\n"
             << "4. Hapus Data Pegawai dari Belakang\n"
             << "5. Hitung Total Gaji Pegawai\n"
             << "6. Tampilkan Data Pegawai\n"
             << "7. Keluar\n"
             << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIP: ";
                cin >> nip;
                cout << "Masukkan Nama Pegawai: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Golongan (3A/3B/3C/3D): ";
                cin >> golongan;
                cout << "Apakah memiliki istri? (1=Ya, 0=Tidak): ";
                cin >> punyaIstri;
                if (punyaIstri) {
                    cout << "Masukkan jumlah tanggungan anak: ";
                    cin >> jumlahTanggunganAnak;
                }
                cout << "Masukkan jumlah absensi: ";
                cin >> absensi;
                tambahDataDepan(nip, nama, golongan, punyaIstri, jumlahTanggunganAnak, absensi);
                break;
            case 2:
                cout << "Masukkan NIP: ";
                cin >> nip;
                cout << "Masukkan Nama Pegawai: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Golongan (3A/3B/3C/3D): ";
                cin >> golongan;
                cout << "Apakah memiliki istri? (1=Ya, 0=Tidak): ";
                cin >> punyaIstri;
                if (punyaIstri) {
                    cout << "Masukkan jumlah tanggungan anak: ";
                    cin >> jumlahTanggunganAnak;
                }
                cout << "Masukkan jumlah absensi: ";
                cin >> absensi;
                tambahDataBelakang(nip, nama, golongan, punyaIstri, jumlahTanggunganAnak, absensi);
                break;
            case 3:
                hapusDataDepan();
                break;
            case 4:
                hapusDataBelakang();
                break;
            case 5:
                cout << "Total Gaji Pegawai: " << fixed << setprecision(2) << hitungTotalGaji() << endl;
                break;
            case 6:
                tampilkanSemuaData();
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 7);

    return 0;
}



