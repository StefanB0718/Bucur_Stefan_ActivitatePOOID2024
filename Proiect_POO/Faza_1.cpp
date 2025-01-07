#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

// domeniul baschet

class Minge {
public:
	const int idMinge;
	char* culoare;
	float pret;
	static int dimensiune;

	//constructor fara parametri
	Minge() : idMinge(1) {
		this->culoare = new char[strlen("albastru") + 1];
		strcpy(this->culoare, "albastru");
		this->pret = 4.99;
	}
	//constructor cu parametri
	Minge(const int idMinge, const char* culoare, float pret) :idMinge(idMinge) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
		this->pret = pret;
	}

	//supraincarcare operator <<
	friend ostream& operator <<(ostream& out, Minge& m) {
		out << "ID:" << m.idMinge << endl;
		out << "Culoare: " << m.culoare << endl;
		out << "Pret: " << m.pret << endl;
		out << "Dimensiune: " << Minge::dimensiune << endl;
		return out;
	}
	//destructor 
	~Minge() {
		delete[] this->culoare;
	}

};
int Minge::dimensiune = 5;

class Cos {
public:
	int pret;
	const int idCos;
	static int nrCos;
	char* producator;
	string culoare;

};

class Echipament {
public:
	const int idEchipament;
	static int nrEchipament;
	int pret;
	char* producator;
	string masura;
};

int main() {
	cout << "Constructor fara parametri" << endl;
	Minge m1;
	cout << "ID: "<< m1.idMinge << " culoare: " << m1.culoare << " pret = " << m1.pret << " dimensiunea: " << Minge::dimensiune << endl;
	cout << m1 << endl;

	cout << "Constructor cu parametri" << endl;
	Minge m2(1, "rosu", 10.99);
	cout << m2 << endl;

	
	
	return 0;
}