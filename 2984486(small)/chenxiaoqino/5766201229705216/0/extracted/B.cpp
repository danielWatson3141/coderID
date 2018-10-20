#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


//int treest[1001][3];//0:par, 1:left, 2:right
int conns[1001][1001];
int cach[1001];

int trybuildtree(int cr, int pr)
{
	int i,j;
	int depths[1000];
	int childcnt=conns[cr][0];
	
	if(cach[cr]>0)return cach[cr];
	
	//cout<<"at point"<<cr<<" with childcnt "<<childcnt<<endl;
	
	memset(depths,0,sizeof(depths));
	depths[1]=0;
	j=0;
	for(i=1;i<=childcnt;i++)
	if(conns[cr][i]!=pr)
		depths[j++]=trybuildtree(conns[cr][i],cr);
	
	//for(i=0;i<j;i++)
	//cout<<depths[i]<<"-";
	//cout<<"("<<j<<','<<depths[1]<<endl;
		
	if(depths[1]==0)	
		{
			cach[cr]=1;
			return 1;
		}
	sort(&depths[0],&depths[j]);
	cach[cr]=(depths[0]+depths[1])+1;
	return cach[cr];
}
	


int main()
{
int T,ti;
cin>>T;
for(ti=0;ti<T;ti++)
{
	int n,i;
	cin>>n;
	
	memset(conns,0,sizeof(conns));
	for(i=0;i<n-1;i++)
	{	
		int x,y;
		cin>>y>>x;
		//cout<<"add:"<<y<<x;
		conns[x][0]++;
		conns[x][ conns[x][0] ]=y;
		conns[y][0]++;
		conns[y][ conns[y][0] ]=x;
	}
	for(i=1;i<=0*n;i++)
	{
		for(int j=1;j<=conns[i][0];j++)
			cout<<conns[i][j];
		cout<<endl;
	}
	
	int bestallcnt=0;
	for(i=1;i<=n;i++)
	{
	
		//for(int j=0;j<1001;j++)cach[j]=0;
		
		memset(cach,0,sizeof(cach));
		
		
		//cout<<"startsearch"<<i<<endl;
		int allcnt=trybuildtree(i,i);
		//cout<<"allcnt @"<<i<<": "<<allcnt<<endl;
		
		//for(int j=1;j<=n;j++)
		//	cout<<cach[j]<<"~";
		//cout<<endl;
		
		if(bestallcnt<allcnt)bestallcnt=allcnt;
		//compare
	}
	//cout<<"bestallcnt " <<bestallcnt;
	
	cout<<"Case #"<<(ti+1)<<": ";
	cout<<n-bestallcnt;
	cout<<endl;
}
return 0;
}