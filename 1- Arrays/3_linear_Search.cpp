#include<iostream>
using namespace std;

int main()
{
    int n, key;
    cout << "Enter the number of elements you want in the array: ";
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i+1 << " element of the array: " ;
        cin >> arr[i];
    }

    cout << "\n\nEnter the element/item to be searched: ";
    cin >> key;

    int j = 0;
    while (j<n && key != arr[j])
    {
        j++;
    }

    if (j<n){
        cout << "The element is found at position: " << j+1;
    }
    else{
        cout << "The required element is not in the array: ";
    }
    
    

    
    delete []arr;
    return 0;
}