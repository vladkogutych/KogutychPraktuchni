#include "car.h"
#include <iostream>
#include <math.h>
#include<clocale>
#include <string>
using namespace std;

cCar::cCar(double fuel, int price, int run, string name ) {
	this->fuel = fuel;
	this->price = price;
	this->run = run;
	this->name = name;
	
}


void cCar::Movement(int pdistance) {

	double use;
	run = +(pdistance / 1000);
	price = -(run * priceRun);
	use = usedfuel * pdistance;

	fuel = 540 - use;

}



void cCar::ShowData()
{
	setlocale(LC_CTYPE, "ukr");
	cout << endl << "����� ������: " << name;
	cout << endl << "�i���i���  ������: " << fuel << " �";
	cout << endl << "����i� ����i��: " << run << "��";
	cout << endl << "����i��� ������: " << price << " ���";
	cout << endl << "����i��� ����i��: " << priceRun << " ���/��";

}
cCar::~cCar() {}