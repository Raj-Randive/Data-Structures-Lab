#include<stdio.h>

int main()
{
    char arr[50];
    int n;
    int enteredNum;
    printf("Enter the number of elements of the array : ");
    scanf("%d", &n);
    
    for (int i = 0; i < n ; i++)
    {
        printf("Enter the elements of the array : ");
        scanf("%d", &arr[i]);
    }

    printf("Enter the item to be searched : ");
    scanf("%d", &enteredNum);

    int j =0; 
    while (j < n && enteredNum != arr[j]) {
        j++;
    }
 
    if (j < n) {
        printf("The element is found in the position = %d", j + 1);
    } else {
        printf("Element is not in the array !");
    }

    return 0;
}
