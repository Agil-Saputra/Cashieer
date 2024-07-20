#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

#include "Karyawan.h"
#include "Barang.h"
#include "Struk.h"

using namespace std;
Karyawan karyawan;
Barang barang;
Struk struk;

void MENU_displayBarang();
void MENU_EditBarang();
void MENU_KelolaBarang();
void MENU_Manager();
void Checkout_Barang(string namaKaryawan);
void MENU_Karyawan(string namaKaryawan = "");

void gotoxy(int x, int y) {
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}



int main()
{
	system("Color 70");
	//Bingkai X menyamping
	for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,10);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,15);
		cout<<"=";
		gotoxy(i,22);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

	//Bingkai Y kebawah
	for(int i=0; i<=29; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
	for(int i=16; i<=21; i++) {
		gotoxy(59,i);
		cout<<"=";
		gotoxy(60,i);
		cout<<"=";
	}
	int choice;
	// Menu login ada disini..
	gotoxy(29,3);
   	cout<<"#######   #######   #######  ##   ##  ####  #######  ######\n";
   	Sleep(300);
   	gotoxy(29,4);
	cout<<"##       ##     ##  ##       ##   ##   ##   ##       ##   ##\n";
	Sleep(300);
	gotoxy(29,5); 
	cout<<"##       #########  #######  #######   ##   #######  #####\n";
	Sleep(300);
	gotoxy(29,6);
	cout<<"##       ##     ##       ##  ##   ##   ##   ##       ##  ##\n";
	Sleep(300);
	gotoxy(29,7);
    cout<<"#######  ##     ##  #######  ##   ##  ####  #######  ##   ##\n";
    Sleep(300);
    
    gotoxy(43,13);
    cout << "L";
    Sleep(200);
    gotoxy(45,13);
    cout << "O";
    Sleep(200);
    gotoxy(47,13);
    cout << "G";
    Sleep(200);
    gotoxy(49,13);
    cout << "I";
    Sleep(200);
    gotoxy(51,13);
    cout << "N";
    Sleep(200);
    gotoxy(54,13);
    cout << "S";
    Sleep(200);
    gotoxy(56,13);
    cout << "E";
    Sleep(200);
    gotoxy(58,13);
    cout << "B";
    Sleep(200);
    gotoxy(60,13);
    cout << "A";
    Sleep(200);
    gotoxy(62,13);
    cout << "G";
    Sleep(200); 
	gotoxy(64,13);
    cout << "A";
    Sleep(200);
	gotoxy(66,13);
    cout << "I";
    Sleep(200);
	gotoxy(68,13);
    cout << ":";
    Sleep(200); 
    
	gotoxy(25,17);
	cout << "MANAGER" << endl;
	gotoxy(27,19);
	cout << "[1]" << endl;
	gotoxy(84,17);
	cout << "KARYAWAN" << endl;
	gotoxy(87,19);
	cout << "[2]" << endl;
	gotoxy(57,25);
	cout << "[" << endl;
	gotoxy(63,25);
	cout << "]" << endl;
	gotoxy(60,25);
	cin >> choice;
	system("cls");

	if (choice == 1)
	{	
	input_manager_menu:
		//Bingkai X menyamping
	for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,6);
		cout<<"=";
		gotoxy(i,12);
		cout<<"=";
		gotoxy(i,13);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}
	 
	 		//Bingkai Y kebawah
	for(int i=0; i<=29; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
	
		string namaManager, passwordManager;
		gotoxy(40,3);
		cout<<"L O G I N  M A N A G E R  A C C O U N T";
		gotoxy(5,8);
		cout << "Masukkan Nama      : " ;
		cin >> namaManager;
		gotoxy(5,10);
		cout << "Masukkan Password  : " ;
		cin >> passwordManager;

		if (namaManager == "radinka" && passwordManager == "radinka")
		{
			gotoxy(37,15);
			cout<<"##        #####   #######  ####  ###     ##\n";
			gotoxy(37,16);
			cout<<"##       ##   ##  ##        ##   ## ##   ##\n";
			gotoxy(37,17);
			cout<<"##       ##   ##  ## ####   ##   ##  ##  ##\n";
			gotoxy(37,18);
			cout<<"##       ##   ##  ##   ##   ##   ##   ## ##\n";
			gotoxy(37,19);
			cout<<"#######   #####   #######  ####  ##     ###\n";
			
			gotoxy(22,21);
			cout<<"######   ######  ######   ##   ##   ######   #######  ####  ##         ##\n";
			gotoxy(22,22);
			cout<<"##   ##  ##      ##   ##  ##   ##  ##    ##  ##        ##   ##         ##\n";
			gotoxy(22,23);
			cout<<"######   ######  #####    #######  ########  #######   ##   ##         ##\n";
			gotoxy(22,24);
			cout<<"##   ##  ##      ##  ##   ##   ##  ##    ##       ##   ##   ##          \n";
			gotoxy(22,25);
			cout<<"######   ######  ##   ##  ##   ##  ##    ##  #######  ####  #######    ##\n";
            cin.ignore();
            gotoxy(45,27);
            system("pause");
            system("cls");
			MENU_Manager();
		}
		else
		{
			gotoxy(38,20);
			cout << "Maaf Nama & Password Yang Anda Masukkan Salah!" << endl;
			gotoxy(56,22);
			cout << "COBA LAGI !" << endl;
			gotoxy(45,27);
			system("pause");
			system("cls");
			goto input_manager_menu;
		}
	}
	else if (choice == 2)
	{
	input_karyawan_menu:
		//Bingkai X menyamping
	for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,6);
		cout<<"=";
		gotoxy(i,12);
		cout<<"=";
		gotoxy(i,13);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}
	 
	 		//Bingkai Y kebawah
	for(int i=0; i<=29; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
	
		gotoxy(37,3);
		cout<<"L O G I N  K A R Y A W A N  A C C O U N T";
		string namaKaryawan, passwordKaryawan;
		gotoxy(5,8);
		cout << "Masukkan Nama     : ";
		cin >> namaKaryawan;
		gotoxy(5,10);
		cout << "Masukkan Password : ";
		cin >> passwordKaryawan;

		Node *Karyawan = karyawan.GetkaryawanByUsername(namaKaryawan);

		if (karyawan.IsKaryawanUsernameExist(namaKaryawan) && karyawan.IsKaryawanPasswordTrue(passwordKaryawan))
		{
			gotoxy(35,15);
			cout<<"##        #####   ########  ####  ###     ##\n";
			gotoxy(35,16);
			cout<<"##       ##   ##  ##         ##   ## ##   ##\n";
			gotoxy(35,17);
			cout<<"##       ##   ##  ##  ####   ##   ##  ##  ##\n";
			gotoxy(35,18);
			cout<<"##       ##   ##  ##    ##   ##   ##   ## ##\n";
			gotoxy(35,19);
			cout<<"#######   #####   ########  ####  ##     ###\n";
			
			gotoxy(20,21);
			cout<<"######   #######  ######   ##   ##   #######   ########  ####  ##         ##\n";
			gotoxy(20,22);
			cout<<"##   ##  ##       ##   ##  ##   ##  ##     ##  ##         ##   ##         ##\n";
			gotoxy(20,23);
			cout<<"######   #######  #####    #######  #########  ########   ##   ##         ##\n";
			gotoxy(20,24);
			cout<<"##   ##  ##       ##  ##   ##   ##  ##     ##        ##   ##   ##          \n";
			gotoxy(20,25);
			cout<<"######   #######  ##   ##  ##   ##  ##     ##  ########  ####  #######    ##\n";
            cin.ignore();
            gotoxy(45,27);
            system("pause");
            system("cls");
			MENU_Karyawan(namaKaryawan);
		}
		else
		{
			gotoxy(40,20);
			cout << "Maaf Nama & Password Yang Kamu Masukkan Salah!" << endl;
			gotoxy(45,27);
			system("pause");
			system("cls");
			goto input_karyawan_menu;
		}
	}
}

void MENU_displayBarang()
{
	for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,13);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
			gotoxy(50,3);
			cout<<"D A T A  B A R A N G";
			string namaBarang;
			int pilihan;
			gotoxy(16,7);
			cout << "[ 1 ] Tampilkan data semua barang" << endl;
			gotoxy(65,7);
			cout << "[ 2 ] Tampilkan data barang tertentu" << endl;
			gotoxy(16,10);
			cout << "[ 3 ] Tampilkan data berdasarkan urutan" << endl;
			gotoxy(65,10);
			cout << "[ 4 ] Back" << endl;
			gotoxy(57,22);
			cout << "[" << endl;
			gotoxy(63,22);
			cout << "]" << endl;
			gotoxy(60,22);
			cin >> pilihan;	
			system("cls");

	switch (pilihan)
	{
	case 1:
	{	
			barang.DisplaySemuaBarang();
			gotoxy(45,27);
			system("pause");
			system("cls");
			break;
	}
	case 2:
	{
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
		gotoxy(20,3);
		cout<<"I N P U T  D A T A  B A R A N G  Y A N G  I N G I N  D I T A M P I L K A N";
		string namaBarangYangDicari;
		gotoxy(5,8);
		cout << " Nama barang yang ingin ditampilkan : ";
		cin.ignore();
		getline(cin, namaBarangYangDicari);

		if (barang.IsBarangNameExist(namaBarangYangDicari))
		{
			
		gotoxy(47,13);
		cout<<"DATA BARANG YANG DICARI";
			NodeBarang *barangTerpilih = barang.GetBarang(namaBarangYangDicari);
			gotoxy(34,18);
			cout << "{ Nama Barang }";
			gotoxy(36,20);
			cout << barangTerpilih->nama_barang << endl;
			gotoxy(55,18);
			cout << "{ Harga }";
			gotoxy(57,20);
			cout << barangTerpilih->harga << endl;
			gotoxy(72,18);
			cout << "{ Stok }" ;
			gotoxy(75,20);
			cout << barangTerpilih->stok << endl;
		}
		else
		{
			gotoxy(48,18);
			cout << "Barang Dengan Nama : " << namaBarangYangDicari;
			gotoxy(51,20);
			cout << " Tidak Ditemukan!";
		}
		gotoxy(45,27);
		system("pause");
		system("cls");
		break;
	}
	case 3:
	{
	for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
	
		int pilihanSorting;
		gotoxy(44,3);
		cout<<"U R U T A N  D A T A  B A R A N G";
		gotoxy(25,8);
		cout << "[ 1 ]  Nama Barang (A - Z)" << endl;
		gotoxy(72,8);
		cout << "[ 2 ]  Nama Barang (Z - A)" << endl;
		gotoxy(53,13);
		cout << "URUT BERDASARKAN" << endl;
		gotoxy(57,15);
		cout << "[" << endl;
		gotoxy(63,15);
		cout << "]" << endl;
		gotoxy(60,15);
		cin >> pilihanSorting;

		system("cls");
		barang.sortBarang(pilihanSorting);
		gotoxy(45,27);
		system("pause");
		system("cls");

		break;
	}
	case 4:
	{
		break;
	}

	default:
		break;
	}
}

void MENU_EditBarang()
{
	int pilihan, updatedharga, updatedStok;
	string updatedNamaBarang, namaBarangYangDicari;
	for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
		gotoxy(45,3);
		cout<<"E D I T  D A T A  B A R A N G";
		gotoxy(5,8);
		cout << "Masukkan Nama barang yang ingin diedit : ";
		cin.ignore();
		getline(cin, namaBarangYangDicari);

	if (barang.IsBarangNameExist(namaBarangYangDicari))
	{
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
		gotoxy(45,3);
		cout<<"E D I T  D A T A  B A R A N G";
		
		gotoxy(45,13);
		cout<<"DATA BARANG YANG INGIN DIEDIT";
		NodeBarang *barangTerpilih = barang.GetBarang(namaBarangYangDicari);
		gotoxy(30,18);
		cout << "[ 1 ] Nama Barang";
		gotoxy(33,20);
		cout << barangTerpilih->nama_barang << endl;
		gotoxy(55,18);
		cout << "[ 2 ] Harga";
		gotoxy(58,20);
		cout << barangTerpilih->harga << endl;
		gotoxy(76,18);
		cout << "[ 3 ] Stok";
		gotoxy(81,20);
		cout << barangTerpilih->stok << endl;
		gotoxy(57,23);
		cout << "[" << endl;
		gotoxy(63,23);
		cout << "]" << endl;
		gotoxy(60,23);
		cin >> pilihan;
		gotoxy(45,27);
		system("pause");
		system("cls");
		switch (pilihan)
		{
		case 1:
			
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
		gotoxy(45,3);
		cout<<"E D I T  N A M A  B A R A N G";
		gotoxy(5,8);
		cout << "Masukkan Nama Barang yang baru : ";
		cin >> updatedNamaBarang;
		barangTerpilih->nama_barang = updatedNamaBarang;
		gotoxy(47,20);
		cout << "Nama barang Berhasil diedit" << endl;
		gotoxy(47,27);
		system("pause");
		system("cls");
		break;
			
		case 2:
			for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
		gotoxy(44,3);
		cout<<"E D I T  H A R G A  B A R A N G";
		gotoxy(5,8);
		cout << "Masukkan Harga Barang Satuan yang baru : " ;
		cin >> updatedharga;
		barangTerpilih->harga = updatedharga;
		gotoxy(45,20);
		cout << "Harga Satuan Barang Berhasil diedit" << endl;
		gotoxy(47,27);
		system("pause");
		system("cls");
		break;
			
		case 3:
			for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
		gotoxy(43,3);
		cout<<"E D I T  J U M L A H  B A R A N G";
		gotoxy(5,8);
		cout << "Masukkan Jumlah Stok yang baru : " ;
		cin >> updatedStok;
		barangTerpilih->stok = updatedStok;
		gotoxy(45,20);
		cout << "Jumlah stok barang Berhasil diedit" << endl;
		gotoxy(47,27);
		system("pause");
		system("cls");
		break;
		default:
		break;
		}
	}
	else
	{
		gotoxy(50,18);
		cout << "Barang dengan nama " << namaBarangYangDicari;
		gotoxy(53,20);
		cout << "Tidak ditemukan." << endl;
		gotoxy(45,27);
		system("pause");
		system("cls");
		
	}
}

void MENU_KelolaBarang(){
	int subpilihan, harga, stok;
	string nama_barang;

kelola_menu:
	for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,10);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

	//Bingkai Y kebawah
	for(int i=0; i<=29; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
	
		for(int i=12; i<=28; i++) {
		gotoxy(59,i);
		cout<<"=";
		gotoxy(60,i);
		cout<<"=";
	}
	
	gotoxy(30,3);
    	cout<<"######    ######   ######    ######   ###     ##  ####### \n";
    	gotoxy(30,4); 
		cout<<"##   ##  ##    ##  ##   ##  ##    ##  ## ##   ##  ##      \n";
		gotoxy(30,5); 
		cout<<"######   ########  #####    ########  ##  ##  ##  ## #### \n";
		gotoxy(30,6);
		cout<<"##   ##  ##    ##  ##  ##   ##    ##  ##   ## ##  ##   ## \n";
		gotoxy(30,7);
    	cout<<"######   ##    ##  ##   ##  ##    ##  ##     ###  ####### \n";
		gotoxy(24,13);
    	cout << "[ M E N U ]";
		gotoxy(5,16);
		cout << "[ 1 ]       Tambah Barang" << endl;
		gotoxy(5,18);
		cout << "[ 2 ]       Tampilkan Semua Barang" << endl;
		gotoxy(5,20);
		cout << "[ 3 ]       Hapus Barang" << endl;
		gotoxy(5,22);
		cout << "[ 4 ]       Cari Dan Edit Barang" << endl;
		gotoxy(5,24);
		cout << "[ 5 ]       Back" << endl;
		gotoxy(65,20);
		cout << "Masukkan Pilihan :  [ ";
		gotoxy(88,20);
		cout << " ]";
		gotoxy(87,20);
		cin >> subpilihan;
		system("cls");

	do
	{
		switch (subpilihan)
		{
		case 1:
		{
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,13);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
			gotoxy(49,3);
			cout<<"I N P U T  B A R A N G";
			string namaBarang;
			cin.ignore();
			gotoxy(5,7);
			cout << "Masukkan Nama barang : ";
			getline(cin, namaBarang);
			gotoxy(5,9);
			cout << "Masukkan Harga       : ";
			cin >> harga;
			gotoxy(5,11);
			cout << "Masukkan Stok        : ";
			cin >> stok;
			if (barang.IsBarangNameExist(namaBarang))
			{
				gotoxy(51,18);
				cout << "Barang Sudah ada";
				gotoxy(49,20);
				cout << "Tambahkan Barang lain!";
				gotoxy(45,27);
				system("pause");
				system("cls");
			}
			else
			{
				gotoxy(44,20);
				barang.AddBarang(namaBarang, harga, stok);
				gotoxy(45,27);
				system("pause");
				system("cls");
				
			}
			goto kelola_menu;
			break;
		}
		case 2:
		{
			MENU_displayBarang();
			goto kelola_menu;
			break;
		}
		case 3:
		{
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
			gotoxy(44,3);
			cout<<"H A P U S  D A T A  B A R A N G";
			gotoxy(5,8);
			cout << "Nama Barang yang ingin di hapus : " ;
			cin.ignore();
			getline(cin, nama_barang);
			barang.deleteBarang(nama_barang);
			gotoxy(45,27);
			system("pause"); // jika di windows ganti ke system("pause")
			system("cls");
			goto kelola_menu;
			break;
		}
		case 4:
		{
			MENU_EditBarang();
			goto kelola_menu;
			break;
		}
		case 5:
		{
			MENU_Manager();
			break;
		}
		break;
		}
	} while (subpilihan != 0);
}

// Semua Fungsi manager disini
void MENU_Manager()
{
	int choice;
	do
	{
		system("cls");
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,10);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

	//Bingkai Y kebawah
	for(int i=0; i<=29; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
	
		for(int i=12; i<=28; i++) {
		gotoxy(59,i);
		cout<<"=";
		gotoxy(60,i);
		cout<<"=";
	}
	
	gotoxy(22,3);
    	cout<<" #####  #####    ######   ###     ##   ######   #######  #######  ###### \n";
    	gotoxy(22,4); 
		cout<<" ##   ##   ##   ##    ##  ## ##   ##  ##    ##  ##       ##       ##   ##\n";
		gotoxy(22,5); 
		cout<<" ##   ##   ##   ########  ##  ##  ##  ########  ## ####  #######  #####  \n";
		gotoxy(22,6);
		cout<<" ##   ##   ##   ##    ##  ##   ## ##  ##    ##  ##   ##  ##       ##  ## \n";
		gotoxy(22,7);
    	cout<<"###   ##   ###  ##    ##  ##     ###  ##    ##  #######  #######  ##   ##\n";
	
    	gotoxy(24,13);
    	cout << "[ M E N U ]";
    	gotoxy(5,16);
		cout << "[ 1 ]       Tampilkan Semua Data Karyawan" << endl;
		gotoxy(5,18);
		cout << "[ 2 ]       Tambah Karyawan" << endl;
		gotoxy(5,20);
		cout << "[ 3 ]       Pecat Karyawan" << endl;
		gotoxy(5,22);
		cout << "[ 4 ]       Kelola Stock Barang" << endl;
		gotoxy(5,24);
		cout << "[ 5 ]       Lihat Penjualan Barang Hari ini" << endl;
		gotoxy(5,26);
		cout << "[ 6 ]       Logout" << endl;
		gotoxy(65,20);
		cout << "Masukkan Pilihan :  [ ";
		gotoxy(88,20);
		cout << " ]";
		gotoxy(87,20);
		cin >> choice;
		system("cls");
	
		switch (choice)
		{
		case 1:
		{	
//		gotoxy(47,8);	
		karyawan.DisplaySemuaKaryawan();
		gotoxy(45,27);
		system("pause"); // jika di windows ganti ke system("pause")
		break;
		}
		case 2:
		{
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
			gotoxy(37,3);
			cout<<"I N P U T  K A R Y A W A N  A C C O U N T";
			string username, password;
			gotoxy(5,7);
			cout << "Username : ";
			cin >> username;
			gotoxy(5,9);
			cout << "Password : ";
			cin >> password;
			if (karyawan.IsKaryawanUsernameExist(username))
			{
				gotoxy(43,18);
				cout << "Username Karyawan Telah Digunakan!" << endl;
				gotoxy(49,20);
				cout << "Gunakan username lain!";
				gotoxy(45,27);
				system("pause"); // jika di windows ganti ke system("pause")
				break;
			}
			else
			{
				karyawan.AddKaryawan(username, password);
				gotoxy(43,20);
				cout << "Data Karyawan Berhasil Ditambahkan!" << endl;
				gotoxy(45,27);
				system("pause"); // jika di windows ganti ke system("pause")
				break;
			}
			break;
		}
		case 3:
		{
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,5);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,28);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(1,i);
		cout<<"=";
		gotoxy(118,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
			gotoxy(48,3);
			cout<<"P E C A T  K A R Y A W A N";
			string username;
			gotoxy(5,8);
			cout << "Username : ";
			cin >> username;
			gotoxy(45,27);
			karyawan.deleteKaryawan(username);
			gotoxy(45,27);
			system("pause"); // jika di windows ganti ke system("pause")
			break;
		}
		case 4:
		{
			system("cls");
			MENU_KelolaBarang();
			break;
		}
		case 5:
		{
			system("cls");
			struk.DisplaySemuaStruk();
			gotoxy(45,27);
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			main();
			break;
		}
		}
	} while (choice != 0);
}

void Checkout_Barang(string namaKaryawan)
{
	string namaBarang;
	int harga, jumlahBarang, jumlahBayar;
	int totalBelanja = 0;
	string confirmation = "y";

		while (confirmation == "y")
		{
		Checkout_menu:
			for(int i=0; i<=119; i++) {
			gotoxy(i,0);
			cout<<"=";
			gotoxy(i,1);
			cout<<"=";
			gotoxy(i,5);
			cout<<"=";
			gotoxy(i,9);
			cout<<"=";
			gotoxy(i,28);
			cout<<"=";
			gotoxy(i,29);
			cout<<"=";
			}

			for(int i=2; i<=27; i++) {
			gotoxy(0,i);
			cout<<"=";
			gotoxy(1,i);
			cout<<"=";
			gotoxy(118,i);
			cout<<"=";
			gotoxy(119,i);
			cout<<"=";
			}
			gotoxy(44,3);
			cout<<"C H E C K O U T  B A R A N G";
			gotoxy(5,7);
			cout << "Masukkan Nama Barang :  " ; 
			cin.ignore();
			getline(cin, namaBarang);
			
		
			if (barang.IsBarangNameExist(namaBarang))
			{
				NodeBarang *barangTerpilih = barang.GetBarang(namaBarang);
				gotoxy(5,11);
				cout << "Masukkan Jumlah Barang yang dibeli :  ";
				cin >> jumlahBarang;
				if (jumlahBarang > barangTerpilih->stok)
				{
					system("cls");
					for(int i=0; i<=119; i++) {
				gotoxy(i,0);
				cout<<"=";
				gotoxy(i,1);
				cout<<"=";
				gotoxy(i,28);
				cout<<"=";
				gotoxy(i,29);
				cout<<"=";
				}
		
				for(int i=2; i<=27; i++) {
				gotoxy(0,i);
				cout<<"=";
				gotoxy(1,i);
				cout<<"=";
				gotoxy(118,i);
				cout<<"=";
				gotoxy(119,i);
				cout<<"=";
				}
				gotoxy(49,14);
					cout << "Stock tidak cukup" << endl;
					gotoxy(48,15);
					cout << "Stock sisa adalah : " << barangTerpilih->stok << endl;
					gotoxy(45,27);
					system("pause");
					system("cls");
					goto Checkout_menu;
				}
				
				gotoxy(5,12);
				cout << "Harga Satuan                       : " << barangTerpilih->harga;
				gotoxy(5,13);
				cout << "Harga Total                        : " << barangTerpilih->harga * jumlahBarang;
				barangTerpilih->stok -= jumlahBarang;
				totalBelanja += barangTerpilih->harga * jumlahBarang;
				struk.AddStruk(namaBarang, barangTerpilih->harga * jumlahBarang, jumlahBarang, namaKaryawan);
				gotoxy(5,15);
				cout << "Apakah Anda Ingin Menambahkan Barang Lagi? y/n";
				gotoxy(61,15);
				cout << "[";
				gotoxy(65,15);
				cout << "]";
				gotoxy(63,15);
				cin >> confirmation;
				system("cls");
			}
			else
			{
				gotoxy(29, 15);	
				cout << "Maaf Barang Yang anda masukkan tidak ada, Masukkan Barang yang lain";
				gotoxy(33, 17);	
				cout << "Apakah Anda Ingin Tetap Menambahkan Barang Lagi? y/n";
				gotoxy(57,23);
				cout << "[" << endl;
				gotoxy(63,23);
				cout << "]" << endl;
				gotoxy(60,23);
				cin >> confirmation;
				system("cls");
			}
		}
			
			Total_bayar:
			for(int i=0; i<=119; i++) {
			gotoxy(i,0);
			cout<<"=";
			gotoxy(i,1);
			cout<<"=";
			gotoxy(i,5);
			cout<<"=";
			gotoxy(i,9);
			cout<<"=";
			gotoxy(i,15);
			cout<<"=";
			gotoxy(i,28);
			cout<<"=";
			gotoxy(i,29);
			cout<<"=";
			}
	
			for(int i=2; i<=27; i++) {
			gotoxy(0,i);
			cout<<"=";
			gotoxy(1,i);
			cout<<"=";
			gotoxy(118,i);
			cout<<"=";
			gotoxy(119,i);
			cout<<"=";
			}
			
			for(int i=5; i<=15; i++){
			gotoxy(58,i);
			cout<<"=";
			}
			
			gotoxy(44,3);
			cout<<"T O T A L  B E L A N J A";
			gotoxy(5,7);
			cout << "Total Harga "; 
			gotoxy(59,7);
			cout << " Rp." << totalBelanja ;
			gotoxy(5,11);
			cout << "Jumlah Bayar" ;
			gotoxy(59,11);
			cout <<" Rp.";
			gotoxy(63,11);
			cin >> jumlahBayar;
		
	
				while (jumlahBayar - totalBelanja < 0)
				{
				system("cls");
				for(int i=0; i<=119; i++) {
				gotoxy(i,0);
				cout<<"=";
				gotoxy(i,1);
				cout<<"=";
				gotoxy(i,7);
				cout<<"=";
				gotoxy(i,28);
				cout<<"=";
				gotoxy(i,29);
				cout<<"=";
				}
		
				for(int i=2; i<=27; i++) {
				gotoxy(0,i);
				cout<<"=";
				gotoxy(1,i);
				cout<<"=";
				gotoxy(118,i);
				cout<<"=";
				gotoxy(119,i);
				cout<<"=";
				}
				
				gotoxy(31, 4);	
				cout << "Maaf, uang anda kurang. Mohon lakukan ulang pembayaran" << endl;
				gotoxy(5,11);
				cout << "Jumlah Bayar";
				gotoxy(59,11);
				cout <<" Rp.";
				gotoxy(63,11);
				cin >> jumlahBayar;
				
				}

			gotoxy(5,13);
			cout << "Kembalian"; 
			gotoxy(59,13);
			cout <<" Rp." << jumlahBayar - totalBelanja << endl;
			gotoxy(40,24);
			cout << "Terima Kasih Telah Berbelanja Di Toko Kami" << endl;
		
			gotoxy(45,27);
			system("pause");
			system("cls");
			MENU_Karyawan();
}

void MENU_Karyawan(string namaKaryawan)
{
	int choice;
	main_menu:
		for(int i=0; i<=119; i++) {
		gotoxy(i,0);
		cout<<"=";
		gotoxy(i,10);
		cout<<"=";
		gotoxy(i,11);
		cout<<"=";
		gotoxy(i,29);
		cout<<"=";
	}

	//Bingkai Y kebawah
	for(int i=0; i<=29; i++) {
		gotoxy(0,i);
		cout<<"=";
		gotoxy(119,i);
		cout<<"=";
	}
	
		for(int i=12; i<=28; i++) {
		gotoxy(59,i);
		cout<<"=";
		gotoxy(60,i);
		cout<<"=";
	}
		gotoxy(15,3);
    	cout<<"##     ##   ######   ######   ##    ##   ######    ###    ##    ###   ######    ###     ##\n";
    	gotoxy(15,4); 
		cout<<"##   ##    ##    ##  ##   ##   ##  ##   ##    ##     ##   ##   ##    ##    ##   ## ##   ##\n";
		gotoxy(15,5); 
		cout<<"## ##      ########  #####       ##     ########     ##   ##   ##    ########   ##  ##  ##\n";
		gotoxy(15,6);
		cout<<"##   ##    ##    ##  ##  ##      ##     ##    ##     ##  ####  ##    ##    ##   ##   ## ##\n";
		gotoxy(15,7);
    	cout<<"##     ##  ##    ##  ##   ##     ##     ##    ##     #####  #####    ##    ##   ##     ###\n";
    	
    	gotoxy(24,13);
    	cout << "[ M E N U ]";
    	gotoxy(5,17);
		cout << "[ 1 ]       Checkout" << endl;
		gotoxy(5,20);
		cout << "[ 2 ]       Tampilkan Barang" << endl;
		gotoxy(5,23);
		cout << "[ 3 ]       Logout" << endl;
		gotoxy(65,20);
		cout << "Masukkan Pilihan :  [ ";
		gotoxy(88,20);
		cout << " ]";
		gotoxy(87,20);
		cin >> choice;

	switch (choice)
	{
	case 1:
		system("cls");
		Checkout_Barang(namaKaryawan);
		break;
	case 2:
		system("cls");
		MENU_displayBarang();
		goto main_menu;
		break;
	case 3:
		system("cls");
		main();
		break;

	default:
		break;
	}
}
