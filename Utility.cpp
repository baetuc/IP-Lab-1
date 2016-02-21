#pragma once
#include"Utility.h"

double Utility::valideazaNumar(istream &istr) {
	double numar;
	char aux;
	//verificam daca atunci cand ne asteptam sa citim un numar, in fisier chiar este un numar
	aux = istr.peek();
	while (strchr(" \n\t", aux)) {
		istr.get();
		aux = istr.peek();
	}
	if (strchr("0123456789", aux) == NULL) {
		throw "Eroare la deserializarea din fisier: number expected.";
	}

	istr >> numar;

	aux = istr.get();
	if (strchr(" \n\t", aux) == NULL) {
		throw "Eroare la deserializarea din fisier: blank space expected.";
	}

	return numar;
}
string Utility::valideazaString(istream &istr) {
	string sir;
	istr >> sir;
	if (strchr(sir.c_str(), '#')) {
		throw "Eroare la deserializarea din fisier: '#' found elsewhere.";
	}

	return sir;
}

void Utility::valideazaSfarsitObiect(istream &istr) {
	string sir;
	istr >> sir;
	if (sir != "#") {
		throw "Eroare la deserializarea din fisier: '#' missing.";
	}
}

void Utility::printHeader(ostream & ostr, int deplasament)
{
	ostr << "| ";
	for (int i = 0; i < deplasament; ++i)
	{
		ostr << "\t| ";
	}
}
