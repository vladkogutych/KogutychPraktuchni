#include <iostream>
#include <iomanip>
using namespace std;



template<typename T1>
class MyClass
{
public:
	MyClass(int size_st, int size_r)
	{
		this->size_st = size_st;
		this->size_r = size_r;
		arr = new T1*[size_st];
		for (int i = 0; i < size_st; i++)
		{
			arr[i] = new T1[size_r];
		}

		for (int i = 0; i < size_st; i++)// ���������� �������
		{
			for (int j = 0; j < size_r; j++)
			{
				arr[i][j] = rand() % 100;
				if ((rand() / 100) % 2 > 0) arr[i][j] *= -1;
			}
		}
	}

	~MyClass()
	{
		if (arr != nullptr)
		{
			for (int i = 0; i < size_st; i++)
			{
				delete arr[i];
			}
			delete[] arr;
			cout << "Matrix sucesfully delete!" << endl;
		}
		arr = nullptr;
	}


	void GetMatrix()
	{
		cout << endl << "Your matrix:" << endl;

		for (int i = 0; i < this->size_st; i++)
		{
			for (int j = 0; j < this->size_r; j++)
			{
				
				cout<< setw(4)<<left <<this->arr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	void Search()
	{
		T1 res_n = 0, res_count = 0, count=0;
		
		for (int i = 0; i < this->size_st; i++)
		{
			for (int j = 0; j < this->size_r; j++)
			{
				res_n += this->arr[i][j];
				res_count++;
			}
			
		}
		count = res_n / res_count;
		
		for (int i = 0; i < this->size_st; i++)
		{
			for (int j = 0; j < this->size_r; j++)
			{
				if (this->arr[i][j] > count) {
					this->arr[i][j] = count;
				}
				
				else {
					this->arr[i][j] = this->arr[i][j];
				}

			}

		}
		cout << endl << "Your matrix now :" << endl;

		for (int i = 0; i < this->size_st; i++)
		{
			for (int j = 0; j < this->size_r; j++)
			{

				cout << setw(4) << left << this->arr[i][j];
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

private:
	int size_r, size_st;
	T1** arr;

};

int main()
{
	int size__st, size__r;

	cout << "Enter count of st:";
	cin >> size__st;
	cout << "Enter count of r:";
	cin >> size__r;
	cout << endl;

	MyClass<int> a(size__st, size__r);
	
	a.GetMatrix();
	a.Search();

	return 0;
}
