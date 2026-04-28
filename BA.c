#include <stdio.h>

int main() {
    int n, r;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    printf("Enter number of resources:\n");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], need[n][r], avail[r];

    printf("Enter Allocation Matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < r; j++){
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < r; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(int i = 0; i < r; i++){
        scanf("%d", &avail[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < r; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int finish[n], safeSeq[n];

    for(int i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while(count < n){
        int found = 0;

        for(int i = 0; i < n; i++){
            if(finish[i] == 0){
                int possible = 1;

                for(int j = 0; j < r; j++){
                    if(need[i][j] > avail[j]){
                        possible = 0;
                        break;
                    }
                }

                if(possible){
                    for(int j = 0; j < r; j++){
                        avail[j] += alloc[i][j];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0){
            printf("System is NOT in a safe state (Deadlock may occur).\n");
            return 0;
        }
    }

    printf("System is in a SAFE STATE.\nSafe Sequence: ");

    for(int i = 0; i < n; i++){
        printf("P%d ", safeSeq[i]);
    }

    printf("\n");

    return 0;
}