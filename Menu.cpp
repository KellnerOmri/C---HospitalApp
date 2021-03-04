#include "Menu.h"

void Menu::MenuProgram()
{
	ArrayOfhospital = new Hospital*[NumOfHospital];
	//init the array
		ArrayOfhospital[0] = new Hospital("Hill Yafe");
		ArrayOfhospital[1] = new Hospital("Soroka");
		ArrayOfhospital[2] = new Hospital("Rambam");
		ArrayOfhospital[3] = new Hospital("Laniado");
	
		cout << "Which hospital would you like to run ? " << endl << "Please enter number : " << endl;
		cout << " [1] Hill Yafe " << endl;
		cout << " [2] Soroka" << endl;
		cout << " [3] Rambam " << endl;
		cout << " [4] Laniado " << endl;
        int IndexOfHos = 0;//index of hospital in array
		cin >> IndexOfHos;
	
	int num=1;
	system("cls");

while(num!=10)
{	
	Dis.displayMenu();//display menu- use frined function from Display class
	if (!(cin >> num))//get input
	{
    cin.clear();
	cin.ignore(INT_MAX, '\n');
	num = 11;//go to the defult and try again.
	}
		getchar();
	system("cls");
		switch (num)
		{
		case 1:
		CinPatientToHospital(*ArrayOfhospital[IndexOfHos - 1]);//Create Pateint(C/M) with user details, and add to Patient pointer array in hospital
        system("pause");
        system("cls");
        break;
	case 2:
		try{
		ArrayOfhospital[IndexOfHos - 1]->deletePatient();
		}
		catch (char* msg)
		{
			cout << msg << endl;
		}
		system("pause");
		system("cls");
		break;
	case 3:
		ArrayOfhospital[IndexOfHos - 1]->show();
		system("pause");
		system("cls");
		break;
	case 4:
		cout << *ArrayOfhospital[IndexOfHos - 1];
		system("pause");
		system("cls");
		break;

	case 5:
		ArrayOfhospital[IndexOfHos - 1]->showCoronaPatient();
		system("pause");
		system("cls");
		break;
	case 6:
		ArrayOfhospital[IndexOfHos - 1]->showMeslesPatient();
		system("pause");
		system("cls");
		break;
	case 7:
		ArrayOfhospital[IndexOfHos - 1]->DeleteAllPatient();//remove all the Patients from the hospital
		system("pause");
		system("cls");
		break;
	
	case 8:
		cout << "Which hospital would you like change ? " << endl << "Please enter number : " << endl;
		cout << " [1] Hill Yafe " << endl;
		cout << " [2] Soroka" << endl;
		cout << " [3] Rambam " << endl;
		cout << " [4] Laniado " << endl;		
		cin >> IndexOfHos;
		system("cls");		
		break;
	
	case 9:
		for (int i = 0; i < NumOfHospital; i++)
		{
			cout << *ArrayOfhospital[i]<<endl;
		}
		system("pause");
		system("cls");
	case 10:
		exit;
		break;
	default:
		cout << "invalid input!" << endl;
		break;

	}
}
}

Menu::~Menu()//destractor
{

	for (int i = 0; i < NumOfHospital; i++)
	{
		if (ArrayOfhospital[i] != NULL)
		{
			delete ArrayOfhospital[i];
		}
	}
	delete ArrayOfhospital;
}

void Menu::CinPatientToHospital(Hospital &myhospital)
{
	//init Patient details
	string Patientname;
	int Cough = 0;
	double Bodyheat = 0;
	int DaysgoneWithSymptoms = 0;
	Date DateOfPatient;
	int CoronaOrMeasles = 0;
	string symptoms;

	//insert details
	cout << "Hellow patient ,please enter your details : " << endl << "Please enter your  name " << endl;
	getline(cin, Patientname);

	try// try to cin date
	{
		cout << "Date of birth : dd/mm/yyyy " << endl;
		cin >> DateOfPatient;
		if (!cin)
		{
			DateOfPatient.setDate(1, 1, 2020);
			throw("Invalid date format, defult date 1/1/2020");
		}
	}
	catch (char* msg)
	{
		cout << msg << endl;
	}

	try //try to cin cough
	{
		
		cout << "Are you cough? please enter number:" << endl << "[1]  yes " << endl << "[2]  no" << endl;
		if (!(cin >> Cough))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			Cough = 1;
			throw("Cough passed must be an yes or no !- defualt answer - yes \n");
			system("pause");
		}
		if (Cough != 1 && Cough != 2)
		{
			Cough = 1;
			throw("invalid number, defult answer - yes \n");

		}
		if (Cough == 2)
			Cough = 0;
		system("cls");
	}
	catch (char* msg)
	{
		cout << msg << endl;
	}


	try //try to insert heat
	{
		cout << "What's your heat?  <30-45>" << endl;
		if (!(cin >> Bodyheat))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			Bodyheat = 38.5;
			throw("Days passed must be an integer !- defualt days passed - 38.5 \n");
			system("pause");
		}

		if (Bodyheat < 30 || Bodyheat>45)
		{
			Bodyheat = 38.5;
			throw("Imposible heat, defult heat - 38.5 \n");
		}
	}
	catch (char* msg)
	{
		cout << msg << endl;
	}

	try //try to insert days passed
	{
		cout << "How manny days have passed since the onset of symptoms?" << endl;

		if (!(cin >> DaysgoneWithSymptoms))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			DaysgoneWithSymptoms = 0;
			throw("Days passed must be an integer !- defualt days passed - 0 \n");
			system("pause");
	    }
		if (DaysgoneWithSymptoms < 0 )
		{
			DaysgoneWithSymptoms = 0;
			throw("Days passed Can't be negative,defualt days passed - 0 \n");
		}
	}
	catch (char* msg)
	{
		cout << msg << endl;
		system("pause");
		
	}
	system("cls");

	try//try to choose witch patient is it
	{		
		cout << "Please enter which patient you are" << endl << "[1]  Corona patient " << endl << "[2]  Measles patient" << endl;
		if (!(cin >> CoronaOrMeasles))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			DaysgoneWithSymptoms = 0;
			throw("The patient must be Corona or Measles ! - defualt answer- Corona \n");
		}
		if (CoronaOrMeasles != 1 && CoronaOrMeasles != 2)
		{
			CoronaOrMeasles = 1;
			throw("invalid number, defult answer - Corona \n");
		}
		if (CoronaOrMeasles == 2)
			CoronaOrMeasles = 0;
	}
	catch (char* msg)
	{
		cout << msg << endl;
	}

	cout << " enter your symptoms that you got :  " << endl;
	getchar();
	getline(cin, symptoms);
	system("cls");
	//convert string to char*, for using constractors
	char* NameOfPatient = const_cast<char*>(Patientname.c_str());
	char* Symptoms = const_cast<char*>(symptoms.c_str());

	if (CoronaOrMeasles == 1)
	{
		int backgroundDiseases;

		try // try to cin BackgroundDiseases
		{
			cout << "Have you had any background illnesses in the past ? please enter number " << endl << "[1]  yes " << endl << "[2]  no" << endl;
			if (!(cin >> backgroundDiseases))
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				backgroundDiseases = 1;
				throw("The answer must be yes or no! - defualt answer- yes \n");
				system("pause");
			}
			if (backgroundDiseases != 1 && backgroundDiseases != 2)
			{
				backgroundDiseases = 1;
				throw("invalid number, defult answer - yes \n");
			}
			if (backgroundDiseases == 2)
				backgroundDiseases = 0;
		}
		catch (char* msg)
		{
			cout << msg << endl;
		}
		system("cls");

		CoronaPatient CPatient(NameOfPatient, DateOfPatient, Bodyheat, DaysgoneWithSymptoms, Cough, backgroundDiseases, Symptoms);
		myhospital.addPatient(&CPatient);
	}
	else //mean that you Measles patient
	{
		int HashappenedBefore;
		try // try to cin HashappenedBefore
		{
			cout << "Have you previously contracted this disease? ? please enter number " << endl << "[1]  yes " << endl << "[2]  no" << endl;
			if (!(cin >> HashappenedBefore))
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				HashappenedBefore = 1;
				throw("The answer must be yes or no ! - defualt answer- yes \n");
				system("pause");
			}
			if (HashappenedBefore != 1 && HashappenedBefore != 2)
			{
				HashappenedBefore = 1;
				throw("invalid number, defult answer - yes \n");

			}
			if (HashappenedBefore == 2)
				HashappenedBefore = 0;
		}
		catch (char* msg)
		{
			cout << msg << endl;
		}
		system("cls");
		MeaslesPatient MyPatient(NameOfPatient, DateOfPatient, Bodyheat, DaysgoneWithSymptoms, Cough, HashappenedBefore, Symptoms);
		myhospital.addPatient(&MyPatient);
	}
}






