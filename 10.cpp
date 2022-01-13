#include <iostream>
using namespace std;

void print_mass(int* mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}

int* create_mass(int* mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> mass[i];
	}
	return mass;
}

int* update_mass(int* mass1, int* mass2, int n, int del, int add)
{
	int* sup_mass = new int[n-del];
	for (int i = 0; i < del; i++)
	{
		mass2[i] = mass1[i];
	}
	for (int i = del; i < n; i++)
	{
		sup_mass[i+add] = mass1[i];
	}
	for (int i = del; i < del+add; i++)
	{
		cin >> mass2[i];
	}
	for (int i = del+add; i < n+add; i++)
	{
		mass2[i] = sup_mass[i];
	}


	return mass2;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, del, add;
	cout << "������� ����������� �������: ";
	cin >> n;
	int* mass = new int[n];
	cout << "������� ������: ";
	create_mass(mass, n);
	cout << "������� ����� ���������� ��������: ";
	cin >> del;
	for (int i = del; i < n-1; i++)
	{
		mass[i] = mass[i + 1];
	}
	n--;
	cout << "������ ����� ��������: ";
	print_mass(mass, n);
	cout << "������� ���������� ����������� ���������: ";
	cin >> add;
	int* newmass = new int[n+add];
	cout << "������� ����������� ��������: ";
	newmass = update_mass(mass, newmass, n, del, add);
	print_mass(newmass, n+add);

}
