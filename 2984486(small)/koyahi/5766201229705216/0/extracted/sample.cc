// g++ -Wall sample.cc
// ./a.out <sample-input.txt >output.txt
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 20;
int T, N, L;
bool G[MAX_N][MAX_N];
bool deleted[MAX_N];
bool arrived[MAX_N];

void dfs2(int p) {
    arrived[p] = true;
    for (int j = 0; j < N; j++) {
        if (!deleted[j] && !arrived[j] && G[p][j]) {
            dfs2(j);
        }
    }
}

bool dfs(int p) {
    vector<int> ch;
    for (int i = 0; i < N; i++) {
        if (i == p) continue;
        if (!deleted[i] && !arrived[i] && G[p][i]) ch.push_back(i);
    }
    if ((int)ch.size() != 0 && (int)ch.size() != 2) return false;
    arrived[p] = true;
    for (int i = 0; i < (int)ch.size(); i++) {
        if (!dfs(ch[i])) return false;
    }
//    arrived[p] = false;
    return true;
}

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
        memset(G, false, sizeof(G));
		scanf("%d", &N);
		for (int i = 0; i < N-1; i++) {
			int x, y;
            scanf("%d %d", &x, &y);
            x--;  //0-indexed
            y--;
            G[x][y] = G[y][x] = true;
		}
        int ret = N-1;
        for (int i = 0; i < (1 << N); i++) {
            int num = 0;
            memset(deleted, false, sizeof(deleted));
            for (int j = 0; j < N; j++) {
                if ((i>>j)&1) {  //delete tree j
                    num++;
                    deleted[j] = true;
                }
            }
            for (int j = 0; j < N; j++) {
                if (!deleted[j]) {
                    bool iso = true;
                    for (int k = 0; k < N; k++) {
                        if (j == k) continue;
                        if (!deleted[k]) {
                            iso = false;
                            break;
                        }
                    }
                    if (iso) deleted[j] = true;
                }
            }
            memset(arrived, false, sizeof(arrived));
            int group = 0;
            for (int j = 0; j < N; j++) {
                if (!deleted[j] && !arrived[j]) {
                    group++;
                    dfs2(j);
                }
            }
            if (group > 1) continue;
            for (int r = 0; r < N; r++) {  //root
                if (deleted[r]) continue;
                memset(arrived, false, sizeof(arrived));
                if (dfs(r)) {
                    ret = min(ret, num);
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", t+1, ret);
	}
}