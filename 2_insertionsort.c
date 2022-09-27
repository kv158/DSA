#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionsort(int *a, int n)
{
    int key, j;

    for (int i = 0; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {12, 36, 54, 96, 45, 26};
    int n = 6;

    printarray(a, n);
    insertionsort(a, n);
    printarray(a, n);

    return 0;
}