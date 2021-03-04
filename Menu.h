
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Hospital.h"
using namespace std;



class display
{
public:
void displayMenu()
{
	cout << " Hellow, choose an option" << endl;
	cout << "[1]  Add patient to the hospital " << endl;
	cout << "[2]  Remove patient from hospital " << endl;
	cout << "[3]  Display the hospital details" << endl;
	cout << "[4]  Display the patients in the hospital" << endl;
	cout << "[5]  Display Corona Patient" << endl;
	cout << "[6]  Display Measles Patient" << endl;
	cout << "[7]  Remove all the patients from the hospital" << endl;
	cout << "[8]  change hospital " << endl;
	cout << "[9]  Display the patients from all Israeli hospitals" << endl;
	cout << "[10] Exit " << endl;

}
};

class Menu
{
private:
	Hospital **ArrayOfhospital;//array of hospital
	void CinPatientToHospital(Hospital &myhospital);//Create Pateint(C/M) with user details, and add to Patient pointer array in hospital
    friend void display::displayMenu();//just menu can get it
public:
	void MenuProgram();
	display Dis;
	~Menu();//destractor
};

