#include <stdio.h>
#include <stdlib.h>


struct stack{
    int size;
    int top;
    char *arr;
};



int isEmpty(struct stack*ptr)
{
    if(ptr->top== -1)
    {
        // printf("ya");
        return 1;
    }
    else{
        return 0;
        }
}

int isfull(struct stack*ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
        }
}

void push(struct stack*ptr,char val)
{
if(isfull(ptr))
{
    printf("stack is full\n");
}
else
{
    ptr->top++;
    ptr->arr[ptr->top]=val;

}

}

char pop (struct stack*ptr)
{
if(isEmpty(ptr))
{
    printf("stack is empty\n");
    return -1; 
}
else    
{
    char val = ptr->arr[ptr->top];
    ptr->top--; 
    return val; 

}

}

int peek(struct stack*s,int i)
{
    int index=s->top - i + 1;
    if(index<0)
    {
        printf("invalid position\n");
        return -1;
    }
    return s->arr[index] ;

}



int parenthesisMatch(char * exp){
    // =(struct Stack*)malloc(sizeof(struct stack))
  struct stack *sp=(struct Stack*)malloc(sizeof(struct stack));
  sp->size=100;
  sp->top=-1;
  sp->arr=(char*) malloc(sp ->size * sizeof(char));
  
        

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
        {
                push(sp,'(');
        }

        else if (exp[i]==')' )
        {
           if(isEmpty(sp))
           {
            return 0;
           } 
          pop(sp);
        }

        
    }
    if(isEmpty(sp))
    {
        return 1; 
    }
    else
    {
        return 0;
    }

    
}
int main()
{
    char * exp="8*(9)(5)";
    
  if(parenthesisMatch(exp))
{
    printf("perenthesis is matching \n");
    return -1; 
}
else
{
    printf("perenthesis is not matching \n"); 

}    

 
    // if(isEmpty(s))
    // {
    //    printf("s is empty\n");
    // }
    // else
    // {
    //    printf("s is not empty\n");
    // }

    
    // if(isfull(s))
    // {
    //    printf("s is full");
    // }
    // else
    // {
    //    printf("s is not fulll");
    // }



return 0;

}