#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define INF 0x7fffffff
struct Node{
	char str[12];
}node1[12],node2[12],node3[12];

int N,L;

bool cmp(Node a,Node b)
{
	if(strcmp(a.str,b.str) < 0)
		return true;
	return false;
}

int jud()
{
	sort(node3,node3+N,cmp);
	for(int i=0;i<N;i++)
		if(strcmp(node3[i].str,node2[i].str) != 0)
			return 0;
	return 1;
}

int deal(int a)
{
	for(int i=0;i<N;i++)
		strcpy(node3[i].str,node1[i].str);
	int t=0,s=0;
	while(a)
	{
		if(a & 1)
		{
			for(int i=0;i<N;i++)
				node3[i].str[t]=1-(node3[i].str[t]-'0')+'0';
			s++;
		}
		t++;
		a/=2;
	}
	if(jud())
		return s;
	return INF;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt", "r", stdin);
    freopen("testout.txt", "w", stdout);
#endif
    int T,cas=1;
    cin>>T;
    while(T--)
    {
    	printf("Case #%d: ",cas++);
    	scanf("%d %d",&N,&L);
    	for(int i=0;i<N;i++)
    		scanf("%s",node1[i].str);
    	for(int i=0;i<N;i++)
    		scanf("%s",node2[i].str);
    	sort(node2,node2+N,cmp);
    	int tot=1<<L,ans=INF;
    	for(int i=0;i<tot;i++)
    		ans=min(ans,deal(i));
    	if(ans == INF)
    		printf("NOT POSSIBLE\n");
    	else
    		printf("%d\n",ans);
    }
    return 0;
}

