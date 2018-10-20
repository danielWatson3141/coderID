#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 155;
const int MAXL = 55;

int N, L;
char ch;
long long A[MAXN], B[MAXN];
vector<long long> gao;
int cases;
char buf[MAXL];
bool flag[MAXL];

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%d%d", &N, &L);
		scanf("%c", &ch);
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for(int i = 0; i < N; ++i){
			scanf("%s", buf);
			for(int j = 0; j < L; ++j)
				if(buf[j] == '1') A[i] += (1LL << j);
		}
		for(int i = 0; i < N; ++i){
			scanf("%s", buf);
			for(int j = 0; j < L; ++j)
				if(buf[j] == '1') B[i] += (1LL << j);
		}
		sort(A, A + N);
		sort(B, B + N);
		int ans = 99999999;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j){
				long long sta = A[i] ^ B[j];
				int cnt = __builtin_popcountll(sta);
				gao.clear();
				for(int k = 0; k < N; ++k)
					gao.push_back(A[k] ^ sta);
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
