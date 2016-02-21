#include"Superior.h"
#include"Utility.h"

extern map<string, map<int, pair<Serializabil*, bool>>> obiecteCreateDinClasa;
typedef Serializabil* (*CreareObiect)();
extern map<string, CreareObiect> creeazaObiectDeTipul;

void Superior::setStudent(Student * stud) {
	this->stud = stud;
}

Student* Superior::getStudent() {
	return stud;
}

void Superior::creareStudent(istream &istr, int ID)
{
	string tip = Utility::valideazaString(istr);
	if (obiecteCreateDinClasa["Student"].find(ID) == obiecteCreateDinClasa["Student"].end())
	{
		Student* student = (Student*)creeazaObiectDeTipul[tip]();
		student->setID(ID);
		stud = student;
		obiecteCreateDinClasa["Student"][ID] = make_pair(student, false);
	}
	else
	{
		stud = (Student*)obiecteCreateDinClasa["Student"][ID].first;
	}
}

