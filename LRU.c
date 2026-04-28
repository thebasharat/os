#include <stdio.h>

int main() {
    int n, frames;

    printf("Enter number of pages in reference string:\n");
    scanf("%d", &n);

    int ref[n];

    printf("Enter the reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames:\n");
    scanf("%d", &frames);

    int frame[frames], time[frames];

    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    int counter = 0;
    int faults = 0, hits = 0;

    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                counter++;
                time[j] = counter;
                hits++;
                found = 1;
                break;
            }
        }

        if(!found) {
            int pos = 0;

            for(int j = 1; j < frames; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            counter++;
            frame[pos] = ref[i];
            time[pos] = counter;
            faults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);

    return 0;
}