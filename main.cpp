
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
using namespace std;
#define _Menu

int main()
{//you can create objects with constractors (without the menu) for chaking the program, just undefine _Menu at the top

#ifdef _Menu
	
	
	Menu M;
	M.MenuProgram();//start the menuProgram
	
	
#else

	//i created for you , beacuse it can cost alot of time for create it
	
	Date d1;
	Date d2(12, 3, 1980);
	Date d4(22, 3, 1911);
	Date d3(22, 3, 1911);
	bool a = 0;
	a = (d4 == d3);
	cout << a;
	d1 = d3;
	cout << d1;
	d1.setDate(1, 4, 2011);
	cout << d1;
	CoronaPatient C1("Yoram Gaon", d2, 44.4, 1, 1, "sleeping all the day");
	CoronaPatient C2("Omri Kellner", d4, 42.1, 1, 1, "hard headache");
	CoronaPatient C3("Barak Obama", d3, 31.2, 1,1, 1, "constipation");
	MeaslesPatient M2("Omri Kellner", d4, 41.42, 1, 1, "hard headache");
	CoronaPatient C4(C3);
	Hospital hospi("hill yafe");
	cout << hospi;
	int e = C4.patientSituation();
	Patient *s = new CoronaPatient(C3);
	a= (*s == C3);
	Hospital myhos("Laniado");
	cout << myhos;
	myhos.showCoronaPatient();
	cout << endl << Patient::NumOfSoulMachinesActive;
	myhos.addPatient(&C1);
	cout << Patient::NumOfSoulMachinesActive;
	myhos.addPatient(&C2);
	myhos.addPatient(&M2);
	myhos.addPatient(&*s);
	hospi.addPatient(&C2);
	myhos= hospi;
	cout << hospi;
	myhos.show();
    system("pause");
	
#endif // _Menu
}












	
