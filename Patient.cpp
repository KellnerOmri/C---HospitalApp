#include "Patient.h"
#define Year 2020;

 int Patient::NumOfSoulMachinesActive=0;// static parameter , count the num of soul mechines that active for this moment

Patient::Patient(char* name)// constractor with 1 argument
{
	this->dateOfPatient = Date();
	this->BodyHeat = 37.0;
	this->cough = false;
	this->DaysGoneWithSymptoms = 0;
	this->nameOfPatient = new char[strlen(name) + 1];
	strcpy_s(this->nameOfPatient, strlen(name) + 1, name);
	
}

Patient::Patient(Date &date , bool Cough, double heat, int Dgws,char* name):dateOfPatient(date)//constractor with 5 arguments
{
	this->BodyHeat = heat;
	this->cough = Cough;
	this->DaysGoneWithSymptoms = Dgws;
	this->nameOfPatient = new char[strlen(name) + 1];
	strcpy_s(this->nameOfPatient, strlen(name) + 1, name);
}



Patient::Patient(const Patient & other) :dateOfPatient(other.dateOfPatient)//copy constractor
{
	nameOfPatient = NULL;
	*this = other;
}

Patient::~Patient()//destructor
{
	delete[] nameOfPatient;
}

const Patient & Patient::operator=(const Patient& other)//operator =
{
	if (this != &other)
	{
		delete[] nameOfPatient;
		this->dateOfPatient = other.dateOfPatient;
		this->cough = other.cough;
		this->DaysGoneWithSymptoms = other.DaysGoneWithSymptoms;
		this->BodyHeat = other.BodyHeat;
		this->nameOfPatient = new char[strlen(other.nameOfPatient) + 1];
		strcpy_s(this->nameOfPatient, strlen(other.nameOfPatient) + 1, other.nameOfPatient);	
	}
	return *this;
}

bool Patient::operator==(const Patient & o) const //operator == ,return true if the patient is the same patient
{
	return((this->dateOfPatient == o.dateOfPatient) && (this->BodyHeat == o.BodyHeat) && (this->cough == o.cough) && (this->DaysGoneWithSymptoms == o.DaysGoneWithSymptoms) && (!strcmp(this->nameOfPatient,o.nameOfPatient)));
}



ostream & operator<<(ostream & out, Patient & D)
{
	string ans = (D.cough > 0) ? "yes" : "no";
	out << typeid(D).name() + 6 << ":" << endl << "name of patient: "<< D.nameOfPatient << endl << "date of birth : " << D.dateOfPatient <<endl<<"Age: "<<D.calculateTheAgeYear()<< endl << "cough : " <<ans<< endl << "heat body: " << D.BodyHeat;
	out << endl << "days gone with symptoms :" << D.DaysGoneWithSymptoms<<endl ;
	D.show();//use virtual function;
	return out;
}

int Patient::calculateTheAgeYear()//return the age of the patient
{
	
	int ThisYear = Year;//Year is define for generic project (2020 today)
	return (ThisYear - this->dateOfPatient.getyear());//need this parameter for save the Year from define

}
void Patient::setDateOfPatient(Date D)
{
	this->dateOfPatient = D;
	
}

void Patient::setDaysGoneWithSymptoms(int day)
{
	this->DaysGoneWithSymptoms = day;
}

void Patient::setcough(bool cough)
{
	this->cough = cough;
}

void Patient::setBodyHeat(double heat)
{
	this->BodyHeat = heat;
}

void Patient::setnameOfPatient(char * nameOfPatient)
{
	this->nameOfPatient = new char[strlen(nameOfPatient) + 1];
	strcpy_s(this->nameOfPatient, strlen(nameOfPatient) + 1, nameOfPatient);
}


