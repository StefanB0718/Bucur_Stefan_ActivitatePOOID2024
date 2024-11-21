#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	//Constructor fara parametri
	Autobuz() : idAutobuz(++nrAutobuze) {
		capacitate = 60;
		nrPersoaneImbarcate = 49;
		producator = new char[strlen("Mercedes") + 1];
		strcpy(producator, "Mercedes");
	}
	//Constructor cu parametri
	Autobuz  (int capacitateaAutobuzului,int NrPersoaneImbarcate, const char* producatorulAutobuzului): idAutobuz(++nrAutobuze) {
		capacitate = capacitateaAutobuzului;
		nrPersoaneImbarcate = NrPersoaneImbarcate;
		producator = new char[strlen(producatorulAutobuzului) + 1];
		strcpy(producator, producatorulAutobuzului);
	}
	//Destructor
	~Autobuz() {
		delete[] producator;
	}
	// setter capacitate
	void setCapacitatea( int Capacitatea) {
		capacitate = Capacitatea;
	}
	//getter capacitate
	int getCapacitatea() const {   
		return capacitate;
	}
	//setter nr persoane imbarcate
	void setImbarcate(int persoaneImbarcate) {
		nrPersoaneImbarcate = persoaneImbarcate;
	}
	//getter nrPersoaneImbarcate
	int getImbarcate() {
		return nrPersoaneImbarcate;
	}
	//getter producator
	char* getProducator() {
		return producator;
	}
	//setter producator
	void setProducator(char* producator) {
		delete[] this->producator;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& out, Autobuz& a) {
		out << "Autobuzul nr." << a.nrAutobuze << "; " << "ID:" << a.idAutobuz << "; " << "Capacitate " << a.capacitate << "; " << "Persoane Imbarcate " << a.nrPersoaneImbarcate << "; " << "Producator " << a.producator << endl;
		return out;
	}
	//operator egal
	Autobuz& operator=(Autobuz& a) {
		delete[] producator;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;

		return *this; 
	}
	//numar locuri libere din autobuz
	int getNumarLocuriLibere() const {
		return capacitate - nrPersoaneImbarcate;
	}


	//operator de cast la int
	operator int() const {
		return nrPersoaneImbarcate;
	}

	//operator >

	bool operator> (const Autobuz& a) {
		return capacitate > a.capacitate;
	}

	//constructor de copiere
	Autobuz(const Autobuz& a) : idAutobuz(++nrAutobuze) {
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(producator, a.producator);

	}


 };

int Autobuz::nrAutobuze = 0;

int main() {
	cout << "Constructor fara parametri" << endl;
	Autobuz autobuzInitial;
	cout << autobuzInitial << endl;

	cout << "Constructor cu parametri" << endl;
	Autobuz primulAutobuz(72, 34, "Otokar");
	cout << primulAutobuz << endl;

	//modificare cu setter si getter 

	autobuzInitial.setCapacitatea(70);
	autobuzInitial.setImbarcate(65);

	cout << "Noua capacitate a autobuzului este de " << autobuzInitial.getCapacitatea() << " de persoane" << endl;
	cout << "Noul numar de persoane imbarcate este de " << autobuzInitial.getImbarcate() << " de persoane" << endl;
	
	//testare afisare locuri libere

	cout << "In primul autobuz au ramas " << autobuzInitial.getNumarLocuriLibere() << " de locuri libere" << endl;
	cout << "In al doilea autobuz au ramas " << primulAutobuz.getNumarLocuriLibere() << " de locuri libere" << endl;

	//operator cast la int
	if (autobuzInitial = primulAutobuz);
	cout << "Numarul de persoane urcate in primul autobuz este de: " << autobuzInitial.getImbarcate() << endl;
	cout << endl;
	 //operator >
	if (autobuzInitial > primulAutobuz) {
		cout << "In primul autobuz incap mai multe persoane" << endl;
	}
	
	else {
		cout << "In primul autobuz incap mai putine persoane" << endl;
	}
	return 0;
}