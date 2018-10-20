#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>

#define pb push_back
#define rep(i,s,n) for(int i=s;i<n;i++)
#define s(n) scanf("%d",&n)

using namespace std;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	//freopen("Inp1.txt","r",stdin);
	freopen("Out.out","w",stdout);
	static long T, N, L, nomatch, bit[1024], found, ans;
	string inp1[150], inp2[150], temp[150];
	rep(i,1,(1<<10))
		bit[i]=bit[i-(i&(-i))]+1;
    cin>>T;
	for(int i=1;i<=T;i++)
	{
		ans=10000;
		nomatch=0;
		found=0;
		cin>>N>>L;
		rep(j,0,N)
		{
			cin>>inp1[j];
			temp[j]=inp2[j];
		}
		rep(j,0,N)
		{
			cin>>inp2[j];
		}
		sort(inp2,inp2+N);
		rep(j,0,(1<<L))
		{
			nomatch=0;
			rep(k,0,N)
            	temp[k]=inp1[k];
			rep(k,0,L)
			{
				if(1<<k & j)
				{
					rep(w,0,N)
					{
						if(temp[w][k]=='0')
						    temp[w][k]='1';
						else
						    temp[w][k]='0';
					}
				}
			}
			sort(temp,temp+N);
			rep(k,0,N)
			{
				if(temp[k]!=inp2[k])
				    nomatch++;
			}
			if(nomatch==0)
			{
				ans=min(ans,bit[j]);
				found++;
			}
		}
		if(found==0)
			cout<<"Case #"<<i<<": NOT POSSIBLE"<<endl;
		else
		    cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
