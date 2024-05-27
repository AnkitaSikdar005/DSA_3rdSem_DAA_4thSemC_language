#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

 void fractionalknapsack(int n, float weight[], float profit[], float capacity)
 {
   float x[20], tp = 0;
   int i, j, u;

   u = capacity;

  //main algorithm starts from here
   for (i = 0; i < n; i++)
   {
       x[i] = 0.0;
   }

   for (i = 0; i < n; i++)
   {
      if (weight[i] > u)
      {
          break;
      }
      else
      {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n)
   {
       x[i] = u / weight[i];
   }

   tp = tp + (x[i] * profit[i]);

   printf("\nMaximum Profit:- %.2f\n", tp);

}

int main()
{
   float weight[20], profit[20], capacity, ratio[20], temp;
   int num, i, j;

   printf("\nNumber of objects:- ");
   scanf("%d", &num);

   printf("\nWeights and Profits of each object:- \n");
   for (i = 0; i < num; i++)
   {
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\nCapacity of knapsack:- ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++)
   {
      ratio[i] = profit[i] / weight[i];
   }

   //Sorting objects according to their profit per unit weight
   for (i = 0; i < num; i++)
   {
      for (j = i + 1; j < num; j++)
      {
         if (ratio[i] < ratio[j])
         {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   fractionalknapsack(num, weight, profit, capacity);
   return(0);
}