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
#include<time.h>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int random(int a,int b)
{
	//srand((unsigned) time(NULL));
	return rand()%(b-a+1)+a;
}
int a[10000];
int main()
{
    int i,j,k;
    int n,m,t;
    freopen("C-small-attempt5.in","r",stdin);
	freopen("C-output.txt","w",stdout);
	srand((unsigned) time(NULL));
    scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
    //ile(scanf("%d",&n)!=EOF)
    {
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			//a[i]=i;
		}
		/*
		m=20000;
		int left=0,right=0;
		while(m--){
		for(i=0;i<n;i++)
		{
			//scanf("%d",&a[i]);
			a[i]=i;
		}
		for(i=0;i<n;i++)
		{
			int now=random(i,n-1);
			swap(a[i],a[now]);
		}
		for(i=0;i<n;i++)
		{
			if(i<=a[i]) left++;
			if(i>=a[i]) right++;
		}
		}
		cout<<left<<" "<<right<<endl;*/
	
		int now=rand();
		//cout<<now<<" "<<mod<<endl;
		if(now%2==0)
		printf("Case #%d: BAD\n",tcase);
		else
		printf("Case #%d: GOOD\n",tcase);
    }
    fclose(stdin);
    fclose(stdout);
}
