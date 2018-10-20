#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <queue>
#define INF 200000000000LL
#define M 1000000007LL

using namespace std;

int n, l;
string a[200], b[200], c[200];

int check()
{
	int v[200] = {0};
	for (int i = 1; i<=n; i++){
		int flag = 0;
		for (int j = 1; j<=n; j++){
			if (v[j]) continue;
			if (b[i]==a[j]){
				v[j] = 1;
				flag = 1;
				break;
			}
		}
		if (!flag) return 0;
	}
	return 1;
}

int main()
{
	int T;
	cin>>T;
	int ttt = 0;
	while (T--){
		ttt++;
		cin>>n>>l;
		for (int i = 1; i<=n; i++){
			cin>>a[i];
			c[i] = a[i];
		}
		for (int i = 1; i<=n; i++) cin>>b[i];
		int res = 10000;
		for (unsigned int x = 0; x<1<<l; x++){
			for (int i = 1; i<=n; i++) a[i] = c[i];
			for (int i = 0; i<l; i++){
				if ((x>>i)&1){
					for (int j = 1; j<=n; j++){
						if (a[j][i]=='0') a[j][i] = '1';
						else a[j][i] = '0';
					}
				}
			}
			if (check()) res = min(res, __builtin_popcount(x));
		}
		cout<<"Case #"<<ttt<<": ";
		if (res>l) cout<<"NOT POSSIBLE"<<endl;
		else cout<<res<<endl;
	}
}