#include<iostream>
using namespace std;

struct student{
    int roll_no;
    char name[40];
    float cgpa;
};


int main()
{
    struct student s1;
    cout << "Enter the Roll Number of Student 1: ";
    cin >> s1.roll_no;

    cout << "Enter the Name of Student 1: ";
    cin >> s1.name;

    cout << "Enter the CGPA of Student 1: ";
    cin >> s1.cgpa;

    cout << endl << "The Roll Number of the Student 1 is : " << s1.roll_no << endl;
    cout << "The Name of the Student 1 is : " << s1.name << endl;
    cout << "The CGPA of the Student 1 is : " << s1.cgpa << endl;


    return 0;
}