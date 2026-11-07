#include <iostream>
using namespace std;
struct Student
{
    string name;
    int rollNo;
    float marks;
};
int main()
{
    Student s1;
    cout << "Enter student name: ";
    cin >> s1.name;
    cout << "Enter roll number: ";
    cin >> s1.rollNo;
    cout << "Enter marks: ";
    cin >> s1.marks;
    cout << "\nStudent Information" << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Roll No: " << s1.rollNo << endl;
    cout << "Marks: " << s1.marks << endl;
    if (s1.marks >= 50)
        cout << "Result: Pass" << endl;
    else
        cout << "Result: Fail" << endl;
    return 0;
}
