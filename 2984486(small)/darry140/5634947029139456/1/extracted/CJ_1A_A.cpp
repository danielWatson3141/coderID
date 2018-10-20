#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define min(x,y) (x<y?x:y)
using namespace std;
vector<string> org,tar;
long long dif[200][200];
bool v[200];
long long getdif(string a,string b)
{
	long long ret=0;
	for(int i=0;i<a.length();i++)
	{
		ret*=2;
		if(a[i]!=b[i])
			ret++;
	}
	return ret;
}
int getlen(long long k)
{
	int ret=0;
	while(k>0)
	{
		if(k%2)
			ret++;
		k/=2;
	}
	return ret;
}
int sol(int N,int L)
{
	memset(dif,0,sizeof(dif));
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dif[i][j]=getdif(org[i],tar[j]);
	long long ans=-1;
	for(long long k=0,find;k<N;k++)
	{
		memset(v,false,sizeof(v));
		find=dif[k][0];
		v[k]=true;
		for(int i=0;i<N;i++)
			for(int j=1;j<N;j++)
				if(!v[i]&&dif[i][j]==find)
				{
					v[i]=true;
					break;
				}
		bool f=false;
		for(int i=0;i<N&&!f;i++)
			if(!v[i])
				f=true;
		if(!f)
		{
			if(ans==-1)
				ans=getlen(find);
			else
				ans=min(ans,getlen(find));
		}
	}
	return ans;
}
int main()
{
	freopen("AinL.in","r",stdin);
	freopen("AoutL.txt","w",stdout);
	int T,N,L;
	string tmp;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>N>>L;
		org.clear();
		tar.clear();
		for(int i=0;i<N;i++)
			cin>>tmp,org.push_back(tmp);
		for(int i=0;i<N;i++)
			cin>>tmp,tar.push_back(tmp);
		printf("Case #%d: ",i);
		int ans=sol(N,L);
		if(ans==-1)
			cout<<"NOT POSSIBLE\n";
		else
			cout<<ans<<endl;
	}
	return 0;
}
