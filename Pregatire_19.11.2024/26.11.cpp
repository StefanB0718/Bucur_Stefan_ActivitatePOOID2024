#include<iostream>
#include<cstring>

using namespace std;

class Vapor {
private:
	const int id;
	static int nrVapoare;
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstePasageri;

public:
	Vapor() :id(++nrVapoare) {
		this->capacitate = 10;
		this->nrPersoaneImbarcate = 5;
		this->varstePasageri = new int[nrPersoaneImbarcate];
		this->varstePasageri[0] = 3;
		this->varstePasageri[1] = 9;
		this->varstePasageri[2] = 20;
		this->varstePasageri[3] = 34;
		this->varstePasageri[4] = 35;
	}
	Vapor(int capacitate, int nrPersoaneImbarcate, int* varstePasageri) :id(++nrVapoare) {
		if (capacitate > 0)
			this->capacitate = capacitate;
		if (nrPersoaneImbarcate < capacitate)
			this->nrPersoaneImbarcate - nrPersoaneImbarcate;
		this->varstePasageri - new int[nrPersoaneImbarcate];
		for (int i; i < this->nrPersoaneImbarcate; i++) {
			this->varstePasageri[i] - varstePasageri[i];
		}
	}
	~Vapor() {
		if (varstePasageri != NULL) {
			delete[] varstePasageri;
		}
	}
		

			Vapor(const Vapor & v) :id(++nrVapoare) {
				this->capacitate = v.capacitate;
				this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
				this->varstePasageri = new int[v.nrPersoaneImbarcate];
				for (int i; i < v.nrPersoaneImbarcate; i++) {
					this->varstePasageri[i] = v.varstePasageri[i];
				}

			}

		
		int getCapacitate() {
			return capacitate;
		}

		void setCapacitate(int capacitate) {
			if (capacitate != NULL)
				this->capacitate = capacitate;
		}

		int getVarstePasageri(int index) {
			if(index>=0 && index<nrPersoaneImbarcate)
				return varstePasageri[index];
		}

		void setVarstePasageri(int nrPersoaneImbarcate, int* varstePasageri) {
			if(varstePasageri != NULL)
				delete[] this->varstePasageri;
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;;
			this->varstePasageri = new int[nrPersoaneImbarcate];
			for (int i = 0; i < nrPersoaneImbarcate; i++) {
				this->varstePasageri[i] = varstePasageri[i];
			}
		}

		friend ostream& operator<<(ostream& out, Vapor& v) {
			out << v.id << endl;
			out << v.capacitate << endl;
			out << v.nrPersoaneImbarcate << endl;
			for (int i = 0; i < v.nrPersoaneImbarcate; i++)
				out << v.varstePasageri[i] << endl;
			return out;
		}
	
};

int Vapor::nrVapoare = 0;

int main() {

	Vapor vapor1;
	cout << vapor1 << endl;

	vapor1.setCapacitate(10);
	cout << vapor1.getCapacitate() << endl;

	vapor1.setVarstePasageri(7, new int[7] {40, 41, 42, 43, 44, 45, 46});
	cout << vapor1.getVarstePasageri(5) << endl << endl;

	cout << vapor1 << endl;
}