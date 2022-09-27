#include <stdio.h>
#include<limits.h>
#include<stdlib.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int a[], int n)
{int max=INT_MIN; 
    for (int i = 0; i < n; i++)
    {
        if(a[i]>max)
        {
            max=a[i];
       
        }
    }
     return max;
}

void countsort(int *a, int n)
{ int i,j;
    int mmax=max(a,n);
    int * count=(int *)malloc((mmax+1)*sizeof(int));

    for (int i = 0; i <= mmax+1 - 1; i++)
    {
        count[i]=0;
      
    }
     for (i = 0; i <= n - 1; i++)
    {
       count[a[i]]= count[a[i]]+1;
      
    }
    i=0;
    j=0;

    while(i<=mmax)
    {
        if(count[i]>0)
        {
            a[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else
        {
            i++;
        }
        
        
    }
}

int main()
{
    int a[] = {12, 36, 54, 96, 45,26 };
    int n = 6;

    printarray(a, n);
    countsort(a, n);
    printarray(a, n);

    return 0;
}