#include<stdio.h>
#include<stdlib.h>

typedef struct
{ int top;
int *ar;
}stack;

int n;
void push(stack *s,int value)
{ if(s->top==n-1)
        printf("overflow");
else
        s->ar[++s->top]=value;
}

int empty(stack *s)
{ if(s->top==-1)
        return 1;
else
        return 0;
}

int pop(stack *s)
{ if(!empty(s))
        return s->ar[s->top--];
}

int main()
{ stack *s;
s=(stack*) calloc(1,sizeof(stack));
s->top=-1;
int ans=1,i;
scanf("%d",&n);
(s->ar)=(int*) calloc(n,sizeof(int));

for(i=n;i>1;i--)
        push(s,i);

while(!empty(s))
        ans=ans*pop(s);

printf("%d",ans);

return 0;
}            
