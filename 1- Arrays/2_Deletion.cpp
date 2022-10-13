// say array is:  4 6 8 3 7 2
#include<iostream>
using namespace std;

int main()
{
    int n, k, temp;
    cout << "\nEnter the number of elements you want in the array: ";
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i+1 << " element of the array: ";
        cin >> p[i];
    }

    cout <<"\nThe elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i]<< " ";
    }


    cout << "\n\nEnter the position of element you want to delete: " ;
    cin >> k;

    for (int j = k-1; j < n-1; j++)
    {
        p[j] = p[j+1];
    }

    n = n-1;
    cout << "Elements of the array after deletion is: ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}