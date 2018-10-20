#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;

ul one = 1;

int t,n,l;
string s;
int arr[50];
int target[50];
int memo[(1<<10)+5];
bool found;
int ans;

void dp(int bitmask, int p){
	//if (found) return;
	if (memo[bitmask] >= 0) return;
	memo[bitmask] = 1;
	sort(arr,arr+n);
	found = true;
	for (int i=0; i<n; i++){
		if (arr[i] != target[i]){
			found = false;
			break;
		}
	}
	if (found){
		ans = min(ans,p);
		return;
	}
	for (int i=0; i<l; i++){
		if (!(bitmask & (1<<i))){
			for (int j=0; j<n; j++){
				arr[j] ^= (1<<i);
			}
			dp(bitmask | (1<<i), p+1);
			for (int j=0; j<n; j++){
				arr[j] ^= (1<<i);
			}
		}
	}
	return;
}

int main(){
	scanf("%d",&t);
	for (int jj=1; jj<=t; jj++){
		scanf("%d%d",&n,&l);
		for (int i=0; i<n; i++){
			cin >> s;
			arr[i] = 0;
			for (int j=0; j<l; j++){
				arr[i] = arr[i]*2+(s[j]-'0');
			}
			//cout << arr[i] << endl;
		}
		for (int i=0; i<n; i++){
			cin >> s;
			target[i] = 0;
			for (int j=0; j<l; j++){
				target[i] = target[i]*2+(s[j]-'0');
			}
			//cout << target[i] << endl;
		}
		sort(target,target+n);
		found = false;
		memset(memo,-1,sizeof memo);
		printf("Case #%d: ",jj);
		ans = 1000000000;
		dp(0,0);
		if (ans > l) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}
