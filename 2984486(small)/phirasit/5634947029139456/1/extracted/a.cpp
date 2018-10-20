#include <stdio.h>
#include <algorithm>
#include <iostream>

#define N 200

using namespace std;

string s[N],p[N],ts[N],tp[N];
int com[N];
int n,k,t;

int main() {
	cin >> t;
	for(int Case = 1;Case <= t;Case++) {
		cin >> n >> k;
		for(int i=0;i<n;i++) {
			cin >> p[i];
		}
		for(int i=0;i<n;i++) {
			cin >> s[i];
		}
		int ans = -1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				for(int x=0;x<n;x++) {
					ts[x] = s[x];
					tp[x] = p[x];
				}
				swap(ts[0],ts[i]);
				sort(ts + 1,ts + n);
				swap(tp[0],tp[j]);
				int cnt = 0;
				for(int x=0;x<k;x++) {
					if(ts[0][x] != tp[0][x]) {
						com[x] = 1;
						cnt++;
					}else {
						com[x] = 0;
					}
				}
				for(int ii=0;ii<n;ii++) {
					for(int jj=0;jj<k;jj++) {
						if(com[jj]) {
							tp[ii][jj] = !(tp[ii][jj]-'0') + '0';
						}
					}
				}
				sort(tp + 1,tp + n);
				bool found = false;
				for(int ii=0;ii<n;ii++) {
					if(ts[ii] != tp[ii]) {
						found = true;
					}
				}
				if(found) continue;
				if(ans == -1 || cnt < ans) {
					ans = cnt;
				}
			}
		}
		printf("Case #%d: ",Case);
		if(ans == -1) {
			printf("NOT POSSIBLE\n");
		}else {
			printf("%d\n",ans);
		}
	}
	return 0;
}
