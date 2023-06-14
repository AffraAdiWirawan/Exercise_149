#include <iostream>

using namespace std;

class bidangDatar {
private:
	int x; // variabel untuk menyimpan input dari lingkaran maupun bujungsangkar
public:
	bidangDatar() {
		x = 0;
	}

	virtual void input() {} // untuk menerima input dan mengirim input melalui fungsi setX
	virtual float luas(int a) { // untuk menghitung luas
		return 0;
	}
	virtual float keliling(int a) { // untuk menghitung keliling
		return 0;
	}
	void setX(int a) { // untuk mengirim nilai pada x a
		this->x = a;
	}
	int getX() { // untuk memngambil nilai dalam x
		return x;
	}
};

class Lingkaran :public bidangDatar {
public:
	void input() {
		cout << "Lingkaran dibuat" << endl;
		cout << "Masukkan jejari: ";
		int jejari;
		cin >> jejari;
		setX(jejari); // butuh enkapsulasi untuk mengatur nilai input
	}
	float luas(int a) {
		return 3.14 * a * a; // enkapsulasi
	}
	float keliling(int a) {
		return 2 * 3.14 * a;
	}
};

class Bujungsangkar :public  bidangDatar {
public:
	void input() {
		cout << " BujungSangkar dibuat " << endl;
		cout << " Masukkan Sisi  : ";
		int sisi;
		cin >> sisi;
		setX(sisi);
	}
	float luas(int a) {
		return a * a;
	}
	float  keliling(int a) {
		return 4 * a;
	}
};

int main() {

	// metode polimorpi
	bidangDatar* obyek;
	Lingkaran a;
	Bujungsangkar b;;

	// lingkaran
	obyek = &a;
	obyek->input();
	cout << "Luas Lingkaran = " << obyek->luas(obyek->getX()) << endl;
	cout << "Keliling Lingkaran = " << obyek->keliling(obyek->getX());
	cout << "\n " << endl;

	obyek = &b;
	obyek->input();
	cout << " Luas BujungSangkar = " << obyek->luas(obyek->getX()) << endl;
	cout << " Keliling Bujung Sangkar = " << obyek->keliling(obyek->getX()) << endl;
	delete obyek;

	return 0;
}