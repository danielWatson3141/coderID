#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> a, b;

#define INF 0x3f3f3f3f

bool check(vector<string> x, vector<string> y)
{
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
//	cout<<endl<<endl;
	for(int i = 0; i < x.size(); ++i)
	{
//		cout<<x[i] <<" "<<y[i]<<endl;
		if(x[i] != y[i])
			return false;
	}
	return true;
}

int main()
{
	freopen("d:\\1.in", "r", stdin);
	freopen("d:\\1.txt", "w", stdout);
	
	int T;
	cin>>T;
	for(int kase = 1; kase <= T; ++kase)
	{
		a.clear();
		b.clear();
		int n, l;
		cin>>n>>l;
		string str;
		for(int i = 0; i < n; ++i)
		{
			cin>>str;
			a.push_back(str);
		}
		
		for(int i = 0; i < n; ++i)
		{
			cin>>str;
			b.push_back(str);
		}
		
		int ans = INF;
		for(int i = 0; i < n; ++i)
		{
			long long mask = 0;
			int cnt = 0;
			for(int j = 0; j < l; ++j)
			{
				if(a[0][j] != b[i][j])
				{
					cnt++;
					mask |= (1LL << j);
				}
			}
			
			vector<string> tmpa, tmpb;
			for(int j = 0; j < n; ++j)
			{
				str = "";
				for(int k = 0; k < l; ++k)
				{
					if(mask & (1LL<<k))
					{
						if(a[j][k] == '0')
							str += '1';
						else
							str += '0';
					}
					else
					{
						str += a[j][k];
					}
				}
				
				tmpa.push_back(str);
				tmpb.push_back(b[j]);
			}
			
			if(check(tmpa, tmpb))
			{
				ans = min(ans, cnt);
			}
		}
		
		cout<<"Case #"<<kase<<": ";
		if(ans == INF)
			cout<<"NOT POSSIBLE"<<endl;
		else
			cout<<ans<<endl;
	}
	
	return 0;
}
