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
string outs[43],devs[43];

string nouts[43];
bool used[43];
vector<int> cpos;

void solveSmall(int tid) {
    int res=-1,cnt;

    for (int k=1; k<=n; ++k) {
        for (int i=1; i<=n; ++i) {
            used[i]=false;
            nouts[i]=outs[i];
        }

        used[k]=true;
        cnt=0;
        cpos.clear();

        for (int i=0; i<l; ++i)
            if (devs[1][i]!=outs[k][i]) {
                ++cnt;
                cpos.push_back(i);
            }

        for (int i=1; i<=n; ++i)
            for (vector<int>::iterator it=cpos.begin(); it!=cpos.end(); ++it) {
                nouts[i][*it]=(char)(SUM01-(int)nouts[i][*it]);
            }

        bool success=true;

        for (int i=2; i<=n; ++i) {
            bool found=false;

            for (int j=1; j<=n; ++j)
                if (!used[j] && nouts[j]==devs[i]) {
                    found=true;
                    used[j]=true;
                    break;
                }

            if (!found) {
                success=false;
                break;
            }
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
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);

    scanf("%d",&tcase);

    char scanstring[154];

    for (int tid=1; tid<=tcase; ++tid) {
        scanf("%d%d\n",&n,&l);

        for (int i=1; i<=n; ++i) {
            scanf("%s",scanstring);
            outs[i]=string(scanstring);
        }

        for (int i=1; i<=n; ++i) {
            scanf("%s",scanstring);
            devs[i]=string(scanstring);
        }

        if (n<=10 && l<=10) solveSmall(tid); else solveBig(tid);
    }

    return 0;
}
