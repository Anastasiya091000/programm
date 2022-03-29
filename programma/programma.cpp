#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <sstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct student
{
    string surname;
    int school{0};
    vector<int> answer;
};

std::vector<std::string> split(const std::string& str, const std::string& delimiter)
{
    std::vector<std::string> strings;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos)
    {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }

    // To get the last substring (or only, if delimiter is not found)
    strings.push_back(str.substr(prev));

    return strings;
}

vector<student> readFile()
{	
    vector<student> students;

    std::ifstream file("stud.txt");

    if ( !file ) {
        cerr << "Unable to open file" << endl;
        exit(EXIT_FAILURE);
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    vector<string> strings = split(content, "\n");

    for ( int i = 0; i < strings.size(); i++ ) {
        vector<string> studentData = split(strings[i], " ");

        if ( studentData.size() != 7 )
            continue;

        student stud;
        stud.surname = studentData.at(0);
        stud.school  = atoi(studentData.at(1).c_str());

        for ( int j = 2; j < studentData.size(); j++ )
            stud.answer.push_back(j);

        students.push_back(stud);
    }

    return students;
}

void showData(const vector<student>& students)
{
    cout << "==================================================================" << endl;

    if ( students.empty() )
        return;

    cout << "Фамилия\t" << "Школа\t" << "Ответы\t" << endl;

    for ( int i = 0; i < students.size(); i++ ) {

        student stud = students.at(i);

        cout << stud.surname << "\t" <<  to_string(stud.school) << " \t";

        for ( int j = 0; j < stud.answer.size(); j++ )
            cout << stud.answer.at(j) << " ";

        cout << endl;
    }
};

vector<student> sorting(const vector<student>& students)
{
    return vector<student>{};
}


int main()
{
	setlocale(LC_CTYPE, "rus");

    // read information about students
    vector<student> students = readFile();

    // show raw students data from file
    showData(students);

    // sorting students information
    vector<student> sortedStudents = sorting(students);

    // show sorted students data
    showData(sortedStudents);

    return EXIT_SUCCESS;
}
