#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 155;
const int MAXL = 55;

int N, L;
char ch;
string A[MAXN], B[MAXN];
vector<string> gao;
int cases;
char buf[MAXL];
bool flag[MAXL];

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%d%d", &N, &L);
		scanf("%c", &ch);
		for(int i = 0; i < N; ++i){
			scanf("%s", buf);
			string tmp(buf);
			A[i] = tmp;
		}
		for(int i = 0; i < N; ++i){
			scanf("%s", buf);
			string tmp(buf);
			B[i] = tmp;
		}
		sort(A, A + N);
		sort(B, B + N);
		int ans = 99999999;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j){
				int cnt = 0;
				memset(flag, false, sizeof(flag));
				for(int k = 0; k < L; ++k)
					if(A[i][k] != B[j][k]){
						flag[k] = true;
						cnt++;
					}
				gao.clear();
				for(int k = 0; k < N; ++k){
					string now = "";
					for(int l = 0; l < L; ++l){
						if(flag[l]){
							if(A[k][l] == '0') now = now + "1";
							else now = now + "0";
						} else {
							if(A[k][l] == '0') now = now + "0";
							else now = now + "1";
						}
					}
					gao.push_back(now);
				}
				sort(gao.begin(), gao.end());
				bool ok = true;
				for(int k = 0; k < N; ++k)
					if(gao[k] != B[k]){
						ok = false;
						break;
					}
				if(ok){
					ans = min(ans, cnt);
				}
			}
		printf("Case #%d: ", xx);
		if(ans == 99999999){
			puts("NOT POSSIBLE");
		} else {
			printf("%d\n", ans);
		}
	}

}
