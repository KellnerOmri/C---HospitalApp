
#ifndef _Patient
#define _Patient
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
#include <string>

using namespace std;

class Patient
{
protected:
	char* nameOfPatient;
	bool cough;
	double BodyHeat;
	int DaysGoneWithSymptoms;
	Date dateOfPatient;

public:
static int NumOfSoulMachinesActive;	
	

//constractors
	Patient(char* name);
	Patient(Date &date, bool Cough, double heat, int Dgws, char* name);//constractor with 5 argument
	Patient(const Patient& other);//copy constractor	

//operators
	const Patient& operator=(const Patient& other);//operator=
	friend ostream& operator<<(ostream& out, Patient& D);//operator <<
	bool operator ==(const Patient &o)const;//operator == return true if the patient is the same patient
	const Patient& operator +=(const int num) { DaysGoneWithSymptoms += num; return *this; }//operator +=

//metods
	int calculateTheAgeYear();//calculate the age of the patient (years);
	virtual void const show() = 0;// pure virtual function
	virtual int patientSituation() = 0;// pure virtual function

//set	
	void setDateOfPatient(Date D);
	void setDaysGoneWithSymptoms(int day);
	void setcough(bool cough);
	void setBodyHeat(double heat);
	void setnameOfPatient(char* nameOfPatient);
//get
	char* getnameOfPatient()const { return nameOfPatient; }
	Date getDateOfPatient()const { return dateOfPatient; }
	bool getcough() const { return cough; }
	double getBodyHeat() const { return BodyHeat; }
	int getDaysGoneWithSymptoms() const { return DaysGoneWithSymptoms; }
	virtual ~Patient();//virtual destructor

};
#endif 

