#include <iostream>
using namespace std;



int Sum(int n, ...)
{
	int* p = &n;
	int sum;
	sum = 0;
	int mass[12];
	for (int i = 0; i < n; i++)
	{
		mass[i] = *(++p);
		mass[i+1] = *(++p);
		sum += mass[i] * mass[i + 1];
		i++;
	}

	return sum;
}



int main()
{
	setlocale(LC_ALL, "Rus");

		cout << "Сумма 8 попарно умноженных чисел \n(Числа 12, 48, 54, 18, 78, 22, 65, 11)\n";
		cout << "Результат: ";
		cout << Sum(8, 12, 48, 54, 18, 78, 22, 65, 11);
		cout << endl;
		cout << "Сумма 10 попарно умноженных чисел \n(Числа 12, 48, 54, 18, 78, 22, 65, 11, 1, 2)\n";
		cout << "Результат: ";
		cout << Sum(10, 12, 48, 54, 18, 78, 22, 65, 11, 1, 2);
		cout << endl;
		cout << "Сумма 12 попарно умноженных чисел \n(Числа 12, 48, 54, 18, 78, 22, 65, 11, 1, 2, 20, 30)\n";
		cout << "Результат: ";
		cout << Sum(12, 12, 48, 54, 18, 78, 22, 65, 11, 1, 2, 20, 30);


}