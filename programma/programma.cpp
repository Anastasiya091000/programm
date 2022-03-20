#include<iostream>
#include<string>
#include <fstream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


struct student
{
	char surname[64];
	int school;
	int answer;

};

const int amountOfS = 3;
student stud[amountOfS] = {};

int ans[] = { 1,1 };
int kol;

void sravn()
{
	cout << "Список учеников школы №1" << endl << endl;
	cout << "№\t" << "Фамилия\t" << "Школа\t" << "Ответы\t" << "Количество правильных ответов" << endl;
	cout << "==================================================================" << endl;

	for (int i = 0; i < amountOfS; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (stud[i].answer == ans[j])
			{
				kol = kol + 1;
			}
		}

		if (stud[i].school == 1)
		{


			cout << i + 1 << '\t' << stud[i].surname << '\t' << stud[i].school
				<< '\t'; for (int i = 0; i < 2; i++) { cout << stud[i].answer << " "; };
			cout << kol << endl;


		}
		
	}
	cout << endl << endl;

	cout << "Список учеников школы №2" << endl << endl;
	cout << "№\t" << "Фамилия\t" << "Школа\t" << "Ответы\t" << "Количество правильных ответов" << endl;
	cout << "==================================================================" << endl;

	for (int i = 0; i < amountOfS; i++)
	{
		if (stud[i].school == 2)
		{


			cout << i + 1 << '\t' << stud[i].surname << '\t' << stud[i].school
				<< '\t'; for (int i = 0; i < 2; i++) { cout << stud[i].answer << " "; };
			cout << kol << endl;


		}
		for (int j = 0; j < 2; j++)
		{
			if (stud[i].answer == ans[j])
			{
				kol = kol + 1;
			}
		}

	}
	cout << endl << endl;

	cout << "Список учеников школы №3" << endl << endl;
	cout << "№\t" << "Фамилия\t" << "Школа\t" << "Ответы\t" << "Количество правильных ответов" << endl;
	cout << "==================================================================" << endl;

	for (int i = 0; i < amountOfS; i++)
	{
		if (stud[i].school == 3)
		{


			cout << i + 1 << '\t' << stud[i].surname << '\t' << stud[i].school
				<< '\t'; for (int i = 0; i < 2; i++) { cout << stud[i].answer << " "; };
			cout << kol << endl;


		}
		for (int j = 0; j < 2; j++)
		{
			if (stud[i].answer == ans[j])
			{
				kol = kol + 1;
			}
		}
	}
}

void input()

{
	//const int amountOfS = 6;
	//student stud[amountOfS] = {};

	for (int i = 0; i < amountOfS; i++)
	{
		cout << "Фамилия: ";
		cin.getline(stud[i].surname, 32);
		cout << "Школа: ";
		cin >> stud[i].school;
		cout << "Ответы: ";
		for (int i = 0; i < 2; i++)
		{
			cin >> stud[i].answer;
		}
		cin.get(); // считывает из потока Enter который пользователь нажимает после ввода возраста
		cout << endl;
	}
		cout << "№\t" << "Фамилия\t" << "Школа\t" << "Ответы\t" << endl;
		cout << "==================================================================" << endl;
		for (int i = 0; i < amountOfS; i++)
		{
			cout << i + 1 << '\t' << stud[i].surname << '\t' << stud[i].school
				<< '\t'; for (int i = 0; i < 2; i++) { cout << stud[i].answer<<" "; };
			cout << endl;
		}
		
}

void load()
{	setlocale(LC_ALL,"Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// создать экземпляр файла filename
	ifstream inputFile("stud.txt");
	if (!inputFile)
	{
		cout << "Ошибка в открытии файла!!!";
	};

	char buffer[255]; // буфер для сохранения одной строки

	// цикл чтения строк файла
	// строки читаются до тех пор, пока не будет достигнут конец файла
	cout << "№\t" << "Фамилия\t" << "Школа\t" << "Ответы\t" << endl;
	cout << "==================================================================" << endl;
	while (!inputFile.eof())
	{
		inputFile.getline(buffer, 255);
		if (inputFile)
			cout << buffer << '\t' << endl;
	}

	inputFile.close();
}
void print_menu() {
	system("cls"); // очищаем экран
	cout << "1. Ввести данные с клавиатуры" << endl;
	cout << "2. Вывести данные из файла" << endl;
	cout << "3. Выход" << endl;
	cout << "Введите номер (1-3):";
}


int get_variant(int count) {
	int variant;
	string s; // строка для считывания введённых данных
	getline(cin, s); // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
		cout << "Incorrect input. Try again: "; // выводим сообщение об ошибке
		getline(cin, s); // считываем строку повторно
	}

	return variant;
}


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int variant; // выбранный пункт меню

	do {
		print_menu(); // выводим меню на экран

		variant = get_variant(3); // получаем номер выбранного пункта меню

		switch (variant) {
		case 1:
			input();
			sravn();
			break;

		case 2:
			load();
			sravn();
				break;
		case 3:
			exit(0);

		}
		system("pause");
	} 

	while (1);
	return 0;
}