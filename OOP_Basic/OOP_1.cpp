#include <iostream>
using std::string;

class AngajatiPromovati {
	virtual void SolicitarePromovare()=0;
};


class Angajati:AngajatiPromovati {
private:
	string Nume;
	string Companie;
	int Varsta;
public:
	void setNume(string nume) { //setter
		Nume = nume;
	}
	string getNume() { //getter
		return Nume;
	}
	void setCompanie(string companie) {
		Companie = companie;
	}
	string getCompanie() {
		return Companie;
	}
	void setVarsta(int varsta) {
		if(varsta>=18)
		Varsta = varsta;
	}
	int getVarsta() {
		return Varsta;
	}

	void Introducere() { //functie
		std::cout << "Nume - " << Nume << std::endl;
		std::cout << "Companie - " << Companie << std:: endl;
		std::cout << "Varsta - " << Varsta << std:: endl;
	}
	Angajati(string nume, string companie, int varsta) {
		Nume = nume;
		Companie = companie;
		Varsta = varsta;
	} 
	void SolicitarePromovare() {
		if (Varsta > 30)
			std::cout << Nume << " a fost promovat/a" << std::endl;
		else
			std::cout << Nume << ", ne pare rau, nu ai varsta necesara pentru a promova" << std::endl;
	}
};
int main()
{
	Angajati angajati1 = Angajati("Victor Popescu", "Endava", 25);
		angajati1.Introducere();

	Angajati angajati2 = Angajati("Vlad Ionescu", "Oracle", 29);
		angajati2.Introducere();
	Angajati angajati3 = Angajati("Raluca Dumitrescu", "Amazon", 21);
		angajati3.Introducere();

		angajati1.setVarsta(33);
		std::cout << angajati1.getNume() << " are " << angajati1.getVarsta() << " de ani" << std::endl;
		angajati1.SolicitarePromovare();
		angajati2.SolicitarePromovare();
		angajati3.SolicitarePromovare();
}