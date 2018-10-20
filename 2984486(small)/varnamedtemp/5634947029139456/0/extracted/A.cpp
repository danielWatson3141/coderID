#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cmath>
#include <queue>
#include <assert.h>
#include <cstdlib>

using namespace std;

typedef long long ll;

int N, L;
string start[15], target[15];

vector<string> init() {
    vector<string> res;
    for(int i = 0;i<N;i++)
        res.push_back(start[i]);
    return res;
}

void flip(vector<string> &v, int idx) {
    for(int i= 0;i<N;i++)
        if(v[i][idx] == '0')
            v[i][idx] = '1';
        else
            v[i][idx] = '0';
}

int main() {
    freopen("A-small-attempt1.in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++) {
        cin>>N>>L;
        for(int i = 0;i<N;i++)
            cin>>start[i];

        for(int i = 0;i<N;i++)
            cin>>target[i];
        
        sort(start, start + N);
        sort(target, target + N);
        int res = 1<<30;
        for(int i = 0;i<N;i++) {
            for(int j = 0;j<N;j++) {
                vector<string> temp = init();
                int cnt = 0;
                for(int k = 0;k<L;k++) {
                    if(start[i][k] != target[j][k]) {
                        flip(temp, k);
                        cnt++;
                    }
                }
                sort(temp.begin(), temp.end());
                
                bool ok = true;
                for(int k = 0;k<N;k++)
                    if(target[k] != temp[k]) {
                        ok = false;
                        break;
                    }
                if(ok) res = min(res, cnt);
            }
        }
        printf("Case #%d: ", t);
        if(res == 1<<30)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", res);
    }
    return 0;
}
