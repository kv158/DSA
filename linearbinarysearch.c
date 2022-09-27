#include <stdio.h>


int linearsearch(int arr[],int size,int element)
{

    for (int i = 0; i < size; i++)
    {
       if(arr[i]==element){ 
        return i;
       }
    }
    return -1;
}

int binarysearch(int arr[],int size,int element)
{
    int low=0 ,mid,high=size-1;
    while (low<=high)
    {

    mid=(low+high)/2;
    if(arr[mid]== element){
    return mid;
    }
     if(arr[mid]< element){
    low=mid+1;
    }
    else
    {
    high=mid-1;
        
    }
    }
    return -1;

}




int main()
{
int arr[]={2,3,4,5,6,8,9,21,22,25};
int size=sizeof(arr)/sizeof(int);
int element=5;
int element2=9;

int posl=linearsearch(arr,size,element);
int posb=binarysearch(arr,size,element2);

printf("element %d found  at %d\n " ,element ,posl);
printf("element %d found  at %d " ,element2 ,posb);
return 0;
}