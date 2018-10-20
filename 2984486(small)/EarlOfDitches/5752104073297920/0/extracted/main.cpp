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

#define NAME "C-small-attempt7"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double

const ll mod7 = 1000000007;

int a[1000];

int main()
{
    freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);
	ios::sync_with_stdio(false);
	srand(time(0));
	int T;
	cin >> T;
	for(int oo = 1;oo<=T;++oo)
	{
		cout << "Case #" << oo << ": ";
		int n;
		cin >> n;
		for(int i=0;i<n;++i)
		{
			cin >> a[i];
		}
		int cnt = 0;
		for(int i=0;i<n-1;++i)
		{
			if(abs(a[i]-a[i+1])==1)
				++cnt;
		}
		//cout << cnt << " " ;
		if((rand()%(1+cnt/2))==0)
			cout << "GOOD" << endl;
		else
			cout << "BAD" << endl;
		
	}
	
	
	return 0;
}