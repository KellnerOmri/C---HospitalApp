#include "Hospital.h"

Hospital::Hospital(char * name)//constractor with 1 arg
{
	this->NumOfPatientInHospital = 0;
	this->nameOfHospital = new char[strlen(name) + 1];
	strcpy(this->nameOfHospital, name);
	this->MaxPatientinHospital = MaxOFPatientInHospital;
	ArrOfPatient = new Patient*[MaxOFPatientInHospital];
	for (int i = 0; i < MaxOFPatientInHospital; i++)
	{
		ArrOfPatient[i] = NULL;
	}
}

Hospital::Hospital(char * name, int maxNumP)//constractor with 2 args
{
	
	this->NumOfPatientInHospital = 0;
	this->nameOfHospital = new char[strlen(name) + 1];
	strcpy(this->nameOfHospital, name);
	this->MaxPatientinHospital = maxNumP;
	ArrOfPatient = new Patient*[maxNumP];
	for (int i = 0; i < maxNumP; i++)
	{
		ArrOfPatient[i] = NULL;
	}
}

Hospital::Hospital(const Hospital & other)//copy constractor
{
	this->nameOfHospital = NULL;
	for (int i = 0; i < MaxPatientinHospital; i++)
	{
		ArrOfPatient[i] = NULL;
	}
	
	*this = other;
}


const Hospital & Hospital::operator=(const Hospital & other)//operator=
{
	if (this != &other)
	{
		this->MaxPatientinHospital = other.MaxPatientinHospital;
		this->NumOfPatientInHospital = other.NumOfPatientInHospital;
		delete[] ArrOfPatient;
		this->ArrOfPatient = new Patient*[other.MaxPatientinHospital];
		delete[] nameOfHospital;
		this->nameOfHospital = new char[strlen(other.nameOfHospital) + 1];
		strcpy_s(this->nameOfHospital, strlen(other.nameOfHospital) + 1, other.nameOfHospital);
		for (int i = 0; i < MaxPatientinHospital; i++)
		{
			if (other.ArrOfPatient[i] != NULL)
			{


				if (!strcmp(typeid(*other.ArrOfPatient[i]).name(), typeid(CoronaPatient).name()))//cheak witch type op pointer (Corona/Measles)
				{
					ArrOfPatient[i] = new CoronaPatient(*dynamic_cast<const CoronaPatient*>(other.ArrOfPatient[i]));
				}
				else
				{
					ArrOfPatient[i] = new MeaslesPatient(*dynamic_cast<const MeaslesPatient*>(other.ArrOfPatient[i]));
				}
			}
			else
			{
				ArrOfPatient[i] = NULL;
			}
		}

	
		return *this;
	}
}

bool Hospital::operator==(const Hospital & o) const//operator == return if the Hospital name,number of patient and max number of patient are the same
{
	return(this->MaxPatientinHospital == o.MaxPatientinHospital && this->NumOfPatientInHospital == o.NumOfPatientInHospital && !strcmp(this->nameOfHospital,o.nameOfHospital));
}

bool Hospital::operator<(const Hospital & o) const//return true if this hospital has more patient than other 
{
	return(this->NumOfPatientInHospital < o.NumOfPatientInHospital);
}

void const Hospital::showMeslesPatient()
{
	int count = 0;
	for (int i = 0; i < this->NumOfPatientInHospital; i++)
	{
		if (!strcmp(typeid(*ArrOfPatient[i]).name(), typeid(MeaslesPatient).name()))//check the pointer type
		{
			cout << *ArrOfPatient[i]<<endl;
			count++;//count how manny patients are Measles Patient
		}
	}
	if (count == 0)
	{
		cout << "there is no Measles Patient in this hospital" << endl;
	}
}

void const Hospital::showCoronaPatient()
{
	int count = 0;
	for (int i = 0; i < this->NumOfPatientInHospital; i++)
	{
		if (!strcmp(typeid(*ArrOfPatient[i]).name(), typeid(CoronaPatient).name()))//check the pointer type
		{
			cout<< *ArrOfPatient[i]<<endl;
			
			count++;//count how manny patients are Corona Patient
		}
	}
	if (count == 0)
	{
		cout << "there is no Corona Patient in this hospital" << endl;
	}
}


void Hospital::addPatient(const Patient * ptrToPatient)//add the pointer to the array of pointers
{
	int indexPatient = 0;//count the num of Patient
	for (int i = 0; i < this->MaxPatientinHospital; i++)
	{
		if (ArrOfPatient[i] != NULL)
		{
			indexPatient++;
		}
		else
		{
			if (!strcmp(typeid(*ptrToPatient).name(), typeid(CoronaPatient).name()))//check the pointer type
			{
				ArrOfPatient[i] = new CoronaPatient(*dynamic_cast<const CoronaPatient*>(ptrToPatient));
			}
			else
			{
				ArrOfPatient[i] = new MeaslesPatient(*dynamic_cast<const MeaslesPatient*>(ptrToPatient));
			}

			cout << endl<<"The added Pateint:"  << endl;
			cout << *ArrOfPatient[i]<<endl;
	    	NumOfPatientInHospital++;
			if (ArrOfPatient[i]->patientSituation() > 7)
				Patient::NumOfSoulMachinesActive++;//update the static parameter
			return;
		}
	}
	if(indexPatient==this->MaxPatientinHospital)
	cout << "no place for another patient!" << endl;
}

void Hospital::deletePatient()
{
	
	if (NumOfPatientInHospital == 0)
	{
		cout << "Can't delete,Patient does not exist " << endl;
		return;
	}
	
	int IndexInArr;
	cout << "please enter index of patient that you want to remove from the hospital" << endl;
	if (!(cin >> IndexInArr))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');		
		throw("Yoy must enter an index ! \n");
	}
	
	

	if (IndexInArr > this->MaxPatientinHospital || this->ArrOfPatient[IndexInArr] == NULL || IndexInArr < 0)
	{
		cout << "Invalid Patient number" << endl;
	}
	else
	{
		if(ArrOfPatient[IndexInArr]->patientSituation()>7)
           Patient::NumOfSoulMachinesActive--;//update the static parameter
		delete[] ArrOfPatient[IndexInArr];
		this->ArrOfPatient[IndexInArr] = NULL;
		cout <<endl<< "Patient deleted!" << endl;	
		NumOfPatientInHospital--;
		
	}


}

void const Hospital::show()//print the details of hospital
{

	cout << "name of the hospital : " << nameOfHospital << endl << "Patients in hospital :" << NumOfPatientInHospital << endl << "Max patient in hospital : " << MaxPatientinHospital << endl<<"Num Of Soul Machines Active: "<< Patient::NumOfSoulMachinesActive<<endl;

}

void Hospital::DeleteAllPatient()//delete all the patient from the hospital
{
	int i = 0;
	int j = 0;
	if (NumOfPatientInHospital == 0)
	{
		cout << "There is no patient in the hospital" << endl;
		return;
	}
	for (; i< NumOfPatientInHospital;j++)
	{
		if(ArrOfPatient[j]!=NULL)
		{ 
			i++;
     	delete[] ArrOfPatient[j];
		this->ArrOfPatient[j] = NULL;
	    }
	}
	cout << "The hospital clean from patients " << endl;
	Patient::NumOfSoulMachinesActive = 0;//update the static parameter
	NumOfPatientInHospital = 0;
	return;
}

void Hospital::setnameOfHospital(char * nameOfHospital)
{
	this->nameOfHospital = new char[strlen(nameOfHospital) + 1];
	strcpy_s(this->nameOfHospital, strlen(nameOfHospital) + 1, nameOfHospital);
}

Hospital::~Hospital()//destructor
{
	delete[] nameOfHospital;
	for (int i = 0; i < NumOfPatientInHospital; i++)
	{
		if (ArrOfPatient[i] != NULL)
		{
			delete ArrOfPatient[i];
		}
	}
	delete ArrOfPatient;
}


ostream & operator<<(ostream & out, Hospital & D)
{
	out << "hospital : " << D.nameOfHospital << endl<< "Patients in hospital :" << D.NumOfPatientInHospital <<endl<< "Max patient in the hospital :" << D.MaxPatientinHospital << endl<< "Num Of Soul Machines Active in Israel: " << Patient::NumOfSoulMachinesActive<<endl<<endl;
	if (D.ArrOfPatient == NULL)
	{
		cout << "no patient in the hospital" << endl;
	}
	for (int i = 0; i < D.MaxPatientinHospital; i++)
	{
		if (D.ArrOfPatient[i] == NULL)
		{

			continue;//cant print NULL pointer
		}
		out << *D.ArrOfPatient[i] << endl;
	}

	return out;
}

