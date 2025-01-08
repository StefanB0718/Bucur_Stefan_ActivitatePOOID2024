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
	//constructor de copiere =
	Minge(const Minge& m) :idMinge(m.idMinge) {
		this->culoare = new char[strlen(m.culoare) + 1];
		strcpy(this->culoare, m.culoare);
		this->pret = m.pret;
	}
	//supraincarcare operator =
	Minge& operator=(const Minge& m) {
		if (this != &m) {
			delete[] this->culoare;
			this->culoare = new char[strlen(m.culoare) + 1];
			strcpy(this->culoare, m.culoare);
			this->pret = m.pret;
		}
		return *this;
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
	static int dimensiune;
	char* producator;
	string culoare;

	//constructor fara parametri
	Cos() :idCos(1) {
		this->pret = 8;
		this->producator = new char[strlen("NBA") + 1];
		strcpy(this->producator, "NBA");
		this->culoare = "Rosu si alb";
	}
	//supraincarcare operator <<
	friend ostream& operator<< (ostream& out, Cos& c) {
		out << "Pret: " << c.pret << endl;
		out << "Producator: " << c.producator << endl;
		out << "Culoarea: " << c.culoare << endl;
		out << "Dimensiune: " << Cos::dimensiune << endl;
		return out;
	}
	//cosntrucot cu parametri
	Cos(const int idCos, int pret, const char* producator, string culoare) :idCos(idCos) {
		this->pret = pret;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->culoare = culoare;
	}
	//destructor
	~Cos() {
		delete[] this->producator;
	}

};
int Cos::dimensiune = 10;

class Echipament {
public:
	const int idEchipament;
	static int nrEchipament;
	int pret;
	char* producator;
	string masura;
};

int main() {
	cout << "Constructor fara parametri clasa Minge" << endl;
	Minge m1;
	cout << "ID: "<< m1.idMinge << " culoare: " << m1.culoare << " pret = " << m1.pret << " dimensiunea: " << Minge::dimensiune << endl;
	cout << m1 << endl;

	cout << "Constructor cu parametri clasa Minge" << endl;
	Minge m2(1, "rosu", 10.99);
	cout << m2 << endl;

	cout << "Constructor de copiere clasa Minge" << endl;
	Minge m3 = m2;
	cout << m3 << endl;

	cout << "Constructor fata parametri clasa Cos" << endl;
	Cos c1;
	cout << c1 << endl;
	
	cout << "Constructor cu parametri clasa COS" << endl;
	Cos c2(2, 20, "Baschet France", "Portocaliu si alb");
	cout << c2 << endl;
	
	return 0;
}