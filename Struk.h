#ifndef Struk_H
#define Struk_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

void gotost(int s, int t) {
    COORD coordinate;
    coordinate.X = s;
    coordinate.Y = t;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

struct NodeStruk
{
	string namaBarang;
	int totalHarga;
	int jumlahBarangTerjual;
	string namaKasir;
	NodeStruk *next;

	NodeStruk(string namaBarang, int totalHarga, int jumlahBarangTerjual, string namaKasir) : namaBarang(namaBarang), totalHarga(totalHarga), jumlahBarangTerjual(jumlahBarangTerjual), namaKasir(namaKasir), next(nullptr) {}
};

class Struk
{
public:
	NodeStruk *head;
	NodeStruk *currentStruk;

	Struk()
	{
		head = nullptr;
	}

	void AddStruk(string namaBarang, int totalHarga, int jumlahBarangTerjual, string namaKasir)
	{
		NodeStruk *newNode = new NodeStruk(namaBarang, totalHarga, jumlahBarangTerjual, namaKasir);
		if (!head)
		{
			head = newNode;
		}

		else
		{
			NodeStruk *current = head;
			while (current->next)
			{
			current = current->next;
			}
			current->next = newNode;
		}
		gotost(43,25);
		cout << "Struk Telah berhasil tersimpan" << endl;
	}

	void DisplaySemuaStruk()
	{
		if (!head)
		{
		for(int i=0; i<=119; i++) {
		gotost(i,0);
		cout<<"=";
		gotost(i,1);
		cout<<"=";
		gotost(i,28);
		cout<<"=";
		gotost(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotost(0,i);
		cout<<"=";
		gotost(1,i);
		cout<<"=";
		gotost(118,i);
		cout<<"=";
		gotost(119,i);
		cout<<"=";
	}
			gotost(45,14);
			cout << "Tidak ada Data Struk Tersimpan!" << endl;
			return;
		}
		else
		{
			NodeStruk *current = head;
			int nomor = 1;
			int positionT = 9 ;
			cout << endl;
			while (current) {
		
			for(int i=0; i<=119; i++) {
			gotost(i,0);
			cout<<"=";
			gotost(i,1);
			cout<<"=";
			gotost(i,5);
			cout<<"=";
			gotost(i,28);
			cout<<"=";
			gotost(i,29);
			cout<<"=";
			}

			for(int i=2; i<=27; i++) {
			gotost(0,i);
			cout<<"=";
			gotost(1,i);
			cout<<"=";
			gotost(118,i);
			cout<<"=";
			gotost(119,i);
			cout<<"=";
			}
			gotost(37,3);
			cout<<"H A S I L  P E N J U A L A N  H A R I  I N I";
			
			for(int i=17; i<=99; i++) {
			gotost(i,6);
			cout<<"-";
			gotost(i,8);
			cout<<"-";
			}
			for(int i=7; i<=25; i++) {
			gotost(17,i);
			cout<<"|";
			gotost(41,i);
			cout<<"|";
			gotost(56,i);
			cout<<"|";
			gotost(74,i);
			cout<<"|";
			gotost(99,i);
			cout<<"|";
		
			}
			gotost(41,8);
			cout<<"+";
			gotost(56,8);
			cout<<"+";
			gotost(74,8);
			cout<<"+";
			
			gotost(23,7);
			cout << "Nama Barang" ;
			gotost(46,7);
			cout << "Jumlah" ;
			gotost(63,7);
			cout << "Total" ;
			gotost(77,7);
			cout << "Kasir Yang Melayani " ;
			
			gotost(23,positionT);
			cout << current->namaBarang << endl;
			gotost(48,positionT);
			cout << current->jumlahBarangTerjual << endl;
			gotost(63,positionT);
			cout << current->totalHarga << endl;
			gotost(83,positionT);
			cout << current->namaKasir << endl;
			nomor++;
			positionT++;
			current = current->next;
			
			}
		}
	};
};

#endif
