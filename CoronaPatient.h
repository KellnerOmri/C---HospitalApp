#ifndef _CoronaPatient
#define _CoronaPatient
#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "Patient.h"
class CoronaPatient : public Patient
{
private:
	bool BackgroundDiseases;
	char* symptoms;	
public:
	
//constractors
	CoronaPatient(char* nameOfPatient, Date &dateOfPatient, double Heat,int Dgws,bool backgroundDiseases, char* symptoms);//constractor with 6 args
	CoronaPatient(char* nameOfPatient, Date &dateOfPatient, double Heat,int Dgws,bool Cough, bool backgroundDiseases, char* symptoms);//constractor with 7 args
	CoronaPatient(const CoronaPatient& other);//copy constractor	

//operators
	const CoronaPatient& operator ^(const bool num) { this->BackgroundDiseases = num; return *this; }//operator ^
	const CoronaPatient& operator=(const CoronaPatient& other);//operator=
	friend ostream& operator<<(ostream& out, CoronaPatient& D);//operator <<
	bool operator ==(const CoronaPatient &o)const;//operator == return if the CoronaPatient is the same CoronaPatient 

//metods
	//set
	void setBackgroundDiseases(bool B);
	void setsymptoms(char* symptoms);
	//get
	bool getBackgroundDiseases() const { return BackgroundDiseases; }
	char* getsymptoms()const { return symptoms; }

	virtual void const show();//show the detals of CoronaClass
	virtual int patientSituation();//calculate the patient situation (between 1-easy --->>> 10 seriuse)	//*
	int DaysuUtilHealthy();//return the number of days that the patient should be stay in the hospital(exist just in Corona class)

		~CoronaPatient();//destructor

};

#endif