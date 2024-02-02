#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,temp,ch,n;
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
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
        if(ch==1)//comment this part
        {            //comment this part
          if(a[j]>a[j+1])
          {
            temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
          }
          
        }
    
    else if(ch==2)//comment this part
    {             //comment this part
         if(a[j]<a[j+1])
         {
             temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
         }
         
    }
    else
    {
        printf("Invalid Input");
        exit(1);
    }
  }               //comment out from line 33 to 47 if only ascending asked
  }
if(ch==1)
{
    printf("The sorted array in ascending\n");
     for (int i = 0; i<n; i++)
   {
    printf("%d ",a[i]);
   }
}
if(ch==2)
{
    printf("The sorted array in descending\n");
     for ( i = 0; i<n; i++)
   {
    printf("%d ",a[i]);
   }
}              ////comment out from line 57 to 65 if only ascending asked
}
