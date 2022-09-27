#include<stdio.h>

void display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
            printf("%d ", arr[i]);

    }
                printf("\n");

}

void insert(int arr[],int size,int element,int capacity,int index)
{
    if(size>=capacity){
                        printf("error");

    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    


}

int main(){
    int arr[100]={1,2,3,5};
    int size=4,element=4,index=3;
    display(arr,size);
    insert(arr,size,element,100,index);
    size +=1;
        display(arr,size);

}