#include <vector>
#include<iostream>
#include<stdio.h>
#define REP(i,n,k) for (int i=k;i<=n;i++)

using namespace std;
long long fib[100]={0,1};

int fibgen(){
    long long temp=10000000000;
int    index=0;
REP(i,99,2)
{
    fib[i]=fib[i-1]+fib[i-2];
    if (fib[i]>10000000000){
            index=i-1;
        break;}
}
return index;
}

int main(){
int up=fibgen();
int t,flag;
cin>>t;
long long n;
while(t--){
        flag=0;
cin>>n;
if (n>fib[up])
    cout<<"IsNotFibo"<<endl;
else{
REP(i,up,0){
if (n==fib[i]){
    flag=1;
    break;
}
}
if (flag==0)
    cout<<"IsNotFibo"<<endl;
else
    cout<<"IsFibo"<<endl;
}



}
}
