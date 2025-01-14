#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

// Domeniul baschet

class Minge {
private:
    const int idMinge;
    char* culoare;
    float pret;
    static int dimensiune;
public:
    // Constructor f?r? parametri
    Minge() : idMinge(1) {
        this->culoare = new char[strlen("albastru") + 1];
        strcpy(this->culoare, "albastru");
        this->pret = 4.99;
    }

    // Constructor cu parametri
    Minge(const int idMinge, const char* culoare, float pret) : idMinge(idMinge) {
        this->culoare = new char[strlen(culoare) + 1];
        strcpy(this->culoare, culoare);
        this->pret = pret;
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, Minge& m) {
        out << "ID: " << m.idMinge << endl;
        out << "Culoare: " << m.culoare << endl;
        out << "Pret: " << m.pret << endl;
        out << "Dimensiune: " << Minge::dimensiune << endl;
        return out;
    }

    // Constructor de copiere
    Minge(const Minge& m) : idMinge(m.idMinge) {
        this->culoare = new char[strlen(m.culoare) + 1];
        strcpy(this->culoare, m.culoare);
        this->pret = m.pret;
    }

    // Supraincarcare operator =
    Minge& operator=(const Minge& m) {
        if (this != &m) {
            delete[] this->culoare;
            this->culoare = new char[strlen(m.culoare) + 1];
            strcpy(this->culoare, m.culoare);
            this->pret = m.pret;
        }
        return *this;
    }

    // Destructor 
    ~Minge() {
        delete[] this->culoare;
    }

    // Metoda statica
    static int getDimensiune() {
        return dimensiune;
    }

    static int calculDimensiune(int valoare) {
        return dimensiune + valoare;
    }

    friend float sumaPret(int nrMingi, Minge* vector);

    // Operator+ obiect + valoare
    Minge operator+(float valoare) {
        pret = pret + valoare;
        return *this;
    }

    // Operator+ obiect + obiect
    Minge operator+(Minge m) {
        pret = pret + m.pret;
        return *this;
    }

    // Valoare + obiect
    friend float operator+(int Valoare, Minge m) {
        m.pret = Valoare + m.pret;
        return m.pret;
    }
};

float operator+(int Valoare, Minge m) {
    m.pret = Valoare + m.pret;
    return m.pret;
}

// Functie statica
float sumaPret(int nrMingi, Minge* vector) {
    float suma = 0;
    for (int i = 0; i < nrMingi; i++) {
        suma += vector[i].pret;
    }
    return suma;
}


int Minge::dimensiune = 5;

class Cos {
public:
    int pret;
    const int idCos;
    static int dimensiune;
    char* producator;
    string culoare;

    // Constructor f?r? parametri
    Cos() : idCos(1) {
        this->pret = 8;
        this->producator = new char[strlen("NBA") + 1];
        strcpy(this->producator, "NBA");
        this->culoare = "Rosu si alb";
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, Cos& c) {
        out << "Pret: " << c.pret << endl;
        out << "Producator: " << c.producator << endl;
        out << "Culoarea: " << c.culoare << endl;
        out << "Dimensiune: " << Cos::dimensiune << endl;
        return out;
    }

    // Constructor cu parametri
    Cos(const int idCos, int pret, const char* producator, string culoare) : idCos(idCos) {
        this->pret = pret;
        this->producator = new char[strlen(producator) + 1];
        strcpy(this->producator, producator);
        this->culoare = culoare;
    }

    // Destructor
    ~Cos() {
        delete[] this->producator;
    }

    // Constructor de copiere
    Cos(const Cos& c) : idCos(c.idCos) {
        this->pret = c.pret;
        this->producator = new char[strlen(c.producator) + 1];
        strcpy(this->producator, c.producator);
        this->culoare = c.culoare;
    }

    // Supraincarcare operator =
    Cos& operator=(const Cos& c) {
        if (this != &c) {
            delete[] this->producator;
            this->producator = new char[strlen(c.producator) + 1];
            strcpy(this->producator, c.producator);
            this->pret = c.pret;
            this->culoare = c.culoare;
        }
        return *this;
    }

    // Operator !
    bool operator!() {
        return pret > 100;
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

    // Constructor f?r? parametri
    Echipament() : idEchipament(1) {
        this->pret = 100;
        this->producator = new char[strlen("Adidas") + 1];
        strcpy(this->producator, "Adidas");
    }

    // Destructor
    ~Echipament() {
        delete[] this->producator;
    }
};

// Initializare variabila statica
int Echipament::nrEchipament = 90;

int main() {
    cout << "Constructor fara parametri clasa Minge" << endl;
    Minge m1;
    cout << m1 << endl;

    cout << "Constructor cu parametri clasa Minge" << endl;
    Minge m2(1, "rosu", 10.99);
    cout << m2 << endl;

    cout << "Constructor de copiere clasa Minge" << endl;
    Minge m3 = m2;
    cout << m3 << endl;

    cout << "Metoda get dimensiune" << endl;
    cout << m1.getDimensiune() << endl;

    cout << "Metoda calcul dimensiune" << endl;
    cout << m1.calculDimensiune(2) << endl;

    cout << "Metoda calcul suma vectori" << endl;
    Minge vectorMingi[3] = { m1, m2, m3 };
    cout << sumaPret(3, vectorMingi) << endl;

    cout << "Apelare operator +" << endl;
    m1 + 3;
    cout << m1 << endl;

    cout << endl;
    m1 + m2;
    cout << m1 << endl;

    cout << endl;
    cout << 100 + m1 << endl;
    cout << endl;

    cout << "Constructor fara parametri clasa Cos" << endl;
    Cos c1;
    cout << c1 << endl;

    cout << "Constructor cu parametri clasa COS" << endl;
    Cos c2(2, 20, "Baschet France", "Portocaliu si alb");
    cout << c2 << endl;

    cout << "Constructor de copiere clasa Cos" << endl;
    Cos c3 = c2;
    cout << c3 << endl;

    cout << "Testare operator ! " << endl;
    if (!c1) {
        cout << "Cosul este mai scump" << endl;
    }
    else {
        cout << "Cosul are pretul optim" << endl;
    }

    return 0;
}
