#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream file("students.txt");
    file<<"student id: 12345\n";
    file<<"student name: John Doe\n";
    file<<"student age: 20\n";
    file<<"student gender: Male\n";
    file<<"student department: Computer Science\n";
    file.close();
    cout<<"Student details written to file successfully."<<endl;
    return 0;
}