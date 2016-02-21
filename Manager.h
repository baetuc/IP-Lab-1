#pragma once
#include<istream>
#include<ostream>

using namespace std;

class Manager {
public:

	void serializeazaFisier(ostream& istr);
	void deserializeazaFisier(istream& ostr);

	void adaugaStudenti(istream& istr);
	void stergeStudent(int ID);
	void printInfo(int ID);
};
