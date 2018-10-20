#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int T, n, l;
vector<string> bitsOutlets, bitsDevices;

bool testBit(int id){
	if(bitsOutlets == bitsDevices) return true;
	for(int i = 0; i < n; i++){
		if(bitsOutlets[i][id] != bitsDevices[i][id]){
			return false;
		}
	}
	return true;
}

bool matches(){
	vector<string> bs = bitsOutlets;
	sort(bs.begin(), bs.end());
	return bs == bitsDevices;
}

void flipBit(int id){
	for(int i = 0; i < n; i++){
		if(bitsOutlets[i][id] == '1')
			bitsOutlets[i][id] = '0';
		else
			bitsOutlets[i][id] = '1';
	}
}

int dp(int id){
	if(matches()) return 0;
	if(id == l) return -1;
	
	int nFlipping, flipping;
	
	nFlipping = dp(id+1);
	
	flipBit(id);
	flipping = dp(id+1);
	flipBit(id);
	if(flipping == -1 && nFlipping == -1) return -1;
	if(flipping == -1) return nFlipping;
	if(nFlipping == -1) return flipping+1;
	return min(flipping+1,nFlipping);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		cout << "Case #" << caso << ": ";
		cin >> n >> l;
		
		bitsOutlets.assign(n,string());
		bitsDevices.assign(n,string());
		string s;
		
		for(int i = 0; i < n; i++){
			cin >> bitsOutlets[i];
		}
		for(int i = 0; i < n; i++){
			cin >> bitsDevices[i];
		}
		sort(bitsDevices.begin(), bitsDevices.end());
		int ans = dp(0);
		if(ans != -1)
			cout << ans << '\n';
		else
			cout << "NOT POSSIBLE\n";
		
	}
}
