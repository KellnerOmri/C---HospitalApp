#ifndef _MeaslesPatient
#define _MeaslesPatient
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"

class MeaslesPatient : public Patient
{
private:
	bool HashappenedBefore; 
	char* symptoms;

public:
	
//constractors
	MeaslesPatient(char* nameOfPatient, Date &dateOfPatient, double Heat, int Dgws, bool HashappenedBefore, char* symptoms);
	MeaslesPatient(char* nameOfPatient, Date &dateOfPatient, double Heat, int Dgws, bool Cough,  bool HashappenedBefore, char* symptoms);
	MeaslesPatient(const MeaslesPatient& other);//copy constractor

//operators
	const MeaslesPatient& operator ^(const bool num) { this->HashappenedBefore = num; return *this; }//operator ^
	const MeaslesPatient& operator +=(const int num) { DaysGoneWithSymptoms += num; return *this; }//operator +=
	const MeaslesPatient& operator=(const MeaslesPatient& other);//operator=
	friend ostream& operator<<(ostream& out, MeaslesPatient& D);//operator <<
	bool operator ==(const MeaslesPatient &o)const;//operator == return true if the CoronaPatient is the same CoronaPatient

//metods
	//set
	void setHashappenedBefore(bool B);
	void setsymptoms(char* symptoms);

	//get
	bool getHashappenedBefore() const { return HashappenedBefore; }
	char* getsymptoms()const { return symptoms; }

	virtual void const show() ;//show the detals of MeaslesPatient,operator << use this function
	virtual int patientSituation();//calculate the patient situation (between 1-easy --->>> 10 seriuse)	
	~MeaslesPatient();//destructor
};

#endif