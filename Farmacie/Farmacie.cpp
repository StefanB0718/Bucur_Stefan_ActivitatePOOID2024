#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
using namespace std; 

enum Reteta {
	cuReteta, faraReteta
};

class Farmacie {
private:
	const int CODUnic; //constanta nu se modifica
	string adresa;
	int nrMedicamente;
	float* pretMedicamente;
	Reteta prescriptieMedicala;
	static int counter;
	

public:  //constructor fara parametri
	Farmacie(): CODUnic(++counter), adresa("Necunoscuta"), nrMedicamente(0), pretMedicamente(nullptr), prescriptieMedicala(faraReteta){
	
	 }

	//constructor cu toti parametrii
	Farmacie(const int CODUnic, string adresa, int nrMedicamente, const float* pretMedicamente, Reteta prescriptieMedicala) :
		CODUnic(CODUnic), adresa(adresa), nrMedicamente(nrMedicamente), prescriptieMedicala(prescriptieMedicala) {
		//alocare dinamica pret medicamente
		this->pretMedicamente = new float[nrMedicamente];
		for (int i = 0;i < nrMedicamente; i++) {
			this->pretMedicamente[i] = pretMedicamente[i]; //de ce conditita este i < nrMedicamente si nu i<pret Medicamente?
		}
	}
		//destructor
	~Farmacie() {
		delete[] pretMedicamente;
		}
		//afisarea functiilor
	void afisare() const {
			cout << "COD Unic: " << CODUnic << endl;
			cout << "Adresa: " << adresa << endl;
			cout << "Nr de cutii: " << nrMedicamente << endl;
			cout << "Pretul Medicamentelor: ";
			for (int i = 0; i < nrMedicamente; i++) {
				cout << pretMedicamente[i] << " "; //de ce facem cout de pretMedicamente si nu nrMedicamente?
			}
			cout << endl;
			cout << "Prescriptie Medicala" << (prescriptieMedicala == cuReteta ? "Cu reteta ?" : "Fara reteta ?") << endl;
		}
};
	//initializare variabila statica counter 
int Farmacie::counter = 0;

int main()
	{
		float preturi1[] = {15.4, 78.6,99.8};
		Farmacie Catena(1, "Strada Laborator", 2, preturi1, cuReteta);
		Catena.afisare();

		Farmacie Tei(2, "Bld. Camil Ressu", 3, preturi1, faraReteta);
		Tei.afisare();

		return 0;

	}
