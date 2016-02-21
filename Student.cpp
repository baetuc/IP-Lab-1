#pragma once
#include "Student.h"

using namespace std;

int Student::getID() {
	return ID;
}

string Student::getNume() {
	return nume;
}

string Student::getPrenume() {
	return prenume;
}

int Student::getAn() {
	return an;
}

string Student::getGrupa() {
	return grupa;
}

void Student::setID(int ID) {
	this->ID = ID;
}

void Student::setNume(string nume) {
	this->nume = nume;
}

void Student::setPrenume(string prenume) {
	this->prenume = prenume;
}

void Student::setAn(int an) {
	this->an = an;
}

void Student::setGrupa(string grupa) {
	this->grupa = grupa;
}

Student::~Student() {}

extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;

namespace
{
	map<int, pair<Serializabil*, bool>> x = obiecteCreateDinClasa["Student"];
}