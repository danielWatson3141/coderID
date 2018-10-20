#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <bitset>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
const int INF = 2147483647;
//cout.setprecisiont(n)
//cout << fixed ;
//resetiosflags(ios::fixed) 
//std::cout << setfill ('x') << setw (n);

ll transform(string &s){
	ll out = 0;
	for(int i=0; i<(int)s.size(); i++){
		if(s[i]=='1')
			out |= (1LL<<i);
	}
	return out;
}


int main(){
	std::ios::sync_with_stdio(false);
	int t,n,l;
	string str;
	vl cur;
	cin >> t;
	for(int test=1; test<=t; test++){
		cin >> n >> l;
		vl initial(n);
		vl devices(n);

		for(int i=0; i<n; i++){
			cin >> str;
			initial[i] = transform(str);
		}
		for(int i=0; i<n; i++){
			cin >> str;
			devices[i] = transform(str);
		}
		
		sort(all(initial));
		sort(all(devices));

		int ans = INF;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cur = initial;
				int toggles=0;
				for(int k=0; k<l; k++){
					if( (initial[i] & (1<<k)) != (devices[j] & (1<<k))  ){
						toggles++;
						for(int p=0; p<n; p++){
							cur[p] ^= (1<<k);
						}
					}
				}
				sort(all(cur));
				if( cur==devices && ans > toggles ){
					ans = toggles;
				}
			}
		}
		cout << "Case #" << test << ": ";
		if(ans == INF){
			cout << "NOT POSSIBLE\n";
		}else{
		 	cout << ans << "\n";
		}
	}


	return 0;
}
