#include <iostream>
#include <string>
#include <set>
#include <fstream>

using namespace std;

int main()
{
    string name;
    int grade;

    set<string> student_name;
    set<string>::iterator p;

    ifstream fin("student-input.txt");

    if(fin.fail()) 
    {   
        cout << "Cannot open the input file!" << endl;
        return 1;
    }

    while(fin >> name && fin >> grade)
    {
        if(grade < 50) { student_name.insert(name); }
    }

    for (p = student_name.begin(); p != student_name.end(); p++)
    {
        cout << *p << endl;
    }

    return 0;
}