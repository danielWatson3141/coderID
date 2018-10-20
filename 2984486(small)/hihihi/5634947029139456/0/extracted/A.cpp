#include <cstdio>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool ok(string s[155],set<string>& st,int N) {
    for ( int i = 0 ; i < N ; i++ ) 
        if ( st.count(s[i]) == 0 ) return false;
    return true;
}
int ans;
void print(string s[155],int N) {
    for ( int i = 0 ; i < N ; i++ ) 
        printf("%s\n",s[i].c_str());
    puts("");
}
void go(string s[155],set<string>& st,int N,int L,int cnt,int idx) {
    if ( idx == L ) return;
    if ( ok(s,st,N) ) 
        ans = min(ans,cnt);
    go(s,st,N,L,cnt,idx+1);
    for ( int i = 0 ; i < N ; i++ ) 
        s[i][idx] = s[i][idx]=='1'?'0':'1';
    if ( ok(s,st,N) ) 
        ans = min(ans,cnt+1);
    go(s,st,N,L,cnt+1,idx+1);
    for ( int i = 0 ; i < N ; i++ ) 
        s[i][idx] = s[i][idx]=='1'?'0':'1';
}
int main() {
    int tc;
    scanf("%d",&tc);
    for ( int _case = 1 ; _case <= tc ; _case ++ ) {
        ans = 987654321;
        int N,L;
        scanf("%d%d",&N,&L);
        string s[155];
        set<string> device;
        for ( int i = 0 ; i < N ; i++ ) 
            cin >> s[i];
        for ( int i = 0 ; i < N ; i++ ) {
            string t;
            cin >> t;
            device.insert(t);
        }
        go(s,device,N,L,0,0);
        printf("Case #%d: ",_case);
        if ( ans == 987654321 ) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
