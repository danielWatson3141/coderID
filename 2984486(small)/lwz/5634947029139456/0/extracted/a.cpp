#include<cstdio>
#include<set>
#include<string>
#include<iostream>
using namespace std;
char i1[150][41],i2[150][41],r2[41];
bool r[41];
set<string> b1,b2;
int main()
{
int N;
scanf("%d",&N);
for(int T=1;T<=N;T++)
{
	int n,l;
	scanf("%d%d",&n,&l);
	for(int a=0;a<n;a++) scanf("%s",i1[a]);
	for(int a=0;a<n;a++) scanf("%s",i2[a]);
	int mn=-1;
	b2.clear();
	for(int a=0;a<n;a++) b2.insert(i2[a]);
	for(int a=0;a<n;a++)
	{
		int c=0;
		for(int s=0;s<l;s++) if( i1[0][s]!=i2[a][s] ){ c++; r[s]=true; } else r[s]=false;
		b1.clear();
		for(int d=0;d<n;d++)
		{
			for(int s=0;s<l;s++) if( r[s] ) r2[s]='1'+'0'-i1[d][s]; else r2[s]=i1[d][s];
			r2[l]=0;
			b1.insert(r2);
		}
//for(set<string>::iterator it=b1.begin();it!=b1.end();it++) cout<<*it<<" "; cout<<endl;
//for(set<string>::iterator it=b2.begin();it!=b2.end();it++) cout<<*it<<" "; cout<<endl;
		if( b1==b2 ) if( mn==-1 || c<mn ) mn=c;
	}
	printf("Case #%d: ",T);
	if( mn==-1 ) printf("NOT POSSIBLE");
	else printf("%d",mn);
done:;
	printf("\n");
}
	return 0;
}
