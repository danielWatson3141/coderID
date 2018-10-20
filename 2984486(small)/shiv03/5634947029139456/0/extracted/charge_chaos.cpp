/*
    Author: Shivang Gupta
    GCJ_1A_2014s
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> Vint;
typedef vector<bool> VB; 
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (int(1e18))
#define EPS 1e-12 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define FORAint(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define Aint(A) A.begin(), A.end()
#define intA(A) A.rbegin(), A.rend()
inline void inp( int &n )
{ 
    n=0;    int ch=getcx();int sign=1;   
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
    while(  ch >= '0' && ch <= '9' )    
    n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}       

int X(char a[][50],char b[][50],int x,int y,int l)
{
    int i,j,ans=0,k=1,m;
    for(i=l-1;i>=0;i--)
    {
        j=a[x][i]-48;m=b[y][i]-48;
        ans=ans+(k*(j^m));
        k=k<<1;
    }
    return ans;
}
int main()
{
    int i,j,k,p,n,t,x=1,l;char in[200][50],fn[200][50];int a[200][200];
    inp(t);
    while(x<=t)
    {
        inp(n);inp(l);
        rep(i,0,n)scanf("%s",in[i]);
        rep(i,0,n)scanf("%s",fn[i]);
        
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                a[i][j]=X(in,fn,i,j,l);
                //printf("%d ",a[i][j]);
            }
            //printf("\n");
        }
        int q=0,min=100000000;
        rep(i,0,n)
        {
            //take first device to ith outlet
            p=a[0][i]; 
            q=0;
            rep(j,1,n)
            {
                rep(k,0,n)
                {
                    if(a[j][k]==p){q++;break;}
                }
            }
            if(q==n-1)//p matched with n-1 outlets
                min=MIN(p,min);
        }
        int ans=0;
        //printf("%d\n",min);
        if(min==100000000){printf("Case #%d: NOT POSSIBLE\n",x++);continue;}
        while(min)
        {
            if(min&1)ans++;
            min=min/2;
        }
        printf("Case #%d: %d\n",x++,ans);
    }
    return 0;
}