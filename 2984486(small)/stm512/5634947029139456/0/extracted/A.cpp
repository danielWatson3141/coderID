#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <iterator>

using namespace std;

int T, N, L;
string outlet[200];
string config[200];
map<string, int> change[200];
set<int> g[400][400];
int edge[400][400];
bool used[400];
int match[400];

string getChange(string a, string b)
{
    string ret = a;
    for (int i = 0; i < L; i++) {
        if (a[i] != b[i]) {
            ret[i] = '1';
        }
        else
            ret[i] = '0';
    }
    return ret;
}

void init()
{
    for (int i = 0; i < N * 2; i++)
        for (int j = 0; j < N * 2; j++)
            g[i][j].clear();
    
    int cnt = 0;
    for (int i = 0; i <= L; i++)
        change[i].clear();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int len = 0;
            int k;
            string cur = getChange(outlet[i], config[j]);
            for (int l = 0; l < L; l++)
                if (cur[l] == '1')
                    len++;
          //  cout << outlet[i] << " " << config[j] << " " << cur << " " << len << endl;
            if (change[len].count(cur)) {
                k = change[len][cur];
            }
            else {
                change[len][cur] = cnt;
                k = cnt++;
            }
            g[i][j + N].insert(k);
            g[j + N][i].insert(k);
        }
}

void build(int num)
{
    memset(edge, 0, sizeof(edge));
    for (int i = 0; i < N; i++)
        for (int j = N; j < N * 2; j++)
            if (g[i][j].count(num)) {
            //    printf("%d i = %d j = %d\n", num, i, j - N);
                edge[i][++edge[i][0]] = j;
                edge[j][++edge[j][0]] = i;
            }
}

bool dfs(int u) {
    for (int i = 1; i <= edge[u][0]; i++) {
        int v = edge[u][i];
        if (!used[v]) {
            used[v] = true;
            if ((match[u] == -1) || (dfs(match[u]))) {
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int calc()
{
    bool flag = true;
    int ans = 0;
    for (int i = 0; i < N * 2; i++) {
        match[i] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        memset(used, false, sizeof(used));
        if (dfs(i))
            ans++;
    }
    return ans;
}

int work()
{
    int ret = -1;
    for (int steps = 0; steps <= L; steps++) {
        bool found = false;
        map<string, int>::iterator iter;
        for (iter = change[steps].begin(); iter != change[steps].end(); iter++) {
            //printf("%d\n", iter->second);
            build(iter->second);
            if (calc() == N) {
                found = true;
                break;
            }
        }
        if (found) {
            ret = steps;
            break;
        }
    }
    return ret;
}

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small1.out", "w", stdout);
    
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    char str[100];
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d %d", &N, &L);
        for (int i = 0; i < N; i++) {
            scanf("%s", str);
            outlet[i] = str;
        }
        for (int i = 0; i < N; i++) {
            scanf("%s", str);
            config[i] = str;
        }
        init();
        int res = work();
        if (res == -1) {
            printf("NOT POSSIBLE\n");
        }
        else
            printf("%d\n", res);
    }
    return 0;
}