#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Vapor {
private:
    const int idVapor;
    static int nrVapoare;
    int capacitate;
    int nrPersoaneImbarcate;
    int* varstePasageri;

public:
    // Constructor fara parametri
    Vapor() : idVapor(++nrVapoare) {
        this->capacitate = 6;
        this->nrPersoaneImbarcate = 3;
        this->varstePasageri = new int[nrPersoaneImbarcate];
        this->varstePasageri[0] = 18;
        this->varstePasageri[1] = 20;
        this->varstePasageri[2] = 32;
    }

    // Constructor cu parametri
    Vapor(int capacitate, int nrPersoaneImbarcate, int* varstePasageri) : idVapor(++nrVapoare) {
        this->capacitate = capacitate;
        if (nrPersoaneImbarcate < capacitate) {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
        else {
            this->nrPersoaneImbarcate = capacitate;
        }
        this->varstePasageri = new int[nrPersoaneImbarcate];
        for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
            this->varstePasageri[i] = varstePasageri[i];
        }
    }

    // Constructor de copiere
    Vapor(const Vapor& v) : idVapor(++nrVapoare) {
        this->capacitate = v.capacitate;
        this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
        this->varstePasageri = new int[nrPersoaneImbarcate];
        for (int i = 0; i < nrPersoaneImbarcate; i++) {
            this->varstePasageri[i] = v.varstePasageri[i];
        }
    }

    // Destructor
    ~Vapor() {
        delete[] varstePasageri;
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Vapor& v) {
        out << "ID-ul vaporului este " << v.idVapor << endl;
        out << "Capacitatea vaporului este " << v.capacitate << endl;
        out << "Nr de persoane imbarcate este " << v.nrPersoaneImbarcate << endl;
        for (int i = 0; i < v.nrPersoaneImbarcate; i++) {
            out << v.varstePasageri[i] << endl;
        }
        out << endl;
        return out;
    }

    // Getter si setter pentru capacitate
    int getCapacitate() {
        return capacitate;
    }

    void setCapacitate(int capacitate) {
        this->capacitate = capacitate;
    }

    // Operator =
    Vapor& operator=(const Vapor& v) {
        if (this != &v) {
            delete[] varstePasageri;
            this->capacitate = v.capacitate;
            this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
            this->varstePasageri = new int[v.nrPersoaneImbarcate];
            for (int i = 0; i < v.nrPersoaneImbarcate; i++) {
                this->varstePasageri[i] = v.varstePasageri[i];
            }
        }
        return *this;
    }

    // Operator cast la int
    operator int() {
        return nrPersoaneImbarcate;
    }

    // Operator >
    bool operator>(const Vapor& v) {
        return capacitate > v.capacitate;
    }

    // Operator + (adunare)
    Vapor operator+(const Vapor& v) {
        return Vapor(capacitate + v.capacitate, 0, nullptr);
    }

    // Operator - (scadere)
    Vapor operator-(const Vapor& v) {
        return Vapor(capacitate - v.capacitate, 0, nullptr);
    }

    // Operator * (inmultire)
    Vapor operator*(int scalar) {
        return Vapor(capacitate * scalar, 0, nullptr);
    }

    // Operator / (impartire)
    Vapor operator/(int scalar) {
        return Vapor(capacitate / scalar, 0, nullptr);
    }

    // Operator +=
    Vapor& operator+=(int val) {
        capacitate += val;
        return *this;
    }

    // Operator -=
    Vapor& operator-=(int val) {
        capacitate -= val;
        return *this;
    }

    // Operator *=
    Vapor& operator*=(int scalar) {
        capacitate *= scalar;
        return *this;
    }

    // Operator /=
    Vapor& operator/=(int scalar) {
        capacitate /= scalar;
        return *this;
    }

    // Operator == (egalitate)
    bool operator==(const Vapor& v) {
        return capacitate == v.capacitate && nrPersoaneImbarcate == v.nrPersoaneImbarcate;
    }

    // Operator != (diferenta)
    bool operator!=(const Vapor& v) {
        return !(*this == v);
    }

    // Operator < (mai mic)
    bool operator<(const Vapor& v) {
        return capacitate < v.capacitate;
    }

    // Operator <= 
    bool operator<=(const Vapor& v) {
        return capacitate <= v.capacitate;
    }

    // Operator >= 
    bool operator>=(const Vapor& v) {
        return capacitate >= v.capacitate;
    }

    // Operator ++
    Vapor& operator++() {
        capacitate++;
        return *this;
    }

    // Operator -- 
    Vapor& operator--() {
        capacitate--;
        return *this;
    }

    // Operator ++ 
    Vapor operator++(int) {
        Vapor temp = *this;
        capacitate++;
        return temp;
    }

    // Operator -- 
    Vapor operator--(int) {
        Vapor temp = *this;
        capacitate--;
        return temp;
    }
};

int Vapor::nrVapoare = 0;

int main() {
    Vapor v1;
    cout << v1 << endl;

    int varste1[] = { 34, 56, 98 };
    Vapor v2(4, 3, varste1);
    cout << v2 << endl;

    // Operator cast la int
    int nrPasageri = v2;
    cout << "Nr de pasageri din al doilea vapor este de " << nrPasageri << " de persoane" << endl;

    // Operator >
    if (v1 > v2) {
        cout << "Primul vapor are o capacitate mai mare decat al doilea vapor." << endl;
    }
    else {
        cout << "Primul vapor are o capacitate mai mica decat al doilea vapor." << endl;
    }

    // Operator +
    Vapor v3 = v1 + v2;
    cout << "Vaporul rezultat din adunarea capacitatii este:" << endl;
    cout << v3;

    // Operator ++ 
    ++v1;
    cout << "Capacitatea vaporului v1 dupa incrementare este: " << v1.getCapacitate() << endl;

    // Operator -=
    v2 -= 2;
    cout << "Capacitatea vaporului v2 dupa scadere este: " << v2.getCapacitate() << endl;

    return 0;
}