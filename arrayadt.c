#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct myArray
{
    int totals;
    int useds;
    int *ptr;
    /* data */
};
void createArray(struct myArray* a , int tsize ,int usize)
{
    (*a).totals=tsize;
        (*a).useds=usize;
     (*a). ptr = (int *)malloc(tsize * sizeof(int));
}

void show(struct myArray* a)
{
    for (int i = 0; i <a->useds; i++)
    {
       printf("%d\n",(a->ptr)[i]);
    }
    
}
void setValue(struct myArray* a)
{
   int n;
    for (int i = 0; i <a->useds; i++)
    {
       printf("enter value %d", i);
       scanf("%d\n",&n);
       (a->ptr)[i]=n;   
    }
    
}

int main(){
    struct myArray marks;
    createArray(&marks,10,2);
    setValue(&marks);
    show(&marks);

}