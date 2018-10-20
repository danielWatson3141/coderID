#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int limit = 1000 + 5;
const int maxn = 1000000000;
vector<string> a , b;
int n, m;

int thu(string start, string target, const vector<string> &b){
	string change;
	int t = 0;
	for(int i = 0; i < m; ++i)
		if (start[i] != target[i]) {
			change.push_back('1');
			t++;
		} else change.push_back('0');

	vector<string> tmp = a;
	for(int i = 0; i < n; ++i)
	for(int k = 0; k < m; ++k)
		if (change[k] == '1')
		if (tmp[i][k] == '1')  tmp[i][k] = '0'; else tmp[i][k] = '1';
	
	sort(tmp.begin(), tmp.end());
	if (tmp == b) return t;
	return maxn;
}



int main(){
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int T = 1; T <= test; ++T){
		printf("Case #%d: ",T);
		cin >> n >> m;
		a.resize(n); b.resize(n);
		int kq = maxn;
		for(int i = 0; i < n; ++i) cin >> a[i];
		for(int i = 0; i < n; ++i) cin >> b[i];
		sort(b.begin(), b.end());
		
		for(int i = 0; i < n; ++i)
			kq = min(kq, thu(a[0], b[i],b)) ;
		if (kq == maxn)
			printf("NOT POSSIBLE\n");
			else printf("%d\n",kq);
			
	}
		
	
}
