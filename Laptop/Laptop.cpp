#include<iostream>
#include<cstring>

using namespace std;

class Laptop {

public:
	string marca;
	int model;
	float versiuneWindows;
	char* tipHardDisk;

	Laptop() {
		this->marca = "Asus";
		this->model = 5324;
		this->versiuneWindows = 11.3;
		this->tipHardDisk = new char[strlen("SSD") + 1];
		strcpy_s(this->tipHardDisk, strlen("SSD") + 1, "SSD");

	}
	Laptop(string marca) {
		this->marca = marca;
		this->model = 5324;
		this->versiuneWindows = 11.3;
		this->tipHardDisk = new char[strlen("SSD") + 1];
		strcpy_s(this->tipHardDisk, strlen("SSD") + 1, "SSD");
	}
	Laptop(int model) {
		this->marca = "Asus";
		this->model = model;
		this->versiuneWindows = 11.3;
		this->tipHardDisk = new char[strlen("SSD") + 1];
		strcpy_s(this->tipHardDisk, strlen("SSD") + 1, "SSD");
	}
	Laptop(float versiuneWindows) {
		this->marca = "Asus";
		this->model = 5324;
		this->versiuneWindows = versiuneWindows;
		this->tipHardDisk = new char[strlen("SSD") + 1];
		strcpy_s(this->tipHardDisk, strlen("SSD") + 1, "SSD");
	}

	~Laptop() {
		delete[] this->tipHardDisk;
	}

	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Model:" << this->model << endl;
		cout << "Versiune Windows:" << this->versiuneWindows << endl;
		cout << "Tip Hard Disk:" << this->tipHardDisk << endl;
	}
};

int main() {
	Laptop laptop;
	laptop.afisare();

	return 0;
}
