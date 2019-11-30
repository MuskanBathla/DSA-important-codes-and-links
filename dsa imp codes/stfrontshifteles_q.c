#include<stdio.h>
#include<stdlib.h>


int cnt=0;

typedef struct myQueue
{
  int *Q;
  int front,rear,size;
}Queue;

Queue* createqueue()
{
    Queue* q =(Queue*) calloc(1,sizeof(Queue)); //memory allocated to structure


     q->size=100;
     q->Q =(int*) calloc(q->size,sizeof(int)); //memory allocated to Q
     q->front=-1;
     q->rear=-1;

return q;
}

int isfull(Queue* q)
{
    if(q->rear == q->size)
            return(1);
    else
            return(0);
}

int isempty(Queue *q)
{ if(q->front==-1)
  return 1;
else
   return 0;
}


void enqueue(Queue *q, int k)
{


       if(isfull(q) == 1)
       {
               printf("Queue is Full\n");
               return;
       }

if(q->rear==-1)
{ q->front=0;
 q->Q[++q->rear] = k;
}
else
q->Q[++q->rear] = k;
cnt++;
}

int dequeue(Queue *q)
{  int x;
if(isempty(q)==1)
   { printf("Queue is empty\n");
        exit(1);
   }

else
//return q->Q[q->front++];
{ int j;
x=q->Q[q->front];

for(j=0;j<q->rear;j++)
q->Q[j]=q->Q[j+1];

q->rear--;
}

return x;
}


int main()
{
      Queue* q=createqueue();

enqueue(q,1);
enqueue(q,2);
enqueue(q,3);
enqueue(q,4);
enqueue(q,5);
enqueue(q,6);
enqueue(q,7);
enqueue(q,8);
enqueue(q,9);
enqueue(q,10);

for(int i=q->front;i<=q->rear;i++)
printf("%d\n",q->Q[i]);

      int element=dequeue(q);
      printf("\ndeq ele%d\n",element);

for(int i=q->front;i<=q->rear;i++)
printf("%d\n",q->Q[i]);

/* element=dequeue(q);
      printf("\ndeq ele%d\n",element);

for(int i=q->front;i<=q->rear;i++)
printf("%d\n",q->Q[i]);
*/

        return 0;

}



