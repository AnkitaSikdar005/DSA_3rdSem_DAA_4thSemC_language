#include<stdio.h>
 void display(int arr[], int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
int indInsertion(int arr[], int size, int element, int capacity, int index){
    // code for Insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1; 
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
     printf("Enter the element to be inserted\n");
    scanf("%d",&element);
     printf("Enter the index at which the element must be inserted\n");
    scanf("%d",&index);
    
   //int arr[100] = {7, 8, 12, 27, 88};
    //element = 45, index=1;
    display(arr, size); 
    indInsertion(arr, size, element, 100, index);
    size +=1;
    display(arr, size);
    return 0;
}
