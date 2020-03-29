#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    string name;
    int grade;

    map<string, int> student_name;
    map<string, int>::iterator p;

    ifstream fin("student-input.txt");

    if (fin.fail())
    {
        cout << "Cannot open the input file!" << endl;
        return 1;
    }

    while (fin >> name && fin >> grade)
    {
        p = student_name.find(name);
        if(p == student_name.end()) // does not exist
        {
            (grade < 50) ? student_name[name] = 1 : student_name[name] = 0;
        } else
        {
            if(grade < 50) { p->second += 1; }
        }
    }

    for (p = student_name.begin(); p != student_name.end(); p++)
    {
        cout << p->first << " " << p->second << endl;
    }

    return 0;
}