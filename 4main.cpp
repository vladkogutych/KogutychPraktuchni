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
		cout << '\t' << " ����:" << endl;
		cout << '\t' << "�������� ���� ������-> press 1" << endl;
		cout << '\t' << "��������� ->press 2" << endl;
		cout << '\t' << "����� � ������ ->press 3" << endl;
	

		cout << "                                            ��� ���i�:";
		cin >> choice;


		if (choice == 1)
		{
			Car.ShowData();
		}
		if (choice == 2)
		{
			int pdistance;
			cout << "����i�� �������i�,��� ������ �������(� ������)" << endl;
			cin >> pdistance;
			Car.Movement(pdistance);
		}

		if (choice == 3)
		{
			break;
		}
		
	}
}