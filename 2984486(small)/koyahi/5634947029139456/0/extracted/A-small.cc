#include <iostream>

#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX_N = 155;
int T, N, L;
ll outlet[MAX_N];
ll device[MAX_N];
int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &L);
		for (int i = 0; i < N; i++) {
            ll o = 0;
            for (int j = 0; j < L; j++) {
                o <<= 1;
                char c;
                scanf(" %c", &c);
                if (c == '1') o += 1;
            }
            outlet[i] = o;
		}
        for (int i = 0; i < N; i++) {
			ll d = 0;
            for (int j = 0; j < L; j++) {
                d <<= 1;
                char c;
                scanf(" %c", &c);
                if (c == '1') d += 1;
            }
            device[i] = d;
		}
        int ret = 42;
        for (int i = 0; i < (1 << L); i++) {
            ll temp[MAX_N];
            for (int j = 0; j < N; j++) {
                temp[j] = outlet[j];
            }
            int count = 0;
            for (int j = 0; j < L; j++) {
                if ((i >> j)&1) {  //j番目をひっくり返す
                    count++;
                    for (int k = 0; k < N; k++) {
                        if ((temp[k]>>j)&1) {
                            temp[k] -= (1<<j);
                        } else {
                            temp[k] += (1<<j);
                        }
                    }
                }
            }
            bool check = true;
            for (int d = 0; d < N; d++) {
                bool exist = false;
                for (int o = 0; o < N; o++) {
                    if (device[d] == temp[o]) {
                        exist = true;
                        break;
                    }
                }
                if (!exist) {
                    check = false;
                    break;
                }
            }
            if (check) ret = min(ret, count);
        }
        if (ret == 42) printf("Case #%d: NOT POSSIBLE\n", t+1);
        else printf("Case #%d: %d\n", t+1, ret);

	}
}