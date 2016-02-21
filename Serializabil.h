#pragma once
#include<iostream>

using namespace std;

class Serializabil {
public:

	virtual void printInfo(ostream& ostr, int deplasament) = 0;
	virtual void serializeaza(ostream& ostr) = 0;
	virtual void deserializeaza(istream& istr, int ID) = 0;
};
