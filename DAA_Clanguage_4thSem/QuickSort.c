#include<stdio.h>
void printArray(int *A, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
/*void printArray1(int *A, int n)
{
    for(int i=n-1;i>=0;i--)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}*/
 //WRITE THIS CODE TO PRINT IN DESCENDING ORDER

int partition(int A[],int low,int high)
{
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;

    do
    {
      while(A[i]<=pivot)
      {
        i++;
      }
      while(A[j]>pivot)
      {
        j--;
      }
      if(i<j)
      {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
      }
    } while (i<j);
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
    }
    void quicksort(int A[],int low,int high)
    {
        int partitionIndex;
        if(low< high)
        {
            partitionIndex=partition(A, low,high);
            quicksort(A,low,partitionIndex-1);
            quicksort(A, partitionIndex+1,high); 
        }
    }
    int main()
    {
        int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter %d numbers to be sorted in the array\n",n);
    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
    printArray(A,n);
    quicksort(A,0, n-1);
    printArray(A,n);//CALL THE FUNCTION printArray1(A,n) TO SORT IN DESCENDING ORDER
    return 0;
    }
    
