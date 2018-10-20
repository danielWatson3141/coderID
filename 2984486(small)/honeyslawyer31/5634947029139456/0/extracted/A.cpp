/*
*************************************************************************
* $ Author : honeyslawyer   $
* $ Name   : shashank gupta $
*************************************************************************
*
* Copyright 2014 @ honeyslawyer and shashank gupta
*
************************************************************************/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<conio.h>
#include<cstring>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<string>
#include<climits>

#define mod 1000000007
#define ll long long

using namespace std;
ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b);}

ll power(ll b,ll exp,ll m)
 {ll ans=1;
  b%=m;
  while(exp)
   {if(exp&1)
     ans=(ans*b)%m;
    exp>>=1;
	b=(b*b)%m;
   }
  return ans;
 }

int main()
{
   FILE *fp1,*fp2;
  fp1=fopen("input.in","r");
  fp2=fopen("output.txt","w");
  int t;
  fscanf(fp1,"%d",&t);
  for(int z=1;z<=t;z++)
  {
        int n,l;
        fscanf(fp1,"%d %d",&n,&l);
        char ini[2000][50];
        for(int i=0;i<n;i++)
        {
          fscanf(fp1,"%s",ini[i]);
          //cout<<ini[i]<<endl;
        }
        char req[2000][50];
        for(int i=0;i<n;i++)
        {
            fscanf(fp1,"%s",req[i]);
            //cout<<req[i]<<endl;
        }
        int ans=INT_MAX;
        for(int i=0;i<power(2,l,INT_MAX);i++)
        {
            int j=0;
            int f=i;
            int vis[20]={0};
            int c=0;
            while(f>0)
            {
              vis[j]=f%2;
              if(vis[j]==1)
              c++;
              f=f/2;
              j++;
            }
            map <string,int> p;
            for(int i=0;i<n;i++)
            {
                string str(req[i]);
                p[str]=1;
            }
            char modi[2000][50];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<=l;j++)
                {
                    if(vis[j]==1)
                    {
                        if(ini[i][j]=='1')
                        modi[i][j]='0';
                        else
                        modi[i][j]='1';
                    }
                    else
                    modi[i][j]=ini[i][j];
                }
            }
            int flag=1;
            for(int i=0;i<n;i++)
            {
                string str(modi[i]);
                int l=p[str];
                if(l==1)
                p[str]=2;
                else
                {
                flag=2;
                break;
                }
            }
            if(flag==1)
            {
                ans=min(ans,c);
            }
        }
        if(ans==INT_MAX)
        fprintf(fp2,"Case #%d: NOT POSSIBLE\n",z);
        else
        fprintf(fp2,"Case #%d: %d\n",z,ans);
        
    }
  


getch();
return 0;
/*checklist
1)getch() and conio.h removed.*/
}
