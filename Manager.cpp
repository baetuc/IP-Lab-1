#include "Manager.h"
#include"Serializabil.h"
#include<map>
#include<list>
#include"Utility.h"
#include"Integralist.h"
#include"Restantier.h"
#include"Responsabil.h"

using namespace std;

extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
extern map<string, string> tipulTipului;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;

void Manager::serializeazaFisier(ostream& ostr) {
	map<string, map<int, pair<Serializabil*, bool>>>::iterator it;
	for (it = obiecteCreateDinClasa.begin(); it != obiecteCreateDinClasa.end(); ++it) {
		map<int, pair<Serializabil*, bool>> obiecteCreate = it->second;
		map<int, pair<Serializabil*, bool>>::iterator it2;
		for (it2 = obiecteCreate.begin(); it2 != obiecteCreate.end(); ++it2) {
			it2->second.first->serializeaza(ostr);
		}
	}
}

void Manager::adaugaStudenti(istream& istr) {
	// tinem o copie a managerului initial...
	map<string, map<int, pair<Serializabil*, bool>>> copieObiecteCreateDinClasa = obiecteCreateDinClasa;

	try
	{
		while (true) {
			string tip = Utility::valideazaString(istr);
			int ID = (int)Utility::valideazaNumar(istr);
			// verificam daca obiectul de tipul "tip", cu id-ul ID exista deja
			if (obiecteCreateDinClasa.find(tipulTipului[tip]) != obiecteCreateDinClasa.end()) {
				// exista tipul "tip"
				Serializabil* obiect;
				if (obiecteCreateDinClasa[tipulTipului[tip]].find(ID) != obiecteCreateDinClasa[tipulTipului[tip]].end()) {
					if (obiecteCreateDinClasa[tipulTipului[tip]][ID].second == true) {
						// daca a mai fost o data initializat complet, se arunca exceptie
						throw("Eroare la deserializare fisier: object repeated.");
					}
					// altfel, inseamna ca a fost initializat partial inainte
					obiect = obiecteCreateDinClasa[tipulTipului[tip]][ID].first;
				}
				else {
					// nu exista obiectul de tipul "tip" si id-ul ID, deci il cream
					obiect = creeazaObiectDeTipul[tip]();
					//obiect->setID(ID);
					obiecteCreateDinClasa[tipulTipului[tip]][ID] = make_pair(obiect, false);
				}
				// acum exista obiectul de tipul "tip" cu id-ul ID
				obiect->deserializeaza(istr, ID);
				// setam faptul ca am construit obiectul prin setarea flagului cu true
				obiecteCreateDinClasa[tipulTipului[tip]][ID].second = true;
			}
			else {
				throw("Eroare la deserializare fisier: unknown type.");
			}
			if (istr.eof()) {
				break;
			}
		}
		// Verificam daca exista vreun tip de obiect pentru care exista un ID 
		// cu flagul de initializare completa setat pe false.

		map<string, map<int, pair<Serializabil*, bool>>>::iterator it;
		for (it = obiecteCreateDinClasa.begin(); it != obiecteCreateDinClasa.end(); ++it) {
			map<int, pair<Serializabil*, bool>> obiecteCreate = it->second;
			map<int, pair<Serializabil*, bool>>::iterator it2;
			for (it2 = obiecteCreate.begin(); it2 != obiecteCreate.end(); ++it2) {
				if (it2->second.second == false) {
					// exista un obiect neinitializat complet
					throw("Eroare la deserializare fisier: found uncomplete object.");
				}
			}
		}
		// Verificam daca exista un singur responsabil cu studentii

		if (obiecteCreateDinClasa["Responsabil"].size() != 1) {
			throw ("Eroare la deserializare fisier: not exactly one responsible for students.");
		}
		
		list<Student*> subordonati;
		map<int, pair<Serializabil*, bool>>::iterator it2;
		for (it2 = obiecteCreateDinClasa["Student"].begin(); it2 != obiecteCreateDinClasa["Student"].end(); ++it2)
		{
			subordonati.push_back((Student*)it2->second.first);
		}
		((Responsabil*)obiecteCreateDinClasa["Responsabil"].begin()->second.first)->setSubordonati(subordonati);
	}
	catch (const char* mesaj)
	{
		cout << mesaj << '\n';
		obiecteCreateDinClasa = copieObiecteCreateDinClasa;
	}
}

void Manager::deserializeazaFisier(istream& istr) {
	map<string, map<int, pair<Serializabil*, bool>>>::iterator it;
	for (it = obiecteCreateDinClasa.begin(); it != obiecteCreateDinClasa.end(); ++it)
	{
		it->second.clear();
	}
	adaugaStudenti(istr);
}

void Manager::stergeStudent(int ID) {
	map<string, map<int, pair<Serializabil*, bool>>> copieObiecteCreateDinClasa = obiecteCreateDinClasa;
	try {
		bool ok = false;
		map<string, map<int, pair<Serializabil*, bool>>>::iterator it;
		for (it = obiecteCreateDinClasa.begin(); it != obiecteCreateDinClasa.end(); ++it) {
			map<int, pair<Serializabil*, bool>> &obiecteCreate = it->second;
			map<int, pair<Serializabil*, bool>>::iterator it2 = obiecteCreate.find(ID);
			if (it2 != obiecteCreate.end()) 
			{
				ok = true;
				obiecteCreate.erase(it2);
			}
		}
		if (ok == false)
		{
			throw "Eroare la stergeStudent: student with specified ID doesn't exist.";
		}

		if (obiecteCreateDinClasa["Responsabil"].size() != 1) {
			throw ("Eroare la deserializare fisier: cannot remove responsible.");
		}

		list<Student*> subordonati;
		map<int, pair<Serializabil*, bool>>::iterator it2;
		for (it2 = obiecteCreateDinClasa["Student"].begin(); it2 != obiecteCreateDinClasa["Student"].end(); ++it2)
		{
			subordonati.push_back((Student*)it2->second.first);
		}
		((Responsabil*)obiecteCreateDinClasa["Responsabil"].begin()->second.first)->setSubordonati(subordonati);
	}
	catch (const char* mesaj)
	{
		cout << mesaj << '\n';
		obiecteCreateDinClasa = copieObiecteCreateDinClasa;
	}
}

void Manager::printInfo(int ID) {
	try {
		if (obiecteCreateDinClasa["Student"].find(ID) != obiecteCreateDinClasa["Student"].end())
		{
			((Student*)(obiecteCreateDinClasa["Student"][ID].first))->printInfo(cout,0);
			map<string, map<int, pair<Serializabil*, bool>>>::iterator it;
			for (it = obiecteCreateDinClasa.begin(); it!=obiecteCreateDinClasa.end(); ++it)
			{
				if ((*it).first != "Student")
				{
					if ((*it).second.find(ID) != (*it).second.end())
					{
						(*it).second[ID].first->printInfo(cout, 0);
					}
				}
			}
		}
		else
		{
			throw "Eroare la printInfo: unfound student with specified ID";
		}
	}
	catch (const char* mesaj)
	{
		cout << mesaj << '\n';
	}
}
