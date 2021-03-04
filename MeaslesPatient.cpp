#include "MeaslesPatient.h"



MeaslesPatient::MeaslesPatient(char* nameofpatient, Date &dateOfPatient, double Heat, int Dgws, bool hashappend, char* symptoms) :Patient(dateOfPatient, false, Heat, Dgws, nameofpatient)
{
	this->symptoms = new char[strlen(symptoms) + 1];
	strcpy_s(this->symptoms, strlen(symptoms) + 1, symptoms);
	
	this->HashappenedBefore = hashappend;

}

MeaslesPatient::MeaslesPatient(char* nameOfPatient, Date &dateOfPatient, double Heat, int Dgws, bool Cough, bool HashappenedBefore, char* symptoms):Patient(dateOfPatient, Cough, Heat, Dgws, nameOfPatient)
{
	this->symptoms = new char[strlen(symptoms) + 1];
	strcpy_s(this->symptoms, strlen(symptoms) + 1, symptoms);
	
	this->HashappenedBefore = HashappenedBefore;
}

MeaslesPatient::MeaslesPatient(const MeaslesPatient & other) :Patient(other)            //copy constractor
{
	symptoms = NULL;
	*this = other;
}

void const MeaslesPatient::show()
{
	string ans = (this->HashappenedBefore > 0) ? "yes" : "no";
	cout << "Symptoms : " << this->symptoms << endl << "Has happened in the past  :" << ans << endl <<"Patient status between 1-easy and 10-serious is: " << this->patientSituation() << endl;
}



void MeaslesPatient::setHashappenedBefore(bool B)
{
	this->HashappenedBefore = B;
}

void MeaslesPatient::setsymptoms(char * symptoms)
{
	this->symptoms = new char[strlen(symptoms) + 1];
	strcpy_s(this->symptoms, strlen(symptoms) + 1, symptoms);
}


int MeaslesPatient::patientSituation()//calculate the patient situation ,1 for easy,10 for hard
{
	int patientSituationNum = 0;
	if (this->BodyHeat > 38)//if the patient has more than 38 degrees Celsius- add 1 point to the scale
		patientSituationNum++;

	if (this->cough)//if the Patient is cough- add 1 point to the scale 
		patientSituationNum++;


	if (this->HashappenedBefore)
		patientSituationNum = patientSituationNum - 5;//A major factor in recovery is who has been ill in the past

	if(this->DaysGoneWithSymptoms>10)//mean that pass 10 day without treatment
		patientSituationNum++;
	
	patientSituationNum = patientSituationNum + this->calculateTheAgeYear() / 10;//every 10 years old=1 point to scale 
	
	if (patientSituationNum > 10)
		return 10;
	if (patientSituationNum < 0)
		return 0;

	return patientSituationNum;
}


const MeaslesPatient & MeaslesPatient::operator=(const MeaslesPatient & other)//operator =
{

	if (this != &other)
	{
		delete[] symptoms;
		Patient::operator=(other);//use Patient operator = 
		this->symptoms = new char[strlen(other.symptoms) + 1];
		strcpy_s(this->symptoms, strlen(other.symptoms) + 1, other.symptoms);
		this->HashappenedBefore = other.HashappenedBefore;
	
	}
	return *this;
}

bool MeaslesPatient::operator==(const MeaslesPatient & o) const //operator == return true if the CoronaPatient is the same CoronaPatient
{
	return (Patient::operator==(o)  && !strcmp(this->symptoms ,o.symptoms)&&(this->HashappenedBefore==o.HashappenedBefore));
}

MeaslesPatient::~MeaslesPatient()//destructor
{
	delete[] symptoms;
}

ostream & operator<<(ostream & out, MeaslesPatient & C)
{
	Patient &ptr = C;
	out << ptr << endl;//use Patient operator << that use show metod of MeaslesPatient
	return out;
}
 