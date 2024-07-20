#ifndef Karyawan_H
#define Karyawan_H

#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

void gotorc(int r, int c) {
    COORD coordinate;
    coordinate.X = r;
    coordinate.Y = c;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void setcolor(unsigned short color) {
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,color);
}

struct Node
{
	string username;
	string password;
	Node *next;

	Node(string username, string password) : username(username), password(password), next(nullptr) {}

	string GetUsername() const
	{
		return username;
	}
};

class Karyawan
{
public:
	Node *head;
	Node *currentPlayer;

	Karyawan()
	{
		head = nullptr;
	}

	void AddKaryawan(string username, string password)
	{

		Node *newNode = new Node(username, password);

		if (!head)
		{
			head = newNode;
		}

		else
		{
			Node *current = head;
			while (current->next)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}

	bool deleteKaryawan(const string &username)
	{ 
		// Membuat Pointer berada pada current yang dimana current merupakan head
		Node *current = head;
		// Membuat Pointer prev berada pada kondisi Kosong
		Node *prev = nullptr;

		while (current && current->username != username)
		{
			// Memperbarui Prev agar selalu sama dengan curret -> untuk penghapusands
			prev = current;
			current = current->next;
		}

		// kondisi jika tidak menemukan player maka false
		if (!current)
		{
			gotorc(44,20);
			cout << "Karyawan dengan Nama : " << username ;
			gotorc(51,22);
			cout << " Tidak Ditemukan!" << endl;
			return false;
		}

		// Kondisi Penghapusan Node berdasarkan Posisinya
		if (!prev)
		{
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
		gotorc(44,20);
		cout << "Karyawan dengan Nama : " << username;
		gotorc(51,22);
		cout << " Berhasil Dipecat!" << endl;
		return true;
	}

	void HapusSemuaKaryawan()
	{
		Node *current = head;
		Node *prev = nullptr;

		while (current)
		{
			prev = current;
			current = current->next;
			delete prev;
		}

		head = nullptr;
	}

	bool IsKaryawanUsernameExist(string username)
	{
		Node *current = head;
		while (current)
		{
			if (current->username == username)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}

	bool IsKaryawanPasswordTrue(string password)
	{
		Node *current = head;
		while (current)
		{
			if (current->password == password)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void DisplaySemuaKaryawan()
	{
		if (!head)
		{
		for(int i=0; i<=119; i++) {
		gotorc(i,0);
		cout<<"=";
		gotorc(i,1);
		cout<<"=";
		gotorc(i,28);
		cout<<"=";
		gotorc(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotorc(0,i);
		cout<<"=";
		gotorc(1,i);
		cout<<"=";
		gotorc(118,i);
		cout<<"=";
		gotorc(119,i);
		cout<<"=";
	}
			gotorc(47,8);
			cout << "Tidak ada data Karyawan!" << endl;
			return;
		}

		Node *current = head;
		int nomor = 1;
		int positionC = 9;
		while (current)
		{	
		
			for(int i=0; i<=119; i++) {
		gotorc(i,0);
		cout<<"=";
		gotorc(i,1);
		cout<<"=";
		gotorc(i,28);
		cout<<"=";
		gotorc(i,29);
		cout<<"=";
	}

		for(int i=2; i<=27; i++) {
		gotorc(0,i);
		cout<<"=";
		gotorc(1,i);
		cout<<"=";
		gotorc(118,i);
		cout<<"=";
		gotorc(119,i);
		cout<<"=";
	}
			for(int i=0; i<=119; i++) {
			gotorc(i,5);
			cout<<"=";
		}
		for(int i=33; i<=88; i++) {
			gotorc(i,6);
			cout<<"-";
			gotorc(i,8);
			cout<<"-";
		}
		for(int i=7; i<=25; i++) {
			gotorc(33,i);
			cout<<"|";
			gotorc(88,i);
			cout<<"|";
			gotorc(40,i);
			cout<<"|";
			gotorc(65,i);
			cout<<"|";
		}
			gotorc(40,8);
			cout<<"+";
			gotorc(65,8);
			cout<<"+";
			
			gotorc(49,3);
			cout << "D A T A  K A R Y A W A N";
			gotorc(35,7);
			cout << "No.";
			gotorc(36,positionC);
			cout << nomor;
			gotorc(49,7);
			cout << "Username";
			gotorc(49, positionC);
			cout << current->username; 
			gotorc(73,7);
			cout << "Password" ;
			gotorc(73,positionC);
			cout << current->password << endl;
			nomor++;
			positionC++;
			current = current->next;
		}
	}

	Node *GetkaryawanByUsername(string username)
  {
    // Memposisikan current berada pada head
    Node *current = head;
    while (current)
    {
      // Jika menemukan username yang sama maka akan mengembalikan nilai dalam curret
      if (current->username == username)
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
