#include<stdio.h>

int main(){
    int n, h;

    printf("Enter number of pages in reference string:\n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the reference string:\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter number of frames:\n");
    scanf("%d",&h);

    int tb[h];
    for(int i = 0; i < h; i++){
        tb[i] = -1;
    }

    int m = 0, g = 0, v = 0;

    for(int i = 0; i < n; i++){
        int found = 0;

        for(int j = 0; j < h; j++){
            if(tb[j] == arr[i]){
                found = 1;
                break;
            }
        }

        if(found == 0){
            tb[v] = arr[i];
            v = (v + 1) % h;
            m++;
        } else {
            g++;
        }
    }

    printf("Total Page Faults: %d\n", m);
    printf("Total Page Hits: %d\n", g);

    return 0;
}