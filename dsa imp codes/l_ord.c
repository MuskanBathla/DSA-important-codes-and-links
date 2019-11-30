#include<stdio.h>
#include<stdlib.h>

int cnt=0;

typedef struct tree
{ int item;
struct tree *right,*left,*ns,*fc;
}tree;

typedef struct myQueue
{
  tree **Q;
  int front,rear,size;
}Queue;

Queue* createqueue()
{
    Queue* q =(Queue*) calloc(1,sizeof(Queue)); //memory allocated to structure


     q->size=100;
     q->Q =(tree**) calloc(q->size,sizeof(tree*)); //memory allocated to Q
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


void enqueue(Queue *q, tree* k)
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

tree* dequeue(Queue *q)
{  if(isempty(q)==1)
   { printf("Queue is empty\n");
        exit(1);
   }

else
return q->Q[q->front++];
}





tree* find(int value,tree* t)
{ if(t==NULL)
  printf("not found");
else if(t->item>value)
return find(value,t->left);
else if (t->item<value)
return find(value,t->right);

return t;
}

tree* findmin(tree *t)
{ if(t==NULL)
printf("empty tree");
if(t->left!=NULL)
return findmin(t->left);
else
return t;
}

tree* findmax(tree *t)
{ if(t==NULL)
printf("not found");
if(t->right==NULL)
return t;
else
return findmax(t->right);
}



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
tree* delete(int value,tree *t)
{ tree *temp,*z;
        if(t==NULL)
         printf("tree is empty");
        else if(t->item>value)
        t->left=delete(value,t->left);
        else if(t->item<value)
        t->right=delete(value,t->right);
        else if(t->right!=NULL && t->left!=NULL) //two children case
        { temp=findmin(t->right);
        t->item=temp->item;
        t->right=delete(temp->item,t->right);
        free(temp);
        }

	else if(t->right==NULL && t->left==NULL) //zero child case.
	{ z=t;
		free(z);
	}

        else //one child case 
        {       if(t->left==NULL)
                { z=t;
                  t=t->right;
                free(z);
                }
                else  
                { z=t;
                 t=t->left;
                free(z);
                }
        }
return t;
}

void level(tree *t)
{ Queue *q;
q=createqueue();
tree *curr,*dum;
if(t==NULL)
return;

enqueue(q,t);

while(!isempty(q))
{ curr=q->Q[q->front];
dum=dequeue(q);

if(curr->left)
enqueue(q,curr->left);

if(curr->right)
enqueue(q,curr->right);

printf("%d ",curr->item);
}
}


int main()
{ tree *t;
Queue *q;
int val,i=1;
t=NULL;
while(i<=3)
{
printf("enter value to insert");
scanf("%d",&val);

t=insert(val,t);
i++;
}

level(t);
printf("\n");


/*t=delete(19,t);
printf("\ndeleted from tree with root node: %d\n",t->item);

rn=find(22,t);
printf("node found %d\n",rn->item);

rn=findmin(t);
printf("min node %d\n",rn->item);

rn=findmax(t);
printf("max node found %d\n",rn->item);*/

return 0;
}
