#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{ int top;
int ar[100];
}stack;



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
{ stack *s;
s=(stack*) calloc(1,sizeof(stack));
s->top=-1;
int i,k=0,j,res,opr1,opr2;
char str[100],temp[100];
/*printf("how many operands do you want to enter?");
scanf("%d",&n1);
printf("how many operators do you want to enter?");
scanf("%d",&n2);
for(i=1;i<=n1;i++)
{       scanf("%d",&k);
        push(s,k);
}*/

printf("enter the expression\n");
scanf("%s",str);


for(i=0;str[i]!='\0';i++)
{ if(str[i]!=' ' || str[i]!='\0')
   temp[k++]=str[i];
else 
{ temp[k]='\0';
k=0;

//for(j=1;j<=n2;j++)
        //{scanf("\n%c",&op);
                if(strcmp(temp,"+")==0)
                {opr1=pop(s);
                opr2=pop(s);
                res=opr1+opr2;
                push(s,res);
                }

                else if(strcmp(temp,"-")==0)
                { opr1=pop(s);
                 opr2=pop(s);
                 res=opr2-opr1;
                 push(s,res);
                }
                        else if(strcmp(temp,"*")==0)
                        { opr1=pop(s);
                                          opr2=pop(s);
                                          res=opr1*opr2;
                                          push(s,res);
                        }
                        else if(strcmp(temp,"/")==0)
                        { opr1=pop(s);
                                          opr2=pop(s);
                                          res=opr2/opr1;
                                          push(s,res);

                }
				else
				{ int n;
				n=atoi(temp);
				printf("%d",n);
				push(s,n);
				}
		}
}
int ans=pop(s);

printf("evaluation of expression is: %d",ans);

return 0;
}


