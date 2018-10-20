#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct node{
    int v, next;
};

int n, u[1001];
node edge[2000];

int calc(int r, int fa) {
    int m1 = -1, m2 = -1;
    for (int p = u[r]; p != -1; p = edge[p].next) {
        if (edge[p].v != fa) {
            int current = calc(edge[p].v, r);
            if (m1 == -1) {
                m1 = current;
            } else {
                if (m2 == -1) {
                    m2 = current;
                } else {
                    if (current > min(m1, m2)) {
                        if (m1 < m2) {
                            m1 = current;
                        } else {
                            m2 = current;
                        }
                    }
                }
            }
        }
    }
    if (m1 != -1 && m2 != -1) {
        return m1 + m2 + 1;
    } else {
        return 1;
    }
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        cin >> n;
        memset(u, -1, sizeof(u));
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            edge[i * 2].v = b;
            edge[i * 2].next = u[a];
            u[a] = i * 2;
            edge[i * 2 + 1].v = a;
            edge[i * 2 + 1].next = u[b];
            u[b] = i * 2 + 1;
        }
        int ans = n;
        for (int i = 1; i <= n; i++) {
            int current = n - calc(i, -1);
            if (current < ans) {
                ans = current;
            }
        }
        printf("Case #%d: %d\n", task, ans);
    }
}
