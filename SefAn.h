#pragma once
#include"Superior.h"
#include"SefGrupa.h"

class SefAn : public Superior {
protected:
	list<SefGrupa*> subordonati;

public:
	list<SefGrupa*> getSubordonati();
	void setSubordonati(list<SefGrupa*> subordonati);

	virtual void printInfo(ostream& ostr, int deplasament);
	virtual void serializeaza(ostream &ostr);
	virtual void deserializeaza(istream &istr, int ID);
};