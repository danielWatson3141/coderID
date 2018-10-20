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

#define NAME "A-large"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double

const ll mod7 = 1000000007;

ll a[1000];
ll b[1000];
string s;

ll tos[1000];

int main()
{
    freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int Case=1;Case<=T;Case++)
	{
		cout << "Case #" << Case << ": ";
		int n,l;
		cin >> n >> l;
		int ans = 100;
		for(int i=0;i<n;++i)
		{
			cin >> s;
			a[i] = 0;
			for(int j=0;j<l;++j)
			{
				if(s[j]=='1')
					a[i]+=1ll<<j;
			}
		}
		for(int i=0;i<n;++i)
		{
			cin >> s;
			b[i] = 0;
			for(int j=0;j<l;++j)
			{
				if(s[j]=='1')
					b[i]+=1ll<<j;
			}
		}
		sort(b,b+n);
		for(int j=0;j<n;++j)
		{
			ll mask = a[0]^b[j];
			ll temp = mask;
			int calc = 0;
			do
			{
				if(temp&1)++calc;
				temp>>=1;
			}
			while(temp);
			
			for(int k=0;k<n;++k)
				tos[k] = a[k]^mask;
			sort(tos,tos+n);
			bool bad = false;
			for(int k=0;k<n && !bad;++k)
			if(tos[k]!=b[k])
			{
				bad = true;
			}
			if(!bad)
			{
				ans = min(ans,calc);
			}
		}

		if(ans==100)
			cout << "NOT POSSIBLE";
		else
			cout << ans;
		cout << endl;
	}


    return 0;
}