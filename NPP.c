#include<stdio.h>

int main(){
    int n;

    printf("Enter number of processes:\n");
    scanf("%d",&n);

    int at[n], bt[n], pt[n], ct[n], tat[n], wt[n], done[n];

    for(int i = 0; i < n; i++){
        done[i] = 0;
        printf("Enter AT, BT and Priority for P%d:\n", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pt[i]);
    }

    int completed = 0, time = 0;

    while(completed < n){
        int idx = -1;
        int minp = 1000;

        for(int i = 0; i < n; i++){
            if(at[i] <= time && done[i] == 0){
                if(pt[i] < minp){
                    minp = pt[i];
                    idx = i;
                }
            }
        }

        if(idx != -1){
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = 1;
            completed++;
        }
        else{
            time++;
        }
    }

    float atat = 0, awt = 0;

    for(int i = 0; i < n; i++){
        atat += tat[i];
        awt += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f\n", atat/n);
    printf("Average Waiting Time = %.2f\n", awt/n);

    return 0;
}