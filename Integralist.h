#pragma once
#include"Student.h"

class Integralist : public Student {
protected:
	double media;
	double bursa;

public:
	double getMedia();
	double getBursa();
	void setMedia(double media);
	void setBursa(double bursa);
	virtual void printInfo(ostream &ostr);

	virtual void serializeaza(ostream& ostr);
	virtual void deserializeaza(istream& istr, int ID);
	virtual string getTip();
};
