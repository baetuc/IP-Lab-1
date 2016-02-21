#pragma once
#include<istream>
#include<ostream>
#include"Student.h"

using namespace std;

class Superior : public Serializabil{
protected:
	Student *stud;
	void creareStudent(istream &istr, int ID);

public:
	//Superior(Student *stud);

	Student* getStudent();
	void setStudent(Student *stud);
	virtual void printInfo(ostream& ostr, int deplasament) = 0;
	virtual void serializeaza(ostream &ostr) = 0;
	virtual void deserializeaza(istream &istr, int ID) = 0;
};