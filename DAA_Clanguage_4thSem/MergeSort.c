#include <stdio.h>
void printArray(int *A, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void merge(int A[],int mid,int low,int high)
{
    int i,j,k,B[100];
    i=low;
    j=mid+1;
    k=low;

while(i<=mid && j<= high)
{
    if(i<=mid && j<= high)
    {
        if(A[i]>A[j]) // Change comparison to '>' for descending order
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
}
    while(i<=mid)
    {
        B[k]=A[i];
        k++;
        i++;
    }
     while(j<=high)
    {
        B[k]=A[j];
        k++;
        j++;
    }
    for(int x=low; x<=high; x++)
    {
        A[x]=B[x];
    }

}

void mergeSort(int A[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,mid,low,high);
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
    mergeSort(A,0, n-1);
    printArray(A,n);
    return 0;
}