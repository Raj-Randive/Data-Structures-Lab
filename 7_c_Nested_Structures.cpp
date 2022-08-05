// #1 Approach

#include<iostream>
using namespace std;

struct structure1 {

    int emp_id;
    char emp_name[50];
    int emp_salary;

};

struct structure2 {

    struct structure1 emp[3];
    
    int org_id;
    char org_name[50];
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
        cin >> o.emp[i].emp_id;

        cout << "Enter the Name of Employee " << i+1 << " of Organisation : ";
        cin >> o.emp[i].emp_name;
        
        cout << "Enter the Salary of Employee " << i+1 << " of Organisation : ";
        cin >> o.emp[i].emp_salary;
    }

    cout << "\n\nThe Organisation Id is : " << o.org_id;
    cout << "\nThe Organisation Name is : " << o.org_name;
    
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\nThe Name of Employee " << i+1 << " is : " << o.emp[i].emp_id;
        cout << "\nThe Id of Employee " << i+1 << " is : " << o.emp[i].emp_name;
        cout << "\nThe Salary of Employee " << i+1 << " is : " << o.emp[i].emp_salary;
    }
    

    return 0;
}