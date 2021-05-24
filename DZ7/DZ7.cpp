// DZ7.cpp 
//

#include <iostream>
#include <fstream>
//Exercise 7.1/7.5
#include "mylib.h"

using namespace std;

//Exercise 7.2
#define CHECK(x , y) ((x >= 0 && x < y) ? "true" : "false")

//Exercise 7.3
#define ARR_SIZE 5
#define SwapINT(a, b) int c = a; a = b; b = c;

int a[ARR_SIZE];

void sortArr(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				SwapINT(arr[j], arr[j+1])
			}
		}
	}
}

//Exercise 7.4
#pragma pack(push, 1)
struct Employee
{
	int id;
	unsigned short age;
	float salary;
};
#pragma pack(pop)

Employee* initEmployee()
{
	Employee* pEmp = new Employee;
	cout << "ID: "; cin >> pEmp->id;
	cout << "Age: "; cin >> pEmp->age;
	cout << "Salary: "; cin >> pEmp->salary;
	return pEmp;
}

string saveEmployee(Employee* pEmp)
{
	cout << "Saving employee." << endl;
	string fname;
	cout << "Enter filename: ";
	cin >> fname;
	fname += ".txt";
	ofstream fout(fname);
	fout << "Employee ID : " << pEmp->id << endl;
	fout << "Employee age : " << pEmp->age << endl;
	fout << "Employee salary : " << pEmp->salary << endl;
	fout.close();
	return fname;
}

int main()
{
	//Exercise 7.1/7.5
	cout << "Exercise 7.1/7.5" << endl;
	size_t n;
	cout << "Enter array size: ";
	cin >> n;
	float* Arr = MyLib::initArray(n);
	MyLib::printArray(Arr, n);
	MyLib::countPosNeg(Arr, n);
	delete[] Arr;
	Arr = nullptr;

	//Exercise 7.2
	cout << endl << "Exercise 7.2" << endl;
	int x;
	cout << "Enter number ";
	cin >> x;
	cout << CHECK(x, 5) << endl;

	//Exercise 7.3
	cout << endl << "Exercise 7.3" << endl;
	cout << "Enter " << ARR_SIZE << " values: ";
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cin >> a[i];
	}
	cout << endl;
	sortArr(a, ARR_SIZE);
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	//Exercise 7.4
	cout << endl << "Exercise 7.4" << endl;
	Employee* pEmployee = initEmployee();
	cout << "Employee ID : " << pEmployee->id << endl;
	cout << "Employee age : " << pEmployee->age << endl;
	cout << "Employee salary : " << pEmployee->salary << endl;
	cout << "Your struct size: " << sizeof(Employee) << endl;
	cout << "Saved to " << saveEmployee(pEmployee);

	return 0;
}

