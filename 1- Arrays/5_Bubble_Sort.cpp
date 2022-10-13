#include<iostream>
using namespace std;

int main()
{
    int temp, n;
    cout << "\nEnter the number of elements you want in the array : ";
    cin >> n;
 
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << (i+1) << " element of the array: ";
        cin >> arr[i];
    }

    cout << "\n\nThe elements after bubble sort are: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n-1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    


    return 0;
}