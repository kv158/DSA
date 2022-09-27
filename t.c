#include <stdio.h>
#include<stdlib.h>
#include <limits.h>


struct stack    
{
    int size;
    int top;
    int *arr;
};

int Empt(struct stack * s)
{
  if(s->top ==-1)
  {
    return 1 ;
  }

}

int main()
{
    struct stack *s=(struct Stack*)malloc(sizeof(struct stack)); 
    s->size=80;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    // empt(s);

       
    if(Empt(s))
    {
        printf("stack is empty");
    }
    else
    {
        printf("stack is not empty");

    }

// printf("%d",s->top);

 
return 0;
}