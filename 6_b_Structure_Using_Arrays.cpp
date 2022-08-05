#include<iostream>
using namespace std;

struct Employee {
    int emp_id;
    char name[50];
    int salary;

};

int main()
{
    struct Employee e[3];  

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the Id of Employee " << i+1 << " is: ";
        cin >> e[i].emp_id;

        cout << "Enter the Name of Employee " << i+1 << " is: ";
        cin >> e[i].name;
        
        cout << "Enter the Salary of Employee " << i+1 << " is: ";
        cin >> e[i].salary;
    }
    
    for (int i = 0; i < 3; i++)
    {
        cout << endl <<"The Id of Emplyee " << i+1 << " is: " << e[i].emp_id << endl;
        cout << "The Name of Emplyee " << i+1 << " is: " << e[i].name << endl;
        cout << "The Salary of Emplyee " << i+1 << " is: " << e[i].salary << endl;
    }
    


    return 0;
}