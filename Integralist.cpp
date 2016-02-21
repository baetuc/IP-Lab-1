#include "Integralist.h"
#include<sstream>
#include<string>
#include"Utility.h"

using namespace std;

map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
map<string, string> tipulTipului;


typedef Serializabil* (*CreareObiect)();
map<string, CreareObiect> creeazaObiectDeTipul;


double Integralist::getMedia() {
	return media;
}

double Integralist::getBursa() {
	return bursa;
}

void Integralist::setMedia(double media) {
	this->media = media;
}

void Integralist::setBursa(double bursa) {
	this->bursa = bursa;
}

void Integralist::serializeaza(ostream& ostr) {
	ostr << '\n' << INTEGRALIST << '\n';
	ostr << ID << '\n';
	ostr << nume << '\n';
	ostr << prenume << '\n';
	ostr << an << '\n';
	ostr << grupa << '\n';
	ostr << media << '\n';
	ostr << bursa << '\n';
	ostr << FINISHED_STUDENT_MARK;
}

void Integralist::deserializeaza(istream& istr, int ID) {
	this->ID = ID;
	nume = Utility::valideazaString(istr);
	prenume = Utility::valideazaString(istr);
	an = (int)Utility::valideazaNumar(istr);
	grupa = Utility::valideazaString(istr);
	media = Utility::valideazaNumar(istr);
	bursa = Utility::valideazaNumar(istr);
	Utility::valideazaSfarsitObiect(istr);
}

string Integralist::getTip() {
	return "Integralist";
}

void Integralist::printInfo(ostream &ostr)
{
	ostr<<"----------------------------------\n";
	ostr << "Student integralist\n";
	ostr << "ID: " << ID<<'\n';
	ostr << "Nume: " << nume << '\n';
	ostr << "Preume: " << prenume << '\n';
	ostr << "An de studiu: " << an << '\n';
	ostr << "Grupa: " << grupa << '\n';
	ostr << "Medie: " << media << '\n';
	ostr << "Bursa: " << bursa << '\n';
	ostr << "----------------------------------\n";
}


namespace
{
	Serializabil * creareIntegralist()
	{
		return new Integralist;
	}
	CreareObiect x = (creeazaObiectDeTipul["Integralist"] = creareIntegralist);
	string y = (tipulTipului["Integralist"] = "Student");
}