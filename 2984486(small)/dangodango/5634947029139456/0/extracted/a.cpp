#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 150;


bool g[N][N];
int match[N];

int n, l;
string fstr[N];
string str[N];
string need[N];

int minflip;

bool MaxMatchDFS(bool g[][N], int m, int a, int y[], bool u[])
{
    for (int i = 0; i < m; i++)
        if (!u[i] && g[a][i]) {
            int t = y[i];
            u[i] = true; y[i] = a;
            if (t == -1 || MaxMatchDFS(g, m, t, y, u)) {
                return true;
            }
            y[i] = t;
        }
    return false;
} int MaxMatch(bool g[][N], int n, int m, int y[]) //v1[y[i]] matches v2[i]
{
    memset(y, 255, sizeof(*y)*m);
    int c = 0;
    for (int i = 0; i < n; i++) {
        bool u[N] = {0};
        if (MaxMatchDFS(g, m, i, y, u)) {
            c++;
        }
    }
    return c;
}

bool flip[4000];

void dfs(int k)
{
    if (k >= l) {
        for (int i = 0; i < n; i++) {
        	fstr[i]=str[i];
            for (int j = 0; j < l; j++) {
                if (flip[j]==true) {
                    fstr[i][j] = fstr[i][j] == '1' ? '0' : '1';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (need[i] == fstr[j]) {
                    g[i][j] = true;
                }
                else {
                	g[i][j] = false;
                }
            }
        }
        int tmp = MaxMatch(g, n, n, match);
        if (tmp == n) {
            int cntflip = 0;
            for (int i = 0; i < l; i++) {
                if (flip[i] == true) {
                    cntflip++;
                }
            }
            if (minflip == -1 || cntflip < minflip) {
                minflip = cntflip;
            }
        }
    } else {
    	flip[k]=false;
        dfs(k + 1);
        flip[k] = true;
        dfs(k + 1);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++) {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> need[i];
        }
        minflip = -1;
        dfs(0);
        if (minflip != -1) {
            cout << "Case #" << cs << ": " << minflip << endl;
        } else {
            cout << "Case #" << cs << ": NOT POSSIBLE" << endl;
        }

    }
    return 0;
}