#include <iostream>
#include <math.h>
using namespace std;



int minys(int a, int b)
{

	int sum;
	sum = 0;
	sum = a - b;

	return sum;
}

void minys(int a, int b, int c, int d)
{

	int sum;
	sum = 0;
	int i = sqrt(-1);
	cout << a - c << " + (" << b - d << "i)";
}



int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, c, d;
	cout << "Введите уменьшаемое число: ";
	cout << endl;
	cin >> a;
	cout << endl;
	cout << "Введите вычитаемое число: ";
	cin >> b;
	cout << endl;
	cout << "Разность: ";
	cout << minys(a, b);
	cout << endl;
	cout << "Введите уменьшаемое комплексное число: ";
	cout << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << endl;
	cout << "Введите вычитаемое комплексное число: ";
	cout << "c: ";
	cin >> c;
	cout << "d: ";
	cin >> d;
	cout << endl;
	cout << "Разность: ";
	minys(a, b, c, d);

}
