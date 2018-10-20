#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define REP(i,RANK) for(i=0;i<RANK;i++)
#define SD(n) scanf("%d",&n)
#define pi(n) printf("%d",n)
#define pn printf("\n")
int mini(int BOT,int RANK){return BOT<RANK?BOT:RANK;}
 
string BOT[12],RANK[12];int n,l,ans;
 
 
int func(int i)
{
int j;
REP(j,n){if(BOT[j][i]=='0'){BOT[j][i]='1';}else{BOT[j][i]='0';}}
return 0;
}
 
int Solve(int sum)
{
int i,j,Arr[12];
int cnt=0;
REP(i,12){Arr[i]=0;}
REP(i,n)
{
REP(j,n)
{
if(BOT[i]==RANK[j]&&Arr[j]==0){Arr[j]=1;cnt++;}
}
}
if(cnt==n){ans=mini(ans,sum);}
return 0;
}
int rec(int i,int sum)
{
int j;
if(i==l)
{
Solve(sum);
return 0;
}
 
rec(i+1,sum);
REP(j,n)
{
if(BOT[j][i]=='0'){BOT[j][i]='1';}
else{BOT[j][i]='0';}
}
 
rec(i+1,sum+1);
return 0;
}
 
int main()
{
int test,X1;
SD(test);
for(X1=1;X1<=test;X1++)
{
int i,j,k;
SD(n);
SD(l);
REP(i,n){cin>>BOT[i];}
REP(i,n){cin>>RANK[i];}
ans=10000000;rec(0,0);
 
printf("Case #%d: ",X1);
if(ans!=10000000){pi(ans);}
else{printf("NOT POSSIBLE");}
pn;
}
return 0;
}
