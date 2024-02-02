#include<stdio.h>
int fact(int x)
{
    int f=1,i;
    for(i=1;i<=x;i++)
    {
        f=f*i;
    }
    return f;
}
 int fib(int n)
{
    if(n==1)
    return 0;
    else if (n==2)
    return 1;
    else
    return fib(n-1)+ fib(n-2);
}
void main()
{
    int n=0,x=0,c=0;
     printf("Enter a number: \n");
    scanf("%d",&n);
    printf("The required factorial of %d is %d\n",n,fact(n));
    printf("Enter the no of terms ");
    scanf("%d",&x);
  //  int fib(int);
    for (int i = 1; i <=x; i++)
    {
         c=fib(i);
        // if(i==n)
        printf("%d ",c);
}
}


 

