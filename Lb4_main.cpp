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
		cout << "����:" << endl;
		cout << "�������� ���� ����� -> press 1" << endl;
		cout << "������� �����i�  -> press 2" << endl;
		cout << "��������� -> press 3" << endl;
		cout << "����� � ����� -> press 4" << endl;

		cout << "��� ���i�:";
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
			cout << "����i�� �������i�,��� ������ �������(� ������)" << endl;
			cin >> pdistance;

			Tank.Movement(pdistance);
		}
		if (choice == 4)
		{
			break;
		}
		
	}
}