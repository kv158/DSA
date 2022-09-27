#include <stdio.h>
#include <stdlib.h>


struct stack{
    int size;
    int top;
    int *arr;
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

void push(struct stack*ptr,int val)
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

int pop (struct stack*ptr)
{
if(isEmpty(ptr))
{
    printf("stack is empty\n");
    return -1; 
}
else
{
    int val = ptr->arr[ptr->top];
    ptr->top--; 
    return val;

}

}

int stacktop (struct stack*s)
{
    return s->arr[s->top];
}

int stackbottom (struct stack*s)
{
    return s->arr[0];
}

int main()
{
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int*) malloc(s.size *sizeof(int));

  struct stack *s=(struct Stack*)malloc(sizeof(struct stack)); 
    s->size=10;
    s->top=-1;
    s->arr=(int*) malloc(s ->size * sizeof(int));

    printf("%d\n",isfull(s));
    printf("%d\n",isEmpty(s));

    push(s,98);
    push(s,15);
    push(s,9);
    push(s,4);
    push(s,9);
    push(s,36);
    push(s,41);
    push(s,12);
    push(s,32);
    push(s,65);

    printf("poped %d from stack\n" ,pop(s));
    printf("poped %d from stack\n" ,pop(s));
    printf("poped %d from stack\n" ,pop(s));

    printf("%d\n",isfull(s));
    printf("%d\n",isEmpty(s));

    printf("top most value is %d\n",stacktop(s));
    printf("bottem most element is %d\n",stackbottom(s));


    
    

 
  

return 0;

}