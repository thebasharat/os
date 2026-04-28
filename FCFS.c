#include<stdio.h>
int main(){
  int n;
  printf("Enter number of processes: \n");
  scanf("%d",&n);
  int at[n],bt[n],ct[n],tat[n],wt[n];
  for(int i=0; i<n; i++){
    printf("Enter Arrival Time and Burst Time for P%d: \n",i+1);
    scanf("%d %d",&at[i],&bt[i]);
    if(i==0){
      ct[i]=at[i]+bt[i];
    }
    else{
      if(ct[i-1]<at[i])
        ct[i]=at[i]+bt[i];
      else
      ct[i]=ct[i-1]+bt[i];
    }
  }
  for(int i=0; i<n; i++){
    tat[i]=ct[i]-at[i];
  }
  for(int i=0; i<n; i++){
    wt[i]=tat[i]-bt[i];
  }
  printf("\n");
  double ttat=0,twt=0;
  for(int i=0; i<n; i++){
    ttat+=tat[i];
    twt+=wt[i];
  }
  printf("Average Turnaround Time: %0.2f\n",ttat/n);
  printf("Average Waiting Time: %0.2f",twt/n);
}