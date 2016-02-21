#include "Responsabil.h"
#include"Utility.h"
#include<utility>

using namespace std;

extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;

list<Student*> Responsabil::getSubordonati() {
	return subordonati;
}

void Responsabil::setSubordonati(list<Student*> subordonati) {
	this->subordonati = subordonati;
}

void Responsabil::serializeaza(ostream& ostr) {
	ostr << "\nResponsabil\n";
	ostr << stud->getID() << '\n';
	ostr << stud->getTip() << '\n';
	ostr << "#";
}

void Responsabil::deserializeaza(istream& istr, int ID) {
	creareStudent(istr, ID);
	Utility::valideazaSfarsitObiect(istr);
}

void Responsabil::printInfo(ostream& ostr, int deplasament)
{
	list<Student*>::iterator it;
	Utility::printHeader(ostr, deplasament);
	ostr << "Responsabil cu studentii:\n";
	for (it = subordonati.begin(); it != subordonati.end(); ++it)
	{
		Utility::printHeader(ostr, deplasament+1);
		ostr << (*it)->getID() << '\n';
	}
}

extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
extern map<string, string> tipulTipului;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;


namespace
{
	Serializabil * creareResponsabil()
	{
		return new Responsabil;
	}
	CreareObiect x = (creeazaObiectDeTipul["Responsabil"] = creareResponsabil);
	string y = (tipulTipului["Responsabil"] = "Responsabil");
	map<int, pair<Serializabil*, bool>> z = obiecteCreateDinClasa["Responsabil"];
}