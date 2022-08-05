#include <stdio.h>

int main(int argc, char const *argv[])
{
    int temp, n;

    printf("Enter the number of elements you want in the array : ");
    scanf("%d", &n);

    int arr[n];

    for (int j = 0; j < n-1; j++)
    {
        scanf("%d ", &arr[j]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    printf("%d ", arr[i]);
    }

    return 0;
}
