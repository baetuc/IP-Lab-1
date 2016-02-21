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

void Integralist::printInfo(ostream &ostr, int deplasament)
{
	Utility::printHeader(ostr, deplasament);
	ostr<<"----------------------------------\n"; 
	Utility::printHeader(ostr, deplasament);
	ostr << "Student integralist\n";
	Utility::printHeader(ostr, deplasament);
	ostr << "ID: " << ID<<'\n'; 
	Utility::printHeader(ostr, deplasament);
	ostr << "Nume: " << nume << '\n';
	Utility::printHeader(ostr, deplasament);
	ostr << "Preume: " << prenume << '\n';
	Utility::printHeader(ostr, deplasament);
	ostr << "An de studiu: " << an << '\n';
	Utility::printHeader(ostr, deplasament);
	ostr << "Grupa: " << grupa << '\n';
	Utility::printHeader(ostr, deplasament);
	ostr << "Medie: " << media << '\n';
	Utility::printHeader(ostr, deplasament);
	ostr << "Bursa: " << bursa << '\n';
	Utility::printHeader(ostr, deplasament);
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