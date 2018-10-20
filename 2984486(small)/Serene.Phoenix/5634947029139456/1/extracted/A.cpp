#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int Tn;
int n,l;
string outlet[200], dev[200];
string tmp1[200], tmp2[200];

void flip(int pos)
{
	for (int i=0;i<n;i++)
		tmp1[i][pos] = (tmp1[i][pos]=='1')?'0':'1';
}

bool check()
{
	bool used[200];
	memset(used, 0, sizeof used);
	for (int i=0;i<n;i++)
	{
		bool flag = false;
		for (int j=0;j<n;j++)
			if (!used[j] && tmp1[i]==tmp2[j])
			{
				used[j] = true;
				flag = true;
			}
		if (!flag)
			return false;
	}
	return true;
}

int calc(int x)
{
	memcpy(tmp1, outlet, sizeof outlet);
	memcpy(tmp2, dev, sizeof dev);

	int i;
	int res = 0;
	for (i=0;i<l;i++)
		if (outlet[0][i]!=dev[x][i])
		{
			flip(i);
			res++;
		}
	if (check())
		return res;
	else
		return 20000;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	int i,j;

	cin >> Tn;
	for (int T=1;T<=Tn;T++)
	{
		cin >> n >> l;
		memset(outlet, 0, sizeof outlet);
		memset(dev, 0, sizeof dev);

		for (i=0;i<n;i++)
			cin >> outlet[i];
		for (i=0;i<n;i++)
			cin >> dev[i];

		int ans = 20000;
		for (i=0;i<n;i++)
			ans = min(ans, calc(i));
		
		cout << "Case #" << T << ": ";
		if (ans <= l)
			cout << ans << endl;
		else
			cout << "NOT POSSIBLE" << endl;
	}
}