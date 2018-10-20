#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T, N;
int G[1004][1004];

bool cmp (pair<int, int> i,pair<int, int> j) {
    if (i.second == j.second)
        return i.first < j.first;
    return i.second > j.second;
}

pair<int, int> recorre(int nodo, int padre) {
    int j = 0, h[1004];
    pair<int, int> H[1004], s = make_pair(0, 0);
    for (int i = 0; i < N; i++) {
        if (i != padre && G[nodo][i] == 1) {
            h[j++] = i;
        }
    }
    for (int i = 0; i < j; i++) {
        H[i] = recorre(h[i], nodo);
    }
    if (j < 2) {
        if (j == 1) {
            s = make_pair(H[0].second + 1, H[0].second + 1);
        }
        else {
            s = make_pair(0, 0);
        }
    }
    else {
        int i;
        sort(H, H+j, cmp);
        s = make_pair(H[0].first + H[1].first, H[0].second + H[1].second);
        for (i = 2; i < j; i++)
            s.first += H[i].second +1;
            s.second += H[i].second +1;
    }
    return s;
}

int main() {

    int i, k;
    int x, y;
    pair <int, int> r, s;

    scanf("%d", &T);
    for (k = 1; k <= T; k++) {
        memset(G, 0, sizeof(G));
        scanf("%d", &N);
        for (i = 0; i < N-1; i++) {
            scanf("%d%d", &x, &y);
            x--;
            y--;
            G[x][y] = 1;
            G[y][x] = 1;
        }

        r = make_pair(10001, 10001);
        int j = -1;
        for (i = 0; i < N; i++) {
            s = recorre(i, -1);
            if (r.first > s.first){
                r = s;
            }
        }

        printf("Case #%d: %d\n", k, y);

    }

    return 0;
}
