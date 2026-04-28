#include <stdio.h>

int main() {
    int n, tq;
    
    printf("Enter number of processes: \n");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    printf("Enter Time Quantum: \n");
    scanf("%d", &tq);

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: \n", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int time = 0, completed = 0;
   

    while (completed < n) {
        int done = 1;

        for (int i = 0; i < n; i++) {

            if (rt[i] > 0 && at[i] <= time) {
                done = 0;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        
        if (done)
            time++;
    }

    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}