#include<stdio.h>
#include<stdlib.h>


typedef struct POINT
{ int x,y;
}point;

typedef struct myQueue
{
  point **pt;
  int front,rear,size;
}Queue;

Queue *createqueue(int r, int c)
{
    Queue* q =(Queue*) calloc(1,sizeof(Queue)); //memory allocated to structure


     q->size=r*c;
     q->pt =(point**) calloc(q->size,sizeof(point*)); //memory allocated to pt
     q->front=-1;
     q->rear=-1;

return q;
}

int isfull(Queue *q)
{
    if(q->rear == q->size-1)
            return(1);
    else
            return(0);
}

int isempty(Queue *q)
{ if(q->front==q->size)
  return 1;
else
   return 0;
}


void enqueue(Queue *q, point *p)
{


       if(isfull(q) == 1)
       {
               printf("Queue is Full\n");
               exit(1);
       }

if(q->rear==-1)
{ q->front=0;
 q->pt[++q->rear] = p;
}
else
q->pt[++q->rear] = p;

}

point *dequeue(Queue *q)
{  if(isempty(q)==1)
   { printf("Queue is empty\n");
        exit(1);
   }

else
return q->pt[q->front++];
}




int main()
{ int r,c,i,j,**ar,**ans;


printf("enter rows");
scanf("%d",&r);
printf("enter columns");
scanf("%d",&c);

Queue *q=createqueue(r,c);

ar=(int**) calloc(r*c,sizeof(int));
ans=(int**) calloc(r*c,sizeof(int));

printf("\nenter the pattern row-wise(only 0s and 1s)\n");

for(i=0;i<r;i++)
{ for(j=0;j<c;j++)
	scanf("%d",&ar[i][j]);
}

for(i=0;i<r;i++)
{ for(j=0;j<c;j++)
  {	if(ar[i][j]==1)
	ans[i][j]=0;
	if(ar[i][j]=0)
	ans[i][j]=-1;
  }
}

point *s,*e;

printf("enter start coordinates (x,y)");
scanf("%d,%d",&s->x,&s->y);

printf("enter end coordinates (x,y)");
scanf("%d,%d",&e->x,&e->y);

ans[s->x][s->y]=1;
enqueue(q,s);

while(!isempty(q))
{  point *temp;
point *P;
temp=dequeue(q);

	if(temp->y-1>=0)
	{	if(ans[temp->x][temp->y-1]==0)
		{ans[temp->x][temp->y-1]=ans[temp->x][temp->y]+1;
		 
		 P->x=temp->x;
		 P->y=temp->y-1;		 
		enqueue(q,P);
		}
	}
	
	if(temp->y+1<c)
	{	if(ans[temp->x][temp->y+1]==0)
		{ans[temp->x][temp->y+1]=ans[temp->x][temp->y]+1;
		
		 P->x=temp->x;
		 P->y=temp->y+1;		 
		enqueue(q,P);
		}
	}
	
	if(temp->x-1>=0)
	{	if(ans[temp->x-1][temp->y]==0)
		{ans[temp->x-1][temp->y]=ans[temp->x][temp->y]+1;
		P->x=temp->x-1;
		 P->y=temp->y;		 
		enqueue(q,P);
		}
	}

	if(temp->x+1<r)
	{	if(ans[temp->x+1][temp->y]==0)
		{ans[temp->x+1][temp->y]=ans[temp->x][temp->y]+1;
		P->x=temp->x+1;
		 P->y=temp->y;		 
		enqueue(q,P);
		}
	}
}

printf("\n\nMinimum distance to reach end point is: %d",ans[e->x][e->y]);

return 0;
}



			


        

