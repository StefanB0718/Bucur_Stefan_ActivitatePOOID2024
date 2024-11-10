#include <iostream>
using std::string;

class Produse {
public:
	string Nume_magazin;
	string Denumire_produs;
	int Cantitate;
	bool Este_la_oferta;

	void Afisare() {
		std::cout << " Denumirea magazinului:" << Nume_magazin << std::endl;
		std::cout << " Denumirea produsului:" << Denumire_produs << std::endl;
		std::cout << " Cantitate:" << Cantitate << std::endl;
		std::cout << " Produsul este redus" << std::boolalpha <<Este_la_oferta << std::endl;
	}
	//Constructor
	Produse(string nume_magazin, string denumire_produs, int cantitate, bool este_la_oferta) {
		Nume_magazin = nume_magazin;
		Denumire_produs = denumire_produs;
		Cantitate = cantitate;
		Este_la_oferta = este_la_oferta;

	}
};

int main() {
	Produse  produsul1 = Produse("Emag", "Aspirator robot", 3, true);
	produsul1.Afisare();
	Produse produsul2 = Produse("Altex", "Consola Jocuri", 4, false);
	produsul2.Afisare();

	return 0;
}
