#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	char c[50];
	bool operator<(const node& a)const
	{
		return strcmp(c,a.c)<0;
	}
}a[200],b[200],c[200];
const int inf=1<<30;
int n,l;

int get(char* a,char* b)
{
	int i,s=0;
	for(i=0;i<l;i++)
		if(a[i]!=b[i])
			s+=1<<i;
	return s;
}

int ch(int bb)
{
	int i,j,s=0;
	memcpy(c,a,sizeof(a));
	for(i=0;i<l;i++)
		if(bb&(1<<i))
			s++;
	for(i=0;i<n;i++)
		for(j=0;j<l;j++)
			if(bb&(1<<j))
				c[i].c[j]='0'+'1'-c[i].c[j];
	sort(c,c+n);
	for(i=0;i<n;i++)
		if(strcmp(c[i].c,b[i].c)!=0)
			break;
	return i<n?inf:s;
}

int main()
{
	freopen("E:/in.txt","r",stdin);
	freopen("E:/out.txt","w",stdout);
	int T,t,i,j,s;
	for(scanf("%d",&T),t=1;t<=T;t++)
	{
		scanf("%d%d",&n,&l);
		for(i=0;i<n;i++)
			scanf("%s",a[i].c);
		for(i=0;i<n;i++)
			scanf("%s",b[i].c);
		printf("Case #%d: ",t);
		sort(b,b+n);
		s=inf;
		for(i=0;i<n;i++)
			s=min(s,ch(get(a[0].c,b[i].c)));
		if(s<inf)
			printf("%d\n",s);
		else
			puts("NOT POSSIBLE");
	}
	return 0;
}
