#include <cstdlib>
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

char bin[50];

long long todec(){
	int len = strlen(bin);
	long long t = 0;
	for(int i=0; i<len; i++){
		t <<= 1;
		if(bin[i] == '1'){
			t += 1;
		}
	}
	return t;
}

int testbit(long long n, int l){
	int ans = 0;
	for(int i=0; i<l; i++){
		if((n&(1LL<<i)) != 0){
			ans++;
		}
	}
	return ans;
}

int main(){
	int cases;
	scanf("%d", &cases);
	for(int z=1; z<=cases; z++){
		int n, l;
		scanf("%d %d", &n, &l);
		
		set<long long> devices;
		vector<long long> devices2;
		for(int i=0; i<n; i++){
			scanf("%s", &bin);
			long long t = todec();
			devices.insert(t);
			devices2.push_back(t);
		}
		
		vector<long long> outlets;
		for(int i=0; i<n; i++){
			scanf("%s", &bin);
			long long t = todec();
			outlets.push_back(t);
		}
		
		queue<long long> mask;
		queue<int> index;
		mask.push(0LL);
		index.push(0);
		int ans = -1;
		while(mask.size() != 0){
			long long m = mask.front(); mask.pop();
			int ind = index.front(); index.pop();
			if(ans != -1 && testbit(m, l) > ans) continue;
			
			bool ok = true;
			for(int i=0; i<n; i++){
				int t = outlets[i]^m;
				if(devices.count(t) == 0){
					ok = false;
				}
			}
			if(ok && (ans == -1 || testbit(m, l) < ans)){
				ans = testbit(m, l);
			}
			
			if(ind == l) continue;
			
			map<long long, int> zero;
			map<long long, int> one;
			long long m2 = (1LL<<(ind+1)) - 1;
			for(int i=0; i<n; i++){
				if(zero.count(devices2[i]&m2) == 0){
					zero[devices2[i]&m2] = 1;
					one[devices2[i]&m2] = 1;
				}else{
					zero[devices2[i]&m2] += 1;
					one[devices2[i]&m2] += 1;
				}
			}
			
			ok = true;
			for(int i=0; i<n; i++){
				long long t = (outlets[i]^m)&m2;
				map<long long, int>::iterator it = zero.find(t);
				if(it == zero.end() || it->second == 0){
					ok = false;
					break;
				}else{
					it->second -= 1;
				}
			}
			if(ok){
				mask.push(m);
				index.push(ind+1);
			}
			
			ok = true;
			for(int i=0; i<n; i++){
				long long t = ((outlets[i]^m)&m2)^(1<<ind);
				map<long long, int>::iterator it = one.find(t);
				if(it == one.end() || it->second == 0){
					ok = false;
					break;
				}else{
					it->second -= 1;
				}
			}
			if(ok){
				mask.push(m^(1<<ind));
				index.push(ind+1);
			}
		}
		
		if(ans == -1){
			printf("Case #%d: NOT POSSIBLE\n", z);
		}else{
			printf("Case #%d: %d\n", z, ans);
		}
	}

	return 0;
}