#include <iostream>
#include <string>
using namespace std;

class cDevice
{
public:

	//Constructor's | Destructor's
	cDevice()
	{
		cout << "Constructor of Device" << endl;
		this->waranty = rand() / 12;

		BatteryCharge = new int;
		*BatteryCharge = rand() / 151-50;
	}

	cDevice(const cDevice& other)
	{
		cout << "Constructor of Device (copy)" << endl;
		this->BatteryCharge = new int;

		this->BatteryCharge = other.BatteryCharge;

		this->waranty = other.waranty;
		this->power = other.power;
	}

	virtual ~cDevice()
	{
		cout << "Destructor of Device" << endl;
		delete BatteryCharge;
		BatteryCharge = nullptr;
	}

	//Method's
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;


	//Geter's  ||  Setter's
	int GetWaranty()
	{
		return this->waranty;
	}

	double GetPower()
	{
		return this->power;
	}

	int* GetBatteryCharge()
	{
		return this->BatteryCharge;
	}


	void SetWaranty(int waranty)
	{
		this->waranty = waranty;
	}

	void SetPower(double power)
	{
		this->power = power;
	}

	void SetGetBatteryCharge(int value)
	{
		this->BatteryCharge = &value;
	}


protected:

	bool State;
	int waranty;
	double power = 1;
	int* BatteryCharge;
};

class Phone : public cDevice
{
private:
	string model;
	int Innermemory;
	int* DISPLAY;

public:
	//Constructor's | Destructor's

	Phone(string model, int Innermemory, int mDISPLAY)
	{
		cout << "Constructor of Phone" << endl;
		this->model = model;
		this->Innermemory = Innermemory;

		DISPLAY = new int;
		*DISPLAY = mDISPLAY;
	}

	Phone(const Phone& other)
	{
		cout << "Constructor of Phone (copy)" << endl;
		this->model = other.model;
		this->Innermemory = other.Innermemory;

		this->DISPLAY = other.DISPLAY;
	}

	~Phone() override
	{
		cout << "Destructor of Phone" << endl;
		delete this->DISPLAY;
		this->DISPLAY = nullptr;
	}

	//Operator
	void operator=(const Phone& other)
	{
		this->model = model;
		this->Innermemory = Innermemory;
	}

	//Method's

	void TurnOn()override
	{
		cout << endl << "TurnOn Phone" << endl;
		this->State = true;
	}
	void TurnOff()override
	{
		cout << endl << "TurnOff Phone" << endl;
		this->State = false;
	}

	void takePhoto(int photo)
	{
		double sizephoto = 0.001;
		int  mphoto;
		mphoto = photo * sizephoto;
		
		if (!this->State)
		{
			cout << "Error: turn on Phone!!!" << endl;
			return;
		}
		if (mphoto > this->Innermemory)
		{
			cout << "Error: dont enough memory" << endl << endl;
			return;
		}
		cout << "Start making " << photo << " photos." << endl << "Process..." << endl << "Finish!" << endl << endl;
	}
	void showData() {


		cout << endl << "Model of Phone: " << model;
		cout << endl << "The amount of battery charge: " << *BatteryCharge << " %";
		cout << endl << "The amount of memory: " << Innermemory << " gigabytes";
		cout << endl << "Screen size: " << *DISPLAY << " inch";
		

	}
	void delateData()
	{
		if (this->State)
		{
			cout << "Error: turn off Phone!!!" << endl;
			return;
		}

		cout << endl << "Start delate data" << endl << "Process..." << endl << "Finish delating" << endl << endl;
	}

	//Geter's  ||  Setter's
	string GetModel()
	{
		return this->model;
	}

	double GetCapacity()
	{
		return this->Innermemory;
	}

	int* GetDISPLAY()
	{
		return DISPLAY;
	}


	void SetModel(string model)
	{
		this->model = model;
	}

	void SetCapacity(int Innermemory)
	{
		this->Innermemory = Innermemory;
	}

	void SetDISPLAY(int value)
	{
		this->DISPLAY = &value;
	}
};


int main()
{
	double displey;
	Phone cPhone("Pixel 4Xl ", 64, 5.7);
	displey = *cPhone.GetDISPLAY();
	cout << endl << "========================================" << endl;

	cPhone.takePhoto(1500);
	cPhone.TurnOn();
	cPhone.takePhoto(1700000);
	cPhone.takePhoto(1800);
	cPhone.showData();

	cPhone.TurnOff();
	cPhone.delateData();

	cout << endl << "========================================" << endl;
	return 0;
}
