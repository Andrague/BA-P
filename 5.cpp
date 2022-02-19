#include<iostream>
#include <math.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int* a;  // указатель на массив
	int i = 0, size = 0;
	int f = 0;
	int neg = 0;
	int sum = 0; //сумма модулей
	int flag = 0; //указатель что найден отрицательный элемент в макссиве
	system("cls");
	cout << "Enter array size:";
	cin >> size;
	while (cin.fail() || (size <= '0' && size > '9'))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error, try again " << endl;
		cin >> size;
	}
	a = new int[size];
	// Выделение памяти
	do {
		while (cin.fail() || (a[i] <= '0' && a[i] > '9'))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error, try again " << endl;
			cin >> a[i];
		}
		cout << endl << "Choose manual filling (1) or random (2): " << endl;
		cin >> f;
	} while (f <1 || f > 2);
	switch (f) {
	case 1: {
		// Ввод элементов массива
		for (i = 0; i < size; i++) {
			while (cin.fail() || (a[i] <= '0' && a[i] > '9'))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error, try again " << endl;
				cin >> a[i];
			}
			cout << "a["; cout << i; cout << "]=";
			cin >> a[i];
			
		}
		break;
	}

	case 2: {
		// Заполнение случайными числами элементов массива
		for (i = 0; i < size; i++) {
			a[i] = 10 - rand() % 20;
		}
		break;
		}
	}
	cout << endl;
	// Вывод элементов массива
	for (i = 0; i < size; i++){
		cout << "a["; cout << i; cout << "]=";
		cout << a[i];
		cout << endl;
	}
		  // Суммируем модули после отрицательного числа
		  for (i = 0; i < size; i++) {
			  if (a[i] <0)
			  {
				  flag = 1; neg = a[i];
			  }
			  if (flag) {
				  sum += abs(a[i]);
			  }
		  }
		  sum = sum + neg;
		  cout << endl << "Sum of modules is : " << sum<<endl;
		  delete[]a;
		  return 0;
	}
