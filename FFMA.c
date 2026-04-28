#include<stdio.h>

int main(){
    int m,n,i,j;
    int b[50],p[50],o[50];

    printf("Enter number of memory blocks:\n");
    scanf("%d",&m);

    printf("Enter size of each block:\n");
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
        o[i]=b[i];
    }

    printf("Enter number of processes:\n");
    scanf("%d",&n);

    printf("Enter size of each process:\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    for(i=0;i<n;i++){
        int flag=0;

        for(j=0;j<m;j++){
            if(b[j] >= p[i]){
                printf("Process %d of size %d allocated to Block %d of size %d with Fragment %d\n",
                       i+1, p[i], j+1, o[j], b[j]-p[i]);

                b[j] -= p[i];
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            printf("Process %d of size %d not allocated\n", i+1, p[i]);
        }
    }

    return 0;
}