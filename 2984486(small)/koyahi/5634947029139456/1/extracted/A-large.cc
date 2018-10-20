#include <iostream>

#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX_N = 155;
const int MAX_L = 42;
int T, N, L;
ll outlet[MAX_N];
ll device[MAX_N];
bool change[MAX_L];
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
        int ret = MAX_L;
        //compare device[0] to outlet[i]
        for (int i = 0; i < N; i++) {
            int count = 0;
            memset(change, false, sizeof(change));
            ll temp[MAX_N];
            for (int j = 0; j < N; j++) {
                temp[j] = outlet[j];
            }
            for (int j = 0; j < L; j++) {
                ll d = (device[0] >> j)&1;
                ll o = (outlet[i] >> j)&1;
                if (d == o) {
                    change[j] = true;
                    count++;
                }
            }
            //change outlet
            for (int j = 0; j < L; j++) {
                if (change[j]) {
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
            for (int o = 0; o < N; o++) {
                bool exist = false;
                for (int d = 0; d < N; d++) {
                    if (temp[o] == device[d]) {
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
        if (ret == MAX_L) printf("Case #%d: NOT POSSIBLE\n", t+1);
        else printf("Case #%d: %d\n", t+1, ret);
        
	}
}