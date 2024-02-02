#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,temp,ch,n,m;
     printf("Enter 1 for Sorting in Ascending order\nEnter 2 for Sorting in Descending Order\n");
    printf("Enter your choice:\n");
    scanf("%d",&ch);
    
    printf("Enter size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d numbers to be sorted\n",n);
   for ( i = 0; i <n; i++)
   {
    scanf("%d",&a[i]);
   }
   for(i=0; i<n;i++)
   {
   m=i;
   for(j=i+1;j<n;j++)
   {
    if(ch==1)
    {
        if(a[j]<a[m])
        m=j;
    }
    else if(ch==2)
    {
        a[j]>a[m];
        m=j;
    }
    else{
        printf("Invalid Input");
        exit(1);
    }
   }
   temp=a[m];
   a[m]=a[i];
   a[i]=temp;
   }
    if(ch==1)
    {
    printf("The sorted array in ascending order: ");
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
    }
    if(ch==2)
    {
    printf("The sorted array in descending order: ");
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
    }
}