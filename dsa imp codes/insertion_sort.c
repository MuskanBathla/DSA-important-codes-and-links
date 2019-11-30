#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int *ar,int size)
{
    int i,j,t;
    for(i=0;i<size;i++)
    {   t=ar[i];
        j=i-1;
        while(j>=0 && t<ar[j])
        {
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=t;

    }

}

int main()
{
    int *ar,i,size;
    scanf("%d",&size);
    ar=(int*)calloc(size,sizeof(int));
    for(i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
    insertion_sort(ar,size);
    printf("\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
return 0;
}


