#pragma once
#include"Superior.h"
#include<list>

using namespace std;

class Responsabil : public Superior {
protected:
	list<Student*> subordonati;

public:
	list<Student*> getSubordonati();
	void setSubordonati(list<Student*> subordonati);

	virtual void serializeaza(ostream &ostr);
	virtual void deserializeaza(istream &istr, int ID);
};