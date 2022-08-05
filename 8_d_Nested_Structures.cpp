// #2 Approach

#include<iostream>
using namespace std;

struct structure2 {
    
    int org_id;
    char org_name[50];

    struct structure1 {
        int emp_id;
        char emp_name[50];
        int emp_salary;

    }e[3];
    
};

int main()
{
    struct structure2 o;

    cout << endl << "Enter the Id of Organisation : ";
    cin >> o.org_id;

    cout << "Enter the Name of Organisation : ";
    cin >> o.org_name;
    
    for (int i = 0; i < 3; i++)
    {
        cout << endl << "Enter the Id of Employee " << i+1 << " of Organisation : ";
        cin >> o.e[i].emp_id;

        cout << "Enter the Name of Employee " << i+1 << " of Organisation : ";
        cin >> o.e[i].emp_name;
        
        cout << "Enter the Salary of Employee " << i+1 << " of Organisation : ";
        cin >> o.e[i].emp_salary;
    }

    cout << "\n\nThe Organisation Id is : " << o.org_id;
    cout << "\nThe Organisation Name is : " << o.org_name;
    
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\nThe Name of Employee " << i+1 << " is : " << o.e[i].emp_id;
        cout << "\nThe Id of Employee " << i+1 << " is : " << o.e[i].emp_name;
        cout << "\nThe Salary of Employee " << i+1 << " is : " << o.e[i].emp_salary;
    }
    

    return 0;
}