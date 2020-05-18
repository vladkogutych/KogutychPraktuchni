
#include <iostream>
#include <math.h>
#include<clocale>
#include <string>

using namespace std;
class cCar {
private:
	string name;
	int price, run, priceRun = 1.5;
	double  usedfuel = 0.0016;

public:
	double fuel;
	cCar() 
	{
	}

	cCar (double fuel)
	{
		this->fuel = fuel;
	
	
	}

	cCar(double fuel, int price, int run, string name) {
		this->fuel = fuel;
		this->price = price;
		this->run = run;
		this->name = name;
	}


	cCar(const cCar& other) {
		this->fuel = other.fuel;
		this->price = other.price;
		this->run = other.run;
		this->name = other.name;
	}


	virtual ~cCar() {
	}





	//operators
	cCar& operator-- ()
	{
		cout << endl << "Operator --" << endl;
		this->run--;
		this->price--;
	
		return *this;
	}


	

	cCar& operator-= (cCar Car2)
	{
		fuel -= Car2.fuel;
		return *this;
	}

	cCar& operator+= (cCar Car2)
	{
		fuel += Car2.fuel;
		return *this;
	}




	bool operator ==(const cCar& other)
	{
		cout << endl << "Operator ==" << (this->fuel == other.fuel && this->price == other.price && this->run == other.run && this->name == other.name && this->priceRun == other.priceRun && this->usedfuel == other.usedfuel) << endl;
		return this->fuel == other.fuel && this->price == other.price && this->run == other.run && this->name == other.name && this->priceRun == other.priceRun && this->usedfuel == other.usedfuel;
	}



	//function
	void Movement(int pdistance) {

		double use;
		run = +(pdistance / 1000);
		price -= (run * priceRun);
		use = usedfuel * pdistance;

		fuel = 70 - use;

	}



	void ShowData()
	{
		setlocale(LC_CTYPE, "ukr");
		cout << endl << "Назва машини: " << name;
		cout << endl << "Кiлькiсть  палива: " << fuel << " л";
		cout << endl << "Розмiр пробiгу: " << run << "км";
		cout << endl << "Вартiсть машини: " << price << " грн";
		cout << endl << "Вартiсть пробiгу: " << priceRun << " грн/км";

	}
	//getters
	int GET_run()
	{
		return run;
	}
	int Get_price()
	{
		return price;
	}

	int Get_fuel()
	{
		return fuel;
	}

};
cCar operator + (cCar Car, cCar Car2)
{
	return cCar(Car.fuel + Car2.fuel);
}

int main()
{
	string name = "Porsche 911 Coupe";
	string name2 = "AUDI R8";
	cCar Car(70.0 , 4058366 , 0, name);
	cCar Car2(80.0, 3550000, 0, name2);
	


	setlocale(LC_CTYPE, "ukr");
	while (true)
	{
		int choice;
		cout << endl;
		cout << endl;
		cout << '\t' << " МЕНЮ:" << endl;
		cout << '\t' << "Поточний стан машини-> press 1" << endl;
		cout << '\t' << "Проїхатись ->press 2" << endl;
		cout << '\t' << "Оператори ->press 3" << endl;
		cout << '\t' << "Вийти з машини ->press 4" << endl;
	

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
			cout << "Was:" << endl << "run: " << Car.GET_run() << endl << "price: " << Car.Get_price() << endl;
			cout << endl << "****************";
			--Car;
			cout << endl << "****************" << endl;
			cout << endl << "Has become:" << endl << "run: " << Car.GET_run() << endl << "price: " << Car.Get_price() << endl;
			cout << "================================================================" << endl;

			
			cout << "Was before operator +=:" << endl << "fuel: " << Car.Get_fuel() << endl;
			cout << endl << "****************";
			Car.fuel += Car2.fuel;
			cout << endl << "****************" << endl;
			cout << endl << "Has become:" << endl << "fuel: " << Car.Get_fuel() << endl;
			cout << "================================================================" << endl;

			cout << "Was before operator -=:" << endl << "fuel: " << Car.Get_fuel() << endl;
			cout << endl << "****************";
			Car.fuel -= Car2.fuel;
			cout << endl << "****************" << endl;
			cout << endl << "Has become:" << endl << "fuel: " << Car.Get_fuel() << endl;
			cout << "================================================================" << endl;



			cout << "====****====****====****====****====****====****====****====****====";
			cout << endl;
			cout << endl << "Was before operator = :" << endl;
			cout << endl << "****************";
			Car == Car2;
			cout << endl << "****************" << endl;
			cout << "================================================================" << endl;

			cout << endl;
			cout << "Was:" << endl;
			Car.ShowData();
			cout << endl;
			cout << endl << "****************";
			Car = Car2;
			cout << endl << "****************" << endl;
			cout << endl;
			cout << "Has become:" << endl;
			Car.ShowData();
			cout << endl;
			cout << "================================================================" << endl;

			cout << endl;
			cout << endl << "has become after operator = :" << endl;
			cout << endl << "****************";
			Car == Car2;
			cout << endl << "****************" << endl;
			cout << "====****====****====****====****====****====****====****====****====";
		}
		if (choice == 4)
		{
			break;
		}
		
	}
}

