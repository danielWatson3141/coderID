#include<bits/stdc++.h>
using namespace std;

long long find_min(vector<string> inlet, vector<string> device, long long curr, long long mov) {
	if(curr >= inlet[0].length() ) {
		return INT_MAX;
	}
	else {
		long long i;
		if(inlet==device) {
			return mov;
		}
		vector<string> ve3 = inlet;
		for(i = 0;i < inlet.size();i++) {
			inlet[i][curr] = (1- (inlet[i][curr] - 48) ) + 48;
		}
		sort(inlet.begin(), inlet.end());
		if(inlet == device) {
			return mov + 1;
		}
		else {
			long long mi = INT_MAX;
			for(i = curr + 1;i < inlet[0].length();i++) {
				mi = min(mi, min(find_min(inlet, device, i, mov+ 1), find_min(ve3, device, i, mov)));
			}
			return mi;
		}
	}
	return INT_MAX;
}

int main()
{
	long long T;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%lld",&T);
	long long i;
	for(i = 1; i <= T;i++) {
		long long N, L;
		long long j;
		scanf("%lld",&N);
		scanf("%lld",&L);
		vector <string> inlet,device;
		for(j = 0;j < N;j++) {
			string s;
			cin>>s;
			inlet.push_back(s);
		}
		for(j = 0;j < N;j++) {
			string s;
			cin>>s;
			device.push_back(s);
		}
		sort(inlet.begin(), inlet.end());
		sort(device.begin(), device.end());
		long long h = find_min(inlet, device, 0,0);
		if(h !=INT_MAX) {
			printf("Case #%lld: %lld\n", i, h);
		}
		else {
			printf("Case #%lld: NOT POSSIBLE\n", i);
		}
		
	}
}



