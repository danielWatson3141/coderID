#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cstring>

#define pb push_back
#define SZ 157
#define INF (1<<29)
using namespace std;

int n,L;
char Outlet[SZ+7][107];
char Device[SZ+7][107];
int Change[SZ+7];
char Out2[SZ+7][107];




int Check(int i,int j)
{
    set<string> st;
    for(int k=0;k<n;k++) st.insert( (string)(Device[k]));
    int cnt = 0;
    for(int k=0;k<L;k++) {
        if(Device[i][k]!=Outlet[j][k]) {
            Change[k] = 1;
            cnt++;
        }
        else Change[k] = 0;
    }

    set<string> :: iterator it;
    for(int m=0;m<n;m++) {
        Out2[m][L] = 0;

        for(int k=0;k<L;k++) {
            if(Change[k]==0) {
                Out2[m][k] = Outlet[m][k];
            }
            else {
                if(Outlet[m][k]=='1') Out2[m][k] = '0';
                else Out2[m][k] = '1';
            }
        }
        it = st.find((string)(Out2[m]));
        if(it==st.end())    return INF;
        st.erase(it);

    }
    if(st.size()==0) return cnt;
    return INF;



}


int main()
{
    freopen("A.in","rt",stdin);
    freopen("A.out","wt",stdout);
    int tst,cas;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++) {
        scanf("%d%d",&n,&L);

        for(int i=0;i<n;i++) scanf("%s",&Outlet[i]);

        for(int i=0;i<n;i++) scanf("%s",&Device[i]) ;

        int mn = INF;

        for(int i=0;i<1;i++) {
            for(int j=0;j<n;j++) {
                int val = Check(i,j);
                if(val<mn) mn = val;
            }
        }
        if(mn==INF) printf("Case #%d: NOT POSSIBLE\n",cas);
        else printf("Case #%d: %d\n",cas,mn);

    }


    return 0;
}
