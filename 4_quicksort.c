#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[],int low ,int high)
{
    int pivot=a[low];
    int i=low+1 ;
    int j =high;
    do{
    while(a[i]<=pivot)
    {
        i++;   
       
    }
      while(a[j]>pivot)
    {
       j--;   
    }

    if(i<j)
    {
       int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    }
    while (i<j); 

    int temp=a[low];
        a[low]=a[j];
        a[j]=temp;
        return j;
       
   
}

void quicksort(int a[], int low, int high)
{
    int partitionindex, temp;

    if (low < high) 
    {
        partitionindex = partition(a, low, high);
        quicksort(a, low, partitionindex - 1);  // left sub array
        quicksort(a, partitionindex + 1, high); // left sub array
    }
}

int main()
{
    int a[] = {12, 36, 54, 96, 45, 26};
    int n = 6;

    printarray(a, n);
    quicksort(a, 0, n - 1);
    printarray(a, n);

    return 0;
}