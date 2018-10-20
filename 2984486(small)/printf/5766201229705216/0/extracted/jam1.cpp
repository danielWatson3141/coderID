#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <assert.h>
#include<string>
#include <cmath>
#include <algorithm>
using namespace std;
int rec(int a, int p, vector <int> v[]) {
    vector<int> vs;
    if(v[a].size() == 2 || v[a].size() == 1) return 1;
    if(v[a].size() >= 3) {
        int r = 1;
        for(int i = 0; i < v[a].size(); i++) {
            if(v[a][i] != p) {
                int r1 = rec(v[a][i], a, v);
                vs.push_back(r1);
            }
        }
        sort(vs.begin(), vs.end());
        r += vs[vs.size() - 1] + vs[vs.size() - 2];
        return r;
    }
    return 0;
}

int main()
{
    int t, n, a, b;
	FILE *fp=fopen("in.txt", "r"), *ofp=fopen("out.txt", "w");
    fscanf(fp, "%d", &t);
    for(int k = 1;k <= t; k++) {
       fscanf(fp, "%d", &n);
       vector <int> v[1005];
       for(int i = 0; i < n - 1; i++) {
           fscanf(fp, "%d%d", &a, &b);
           v[a].push_back(b);
           v[b].push_back(a);
       }
       int res;
       if (n == 2)
           res = 1;
       else if (n > 2) res = n - 3;
 
       for(int i = 0; i < n; i++) {
           int inc = 0;
           if(v[i].size() == 2) {
                inc = 1;
                inc += rec(v[i][0], i, v);
                inc += rec(v[i][1], i, v);
           }
           if(res > n - inc)
               res = n - inc;
       }
       fprintf(ofp, "Case #%d: %d\n", k, res);
    }           
    fclose(fp);
    fclose(ofp); 
    system("pause");
    return 0;
}
