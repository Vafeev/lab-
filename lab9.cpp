#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Human
{
	Human* next;
	char fio[50];
	char adress[50];
	long long number;
	int age;
};
Human* create_obj(...)
{
	Human* p = new Human;
	cout << "\nВведите фамилию имя и отчество: ";
	cin >> p->fio;
	cout << "\nВведите адресс: ";
	cin >> p->adress;
	cout << "\nВведите номер телефона: ";
	cin >> p->number;
	cout << "\nВведите возраст: ";
	cin >> p->age;
	cout << endl;
	p->next = 0;
	return p;
}
Human* create_list(Human*& first, int n)
{
	Human* p = first;
	Human* r;
	for (int i = 1; i < n; i++)
	{
		r = create_obj();
		p->next = r;
		p = r;
	}
	return first;
}
void print_list(Human* first)
{
	Human* p = first;
	while (p)
	{
		cout << "ФИО:" << p->fio << '\t';
		cout << "Адресс:" << p->adress << '\t';
		cout << "Номер телефона:" << p->number << '\t';
		cout << "Возраст" << p->age << endl;
		p = p->next;
	}
}

Human* delete_obj(Human*& first, float k, int n)
{
	Human* p = first;
	Human* ptr = 0;
	if (first->age == k)
	{
		first = first->next;
		delete p;
		return first;
	}
	else {
		for (int i = 1; i < n && p->next != 0; i++)
		{
			if (p->next->age == k)
			{
				ptr = p->next;
				p->next = ptr->next;
				delete ptr;
				return first;
			}
			p = p->next;
			if (p->next == 0)
			{
				return first;
			}
		}
	}
}

Human* add_obj(Human*& first, int num)
{
	Human* p = first;
	for (int i = 0; i < num - 1 && p->next != 0; i++)
	{
		p = p->next;
	}
	if (p != 0)
	{
		Human* r = create_obj();
		r->next = p->next;
		p->next = r;
		return first;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string path = "Human.txt";
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия!";
	}
	else
	{
		int num, n;
		float k;
		cout << "Введите количество объектов:";
		cin >> n;
		cout << endl;
		Human* first = create_obj();
		create_list(first, n);
		Human* p = first;

		while (p)
		{

			fout << "Изначальные данные:\n";
			fout << "ФИО: " << p->fio << '\t';
			fout << "Адресс: " << p->adress << '\t';
			fout << "Номер телефона: " << p->number << '\t';
			fout << "Возраст: " << p->age << endl;
			fout << "_______________________________________________________________\n";
			p = p->next;
		}
		p = first;
		fout << endl;
		cout << "Укажите возраст для удаления:";
		cin >> k;
		delete_obj(first, k, n);
		p = first;
		while (p)
		{

			fout << "Данные после удаления:\n";
			fout << "ФИО: " << p->fio << '\t';
			fout << "Адресс: " << p->adress << '\t';
			fout << "Номер телефона: " << p->number << '\t';
			fout << "Возраст: " << p->age << endl;
			fout << "_______________________________________________________________\n";
			p = p->next;
		}
		p = first;
		fout << endl;
		cout << "Количество добавляемых элементов:";
		cin >> num;
		cout << endl;
		for (int i = 0; i < num; i++)
		{
			add_obj(first, n);
			n++;
		}
		while (p)
		{

			fout << "Данные после добавления:\n";
			fout << "ФИО: " << p->fio << '\t';
			fout << "Адресс: " << p->adress << '\t';
			fout << "Номер телефона: " << p->number << '\t';
			fout << "Возраст: " << p->age << endl;
			fout << "_______________________________________________________________\n";
			p = p->next;

		}
	}
	cout << "_______________________________________________________________\n";
	fout.close();
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия!";
	}
	else
	{
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();
	system("pause");
}