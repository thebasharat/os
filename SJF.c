#include<stdio.h>

int main(){
    int n, time = 0, completed = 0, min;

    printf("Enter number of processes:\n");
    scanf("%d",&n);

    int at[n], bt[n], ct[n], tat[n], wt[n], done[n];

    for(int i = 0; i < n; i++){
        done[i] = 0;
    }

    for(int i = 0; i < n; i++){
        printf("Enter Arrival Time and Burst Time for P%d:\n", i+1);
        scanf("%d %d",&at[i], &bt[i]);
    }

    float avg_tat = 0, avg_wt = 0;

    while(completed < n){
        min = -1;

        for(int i = 0; i < n; i++){
            if(at[i] <= time && done[i] == 0){
                if(min == -1 || bt[i] < bt[min]){
                    min = i;
                }
            }
        }

        if(min == -1){
            time++;
        }
        else{
            time += bt[min];
            ct[min] = time;
            tat[min] = ct[min] - at[min];
            wt[min] = tat[min] - bt[min];

            avg_tat += tat[min];
            avg_wt += wt[min];

            done[min] = 1;
            completed++;
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
    printf("Average Waiting Time = %.2f\n", avg_wt);

    return 0;
}