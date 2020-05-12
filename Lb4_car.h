#include <string>
using namespace std;
class cCar {
private:
	string name;
	int price,run,priceRun = 1.5;
	double fuel,usedfuel = 0.0016;

public:
	cCar (double fuel, int price, int run, string name);



	void Movement(int distance);



	void ShowData();
	~cCar();


};