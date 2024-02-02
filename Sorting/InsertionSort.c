#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,min,x,ch,temp;
    printf("Enter 1 for sorting in ascending order\nEnter 2 for sorting in descending order\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    printf("Enter size of array\n");
    scanf("%d",&x);
    int a[x];
    printf("Enter %d numbers to be sorted in the array\n",x);
    for(i=0;i<x;i++)
    scanf("%d",&a[i]);
    printf("Unsorted array :\n");
    for(i=0;i<x;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
     for(i=0;i<x;i++)
    {
        temp=a[i];
        if(ch==1)
        {
          for(j=i-1;j>=0 && a[j]>temp;j--)
          a[j+1]=a[j];
        }
        else if(ch==2)
        {
         for(j=i-1;j>=0 && a[j]<temp;j--)
          a[j+1]=a[j];

        }
        else
        {
            printf("Invalid inpiut");
            exit(1);
        }
        a[j+1]=temp;
    }
    if(ch==1)
    {
        printf("The sorted array in ascending order\n");
         for(i=0;i<x;i++)
    {
        printf("%d ", a[i]);
    }
    }
    if(ch==2)
    {
        printf("The sorted array in descending order\n");
         for(i=0;i<x;i++)
    {
        printf("%d ", a[i]);
    }

    }
}
