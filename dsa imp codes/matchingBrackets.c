#include<stdio.h>
#include<stdlib.h>

typedef struct 
{ int top;
	char ar[100];
}stack;

void push(stack *s,char value)
{ if(s->top==99)
        printf("overflow");
else
        s->ar[++s->top]=value;
}


char complement(char r)
{ if(r=='}')
return '{';
if(r==']')
	return '[';
if(r==')')
	return '(';
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
int i,l=0;
char str[100],c;
gets(str);

for(i=0;str[i]!='\0';i++)
	l++;

for(i=0;i<l;i++)
{ if(str[i]=='{' || str[i]=='[' || str[i]=='(')
	push(s,str[i]);
else
{	c=pop(s);

if(c!=complement(str[i]))
{printf("invalid expression");
exit(1);
}
}
}

if(!empty(s))
	printf("invalid expression");
else
	printf("valid expression");

return 0;
}



