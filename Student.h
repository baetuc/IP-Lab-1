#pragma once
#include<string>
#include<istream>
#include<ostream>
#include<map>
#include"Serializabil.h"

#define FINISHED_STUDENT_MARK '#'
#define INTEGRALIST "Integralist"

using namespace std;

// Clasa abstracta ce defineste un student
class Student : public Serializabil{
protected:
	int ID;
	string nume;
	string prenume;
	int an;
	string grupa;

public:
	int getID();
	string getNume();
	string getPrenume();
	int getAn();
	string getGrupa(); 
	void setID(int ID);
	void setNume(string nume);
	void setPrenume(string prenume);
	void setAn(int an);
	void setGrupa(string grupa);

	virtual void  printInfo(ostream& ostr) = 0;
	virtual void serializeaza(ostream& ostr) = 0;
	virtual void deserializeaza(istream& istr, int ID) = 0;
	virtual string getTip() = 0;
	virtual ~Student();
};
