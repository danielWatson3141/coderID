#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int tab1[152];
int tab2[152];
int tab3[152];
int n,l;

void copy()
{
    for(int i = 0; i < n; i++)
	{
		tab3[i] = tab1[i];
	}
}

void flip(int x)
{
	for(int i = 0; i < n; i++)
	{
		tab3[i] ^= (1<<x);
	}
}

bool check()
{
	bool ok = true;
	sort(tab2,tab2+n);
	sort(tab3,tab3+n);
	for (int i = 0; i < n; i++) if (tab2[i] != tab3[i]) ok = false;
	return ok;
}

void out()
{
	for (int i = 0; i < n; i++) cout << tab3[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; i++) cout << tab2[i] << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> n >> l;
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < l; j++)
			{
   				char c;
				cin >> c;
				if (c == '1') tab1[i] |= (1<<j);
			}
		}
		for (int i = 0; i < n; i++)
		{
            for(int j = 0; j < l; j++)
			{
   				char c;
				cin >> c;
				if (c == '1') tab2[i] |= (1<<j);
			}
		}
		int ans = 100;
		//out();
		for (int i = 0; i < (1<<l); i++)
		{
			copy();
			for(int j = 0; j < l; j++)
			{
				if (i&(1<<j)) flip(j);
			}
			if (check()) ans = min(ans,__builtin_popcount(i));
			//out();
		}
		cout << "Case #" << t << ": ";
		if (ans < 100) cout << ans << "\n";
		else cout << "NOT POSSIBLE\n";
		memset(tab1,0,sizeof(tab1));
		memset(tab2,0,sizeof(tab2));
		memset(tab3,0,sizeof(tab2));
	}
	
	
	return 0;
}
