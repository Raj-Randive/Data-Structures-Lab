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


    int item;
    cout << "\n\nEnter the position at which you want to insert: " ;
    cin >> k;
    cout << "Enter the element: " ;
    cin >> item;

    for (int j = (n-1); j >= (k-1); j--)
    {
        p[j+1] = p[j];
    }
    p[k-1] = item;

    n = n+1;
    cout << "Elements of the array after insertion of element " << item << " is: ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n\n";

    return 0;
}