#include"Manager.h"
#include"Integralist.h"
#include"Restantier.h"
#include"SefAn.h"
#include"SefGrupa.h"
#include"Responsabil.h"
#include<fstream>
#include<list>
using namespace std;

int main()
{
	/*Integralist x;
	x.setAn(1);
	x.setBursa(100);
	x.setGrupa("A5");
	x.setID(1000);
	x.setMedia(9.99);
	x.setNume("Ciprian");
	x.setPrenume("Cip");
	fstream fstr("Shafie.txt");
	x.serializeaza(fstr);
	fstr.close();
	fstr.open("Shafie.txt");
	string y;
	fstr >> y;
	fstr >> y;
	x.deserializeaza(fstr,1);
	x.printInfo(cout);
	*/

	Restantier x;
	x.setAn(1);
	x.setGrupa("A5");
	x.setID(1000);
	x.setNume("Ciprian");
	x.setPrenume("Cip");
	x.adaugaObiect("Mate");
	x.adaugaObiect("Logica");
	fstream fstr("Shafie.txt");
	/*x.serializeaza(fstr);
	fstr.close();
	fstr.open("Shafie.txt");
	string y;
	fstr >> y;
	fstr >> y;
	x.deserializeaza(fstr, 1);
	x.printInfo(cout);
	*/

	
	//SefGrupa sefgrupa;
//	sefgrupa.setStudent(&x);
	//sefgrupa.getStudent()->printInfo(cout);
//	list<Student*> subordonati;
//	subordonati.push_back(&x);
//	sefgrupa.setSubordonati(subordonati);

	/*sefgrupa.serializeaza(fstr);
	fstr.close();
	fstr.open("Shafie.txt");
	string y;
	fstr >> y;
	fstr >> y;
	sefgrupa.deserializeaza(fstr,2);
	sefgrupa.getStudent()->printInfo(fstr);
	*/

	/*SefAn sefan;
	sefan.setStudent(&x);
	sefan.getStudent()->printInfo(cout);
	list<SefGrupa*> subordonati2;
	subordonati2.push_back(&sefgrupa);
	sefan.setSubordonati(subordonati2);

	sefan.serializeaza(fstr);
	fstr.close();
	fstr.open("Shafie.txt");
	string y;
	fstr >> y;
	fstr >> y;
	sefan.deserializeaza(fstr, 1000);
	sefan.getStudent()->printInfo(cout);
	*/
	
	/*
	Responsabil responsabil;
	responsabil.setStudent(&x);
	responsabil.getStudent()->printInfo(cout);
	list<Student*> subordonati;
	subordonati.push_back(&x);
	responsabil.setSubordonati(subordonati);

	responsabil.serializeaza(fstr);
	fstr.close();
	fstr.open("Shafie.txt");
	string y;
	fstr >> y;
	fstr >> y;
	responsabil.deserializeaza(fstr,2);
	responsabil.getStudent()->printInfo(cout);
	*/

	Manager manager;
	manager.deserializeazaFisier(fstr);
	//manager.serializeazaFisier(cout);
	manager.printInfo(4);
	//manager.stergeStudent(1001);
	//manager.printInfo(1000);
	//manager.serializeazaFisier(cout); 
	return 0;
}