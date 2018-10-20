#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int num[120][1000], n, val[1000], t;

void input() {
	scanf("%d", &t);
	for(int i = 0;i < t;i ++) {
		scanf("%d", &n);
		for(int j = 0;j < n;j ++) scanf("%d", &num[i][j]);
	}
}

void output() {
	vector<pair<double, int> > vp;
	for(int ii = 0;ii < t;ii ++) {
		for(int i = 0;i < n;i ++) val[i] = i;

		double prob = 1;
		for(int i = 0;i < n;i ++) {
			if(val[i] == num[ii][i]) prob *= 1.0/(n-i);
			else {
				for(int j = i+1;j < n;j ++) if(val[j] == num[ii][i]) {
					swap(val[i], val[j]);
					break;
				}
				prob *= (double(n-i-1))/(n-i);
			}
		}
		vp.push_back(make_pair(prob, ii));
	}

	sort(vp.begin(), vp.end());
	
	int ok[120];
	for(int i = 0;i < t;i ++) ok[i] = 1;
	for(int i = 0;i < t/2;i ++) ok[vp[i].second] = 0;

	for(int i = 0;i < t;i ++) {
		printf("Case #%d: ", i+1);
		if(ok[i]) printf("GOOD\n");
		else printf("BAD\n");
	}
}

int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	//int t;
	//scanf("%d", &t);
	//for(int cas = 1;cas <= t;cas ++) {
		input();
		//printf("Case #%d: ", cas);
		output();
	//}
	return 0;
}