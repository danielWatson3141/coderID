//
//  main.c
//  Google Code Jam
//
//  Created by Huzefa on 4/25/14.
//  Copyright (c) 2014 Huzefa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
/* Function to swap values at two pointers */
void swap (int *x, int index)
{
    int a=0x00000001;
    a=a<<index;
    
    *x = *x ^ a;
    //printf("Values are %d %d\n",*x,a);
}
int getanswer(int counter){
    int value=0;
    while(counter){
        if(counter & 0x00000001){
            value++;
            
        }
        counter=counter>>1;
    }
    return value;
}
int solutionCount=0x7fffffff;
int recurringCount=0;
void swapData(int *data,int a, int N){
    int i=0;
    for(i=0;i<N;i++){
        data[i] =data[i]^a;
    }
    return;
}
void compare(int *data,int *actual,int N,int a){
    int j=0;
    int i=0;
    int *flag=malloc(N*sizeof(int));
    int counter=N;
    for(i=0;i<N;i++){
        flag[i]=0;
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(!flag[j] && actual[j]==data[i]){
                counter--;
                flag[j]=1;
            }
        }
    }
    if(counter==0){
        if(solutionCount>getanswer(a)){
            solutionCount=getanswer(a);
        }
    }
    
}
/* Function to print permutations of string
 This function takes three parameters:
 1. String
 2. Starting index of the string
 3. Ending index of the string. */
void permute(int a, int i,int n,int *data,int *actual, int *y,int N,int L)
{
//    int j;
    if (i == 0){
        //printf("%d\n", a);
        swapData(data,a,N);
        compare(data,actual,N,a);
        swapData(data,a,N);
        swap(&a,0);
        swapData(data,a,N);
        compare(data,actual,N,a);
        swapData(data,a,N);
        //printf("%d\n", a);
        return;
    }
    
    permute(a,i-1,n,data,actual,y,N,L);
    swap(&a,i);
    permute(a,i-1,n,data,actual,y,N,L);

}
void findsolution(int *data,int*actual,int *y,int N,int L){
   return permute(0,L-1,0,data,actual,y,N,L);
}

int main(int argc, const char * argv[])
{
    int noOfTestCases = 0;
    int N,L;
    int *data;
    int *flag;
    int *actual;
    int i=0;
    int j=0;
    char *c;
    char string[50];
    FILE *fp;
        FILE *fp1;
    //int counter;
    int y=0;
    int answer=0;
    fp=fopen("/Users/admin/Desktop/test.txt","r");
    fp1=fopen("/Users/admin/Desktop/out.txt","w");
    fscanf(fp,"%d",&noOfTestCases);
    for(i=0;i<noOfTestCases;i++){
            fscanf(fp,"%d %d",&N, &L);
            data=malloc(N*sizeof(int));
            actual=malloc(N*sizeof(int));
            flag=malloc(N*sizeof(int));
            for(j=0;j<N;j++){
                fscanf(fp,"%s",&string[0]);
                data[j] = (int)strtol(string,&c, 2);
                flag[j]=0;
            }
        
            for(j=0;j<N;j++){
                fscanf(fp,"%s",&string[0]);
                actual[j] = (int)strtol(string,&c, 2);
            }
        
        
            findsolution(data,actual,&y,N,L);
        //answer = getanswer(solutionCount);
        if(solutionCount==0x7fffffff){
            fprintf(fp1,"Case #%d: NOT POSSIBLE\n",i+1);
        }else{
            fprintf(fp1,"Case #%d: %d\n",i+1,solutionCount);
        }
        
        solutionCount=0x7fffffff;
    }
    //permute(0,2,0);
    // insert code here...
    //printf("Test results %d %d",N,L);
    return 0;
}

