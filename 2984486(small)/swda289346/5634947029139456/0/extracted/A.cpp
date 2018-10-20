#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	int n, l;
	int ans;
	bool feasible;
	string tmp;
	vector<string> source, target;
	vector<bool> flex, flip;
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		ans = 0;
		feasible = true;
		source.clear();
		target.clear();
		flex.clear();
		flip.clear();
		cin >> n >> l;
		flex.resize(l);
		flip.resize(l);
		for (int j=0;j<n;j++)
		{
			cin >> tmp;
			source.push_back(tmp);
		}
		for (int j=0;j<n;j++)
		{
			cin >> tmp;
			target.push_back(tmp);
		}
		sort(target.begin(), target.end());
		for (int j=0;j<l;j++)
		{
			int ms = 0, mt = 0;
			flip[j] = flex[j] = false;
			for (int k=0;k<n;k++)
			{
				if (source[k][j]=='1')
					ms++;
				if (target[k][j]=='1')
					mt++;
			}
			cerr << ms << " " << mt << endl;
			if (n%2==0 && ms==mt)
				flex[j] = true;
			if (ms!=mt)
			{
				flip[j] = true;
				for (int k=0;k<n;k++)
				{
					if (source[k][j]=='1')
						source[k][j] = '0';
					else	
						source[k][j] = '1';
				}
			}
			sort(source.begin(), source.end());
			for (int k=0;k<n;k++)
				if (source[k][j]!=target[k][j])
					feasible = false;
//			for (int k=0;k<n;k++)
//				cerr << source[k] << " ";
//			cerr << endl;
		}
		cerr << flex[0] << flex[1] << endl;
		cerr << flip[0] << flip[1] << endl;
		if (feasible)
		{
			int dp[40][41] = {};
			if (flex[l-1])
				dp[l-1][0] = dp[l-1][1] = 1;
			else
				dp[l-1][flip[l-1]] = 1;
			for (int j=l-2;j>=0;j--)
			{
				if (flex[j])
				{
					for (int k=l;k>=flip[j];k--)
						dp[j][k] = dp[j+1][k-flip[j]];
					for (int k=0;k<=l;k++)
						if (dp[j+1][k])
							dp[j][(l-j)-k] = 1;
				}
				else
				{
					for (int k=l;k>=flip[j];k--)
						dp[j][k] = dp[j+1][k-flip[j]];
				}
			}
			ans = l;
			for (int j=l-1;j>=0;j--)
				if (dp[0][j])
					ans = j;
		cerr << dp[0][0] << dp[0][1] << endl;
		}
		cout << "Case #" << i << ": ";
		if (feasible)
			cout << ans;
		else
			cout << "NOT POSSIBLE";
		cout << endl;
	}
	return 0;
}
