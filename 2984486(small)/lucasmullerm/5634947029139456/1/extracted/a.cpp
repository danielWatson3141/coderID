#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
int T, n, l;

string dev[200];
string x[200];


int main(int argc, char const *argv[])
{
	string flow[200];
	char aux[50];
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%d %d", &n, &l);
		for (int i = 0; i < n; ++i){
			scanf("%s", aux);
			flow[i] = aux;
		}
		for (int i = 0; i < n; ++i){
			scanf("%s", aux);
			dev[i] = aux;
		}
		sort(dev, dev+n);
		int count = 1000000007;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				x[i] = flow[i];
			}
			int qt = 0;
			for (int j = 0; j < l; ++j)
			{
				if(x[i][j] != dev[0][j]){
					qt++;
					for (int i = 0; i < n; ++i)
					{
						x[i][j] ^= 1;
					}
				}
			}
			sort(x, x + n);
			bool flag = true;
			for (int i = 0; i < n; ++i)
			{
				if(x[i] != dev[i]){
					flag = false;
					break;
				}
			}
			if(flag){
				count = min(count, qt);
			}
			if(count == 0)
				break;
		}
		if(count == 1000000007)
			printf("Case #%d: NOT POSSIBLE\n", tt);
		else
			printf("Case #%d: %d\n", tt, count);
	}
	return 0;
}