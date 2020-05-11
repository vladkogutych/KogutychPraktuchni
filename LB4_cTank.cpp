#include"Tank.h"
#include <iostream>
#include <math.h>
#include<clocale>
using namespace std;

cTank::cTank(double fuel, int chance, int ammunition, int target, int hit) {
	this->fuel = fuel;
	this->chance = chance;
	this->ammunition = ammunition;
	this->target = target;
	this->hit = hit;
}




void cTank::Shot() {
	setlocale(LC_CTYPE, "ukr");
	double R, A, F, S;
	double a, l;

	cout << "Введiть вiдстань до цiлi (в метрах) : " << endl;
	cin >> R;
	cout << endl;

	cout << "Введiть кут : " << endl;
	cin >> A;
	cout << endl;

	cout << "Введiть швидкiсть : " << endl;
	cin >> F;
	cout << endl;

	cout << "Введiть родiус : " << endl;
	cin >> S;
	cout << endl;
	R *= 1000;
	a = A * 3, 14 / 180;
	l = pow(F, 2) * sin(2 * a) / 9.8;
	if (l >= R - S && l <= R + S) {
		cout << "Є влучення!" << endl;
		hit++;
		target--;
		ammunition--;
	}
	else {
		cout << "Ти промазав!" << std::endl;
		ammunition--;
	}

}


void cTank::Movement(int pdistance) {
	double use;

	use = usedfuel * pdistance;
	fuel = 540 - use;

}
void cTank::ShowData()
{
	cout << endl << "Кiлькiсть  палива: " << fuel << " л";
	cout << endl << "Розмiр боєкомплекту: " << ammunition << " шт";
	cout << endl << "Шанс попадання: " << chance << " %";
	cout << endl << "Kiлькiсть  вражених цiлей: " << hit;

}
cTank::~cTank() {}