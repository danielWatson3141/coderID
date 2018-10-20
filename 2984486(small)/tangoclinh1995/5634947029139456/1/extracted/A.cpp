#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>

using namespace std;

int SUM01=(int)'0'+(int)'1';

int tcase,n,l;
string outs[153],devs[153];

string nouts[153];
vector<int> cpos;

void solve(int tid) {
    int res=-1,cnt;
    sort(devs+1,devs+n+1);

    for (int k=1; k<=n; ++k) {
        cnt=0;
        cpos.clear();

        for (int i=0; i<l; ++i)
            if (devs[1][i]!=outs[k][i]) {
                ++cnt;
                cpos.push_back(i);
            }

        for (int i=1; i<=n; ++i) {
            nouts[i]=outs[i];
            for (vector<int>::iterator it=cpos.begin(); it!=cpos.end(); ++it) {
                nouts[i][*it]=(char)(SUM01-(int)nouts[i][*it]);
            }
        }
        sort(nouts+1,nouts+n+1);

        bool success=true;
        for (int i=1; i<=n; ++i)
            if (devs[i]!=nouts[i]) {
                success=false;
                break;
            }

        if (success)
            if (res==-1 || res!=-1 && cnt<res) res=cnt;
    }

    if (res!=-1)
        printf("Case #%d: %d\n",tid,res);
    else printf("Case #%d: NOT POSSIBLE\n",tid);
}

void solveBig(int tid) {

}

int main() {
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);

    scanf("%d",&tcase);

    //char scanstring[154];

    for (int tid=1; tid<=tcase; ++tid) {
        scanf("%d%d\n",&n,&l);

        for (int i=1; i<=n; ++i) {
            //scanf("%s",scanstring);
            //outs[i]=string(scanstring);
            cin >> outs[i];
        }

        for (int i=1; i<=n; ++i) {
            //scanf("%s",scanstring);
            //devs[i]=string(scanstring);
            cin >> devs[i];
        }

        solve(tid);
    }

    return 0;
}
