#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,L;
	scanf("%d",&t);
	for(int T=1;T<=t&&scanf("%d%d",&n,&L);T++)
	{
		vector<string>v1,v2;
		char s[500];
		int res=INT_MAX;
		for(int i=0;i<n;i++)
			{
				scanf("%s",s);
				string tmm(s);
				v1.push_back(tmm);
			}
		for(int i=0;i<n;i++)
		{
				scanf("%s",s);
				string tmm(s);
				v2.push_back(tmm);
		}
		sort(v2.begin(),v2.end());
		for(int i=0;i<(1<<L);i++)
		{
			vector<string>tmp=v1;
			int c_1=0;
			for(int j=0;j<L;j++)
			{
				if(i&(1<<j))
					{
						for(int k=0;k<tmp.size();k++)
							{
								if(tmp[k][j]=='0')
									tmp[k][j]='1';
								else tmp[k][j]='0';
							}
						c_1++;
					}
			}
			sort(tmp.begin(),tmp.end());
			if(tmp==v2)
				res=min(res,c_1);
		}
		if(res==INT_MAX)
			printf("Case #%d: NOT POSSIBLE\n",T);
		else printf("Case #%d: %d\n",T,res);
	}
	return 0;
}
