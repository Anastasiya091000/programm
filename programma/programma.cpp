#include<iostream>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


struct student
{
	char surname[64];
	int school;
	int answer;

};

void input()

{
	const int amountOfS = 6;
	student student[amountOfS] = {};

	for (int i = 0; i < amountOfS; i++)
	{
		cout << "Фамилия: ";
		cin.getline(student[i].surname, 32);
		cout << "Школа: ";
		cin >> student[i].school;
		cout << "Ответы: ";
		for (int i = 0; i < 5; i++)
		{
			cin >> student[i].answer;
		}
		cin.get(); // считывает из потока Enter который пользователь нажимает после ввода возраста
		cout << endl;
	}
		cout << "№\t" << "Фамилия\t" << "Школа\t" << "Ответы\t" << endl;
		cout << "==================================================================" << endl;
		for (int i = 0; i < amountOfS; i++)
		{
			cout << i + 1 << '\t' << student[i].surname << '\t' << student[i].school
				<< '\t'; for (int i = 0; i < 5; i++) { cout << student[i].answer<<" "; };
			cout << endl;
		}
		
}

void output()
{
	cout << "Privet!";
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
			break;

		case 2:
			output();

		case 3:
			exit(0);

		}
		system("pause");
	} 

	while (1);
	return 0;
}