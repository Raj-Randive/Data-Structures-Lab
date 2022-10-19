#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void binarySearch(int arr[], int size, int key){

    int i=0, mid, beg = 0, end;
    end = size;
    mid = (beg + end)/2;
    while( beg <= end && arr[mid] != key ) {
        if (key < mid) {
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }
        mid = (beg + end)/2;
        i++;
    }
    if (arr[mid] == key) {
        cout << "The element found at position: " << (mid+1) << endl;
    }
    else {
        cout << "The element NOT found!" << endl;
    }
}

void sortArray(int arr[], int size){
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0 ; j < size-1; j++)
        {
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 
}

void showArray(int arr[], int size){
    cout << "\nThe Entered array is: "; 
    for (int i = 0; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements you want in the array: ";
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i+1 << " element of the array: " ;
        cin >> arr[i];
    }

    sortArray(arr, n);
    showArray(arr, n);

    int key;
    cout << "\n\nEnter the element you want to find: ";
    cin >> key;

    binarySearch(arr, n, key);
    
    delete []arr;
    return 0;
}