#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Corabie {
private:
    static int nrCorabii;
    int capacitate;
    int nrPersoaneImbarcate;
    int* varstePasageri;
    char* culoare;
    const int idCorabie;

public:
    // Constructor f?r? parametri
    Corabie() : idCorabie(++nrCorabii) {
        this->capacitate = 48;
        this->nrPersoaneImbarcate = 12;
        this->varstePasageri = new int[nrPersoaneImbarcate];
        for (int i = 0; i < nrPersoaneImbarcate; i++) {
            this->varstePasageri[i] = 18;
        }
        this->culoare = new char[strlen("rosu") + 1];
        strcpy(this->culoare, "rosu");
    }

    // Constructor cu parametri
    Corabie(int capacitate, int nrPersoaneImbarcate, int* varstePasageri, const char* culoare) : idCorabie(++nrCorabii) {
        if (capacitate > 0) {
            this->capacitate = capacitate;
        }
        else {
            this->capacitate = 0;
        }
        if (nrPersoaneImbarcate > 0) {
            this->varstePasageri = new int[this->nrPersoaneImbarcate];
            for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
                this->varstePasageri[i] = varstePasageri[i];
            }
        }
        else {
            this->varstePasageri = NULL;
        }
        if (culoare != nullptr) {
            this->culoare = new char[strlen(culoare) + 1];
            strcpy(this->culoare, culoare);
        }
        else {
            this->culoare = nullptr;
        }
    }


    // Destructor
    ~Corabie() {
        delete[] culoare;
        delete[] varstePasageri;
    }

    // Constructor de copiere
    Corabie(const Corabie& CorabiaX) : idCorabie(++nrCorabii) {
        this->capacitate = CorabiaX.capacitate;
        this->nrPersoaneImbarcate = CorabiaX.nrPersoaneImbarcate;
        this->varstePasageri = new int[nrPersoaneImbarcate];
        for (int i = 0; i < nrPersoaneImbarcate; i++) {
            this->varstePasageri[i] = CorabiaX.varstePasageri[i];
        }
        this->culoare = new char[strlen(CorabiaX.culoare) + 1];
        strcpy(this->culoare, CorabiaX.culoare);
    }

    // Setter ?i getter
    void setCapacitate(int Capacitate) {
        capacitate = Capacitate;
    }
    int getCapacitate() const {
        return capacitate;
    }
    void setVarstePasageri(int* VarstePasageri, int NumarPersoaneImbarcate) {
        delete[] varstePasageri;
        nrPersoaneImbarcate = NumarPersoaneImbarcate;
        if (NumarPersoaneImbarcate > 0) {
            varstePasageri = new int[NumarPersoaneImbarcate];
            for (int i = 0; i < NumarPersoaneImbarcate; i++) {
                varstePasageri[i] = VarstePasageri[i];
            }
        }
        else {
            varstePasageri = nullptr;
        }
    }
    int* getVarstePasageri() const {
        return varstePasageri;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Corabie& corabie) {
        out << "Id Corabie: " << corabie.idCorabie << endl;
        out << "Capacitate persoane: " << corabie.capacitate << endl;
        out << "Numar persoane imbarcate: " << corabie.nrPersoaneImbarcate << endl;
        out << "Varste pasageri: ";
        for (int i = 0; i < corabie.nrPersoaneImbarcate; i++) {
            out << corabie.varstePasageri[i] << " ";
        }
        out << endl;
        if (corabie.culoare != nullptr) {
            out << "Culoare: " << corabie.culoare << endl;
        }
        else {
            out << "Culoare: necunoscut" << endl;
        }
        return out;
    }
    //operatorul egal 
    Corabie& operator=(const Corabie& alta) {
        if (this != &alta) { 
            this->capacitate = alta.capacitate;
            this->nrPersoaneImbarcate = alta.nrPersoaneImbarcate;

            delete[] this->varstePasageri;
            delete[] this->culoare;

            if (alta.nrPersoaneImbarcate > 0) {
                this->varstePasageri = new int[alta.nrPersoaneImbarcate];
                for (int i = 0; i < alta.nrPersoaneImbarcate; i++) {
                    this->varstePasageri[i] = alta.varstePasageri[i];
                }
            }
            else {
                this->varstePasageri = NULL;
            }

            if (alta.culoare != NULL) {
                this->culoare = new char[strlen(alta.culoare) + 1];
                strcpy(this->culoare, alta.culoare);
            }
            else {
                this->culoare = NULL;
            }
        }
        return *this;
    }
    // operator < 
    bool operator<(const Corabie& other) const {
        return this->capacitate < other.capacitate;
    }
};

int Corabie::nrCorabii = 0;

int main() {
    cout << "Constructor fara parametri: " << endl;
    Corabie primaCorabie;
    cout << primaCorabie << endl;

    int varste[] = { 30, 25, 40, 35, 50 };
    cout << "Constructor cu parametri: " << endl;
    Corabie aDouaCorabie(200, 5, varste, "neagra");
    cout << aDouaCorabie << endl;

    cout << "Testare operator =: " << endl;
    Corabie aTreiaCorabie;
    aTreiaCorabie = aDouaCorabie;
    cout << aTreiaCorabie << endl;

    cout << "Testare operator <: " << endl;
    if (primaCorabie < aDouaCorabie) {
        cout << "Prima corabie are o capacitate mai mica decat a doua corabie." << endl;
    }
    else {
        cout << "Prima corabie nu are o capacitate mai mica decat a doua corabie." << endl;
    }
    return 0;
}
