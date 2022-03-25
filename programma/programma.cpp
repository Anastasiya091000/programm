#include<iostream>
#include<string>
#include <fstream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

const int kol_ocen = 5;

int po[] = { 1,1 };

struct student
{
	char surname[64];
	int school;
	int answer[kol_ocen];


};

void input(student* stud, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Фамилия: ";
		cin >> stud[i].surname;
		cout << "Школа: ";
		cin >> stud[i].school;
		cout << "Ответы: ";
		for (int j = 0; j < kol_ocen; j++)
		{
			cin >> stud[i].answer[j];
		}
		cin.get(); // считывает из потока Enter который пользователь нажимает после ввода возраста
		cout << endl;
	};
}

void showData(student* stud, int n)
{
	cout << "№\t" << "Фамилия\t" << "Школа\t" << "Ответы\t" << endl;
	cout << "==================================================================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '\t' << stud[i].surname << '\t' << stud[i].school << '\t';
		for (int j = 0; j < kol_ocen; j++)
		{
			cout << stud[i].answer[j] << " ";
		}
		cout << endl;
	}
};

int prav(student* stud, int n)
{
	int kol;

	for (int i = 0; i < n; i++)
	{
		kol = 0;

		for (int j = 0; j < kol_ocen; j++)
		{
			if (stud[i].answer[j] == po[j])
			{
				kol = kol + 1;
			}

		}


	}
	return kol;
}

void sort(student* stud[], int n)

{
	student *tmp;

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			// сравниваем элементы массива структур по сумме баллов студента
			if (prav(stud[j],n) > prav(stud[j + 1], n))
			{
				tmp = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = tmp;
			}
		}
	}

}

void load()
{	
	setlocale(LC_ALL,"Russian");
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
	setlocale(LC_CTYPE, "rus");
	int n;

	cout << "Введите количество учеников:";
	cin >> n;

	student* stud = new student[n];


	int variant; // выбранный пункт меню

	do {
		print_menu(); // выводим меню на экран

		variant = get_variant(3); // получаем номер выбранного пункта меню

		switch (variant) {
		case 1:
			input(stud, n);

			showData(stud, n);

			prav(stud, n);

			sort(stud[], n);

			break;

		case 2:
			load();
			showData(stud, n);

			prav(stud, n);
				break;
		case 3:
			exit(0);

		}
		system("pause");
	} 

	while (1);
	return 0;
}