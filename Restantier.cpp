#pragma once
#include"Restantier.h"
#include"Utility.h"
#include<iostream>

void Restantier::adaugaObiect(string obiect)
{
	obiecte.push_back(obiect);
}

void Restantier::stergeObiect(string obiect)
{
	obiecte.remove(obiect);
}

list<string> Restantier::getObiecte()
{
	return obiecte;
}

void Restantier::serializeaza(ostream& ostr)
{
	ostr << "\nRestantier\n";
	ostr << ID << '\n';
	ostr << nume << '\n';
	ostr << prenume << '\n';
	ostr << an << '\n';
	ostr << grupa << '\n';
	ostr << obiecte.size() << '\n';
	list<string>::iterator it;
	for (it = obiecte.begin(); it != obiecte.end(); ++it)
	{
		ostr << (*it) << '\n';
	}
	ostr << "#";
}

void Restantier::deserializeaza(istream& istr, int ID)
{
	this->ID = ID;
	nume = Utility::valideazaString(istr);
	prenume = Utility::valideazaString(istr);
	an = (int)Utility::valideazaNumar(istr);
	grupa = Utility::valideazaString(istr);
	
	obiecte.clear();
	int length = (int)Utility::valideazaNumar(istr);
	string obiect;
	for (int i = 1; i <= length; ++i)
	{
		obiect = Utility::valideazaString(istr);
		obiecte.push_back(obiect);
	}
	Utility::valideazaSfarsitObiect(istr);
}

string Restantier::getTip() {
	return "Restantier";
}

void Restantier::printInfo(ostream &ostr)
{
	ostr << "----------------------------------\n";
	ostr << "Student restantier\n";
	ostr << "ID: " << ID << '\n';
	ostr << "Nume: " << nume << '\n';
	ostr << "Preume: " << prenume << '\n';
	ostr << "An de studiu: " << an << '\n';
	ostr << "Grupa: " << grupa << '\n';
	ostr << "Are restante la obiectele: ";
	list<string>::iterator it;
	for (it = obiecte.begin(); it != obiecte.end(); ++it)
	{
		ostr << (*it)<<' ';
	}
	ostr << '\n';
	ostr << "----------------------------------\n";
}

extern map<string, string> tipulTipului;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;


namespace
{
	Serializabil * creareRestantier()
	{
		return new Restantier;
	}
	CreareObiect x = (creeazaObiectDeTipul["Restantier"] = creareRestantier);
	string y = (tipulTipului["Restantier"] = "Student");
}