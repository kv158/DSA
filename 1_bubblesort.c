#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubblesort(int *a, int n)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("pass no %d \n ", i + 1);
        issorted = 1;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issorted = 0; 
            }
           
        }
         if (issorted)
            {
                return;

            }
    }
}

int main()
{
    int a[] = {12, 36, 54, 96, 45, 26};
    int b[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    printarray(a, n);
    bubblesort(a, n);
    printarray(a, n);

    printarray(b, n);
    bubblesort(b, n);
    printarray(b, n);

    return 0;
}