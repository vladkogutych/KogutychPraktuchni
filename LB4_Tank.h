class cTank {
private:
	int ammunition, target, chance, hit;
	double fuel,usedfuel = 0.0016;

public:
	cTank(double fuel, int chance, int ammunition, int target, int hit);





	void Shot();

	void Movement(int pdistance);

	void ShowData();
	~cTank();


};