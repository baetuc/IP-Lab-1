#include"Manager.h"
#include"Integralist.h"
#include"Restantier.h"
#include"SefAn.h"
#include"SefGrupa.h"
#include"Responsabil.h"
#include<fstream>
#include<cstdio>
#include<list>
#include"Utility.h"
using namespace std;

int main() {
	cout << "Introduceti:\n\t 1 <nume_fisier> pentru serializare in fisier\n"
		"\t 2 <nume_fisier> pentru deserializare din fisier\n"
		"\t 3 <nume_fisier> pentru adaugare studenti din fisier\n"
		//"\t 4 <ID> pentru stergerea studentului specificat\n"
		"\t 4 <ID> pentru afisare de informatii despre studentul specificat\n"
		"\t 0 pentru iesire din aplicatie\n";
	
	int optiune;
	Manager manager;
	try {
		optiune = (int) Utility::valideazaNumar(cin);
	}
	catch (const char* ) {
		cout << "Ati introdus un text cand trebuia un numar. Invatati sa scrieti!\n";
		exit(1);
	}
	while (optiune)
	{
		switch (optiune)
		{

		case 1:
		{
			string fisier;
			cin >> fisier;
			ofstream f(fisier);
			manager.serializeazaFisier(f);
			f.close();
			cout << "Comanda realizata\n";
			break;
		}

		case 2:
		{
			string fisier;
			cin >> fisier;
			ifstream f(fisier);
			manager.deserializeazaFisier(f);
			f.close();
			cout << "Comanda realizata\n";
			break;
		}

		case 3:
		{
			string fisier;
			cin >> fisier;
			ifstream f(fisier);
			manager.adaugaStudenti(f);
			f.close();
			cout << "Comanda realizata\n";
			break;
		}
		/*
		case 4:
		{
			int ID;
			try {
				ID = (int) Utility::valideazaNumar(cin);
			}
			catch (const char*) {
				cout << "Ati introdus un text cand trebuia un numar. Invatati sa scrieti!\n";
				exit(1);
			}
			manager.stergeStudent(ID);
			cout << "Comanda realizata\n";
			break;
		}
		*/

		case 4:
		{
			int ID;
			try {
				ID = (int) Utility::valideazaNumar(cin);
			}
			catch (const char* ) {
				cout << "Ati introdus un text cand trebuia un numar. Invatati sa scrieti!\n";
				exit(1);
			}
			manager.printInfo(ID);
			cout << "Comanda realizata\n";
			break;
		}

		default:
			cout << "Optiune invalida. Introduceti alta.\n";
		}

		cout << "\nIntroduceti optiunea:\n";

		try {
			optiune = (int) Utility::valideazaNumar(cin);
		}
		catch (const char* ) {
			cout << "Ati introdus un text cand trebuia un numar. Invatati sa scrieti!\n";
			exit(1);
		}
	}

	return 0;
}