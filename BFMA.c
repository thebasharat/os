#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of memory blocks:\n");
    scanf("%d", &m);

    int block[m], original[m];

    printf("Enter size of each block:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &block[i]);
        original[i] = block[i];
    }

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    int process[n];

    printf("Enter size of each process:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    for(int i = 0; i < n; i++) {
        int bestIndex = -1;

        for(int j = 0; j < m; j++) {
            if(block[j] >= process[i]) {
                if(bestIndex == -1 || block[j] < block[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if(bestIndex != -1) {
            int fragment = block[bestIndex] - process[i];

            printf("Process %d (%d) allocated to Block %d (%d), Fragment = %d\n",
                   i + 1, process[i], bestIndex + 1,
                   original[bestIndex], fragment);

            block[bestIndex] -= process[i];
        } else {
            printf("Process %d (%d) not allocated\n",
                   i + 1, process[i]);
        }
    }

    return 0;
}