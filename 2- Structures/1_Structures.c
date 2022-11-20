#include<stdio.h>
#include<string.h>

struct Employee{
    int emp_id;
    char name[50];
    int salary;
};

int main()
{
    struct Employee e;
    e.emp_id = 1001;
    e.salary = 100000;
    // e.name = "Raj";    // this will give us an error
    strcpy(e.name, "Raj");

    printf("\nThe Employee id is: %d", e.emp_id);
    printf("\nThe Employee Name is: %s", e.name);
    printf("\nThe Employee Salary is: %d", e.salary);


    return 0;
}