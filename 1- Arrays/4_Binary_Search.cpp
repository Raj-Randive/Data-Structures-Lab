#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){

    int mid;
    for (int i = start; i < end; i++)
    {
        mid = (start+end)/2;
        if (arr[mid] < key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }

        if (arr[mid] == key){
            cout << "Found at position: " << mid+1;
        }
        else{
            cout << "Not Found";
        }
    }
    return 0;
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

    int key, start = 0, end = (n-1);
    cout << "\n\nEnter the element you want to find: ";
    cin >> key;

    binarySearch(arr, start, end, key);
    
    delete []arr;
    return 0;
}