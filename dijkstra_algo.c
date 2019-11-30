//dijkstra's algo for 5 node graph

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct dijkstra
{
    int mark,dist;
}dijkstra;

int adjMatrix[6][6],dummy[6];
dijkstra d[6];




void addEdge(int i,int j, int weight)
{
    adjMatrix[i][j]=weight;
    adjMatrix[j][i]=weight;

}
int check()
{
    int i,cnt=0;
    for(i=1;i<=5;i++)
    {
        if(d[i].mark==0)
        {
            cnt++;
            dummy[i]=d[i].dist;
        }
        else
        {
            dummy[i]=INT_MAX;
        }
        
    }
    if(cnt!=0)
    return 1;
    else
    return 0;
        
}

int min(int arr[])
{
    int i,pos=1,m;
    m=arr[1];
    for(i=2;i<=5;i++)
    {   if(arr[i]<m)
        {
            pos=i;
            m=arr[i];
        }
    }
    return pos;
}
void algo(int s,int t)
{
    int i,j,w;
    for(i=1;i<=5;i++)
    {
        d[i].dist=INT_MAX;
        d[i].mark=0;
    }
    d[s].dist=0;
    
    while(check())
    {
        int v=min(dummy);
        d[v].mark=1;
        for(w=1;w<=5;w++)
        {
            if(adjMatrix[v][w]!=0 && d[w].mark==0 && (d[w].dist>d[v].dist+adjMatrix[v][w]))
            {
               d[w].dist=d[v].dist+adjMatrix[v][w];
               
            }
        }

    }

}
int main()
{
    int i,j,s,t;
    dummy[0]=INT_MAX;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        adjMatrix[i][j]=0;
        
    }
    addEdge(1,2,2);
    addEdge(2,3,6);
    addEdge(3,4,8);
    addEdge(4,5,9);
    addEdge(5,1,1);
    addEdge(5,2,3);
    printf("enter source");
    scanf("%d",&s);
    printf("enter target");
    scanf("%d",&t);
    algo(s,t);
    printf("%d",d[t].dist);
}
