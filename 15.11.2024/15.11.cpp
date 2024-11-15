#define _CRT_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Autobuz {
public:
	int NrAutobuz;
	string MarcaAutobuz;
	int CapacitateAutobuz;
	float ConsumMediu;
	bool esteElectric;

	void Afisare() {
		cout << "Nr. autobuzului: " << NrAutobuz << endl;
		cout << "Marca autubuzului: " << MarcaAutobuz << endl;
		cout << "Capacitatea autobuzului: " << CapacitateAutobuz << " de locuri" << endl;
		cout << "Consumul mediu: " << ConsumMediu << " litri/100 de km" << endl;
		cout << "Autobuzul este electric? " << esteElectric << endl;
	}
};


int main() {
	Autobuz autobuz1;
	autobuz1.NrAutobuz = 100;
	autobuz1.MarcaAutobuz = "Mercedes";
	autobuz1.CapacitateAutobuz = 55;
	autobuz1.ConsumMediu = 15.5;
	autobuz1.esteElectric = false;
	autobuz1.Afisare();
	

	return 0;

}
