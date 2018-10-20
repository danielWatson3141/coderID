#include<stdio.h>
#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define pb(x) push_back(x)
#define For(i,s,e) for(i=s;i<e;i++)
#define ss(a) scanf("%s",a)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sf(a) scanf("%f",&a)
#define sd(a) scanf("%lf",&a)
#define ps(a) printf("%s\n",a)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define pd(a) printf("%lf\n",a)
#define LL long long
#define MOD 1000000

using namespace std;
 
int main()
{
int t,c=1,m,j,i,k,flag,out;
si(t);
while(c<=t)
{
    int n,l,arr1[2][41]={0},arr2[2][41]={0};
    si(n);si(l);
    For(k,0,n)
    {
        char a;
        For(i,0,l)
        {
            //scanf("%c",&a);
		cin>>a;
            if(a-'0'==0)
            {
             arr1[0][i]++;
            }
 
            else
            {
                arr1[1][i]++;
            }
        }
    }
     For(k,0,n)
    {
        char a;
        For(i,0,l)
        {
            //scanf("%c",&a);
		cin>>a;
            if(a-'0'==0)
            {
             arr2[0][i]++;
            }
 
            else
            {
                arr2[1][i]++;
            }
        }
    }
	flag=0;
	out=0;
	j=0;
	while(j!=l && flag!=1)
	{
	    if(arr1[0][j]==arr2[0][j] && arr1[1][j]==arr2[1][j])
		{
		    j++;
		}
	 
	    else if((arr1[0][j]==arr2[1][j] && arr1[1][j]==arr2[0][j]))
	    {
		out++;
		j++;
	    }
	 
	 
		 else
		 {
		     flag=1;
		 }
	 
	}
 
	if(flag==1)
	{
	    printf("Case #%d: NOT POSSIBLE\n",c);
	}
	 
	else
	{
	    printf("Case #%d: %d\n",c,out);
	}
	c++;
}
return 0;
}
