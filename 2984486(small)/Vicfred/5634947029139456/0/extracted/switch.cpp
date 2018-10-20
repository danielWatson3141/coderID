#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <map>

#define INF 100000000

using namespace std;

int bintoint(string S, int size) {
    int x = 0;
    for(int i = size-1; i >= 0; i--)
    //for(int i = 0; i < size; i++)
        if(S[i] == '1')
            x |= (1<<i);
    return x;
}

int main() {
    int T, N, L;
    scanf("%d", &T);
for(int kase = 1; kase <= T; kase++) {
    scanf("%d %d", &N, &L);

    vector<string> outlet;
    vector<string> device;

    map< vector<string>, bool > use;

    string temp;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        outlet.push_back(temp);
    }

    for(int i = 0; i < N; i++) {
        cin >> temp;
        device.push_back(temp);
    }

    sort(outlet.begin(),outlet.end());
    sort(device.begin(),device.end());

    use.clear();
    use[outlet] = true;

    map<vector<string>, int> dist;

    queue<vector<string> > q;
    q.push(outlet);
    dist[outlet] = 0;
    if(outlet != device)
        dist[device] = INF;
    while(!q.empty()) {
        vector<string> a = q.front(); q.pop();
        if(a == device)
            break;
        for(int i = 0; i < L; i++) {
            vector<string> b = a;
            for(int j = 0; j < N; j++) {
                if(b[j][i] == '1')
                    b[j][i] = '0';
                else
                    b[j][i] = '1';
            }
            sort(b.begin(), b.end());
            if(!use[b]) {
                use[b] = true;
                dist[b] = dist[a] + 1;
                q.push(b);
            }
        }
    }

    if(dist[device] == INF)
        printf("Case #%d: NOT POSSIBLE\n", kase);
    else
        printf("Case #%d: %d\n", kase, dist[device]);

}
    return 0;
}
