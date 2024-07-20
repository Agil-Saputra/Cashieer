#ifndef Barang_H
#define Barang_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <windows.h>


using namespace std;

void gotobk(int b, int k) {
    COORD coordinate;
    coordinate.X = b;
    coordinate.Y = k;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}


struct NodeBarang
{
	string nama_barang;
	int harga;
	int stok;
	NodeBarang *next;

	NodeBarang(string nama_barang, int harga, int stok) : nama_barang(nama_barang), harga(harga), stok(stok), next(nullptr) {}
};

class Barang
{
public:
	NodeBarang *head;
	NodeBarang *currentPlayer;
	vector<NodeBarang> arrBarang;

	Barang()
	{
		head = nullptr;
	}

	template <typename T>
	void printElement(T t, const int &width)
	{
		const char separator = ' ';
		cout << left << setw(width) << setfill(separator) << t;
	}
	
	struct CompareNodeBarangDescending {
    bool operator()(const NodeBarang &a, const NodeBarang &b) const {
        return a.nama_barang > b.nama_barang; 
    }
	};

	struct CompareNodeBarangAscending {
    bool operator()(const NodeBarang &a, const NodeBarang &b) const {
        return a.nama_barang < b.nama_barang; 
    }
	};


	void sortBarang(int pilihan)
	{
		NodeBarang *current = head;
		arrBarang.clear();
		int positionK = 9;
		int width = 18;

		while (current)
		{
			// untuk mendorong data masuk kedalam vector kembali
			arrBarang.push_back(*current);
			current = current->next;
		}
		// fungsi sort merupakan fungsi bawaan dari vector.
		// melakukan perbandingan antara barang.namaBarang - barang.namaBarang dimana jika kondisi memenuhi dia akan mengeluarkan true yang
		// jika false maka akan tukar
		if (pilihan == 1) {
			
	    for(int i=0; i<=119; i++) {
		gotobk(i,0);
		cout<<"=";
		gotobk(i,1);
		cout<<"=";
		gotobk(i,5);
		cout<<"=";
		gotobk(i,28);
		cout<<"=";
		gotobk(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotobk(0,i);
		cout<<"=";
		gotobk(1,i);
		cout<<"=";
		gotobk(118,i);
		cout<<"=";
		gotobk(119,i);
		cout<<"=";
	}	
			
		for(int i=25; i<=96; i++) {
			gotobk(i,6);
			cout<<"-";
			gotobk(i,8);
			cout<<"-";
		}
		for(int i=7; i<=25; i++) {
			gotobk(25,i);
			cout<<"|";
			gotobk(96,i);
			cout<<"|";
		
		}
			gotobk(49,8);
			cout<<"+";
			gotobk(68,8);
			cout<<"+";
		
			
			
			gotobk(41,3);
			cout<<"U R U T A N  D A T A  B A R A N G  {A - Z}";
			sort(arrBarang.begin(), arrBarang.end(), CompareNodeBarangAscending());
		} else {
			
		for(int i=0; i<=119; i++) {
		gotobk(i,0);
		cout<<"=";
		gotobk(i,1);
		cout<<"=";
		gotobk(i,5);
		cout<<"=";
		gotobk(i,28);
		cout<<"=";
		gotobk(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotobk(0,i);
		cout<<"=";
		gotobk(1,i);
		cout<<"=";
		gotobk(118,i);
		cout<<"=";
		gotobk(119,i);
		cout<<"=";
	}	
			
		for(int i=25; i<=96; i++) {
			gotobk(i,6);
			cout<<"-";
			gotobk(i,8);
			cout<<"-";
		}
		for(int i=7; i<=25; i++) {
			gotobk(25,i);
			cout<<"|";
			gotobk(96,i);
			cout<<"|";
		
		}
			gotobk(49,8);
			cout<<"+";
			gotobk(68,8);
			cout<<"+";
		
			
			
			gotobk(41,3);
			cout<<"U R U T A N  D A T A  B A R A N G  {Z - A}";
			sort(arrBarang.begin(), arrBarang.end(), CompareNodeBarangDescending());
		}
		gotobk(31,7);
		printElement("Nama Barang", width);
		gotobk(55,7);
		printElement("Harga", width);
		gotobk(77,7);
		printElement("Stok", width);
		cout << endl;
		
		gotobk(31,positionK);
		for (int i = 0; i < arrBarang.size(); i++)
		{
		gotobk(31,positionK);
		printElement(arrBarang[i].nama_barang, width);
		gotobk(55,positionK);
		printElement(arrBarang[i].harga, width);
		gotobk(78,positionK);
		printElement(arrBarang[i].stok, width);
		cout << endl;
		positionK++;
		}
	
	}

	void AddBarang(string nama_barang, int harga, int stok)
	{
		NodeBarang *newNode = new NodeBarang(nama_barang, harga, stok);
		if (!head)
		{
			head = newNode;
		}

		else
		{
			NodeBarang *current = head;
			while (current->next)
			{
				current = current->next;
			}
			current->next = newNode;
		}
		gotobk(44,20);
		cout << nama_barang + " Telah berhasil ditambahkan" << endl;
	}

	bool deleteBarang(const string namaBarang)
	{ 
		// Membuat Pointer berada pada current yang dimana current merupakan head
		NodeBarang *current = head;
		// Membuat Pointer prev berada pada kondisi Kosong
		NodeBarang *prev = nullptr;

		while (current && current->nama_barang != namaBarang)
		{
			// Memperbarui Prev agar selalu sama dengan curret -> untuk penghapusands
			prev = current;
			current = current->next;
		}

		// kondisi jika tidak menemukan player maka false
		if (!current)
		{
			gotobk(46,20);
			cout << "Barang dengan Nama : " << namaBarang;
			gotobk(50,22);
			cout << "Tidak ditemukan!" << endl;
			return false;
		}

		// Kondisi Penghapusan Node berdasarkan Posisinya
		if (!prev)
		{
			// Kondisi jika pemain yang dihapus berada di head maka head->next
			head = current->next;
		}
		else
		{
			// Memperbarui pointer next dari node sebelumnya (prev) untuk melewatkan node yang akan dihapus dan menunjuk langsung ke node setelahnya
			prev->next = current->next;
		}

		// Melakukan Pengahapusan Curret
		delete current;
		current = nullptr;
		gotobk(50,20);
		cout << "Data barang "<< namaBarang;
		gotobk(50,22);
		cout << "Berhasil Dihapus!" << endl;
		return true;
	}

	void HapusSemuaBarang()
	{
		NodeBarang *current = head;
		NodeBarang *prev = nullptr;

		while (current)
		{
			prev = current;
			current = current->next;
			delete prev;
		}

		head = nullptr;
	}

	bool IsBarangNameExist(string namaBarang)
	{
		NodeBarang *current = head;
		while (current)
		{
			if (current->nama_barang == namaBarang)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void DisplaySemuaBarang()
	{
		const int nameWidth = 20;
		const int numWidth = 15;
		if (!head)
		{
		for(int i=0; i<=119; i++) {
		gotobk(i,0);
		cout<<"=";
		gotobk(i,1);
		cout<<"=";
		gotobk(i,28);
		cout<<"=";
		gotobk(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotobk(0,i);
		cout<<"=";
		gotobk(1,i);
		cout<<"=";
		gotobk(118,i);
		cout<<"=";
		gotobk(119,i);
		cout<<"=";
	}
			gotobk(47,8);
			cout << "Tidak ada data Barang!" << endl;
			gotobk(45,27);
			return;
		}
		else
		{
		NodeBarang *current = head;
		int nomor = 1;
		int positionK = 9;
		for(int i=0; i<=119; i++) {
		gotobk(i,0);
		cout<<"=";
		gotobk(i,1);
		cout<<"=";
		gotobk(i,5);
		cout<<"=";
		gotobk(i,28);
		cout<<"=";
		gotobk(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotobk(0,i);
		cout<<"=";
		gotobk(1,i);
		cout<<"=";
		gotobk(118,i);
		cout<<"=";
		gotobk(119,i);
		cout<<"=";
	}	
			
		for(int i=25; i<=96; i++) {
			gotobk(i,6);
			cout<<"-";
			gotobk(i,8);
			cout<<"-";
		}
		for(int i=7; i<=25; i++) {
			gotobk(25,i);
			cout<<"|";
			gotobk(96,i);
			cout<<"|";
		
		}
			gotobk(49,8);
			cout<<"+";
			gotobk(68,8);
			cout<<"+";
			gotobk(49,7);
			cout<<"|";
			
			gotobk(46,3);
			cout<<"D A T A  S E M U A  B A R A N G";
		    gotobk(31,7);
			printElement("Nama Barang", nameWidth);
			gotobk(55,7);
			printElement("Harga", nameWidth);
			gotobk(79,7);
			printElement("Stok", numWidth);
			cout << endl;

			cout << endl;
			while (current)
			{
				gotobk(31,positionK);
				printElement(current->nama_barang, nameWidth);
				gotobk(55,positionK);
				printElement(current->harga, nameWidth);
				gotobk(80,positionK);
				printElement(current->stok, numWidth);
				cout << endl;
				nomor++;
				positionK++;
				current = current->next;
			}
		}
	}

	NodeBarang *GetBarang(string namaBarang)
	{
		// Memposisikan current berada pada head
		NodeBarang *current = head;
		while (current)
		{
			// Jika menemukan username yang sama maka akan mengembalikan nilai dalam curret
			if (current->nama_barang == namaBarang)
			{
				return current;
			}
			current = current->next;
		}
		// Kondisi jika tidak terdapt data yang sama
		return nullptr;
	}

private:
};

#endif
