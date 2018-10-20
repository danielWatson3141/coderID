#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int N = 150;
const int L = 44;

int n, m;

struct Node {
    string s[N];

    void read() {
        for (int i = 0; i < n; i++) {
            char str[L];
            scanf("%s", str);
            s[i] = str;
        }
        sort(s, s + n);
    }
    void normal() {
        sort(s, s + n);
    }
    int count(int j) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += s[i][j] - '0';
        return cnt;
    }
    void flip(int j) {
        for (int i = 0; i < n; i++)
            s[i][j] = ((s[i][j] - '0') ^ 1) + '0';
        sort(s, s + n);
    }
};

bool same(const Node& a, const Node& b, int d) {
    for (int i = 0; i < n; i++)
        if (a.s[i][d] != b.s[i][d])
            return false;
    return true;
}

int ans;

void dfs(Node cur, Node need, int d, int s) {
    if (ans != -1 && s >= ans)
        return;
    if (d == m) {
        ans = s;
        return;
    }
    int curCnt = cur.count(d);
    int needCnt = need.count(d);
    if (same(cur, need, d)) {
        dfs(cur, need, d + 1, s);
    }
    cur.flip(d);
    if (same(cur, need, d)) {
        dfs(cur, need, d + 1, s + 1);
    }
}

void work() {
    scanf("%d%d", &n, &m);
    Node cur, need;
    cur.read();
    need.read();
    ans = -1;
    dfs(cur, need, 0, 0);
    if (ans == -1)
        puts("NOT POSSIBLE");
    else
        printf("%d\n", ans);
}

int main() {
//freopen("data.in", "r", stdin);
//freopen("data.out", "w", stdout);
    int T, C = 0;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", ++C);
        work();
    }
}
