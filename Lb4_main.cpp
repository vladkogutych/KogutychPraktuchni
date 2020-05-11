#include"Tank.h"
#include<iostream>
#include<clocale>
#include<math.h>

using namespace std;
int main()
{
	cTank Tank(540, 40, 15, 10, 0);


	setlocale(LC_CTYPE, "ukr");
	while (true)
	{
		int choice;
		cout << endl;
		cout << endl;
		cout << "МЕНЮ:" << endl;
		cout << "Поточний стан танку -> press 1" << endl;
		cout << "Зробити вистрiл  -> press 2" << endl;
		cout << "Проїхатись -> press 3" << endl;
		cout << "Вийти з танку -> press 4" << endl;

		cout << "Ваш вибiр:";
		cin >> choice;


		if (choice == 1)
		{
			Tank.ShowData();
		}
		if (choice == 2)
		{
			Tank.Shot();
		}
		if (choice == 3)
		{
			int pdistance;
			cout << "Введiть дистанцiю,яку хочете проЇхати(в метрах)" << endl;
			cin >> pdistance;

			Tank.Movement(pdistance);
		}
		if (choice == 4)
		{
			break;
		}
		
	}
}