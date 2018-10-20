//
//  main.cpp
//  r1.a
//
//  Created by Zhu Haifan on 14-4-26.
//  Copyright (c) 2014年 Zhu Haifan. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, L;
vector<string> outlet {};
vector<string> dest {};
vector<string> current {};
vector<string> sortdest{};
vector<vector<string>> sortsnipt {};
vector<int> no {};
vector<int> nd {};

int dfs(int dep) {
    if (dep == L - 1) {
        if (no[dep] == nd[dep] && no[dep] + nd[dep] != N) {
            vector<string> sortcurrent = current;
            sort(sortcurrent.begin(), sortcurrent.end());
            if (sortcurrent == sortdest) {
                return 0;
            } else return -1;
        } else if (no[dep] + nd[dep] == N && no[dep] != nd[dep]) {
            vector<string> sortcurrent = current;
            for (int i = 0; i < N; ++i) {
                sortcurrent[i][dep] = '0' + (1 - sortcurrent[i][dep] + '0');
            }
            sort(sortcurrent.begin(), sortcurrent.end());
            if (sortcurrent == sortdest) {
                return 1;
            } else return -1;
        } else if (no[dep] + nd[dep] == N && no[dep] == nd[dep]) {
            vector<string> sortcurrent = current;
            sort(sortcurrent.begin(), sortcurrent.end());
            if (sortcurrent == sortdest) return 0;
            sortcurrent.clear();
            sortcurrent = current;
            for (int i = 0; i < N; ++i) {
                sortcurrent[i][dep] = '0' + (1 - sortcurrent[i][dep] + '0');
            }
            sort(sortcurrent.begin(), sortcurrent.end());
            if (sortcurrent == sortdest) {
                return 1;
            } else return -1;
        } else return -1;
    }
    
    if (no[dep] == nd[dep] && no[dep] + nd[dep] != N) {
        vector<string> sortcurrent{};
        for (auto s : current) {
            sortcurrent.push_back(string(s.begin(), s.begin()+dep+1));
        }
        sort(sortcurrent.begin(), sortcurrent.end());
        if (sortcurrent == sortsnipt[dep]) {
            int c = dfs(dep + 1);
            if (c < 0) return -1;
            else return c;
        } else return -1;
    } else if (no[dep] + nd[dep] == N && no[dep] != nd[dep]) {
        for (int i = 0; i < N; ++i) {
            current[i][dep] = '0' + (1 - current[i][dep] + '0');
        }
        vector<string> sortcurrent {};
        for (auto s : current) {
            sortcurrent.push_back(string(s.begin(), s.begin()+dep+1));
        }
        sort(sortcurrent.begin(), sortcurrent.end());
        if (sortcurrent == sortsnipt[dep]) {
            int c = dfs(dep + 1);
            for (int i = 0; i < N; ++i) {
                current[i][dep] = '0' + (1 - current[i][dep] + '0');
            }
            if (c < 0) return -1;
            else return c + 1;
        } else {
            for (int i = 0; i < N; ++i) {
                current[i][dep] = '0' + (1 - current[i][dep] + '0');
            }
            return -1;
        }
    } else if (no[dep] + nd[dep] == N && no[dep] == nd[dep]) {
        vector<string> sortcurrent {};
        for (auto s : current) {
            sortcurrent.push_back(string(s.begin(), s.begin()+dep+1));
        }
        sort(sortcurrent.begin(), sortcurrent.end());
        int c = -1;
        if (sortcurrent == sortsnipt[dep]) {
            c = dfs(dep + 1);
        }
        for (int i = 0; i < N; ++i) {
            current[i][dep] = '0' + (1 - current[i][dep] + '0');
        }
        sortcurrent.clear();
        for (auto s : current) {
            sortcurrent.push_back(string(s.begin(), s.begin()+dep+1));
        }
        sort(sortcurrent.begin(), sortcurrent.end());
        if (sortcurrent == sortsnipt[dep]) {
            int d = dfs(dep + 1);
            for (int i = 0; i < N; ++i) {
                current[i][dep] = '0' + (1 - current[i][dep] + '0');
            }
            if (c < 0 && d < 0) return -1;
            else if (c < 0 && d >= 0) return d + 1;
            else if (c >= 0 && d < 0) return c;
            else return min(c, d + 1);
        } else {
            for (int i = 0; i < N; ++i) {
                current[i][dep] = '0' + (1 - current[i][dep] + '0');
            }
            return c;
        }
    } else return -1;
    
}

int main(int argc, const char * argv[]) {
    freopen("/Users/whshev/Dropbox/Programs/GCJ2014/Data/R1/A-small-attempt3.in", "r", stdin);
    freopen("/Users/whshev/Dropbox/Programs/GCJ2014/Data/R1/A-small-attempt3.out", "w", stdout);
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d%d", &N, &L);
        outlet.clear();
        dest.clear();
        sortdest.clear();
        current.clear();
        no.clear();
        nd.clear();
        no = vector<int>(L, 0);
        nd = vector<int>(L, 0);
        string tmps;
        for (int j = 0; j < N; ++j) {
            cin >> tmps;
            outlet.push_back(tmps);
            for (int k = 0; k < tmps.size(); ++k) {
                if (tmps[k] == '1') {
                    ++no[k];
                }
            }
        }
        for (int j = 0; j < N; ++j) {
            cin >> tmps;
            dest.push_back(tmps);
            for (int k = 0; k < tmps.size(); ++k) {
                if (tmps[k] == '1') {
                    ++nd[k];
                }
            }
        }
        current = outlet;
        sortdest = dest;
        sort(sortdest.begin(), sortdest.end());
        sortsnipt.clear();
        vector<string> vs {};
        for (int j = 0; j < N; ++j) {
            tmps = "";
            tmps += dest[j][0];
            vs.push_back(tmps);
        }
        sortsnipt.push_back(vs);
        for (int j = 1; j < L; ++j) {
            for (int k = 0; k < N; ++k) {
                vs[k] += dest[k][j];
            }
            sortsnipt.push_back(vs);
//            vs.push_back(dest[j][0] + '');
        }
        for (auto &v : sortsnipt) {
            sort(v.begin(), v.end());
        }
        
        int ret = dfs(0);
        if (ret == -1) {
            printf("Case #%d: NOT POSSIBLE\n", i);
        } else printf("Case #%d: %d\n", i, ret);
    }

    return 0;
}

