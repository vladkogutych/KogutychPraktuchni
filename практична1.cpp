#include<iostream>
#include<string.h>
#include<clocale>

using namespace  std;

bool func(int* arr, int length) {
    int i, count = 0;
    int flag;

    if (arr[0] < 0) {
        flag = 0;
    }
    else {
        flag = 1;
    }

    for (i = 1; i < length; i++) {
        if (arr[i] < 0 && flag == 1) {
            count++;
            flag = 0;
        }
        else if (arr[i] >= 0 && flag == 0) {
            count++;
            flag = 1;

        }
    }

    if (count == 5)
        return true;

    return false;


}

bool func(double* arr, int length) {
    int i, count = 0;
    int flag;

    if (arr[0] < 0) {
        flag = 0;
    }
    else {
        flag = 1;
    }

    for (i = 1; i < length; i++) {
        if (arr[i] < 0 && flag == 1) {
            count++;
            flag = 0;
        }
        else if (arr[i] >= 0 && flag == 0) {
            count++;
            flag = 1;
        }
    }

    if (count == 5)
        return true;

    return false;
}
int main()
{
    setlocale(LC_ALL, "ukr");
    int arr1[6];
    double arr2[6];
    for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
        arr1[i] = int(rand() % 100 - 50);
    for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
        cout << arr1[i] << " ";
    cout << endl;
    for (int i = 0; i < sizeof(arr2) / sizeof(double); i++)
        arr2[i] = double(rand() % 100 - 50);
    for (int i = 0; i < sizeof(arr2) / sizeof(double); i++)
        cout << arr2[i] << " ";
    cout << endl;
    if (func(arr1, 6) == 1)
    {
        cout << "знаки в масивi цiлих чисел чергуються" << endl;
    }
    else {

        cout << "знаки в масивi цiлих чисел не чергуються" << endl;
    }

    if (func(arr2, 6) == 1)
    {
        cout << "знаки в масивi дiйсних чисел чергуються" << endl;
    }
    else {
        cout << "знаки в масивi дiйсних чисел не чергуються" << endl;
    }

    return 0;
}
