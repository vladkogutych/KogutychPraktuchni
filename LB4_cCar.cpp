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
	cout << endl << "Назва машини: " << name;
	cout << endl << "Кiлькiсть  палива: " << fuel << " л";
	cout << endl << "Розмiр пробiгу: " << run << "км";
	cout << endl << "Вартiсть машини: " << price << " грн";
	cout << endl << "Вартiсть пробiгу: " << priceRun << " грн/км";

}
cCar::~cCar() {}