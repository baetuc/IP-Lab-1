#pragma once
#include"Student.h"
#include<list>

class Restantier : public Student
{
protected:
	list<string> obiecte;

public:
	void adaugaObiect(string obiect);
	void stergeObiect(string obiect);
	list<string> getObiecte();
	virtual void printInfo(ostream &ostr, int deplasament);

	virtual void serializeaza(ostream& ostr);
	virtual void deserializeaza(istream& istr, int ID);
	virtual string getTip();
};