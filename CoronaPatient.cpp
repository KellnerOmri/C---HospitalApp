#include "CoronaPatient.h"


CoronaPatient::CoronaPatient(char* nameofpatient, Date &dateOfPatient, double Heat, int Dgws, bool backgroundDiseases, char* symptoms) :Patient(dateOfPatient, false, Heat, Dgws, nameofpatient)
{
	this->symptoms = new char[strlen(symptoms) + 1];
	strcpy_s(this->symptoms, strlen(symptoms) + 1, symptoms);
	this->BackgroundDiseases = backgroundDiseases;
	
}

CoronaPatient::CoronaPatient(char* nameofpatient, Date &dateOfPatient, double Heat, int Dgws,bool Cough, bool backgroundDiseases, char* symptoms) :Patient(dateOfPatient,Cough,Heat,Dgws, nameofpatient)
{
	this->symptoms = new char[strlen(symptoms) + 1];
	strcpy_s(this->symptoms, strlen(symptoms) + 1, symptoms);
	this->BackgroundDiseases = backgroundDiseases;
}

CoronaPatient::CoronaPatient(const CoronaPatient & other):Patient(other)            //copy constractor
{
	symptoms = NULL;
	*this = other;
}

void const CoronaPatient::show()
{
	string ans = (this->BackgroundDiseases > 0) ? "yes" : "no";
	cout << "Symptoms : " << this->symptoms << endl << "Has Back ground Diseases :" << ans << endl<< "Patient status between 1-easy and 10-serious is: "<<this->patientSituation()<<endl;
	cout << "Days that the patient should be stay in the hospital: " << this->DaysuUtilHealthy() << endl;
}



void CoronaPatient::setBackgroundDiseases(bool B)
{
	this->BackgroundDiseases = B;
}

void CoronaPatient::setsymptoms(char * symptoms)
{
	this->symptoms = new char[strlen(symptoms) + 1];
	strcpy_s(this->symptoms, strlen(symptoms) + 1, symptoms);
}



int CoronaPatient::patientSituation()//calculate the patient situation ,1 for easy,10 for hard
{
	int patientSituationNum = 0;
	if (this->BodyHeat>38)//if the patient has more than 38 degrees Celsius- add 1 point to the scale
		patientSituationNum++;
	if (this->cough)//if the Patient is cough- add 1 point to the scale 
		patientSituationNum++;
	if (this->DaysGoneWithSymptoms > 10)//mean that pass 10 day without treatment
		patientSituationNum++;
	if (this->BackgroundDiseases)//the patient has back ground diseases like heart diseases,Pneumonia..
		patientSituationNum = patientSituationNum + 2;

		patientSituationNum = patientSituationNum + this->calculateTheAgeYear() / 10;//every 10 years old=1 point to scale,Patient with 7+,use soul mechine.(update outside the class)
		
		if (patientSituationNum > 10)
			return 10;

	return patientSituationNum;
}

const CoronaPatient & CoronaPatient::operator=(const CoronaPatient & other)//operator =
{
	
	if (this != &other)
	{
		delete[] symptoms;
		Patient::operator=(other);//use Patient operator =
	    this->symptoms = new char[strlen(other.symptoms) + 1];
		strcpy_s(this->symptoms, strlen(other.symptoms) + 1, other.symptoms);
		this->BackgroundDiseases = other.BackgroundDiseases;

	}
	return *this;
}

bool CoronaPatient::operator==(const CoronaPatient & o) const//operator == return if the CoronaPatient is the same CoronaPatient 
{
	return (Patient::operator==(o) && !strcmp(this->symptoms,o.symptoms)&&(this->BackgroundDiseases==o.BackgroundDiseases));
}

int CoronaPatient::DaysuUtilHealthy()//return the number of days that the patient should be stay in the hospital
{
	int num = this->patientSituation()*10;//the patient should be stay in the hospital for 10 days each level of patient situation between 1-10
	
	if (this->BodyHeat > 41)//serious situation, stay one more day.
		num++;
	num = num - DaysGoneWithSymptoms;//DaysGoneWithSymptoms its days that include in the "day that the patient should be stay in the hospital
	if (num <= 0)
		num = 1;
	return num;
}

CoronaPatient::~CoronaPatient()//destructor
{
	delete[] symptoms;
}

ostream & operator<<(ostream & out, CoronaPatient & C)
{
	 Patient &ptr = C;
	 out << ptr << endl;//use Patient operator << that use show metod of CoronaPatinet
	return out;
}

