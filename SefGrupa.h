#pragma once
#include"Superior.h"
#include<list>

using namespace std;

class SefGrupa : public Superior {
protected:
	list<Student*> subordonati;

public:
	list<Student*> getSubordonati();
	void setSubordonati(list<Student*> subordonati);

	virtual void printInfo(ostream& ostr, int deplasament);
	virtual void serializeaza(ostream &ostr);
	virtual void deserializeaza(istream &istr, int ID);
};