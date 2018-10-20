#include <cstdio>
#include <vector>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
typedef unsigned long long int ULL;
const int MAXN = 200;

int n, l;
ULL A[MAXN], B[MAXN];
std::vector<int> adj[MAXN];
int leftAssoc[MAXN], rightAssoc[MAXN];
int visited[MAXN], cast;

int bitcount(ULL value) {
    return __builtin_popcountll(value);
}

ULL convert(const char* str) {
    ULL res = 0;
    int it = 0;
    for (int i=l-1; i>=0; i--) {
        res += ((str[i]-'0') << it);
        it++;
    }

    return res;
}

void makegraph(ULL mask) {
    //printf("bufuje graf maska %Lu\n", mask);
    for (int i=0; i<n; i++) {
        adj[i].clear();
        for (int j=0; j<n; j++)
            if ((A[i]^B[j]) == mask) {
                //printf("%d %d\n", i, j);
                adj[i].push_back(j);
            }
    }
}

bool dfs(int u) {
    if (visited[u] == cast)
        return false;
    visited[u] = cast;
    for (int v: adj[u]) {
        if (rightAssoc[v] == -1 || dfs(rightAssoc[v])) {
            //printf("kojarze %d %d\n", u, v);
            leftAssoc[u] = v;
            rightAssoc[v] = u;
            return true;
        }
    }

    return false;
}

int maxmatching() {
    std::fill(leftAssoc, leftAssoc+n, -1);
    std::fill(rightAssoc, rightAssoc+n, -1);
    while (true) {
        cast++;
        
        bool increase = false;
        for (int i=0; i<n; i++)
            if (leftAssoc[i] == -1 && dfs(i))
                increase = true;
        if (!increase)
            break;
    }
    int res = 0;
    for (int i=0; i<n; i++)
        res += leftAssoc[i] != -1;
    //printf("maxxmatchin wyszedl %d\n", res);
    
    return res;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        scanf("%d%d", &n, &l);
        
        char buf[MAXN+1];
        for (int i=0; i<n; i++) {
            scanf("%s", buf);
            A[i] = convert(buf);
        }
        for (int i=0; i<n; i++) {
            scanf("%s", buf);
            B[i] = convert(buf);
        }
        
        ULL best = (1LL << (l+2)) - 1;
        for (int i=0; i<n; i++) {
            ULL mask = A[0] ^ B[i];
            makegraph(mask);
            if (bitcount(mask) < bitcount(best) && maxmatching() == n) {
                best = mask;
            }
        }
        
        int res = bitcount(best);
        printf("Case #%d: ", test);
        
        if (res > l)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", res);
    }
}
