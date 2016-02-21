#pragma once
#include"SefAn.h"
#include"Utility.h"
#include"Student.h"

#define SEF_GRUPA "SefGrupa"

extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;

void SefAn::serializeaza(ostream &ostr)
{
	ostr << "\nSefAn" << '\n';
	ostr << stud->getID() << '\n';
	ostr << stud->getTip() << '\n';
	ostr << subordonati.size() << '\n';
	list<SefGrupa*>::iterator it;
	for (it = subordonati.begin(); it != subordonati.end(); ++it)
	{
		ostr << (*it)->getStudent()->getTip() << ' ' << (*it)->getStudent()->getID() << '\n';
	}
	ostr << '#';
}

void SefAn::deserializeaza(istream &istr, int ID) {
	creareStudent(istr, ID);
	int length = (int)Utility::valideazaNumar(istr);
	for (int i = 1; i <= length; ++i)
	{
		string tip = Utility::valideazaString(istr);
		int ID = (int)Utility::valideazaNumar(istr);

		map<int, pair<Serializabil*, bool>>::iterator it = obiecteCreateDinClasa["Student"].find(ID);

		Student *stud;

		if (it == obiecteCreateDinClasa["Student"].end())//nu exista
		{
			stud = (Student*) creeazaObiectDeTipul[tip]();
			stud->setID(ID);
			obiecteCreateDinClasa["Student"][ID] = make_pair(stud, false);
		}
		else
		{
			stud = (Student*)it->second.first;
		}

		it = obiecteCreateDinClasa[SEF_GRUPA].find(ID);
		SefGrupa *sefGr;
		if (it == obiecteCreateDinClasa[SEF_GRUPA].end())//nu exista
		{
			sefGr = (SefGrupa*)creeazaObiectDeTipul[SEF_GRUPA]();
			sefGr->setStudent(stud);
			obiecteCreateDinClasa[SEF_GRUPA][ID] = make_pair(sefGr, false);
		}
		else
		{
			sefGr = (SefGrupa*)it->second.first;
		}
		subordonati.push_back(sefGr);
	}
	
	Utility::valideazaSfarsitObiect(istr);
}

list<SefGrupa*> SefAn::getSubordonati()
{
	return subordonati;
}
void SefAn::setSubordonati(list<SefGrupa*> subordonati)
{
	this->subordonati = subordonati;
}

void SefAn::printInfo(ostream& ostr, int deplasament)
{
	list<SefGrupa*>::iterator it;
	Utility::printHeader(ostr, deplasament);
	ostr << "Sef de an pentru studentii:\n";
	for (it = subordonati.begin(); it != subordonati.end(); ++it)
	{
		Utility::printHeader(ostr, deplasament + 1);
		ostr << (*it)->getStudent()->getID() << '\n' ;
		(*it)->printInfo(ostr, deplasament + 1);
	}
}

extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
extern map<string, string> tipulTipului;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;


namespace
{
	Serializabil * creareSefAn()
	{
		return new SefAn;
	}
	CreareObiect x = (creeazaObiectDeTipul["SefAn"] = creareSefAn);
	string y = (tipulTipului["SefAn"] = "SefAn");
	map<int, pair<Serializabil*, bool>> z = obiecteCreateDinClasa["SefAn"];
}