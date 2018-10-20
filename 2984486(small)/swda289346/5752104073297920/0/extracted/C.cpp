#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t, n, count;
	int tmp;
	int get[1000];
	double p, e, var, sd;
	cin >> t;
	for (int i=1;i<=t;i++)
	{
	int dp[1000] = {};
		count = 0;
		cin >> n;
		for (int j=0;j<n;j++)
		{
			cin >> get[j];
//			if (tmp==j)
	//			count++;
		}
		p = 1./n;
		e = n*p;
		var = n*p*(1-p);
		sd = sqrt(var);
		dp[0] = 1;
		for (int j=1;j<n;j++)
			for (int k=0;k<j;k++)
				dp[j] = max(dp[j], dp[k]+(get[k]<get[j]));
		int lis = 0;
		for (int j=0;j<n;j++)
			lis = max(lis, dp[j]);
		cout << "Case #" << i << ": ";
		if (lis<=500)
			cout << "GOOD";
		else
			cout << "BAD";
		cout << endl;
	}
	return 0;
}
