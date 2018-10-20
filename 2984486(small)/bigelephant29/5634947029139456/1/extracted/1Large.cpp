#include<cstdio>
#include<iostream>
#include<set>
#include<cstring>
using namespace std;
const int INF = 2147483647;
const int MINF = -INF;
const int MAXN = 150 + 10;
const int MAXL = 40 + 10;
int n, m;
string a1[MAXN];
string a2[MAXN];
string tmp[MAXN];
int cnt[MAXN];

multiset<string> s;

int XOR(string &T1, string &T2, string &A){
	int tcnt = 0;
	for(int i = 0 ; i < m ; i++){
		A[i] = (T1[i]!=T2[i]) ? '1' : '0';
		tcnt += int(A[i]=='1');
	}
	return tcnt;
}

bool cmp(string &T1, string &T2){
	for(int i = 0 ; i < m ; i++)
		if(T1[i]!=T2[i]) return false;
	return true;
}

int main(){
	int TN;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		scanf("%d %d", &n, &m);
		for(int i = 0 ; i < n ; i++){
			cin>>a1[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin>>a2[i];
		}
		for(int i = 0 ; i < n ; i++){
			tmp[i] = a1[0];
			cnt[i] = XOR(a1[0], a2[i], tmp[i]);
		}
		string test = a1[0];
		int ans = INF;
		for(int i = 0 ; i < n ; i++){
			bool flag = true;
			s.clear();
			for(int j = 0 ; j < n ; j++){
				s.insert(a2[j]);
			}
			for(int j = 0 ; j < n ; j++){
				XOR(a1[j], tmp[i], test);
				multiset<string>::iterator itr = s.find(test);
				if(itr == s.end()){
					flag = false;
					break;
				}
				s.erase(itr);
			}
			if(flag){
				ans = min(cnt[i], ans);
			}
		}
		printf("Case #%d: ", casen);
		if(ans==INF) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	return 0;
}
