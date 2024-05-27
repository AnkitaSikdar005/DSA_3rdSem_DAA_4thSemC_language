#include <stdio.h>

int jobsequencing(int n, int deadline[], int profit[], int job[]){
    int i, j, k, max_profit = 0;
    int slot[n];
    for(i = 0; i < n; i++){
        slot[i] = 0;
    }
    for(i = 0; i < n; i++){
        for(j = n-1; j > i; j--){
            if(profit[j] > profit[j-1]){
                int temp = profit[j];
                profit[j] = profit[j-1];
                profit[j-1] = temp;
                temp = deadline[j];
                deadline[j] = deadline[j-1];
                deadline[j-1] = temp;
                temp = job[j];
                job[j] = job[j-1];
                job[j-1] = temp;
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = deadline[i]-1; j >= 0; j--){
            if(slot[j] == 0){
                slot[j] = job[i];
                max_profit += profit[i];
                break;
            }
        }
    }
    printf("JOB SEQUENCE: ");
    for(i = 0; i < n; i++){
        if(slot[i] != 0){
            printf("%d ",slot[i]);
        }
    }
    printf("\n");
    return max_profit;
}

int main(){
    int n;
    printf("ENTER THE NUMBER OF JOBS: ");
    scanf("%d",&n);
    int deadline[n], profit[n], job[n];
    printf("ENTER THE DEADLINES OF THE JOBS: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&deadline[i]);
    }
    printf("ENTER THE PROFIT OF THE JOBS: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&profit[i]);
    }
    for(int i = 0; i < n; i++){
        job[i] = i+1;
    }
    int result = jobsequencing(n,deadline,profit,job);
    printf("MAXIMUM PROFIT: %d",result);
    return 0;
}