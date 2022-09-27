#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct stack{
    int size;
    int top;
    char *arr;
};

int stacktop (struct stack*s)
{
    return s->arr[s->top];
}

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


int precedence(char ch)
{
    if (ch=='*' || ch=='/')
    {
        return 3;
    }
    else if (ch=='+' || ch=='-')
    {
        return 2;    
    }
    else
    {
        return 0;
    }
    
}

int isoperater(char ch){
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

}




char * infixtopostfix(char * infix)
{
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100 ;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*(sizeof(char)));

    char *postfix=(char*)malloc((strlen(infix)+1)*(sizeof(char)));
    int i=0; //track infix traversal
    int j=0;  //track postfix addition

    while (infix[i]!='\0')
    {
       if(!isoperater(infix[i]))
       {
        postfix[j]=infix[i];
        j++;
        i++;
       }
       else
       {
        if(precedence(infix[i])>precedence(stacktop(sp)))
        {
            push(sp,infix[i]);
            i++;
        }
        else
        {
            postfix[j]=pop(sp);
            j++;

        }
        

       }
    }
    
    while (!isEmpty(sp))
    {
       postfix[j]=pop(sp);
       j++;
    }
    postfix[j]='\0';
    return postfix;

    

}



int main()
{
    char * infix="x-y/z-k*d"; 
    printf("infix is = %s \npost fix is = %s" ,infix,infixtopostfix(infix));
  



return 0;

}