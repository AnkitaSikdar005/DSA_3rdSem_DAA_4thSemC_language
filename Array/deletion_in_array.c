#include<stdio.h>
 void display(int arr[], int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
int indDeletion(int arr[], int size,int index){
    // code for deletion
   
    for (int i = index; i <=size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    
}
 
int main(){
     int size = 0, element=0, index=0;

    printf("Enter no of elements in the array\n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i] );
    }
     
     printf("Enter the index at which the element must be deleted\n");
    scanf("%d",&index);
    
   //int arr[100] = {7, 8, 12, 27, 88};
    //element = 45, index=1;
    display(arr, size); 
    indDeletion(arr, size,index);
    size -=1;
    display(arr, size);
    return 0;
}
