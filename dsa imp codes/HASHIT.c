#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char hashTable[101][17]; //17 because first char is indication of empty/non empty

int h(char str[])
{ int i,l,d=0;
l=strlen(str);
    for(i=0;i<l;i++)
    d+=((int)str[i])*(i+1);
    d=19*d;
return d;
}

int hash(char str[])
{ return (h(str)%101);
}

void add(char str[])
{ int index,j,l,i,f,flag=0;
l=strlen(str);
for(f=0;f<101;f++)
{ if(hashTable[f][0]=='Y')
{ for(i=1;i<=l;i++)
    {
        if(hashTable[f][i]!=str[i-1])
        { flag=0;break;}
        else 
        flag++;
    }
if(flag==l)
{
    // printf("returmed");
return;
}
}
}
         for(j=0;j<20;j++)
        { index=(hash(str)+(j*j)+(23*j))%101;
        //dbug
        // printf("%d\n",index);  
                if(hashTable[index][0]=='N')
                {   for(i=1;i<=l;i++)
                    hashTable[index][i]=str[i-1];
                hashTable[index][i]='\0';
                hashTable[index][0]='Y';
                break; //to stop further iteration of j
                }
        }
}    

void delt(char str[])
{int index,j,l,i,k,flag=0;
l=strlen(str);
         for(j=0;j<20;j++)
        { index=(hash(str)+(j*j)+(23*j))%101; 
            if(hashTable[index][0]=='Y')
        {   flag=0;    
            for(k=1;k<=l;k++)
                {    if(hashTable[index][k]!=str[k-1])
                    { flag=0;break;}
                    else 
                    flag++;
                }
            if(flag==l)
            {
            hashTable[index][0]='N';
            break;
            }
        }
        }


}

int main()
{ int f,t,n1,g,count=0,x,mb;
char s1[4],s2[16],temp;

scanf("%d",&t);
scanf("%d",&n1);

for(g=1;g<=t;g++)
{   for(f=0;f<101;f++)
    hashTable[f][0]='N';
    for(mb=1;mb<=n1;mb++)
    {
    // { scanf("%c%[^:]%c%[^\n]",&temp,s1,&temp,s2);
            char opp[25];
            scanf("%s",opp);
            int i=4;
            for(i=4;opp[i]!='\0';i++)
                s2[i-4]=opp[i];
            s2[i-4]='\0';
        // printf("%s",s1);
        // printf("%d",s1[0]);
        if(opp[0]=='A')
        {
            // printf("called add");
        add(s2);    
        }
        else
        delt(s2);
    }
for(f=0;f<101;f++)
{   if(hashTable[f][0]=='Y')
    count++;
}
printf("%d\n",count);
for(f=0;f<101;f++)
{   if(hashTable[f][0]=='Y')
    { 
        printf("%d:",f);
        for(x=1;hashTable[f][x]!='\0';x++)
        printf("%c",hashTable[f][x]);
    printf("\n");
    }
}
}
return 0;
}    


