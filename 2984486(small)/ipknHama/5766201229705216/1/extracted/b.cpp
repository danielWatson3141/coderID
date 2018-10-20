#include  <iostream>
#include <memory>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

char d[1001][1001];
int m[1001][1001];
vector<pair<int,int>> v;
int N;

int solve(int x, int p)
{
	if (d[x][p] == 0)
		return 0;
	if (m[x][p])
		return m[x][p];
	vector<int> v;
	v.reserve(N);
	for(int i = 0; i < N;i++)
	{
		if (i == x || i == p)
			continue;
		if (!d[x][i])
			continue;
		v.push_back(solve(i, x));
	}
	sort(v.begin(), v.end());
	int l = 1;
	if (v.size() <= 1)
	{
	}
	else
	{
		l = v[v.size()-2]+v[v.size()-1]+1;
	}
	m[x][p] = l;
	//cout << x <<' '<<p <<' '<<l<<endl;
	return m[x][p];
}

int main()
{
	int tn;
	cin.sync_with_stdio(false);
	cin >> tn;
	while(tn--)
	{
		static int pn=0;
		pn ++;
		cout << "Case #" << pn <<": ";
		memset(m, 0, sizeof(m));
		memset(d, 0, sizeof(d));
		cin >> N;
		v.clear();
		v.reserve(N);
		for(int i = 1;i <N;i++)
		{
			int a,b;
			cin >> a >> b;
			a--;b--;

			d[a][b] = d[b][a] = 1;
			v.push_back(make_pair(a,b));
		}
		if (N==2)
		{
			cout << 1 << endl;
			continue;
		}
		vector<int> x;
		x.reserve(N);
		int ml = 1;
		for(int i = 0; i < N; i ++)
		{
			//assume i is root
			x.clear();
			for(int j = 0;j < N; j ++)
			{
				if (j == i || d[j][i] == 0)
					continue;
				x.push_back(solve(j,i));
			}
			if (x.size() <= 1)
			{
			}
			else
			{
				sort(x.begin(), x.end());
				int l = x[x.size()-1]+x[x.size()-2]+1;
				if (l > ml)
					ml = l;
			}
		}
		//cout << ml << endl;
		cout << N-ml<<endl;
	}
	return 0;
}
