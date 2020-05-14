#include"car.h"
#include<iostream>
#include<clocale>
#include<math.h>
#include <string>

using namespace std;
int main()
{
	string name = "Porsche 911 Coupe";
	cCar Car(70.0 , 4058366 , 0, name);


	setlocale(LC_CTYPE, "ukr");
	while (true)
	{
		int choice;
		cout << endl;
		cout << endl;
		cout << '\t' << " МЕНЮ:" << endl;
		cout << '\t' << "Поточний стан машини-> press 1" << endl;
		cout << '\t' << "Проїхатись ->press 2" << endl;
		cout << '\t' << "Вийти з машини ->press 3" << endl;
	

		cout << "                                            Ваш вибiр:";
		cin >> choice;


		if (choice == 1)
		{
			Car.ShowData();
		}
		if (choice == 2)
		{
			int pdistance;
			cout << "Введiть дистанцiю,яку хочете проЇхати(в метрах)" << endl;
			cin >> pdistance;
			Car.Movement(pdistance);
		}

		if (choice == 3)
		{
			break;
		}
		
	}
}