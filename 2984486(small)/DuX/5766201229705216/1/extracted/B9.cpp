#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define inf 1234566790
#define eps 0.0000001
#define PI  3.14159265359

int uk[5555],bt[5555];
bool mark[5555];
vector<int> adj[5555];

void dfs(int x) {

    int l,i,y,brd,max1,max2;

    mark[x] = true;

    //uk[x] = 1;
    //sum = 0;

    //min1 = inf; min2 = inf;
    max1 = 0; max2 = 0;
    brd = 0;

    l = adj[x].sz;
    for(i=0; i<l; i++) {
        y = adj[x][i];
        if (!mark[y]) {
            dfs(y);
            //sum += uk[y];

            /*r = uk[y] - bt[y];
            if (r < min1) {
                min2 = min1;
                min1 = r;
            } else if (r < min2) {
                min2 = r;
            }*/

            if (bt[y] > max1) {
                max2 = max1;
                max1 = bt[y];
            } else if (bt[y] > max2) {
                max2 = bt[y];
            }

            brd++;
        }
    }

    if (brd < 2) bt[x] = 1;
    else bt[x] = 1 + max1 + max2;

    //printf("-> %d   bt = %d\n", x, bt[x]);
}

int main() {

    FILE *ff=fopen("B-large.in", "r"), *gg=fopen("B-large.out", "w");

    int n,i,r,a,b,tt,ttt,res;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {

        fscanf(ff,"%d", &n);

        for(i=0; i<n; i++) adj[i].clr;

        for(i=0; i<n-1; i++) {
            fscanf(ff,"%d%d", &a, &b);
            a--; b--;

            adj[a].pb(b);
            adj[b].pb(a);
        }

        res = 0;
        for(r=0; r<n; r++) {

            memset(bt,0,sizeof(bt));
            memset(uk,0,sizeof(uk));
            memset(mark,0,sizeof(mark));

            //printf("---> root = %d\n", r);

            dfs(r);

            if (bt[r] > res) res = bt[r];
        }

        res = n-res;

        fprintf(gg,"Case #%d: %d\n", tt, res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
