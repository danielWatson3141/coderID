#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1010
long long int count=0;

void mergeSort(int arr[],int low,int mid,int high){
    int i,m,k,l,temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
             count=count+(mid-l+1);
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;

         }
    }

    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

void partition(int arr[],int low,int high){
    int mid;
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

long long mean;
int goo=0;
void logic()
{  int  input[MAX],i,N;
   count=0;
   scanf("%d",&N);
   for(i=0;i<N;i++)
    scanf("%d",&input[i]);
     partition(input,0,N-1);
mean+=count/120;
//printf("%d",count);

    if(count >= 245633){printf("GOOD\n");}
   else printf("BAD\n");

}

int main(){
freopen("c.in","r",stdin);
freopen("outputc.txt","w",stdout);
    int T;
       scanf("%d",&T);
      int i;
      for(i=1;i<=T;i++){printf("Case #%d: ",i);
	  logic();
	  }
	//  printf("%d %d",mean,goo);
   return 0;
}
