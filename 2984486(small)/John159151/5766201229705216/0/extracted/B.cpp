#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int a[100000];
int main()
{
    int i,j,k;
    int n,m,t;
    freopen("B-small-attempt1.in","r",stdin);
	freopen("B-output.txt","w",stdout);
    scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
    //while(scanf("%d",&n)!=EOF)
    {
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]++;
			a[y]++;
		}
		int num=0;
		int judge2=0;
		for(i=1;i<=n;i++)
		{
			//cout<<a[i]<<endl;
			if(a[i]>=3)
			{
				num+=a[i]-3;
			}
			else if(a[i]==2)
			{
				judge2++; 
			} 
		}
		int res=num;
		if(judge2==0)
		{
			res+=1;
		}
		else
		{
			res+=judge2-1;
		}
		printf("Case #%d: %d\n",tcase,res);
    }
    fclose(stdin);
    fclose(stdout);
}
