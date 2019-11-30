#include<stdio.h>
#include<stdlib.h>


//int cnt=0;

typedef struct myQueue
{
  int *Q;
  int front,rear,size;
}Queue;

Queue* createqueue()
{
    Queue* q =(Queue*) calloc(1,sizeof(Queue)); //memory allocated to structure


     q->size=10;
     q->Q =(int*) calloc(q->size,sizeof(int)); //memory allocated to Q
     q->front=-1;
     q->rear=-1;

return q;
}

/*int isfull(Queue* q)
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
*/

void print_queue(Queue *q)
{ 
int i;
if(q->front<q->rear)
{
for(i=q->front;i<=q->rear;i++)
printf("%d\n",q->Q[i]);
}

else
{ for(i=q->front;i<=9;i++)
printf("%d\n",q->Q[i]);
for(i=0;i<=q->rear;i++)
printf("%d\n",q->Q[i]);
}
}

void enqueue(Queue *q, int k) //imp note:always take care of dangling else problem!!!!!!!!! ; this created a problem in printing; PS:the code is now corrected
{


       if((q->rear==9 && q->front==0) || (q->rear==q->front-1))
       {
               printf("Queue is Full\n");
               return;
       }

if(q->rear==9 && q->front!=0)
{ q->rear=0;
q->Q[q->rear]=k;
}


else if(q->rear==-1)
{ q->front=0;
 q->Q[++q->rear] = k;
}

else
q->Q[++q->rear] = k;

//cnt++;
}

int dequeue(Queue *q)
{  if(q->front==-1)
   { printf("Queue is empty\n");
        exit(1);
   }
else if(q->front==q->rear)
{ int n=q->front;
q->front=q->rear=-1;
return q->Q[n];
}

else if(q->front==9)
{ q->front=0;
return q->Q[q->front++];
}

else 
return q->Q[q->front++];
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
enqueue(q,11); //will give queue is full message as we have not even dequeued a single element

print_queue(q); //will print queue

int element=dequeue(q);
printf("\ndequeue ele is:%d\n\n",element); //front=1

enqueue(q,12); //now it won't print queue is full message as we have dequeued first element,abhi front is 1 and rear is 0


print_queue(q); 


return 0;
}



