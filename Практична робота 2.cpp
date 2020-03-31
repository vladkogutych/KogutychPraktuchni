#include<iostream>
#include<fstream>
#include<clocale>
#include<iomanip>
#include<string>
#include<math.h>


using namespace std;


int main()
{
	setlocale(LC_CTYPE, "ukr");
	while (true)
	{
		cout << "Write  - press 1" << endl;
		cout << "Show  - press 2" << endl;
		cout << "Exit - press 3" << endl;

		int choice;
		cin >> choice;

		if (choice == 1)
		{
			const double Pi = 3.14159265;
			double angle;
			double y, x;
			double radx, rady;
			cout << "Ввести кут ";
			cin >> angle;
			y = tan(angle);
			x = 1 / y;
			rady = tan(angle * Pi / 180);
			radx = 1 / rady;
			
			
			cout << "Тангенс кута в радіанах: " << y << endl;
			cout << "Тангенс кута в градусах: " << rady << endl;
			cout << "Котангенс кута в радіанах: " << x << endl;
			cout << "Котангенс кута в градусах: " << radx << endl;

			ofstream file;
			file.open("Filereserv1.txt", ios::app);
			if (!file.is_open())
				cout << "Помилка! Файл не знайдений" << endl;
			file << angle << ";" << y << ";" << rady << ";" << endl;
			file << angle << ";" << x << ";" << radx << ";" << endl;
			file.close();
			ofstream file1;
			file1.open("File.txt", ios::app);
			if (!file1.is_open())
				cout << "Помилка! Файл не знайдений" << endl;
			file1 << angle << ";" << y << ";" << rady << ";" << endl;
			file1 << angle << ";" << x << ";" << radx << ";" << endl;
			file1.close();
			ofstream file2;
			file2.open("Filereserv2.txt", ios::app);
			if (!file2.is_open())
				cout << "Помилка! Файл не знайдений" << endl;
			file2 << angle << ";" << y << ";" << rady << ";" << endl;
			file2 << angle << ";" << x << ";" << radx << ";" << endl;
			file2.close();
		}



		if (choice == 2)

		{
			ifstream file;
			file.open("File.txt");
			cout << "Тангенс та Котангенс\t кута в радiанах та градусах" << endl;
			while (!file.eof())
			{
				string buff;
				file >> buff;
				string text;

				for (int i = 0; i < buff.size(); i++)
				{
					if (buff[i] == ';')
					{
						for (int j = 0; j < i; j++)
						{
							text += buff[j];
						}
						buff.erase(0, text.size() + 1);
						i = 0;
						cout << text << "\t";
						text = "";
					}
				}
				cout << endl;
			}
		}
		if (choice == 3)
		{
			break;
		}
	}
	return 0;
}


