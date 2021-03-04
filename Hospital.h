#ifndef _Hospital
#define _Hospital
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include "MeaslesPatient.h"
#include "CoronaPatient.h"
#define NumOfHospital 4
#define MaxOFPatientInHospital 10
using namespace std;

class Hospital
{
private:

	char* nameOfHospital;
	Patient** ArrOfPatient;//this is array of all the patients in the hospital,every pointer in array - pointer to patient - Corona or Measles 
	int MaxPatientinHospital;
	int NumOfPatientInHospital;

public :
 
//constractors
	Hospital(char* name);//constractor with 1 argument
	Hospital(char* name,int maxNumP);//constractor with 2 arguments
	Hospital(const Hospital& other);//copy constractor
	
	//operator
	const Hospital& operator=(const Hospital& other);//opertor =
	friend ostream& operator<<(ostream& out, Hospital& D);//operator <<
	bool operator ==(const Hospital &o)const;//operator == return if the Hospital name,number of patient and max number of patient are the same
	bool operator <(const Hospital &o)const;//operator <  //return true if this hospital has more patient than other 
	//metods
	void const showMeslesPatient();
	void const showCoronaPatient();
	void addPatient(const Patient * ptrToPatient);
	void deletePatient();
	void const show();
	void DeleteAllPatient();
	char*  getnameOfHospital()const { return nameOfHospital; }
	void setnameOfHospital(char* nameOfPatient);
	~Hospital();//destructor
	
};
#endif

