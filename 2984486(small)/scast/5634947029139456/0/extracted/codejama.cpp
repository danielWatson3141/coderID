#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<set>
using namespace std;
int N, L, T;
vector<int> flow, required;
char bin[50];
int main() {
    scanf("%d",&T);
    for (int t=1; t<=T; t++) {
        flow.clear();
        required.clear();
        scanf("%d%d", &N,&L);
        for (int i=0; i<N; i++) {
            int bit;
            int value = 0;
            scanf("%s", bin);
            for (int j=0; j<L; j++) {
                bit = bin[j] == '0' ? 0 : 1;
                // printf("bit = %d\n", bit);
                value |= (bit<<(j));
                // printf("value = %d\n", value);
            }
            flow.push_back(value);
        }
        scanf("\n");
        for (int i=0; i<N; i++) {
            int bit, value =0;
            scanf("%s", bin);
            for (int j=0; j<L; j++) {
                bit = bin[j] == '0' ? 0 : 1;
                value |= (bit<<j);
            }
            required.push_back(value);
        }
        scanf("\n");
        sort(flow.begin(), flow.end());
        sort(required.begin(), required.end());
        // for (int i=0; i<N; i++)
        //     printf("%d ", required[i]);
        // printf("\n");
        set<vector<int> > visit;
        queue<pair<int, vector<int> > > q;
        q.push(make_pair(0, flow));
        int best = -1;
        while (!q.empty()) {
            pair<int, vector<int> > current = q.front();
            int cost = current.first;
            vector<int> cf = current.second;
            q.pop();

            if (cf == required) {
                best = cost;
                break;
            }
            // for (int i=0; i<N; i++) printf("%d ", cf[i]);
            if (visit.count(cf)) {
                // printf("Aca\n");
                continue;
            }
            visit.insert(cf);
            // for (int i=0; i<N; i++) printf("%d ", cf[i]);
            // printf("\n");
            for (int i=0; i<L; i++) {
                vector<int> ncf(cf.begin(), cf.end());
                for (int j=0; j<N; j++) {
                    ncf[j] ^= (1<<i);
                }
                sort(ncf.begin(), ncf.end());
                // for (int j=0; j<N; j++) {
                //     printf("%d ", ncf[j]);
                // }
                // printf("\n");
                if (!visit.count(ncf)) {
                    // printf("Inserting...\n");
                    q.push(make_pair(cost+1, ncf));
                }
            }
        }
        printf("Case #%d: ", t);
        if (best == -1) printf("NOT POSSIBLE");
        else printf("%d", best);
        printf("\n");
    }
    return 0;
}
