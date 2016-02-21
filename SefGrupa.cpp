#include "SefGrupa.h"
#include"Utility.h"
#include<utility>

using namespace std;

extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;

list<Student*> SefGrupa::getSubordonati() {
	return subordonati;
}

void SefGrupa::setSubordonati(list<Student*> subordonati) {
	this->subordonati = subordonati;
}

void SefGrupa::serializeaza(ostream& ostr) {
	ostr << "\nSefGrupa\n";
	ostr << stud->getID() << '\n';
	ostr << stud->getTip() << '\n';
	ostr << subordonati.size() << '\n';
	for (list<Student*>::iterator it = subordonati.begin(); it != subordonati.end(); ++it) {
		ostr << (*it)->getTip() << '\n';
		ostr << (*it)->getID() << '\n';
	}
	ostr << "#";
}

void SefGrupa::deserializeaza(istream& istr, int ID) {
	creareStudent(istr, ID);
	map<int, pair<Serializabil*, bool>>& studentiCreati = obiecteCreateDinClasa["Student"];
	int numarSubordonati = (int)Utility::valideazaNumar(istr);
	for (int i = 0; i < numarSubordonati; ++i) {
		string tip = Utility::valideazaString(istr);
		int IDSubordonat = (int)Utility::valideazaNumar(istr);
		map<int, pair<Serializabil*, bool>>::iterator it = studentiCreati.find(IDSubordonat);
		if (it == studentiCreati.end()) {
			// nu exista studentul, il cream si lasam goale campurile din interiorul sau.
			Student* student = (Student*) creeazaObiectDeTipul[tip]();
			subordonati.push_back(student);
			student->setID(IDSubordonat);
			studentiCreati[IDSubordonat] = make_pair((Serializabil*)student, false);
		}
		else {
			// studentul este deja creat
			Student* student = (Student*) studentiCreati[IDSubordonat].first;
			subordonati.push_back(student);
		}
	}
	Utility::valideazaSfarsitObiect(istr);
}




extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
extern map<string, string> tipulTipului;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;


namespace
{
	Serializabil * creareSefGrupa()
	{
		return new SefGrupa;
	}
	CreareObiect x = (creeazaObiectDeTipul["SefGrupa"] = creareSefGrupa);
	string y = (tipulTipului["SefGrupa"] = "SefGrupa");
	map<int, pair<Serializabil*, bool>> z = obiecteCreateDinClasa["SefGrupa"];
}