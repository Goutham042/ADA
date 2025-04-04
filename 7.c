#include<stdio.h>
#define MAX_ITEM 10
int knapSack(int W,int wt[],int val[],int n){
  int i,j;
  int v[MAX_ITEM+1][W+1];
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=W;j++)
    {
      if(i==0||j==0)
      {
         v[i][j]=0;
      }
      else if(j-wt[i]<0)
     {
       v[i][j]=v[i-1][j];
     }
     else
     {
        v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
      }
    }
  }
  return v[n][W];
}
int max(int a,int b)
{
  return (a>b)?a:b;
}
void main(){
  int W,n,i;
  int wt[MAX_ITEM],val[MAX_ITEM];
  printf("Enter the value of item:\n");
  scanf("%d",&n);
  printf("Enter the value of weigth:\n");
   for(i=1;i<=n;i++){
      scanf("%d",&wt[i]);
    }
  printf("Enter the value:\n");
  for(i=1;i<=n;i++){
     scanf("%d",&val[i]);
  }
  printf("Enter the Max capacity:\n");
  scanf("%d",&W);
  printf("The profit obtain is: %d\n",knapSack(W,wt,val,n));
}












