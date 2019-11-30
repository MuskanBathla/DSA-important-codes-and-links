#include<stdio.h>
#include<stdlib.h>


typedef struct tree
{ int item;
struct tree *right,*left;
}tree;

typedef struct stack
{ int top;
int ar[100];
}stack;

tree* insert(int value, tree* t)
{  if(t==NULL)
        { t=(tree*) calloc(1,sizeof(tree));
        t->item=value;
        t->right=t->left=NULL;
        }
   else if(t->item>value)
        t->left=insert(value,t->left);
   else if(t->item<value)
        t->right=insert(value,t->right);
return t;
}


void push(stack *s,int value)
{ if(s->top==99)
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
{ int d,i=1,n,m;
stack *s1,*s2;
tree *t=NULL;

s1=(stack*) calloc(1,sizeof(stack));
s2=(stack*) calloc(1,sizeof(stack));


printf("how many nodes do u want (<=100)?");
scanf("%d",&n);

printf("enter the nodes in preorder");
while(i<=n)
{ scanf("%d",&d);
push(s1,d);
i++;
}

while(!empty(s1))
{ 
m=pop(s1);
push(s2,m);
}

while(!empty(s2))
{ m=pop(s2);
t=insert(m,t);
}

return 0;
}





