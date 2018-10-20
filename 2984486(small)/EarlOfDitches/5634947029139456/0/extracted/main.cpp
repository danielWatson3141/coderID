//==================================
//==========   WARNING   ===========
//==================================
//===   Contains too many bugs   ===
//==================================
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>

using namespace std;

#define NAME "A-small-attempt0"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double

const ll mod7 = 1000000007;

string arr1[1000];
string arr2[1000];

int a[1000];
int b[1000];
int temp[1000];

int main()
{
    freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);

	int T;
	cin >> T;
	for(int Case=1;Case<=T;Case++)
	{
		cout << "Case #" << Case << ": ";
		int n,l,ans=100;
		cin >> n >> l;
		for(int i=0;i<n;++i)
		{
			cin >> arr1[i];
			a[i] = 0;
			for(int j=0;j<l;++j)
				a[i]+=(arr1[i][j]-'0')<<j;
		}
		for(int i=0;i<n;++i)
		{
			cin >> arr2[i];
			b[i] = 0;
			for(int j=0;j<l;++j)
				b[i]+=(arr2[i][j]-'0')<<j;
		}
		sort(b,b+n);
		for(int i=0;i<(1<<l);++i)
		{
			for(int j=0;j<n;++j)
				temp[j] = a[j]^i;
			sort(temp,temp+n);
			bool bad = false;
			for(int j=0;j<n && !bad;++j)
				if(temp[j]!=b[j])
					bad = true;
			if(!bad)
			{
				int cnt = 0,j = i;
				do
				{
					if(j&1)++cnt;
					j>>=1;
				}while(j);
				ans = min(ans,cnt);
			}
		}

		if(ans == 100)
			cout << "NOT POSSIBLE";
		else
			cout << ans;
		cout << endl;
	}


    return 0;
}