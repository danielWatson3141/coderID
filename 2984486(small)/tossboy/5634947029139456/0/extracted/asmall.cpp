#include <iostream>
#include <algorithm>
using namespace std;

const int N=11;
const int L=11;
int n,l;
int cur[N],tar[N];

void rev(int a[], int k){
    for(int i=0; i<n; i++)
        a[i] ^= 1<<k;
}

bool dfs(int i, int d){
    if(d==0){
        int t[N];
        for(int i=0; i<n; i++)
            t[i] = cur[i];
        sort(t, t+n);
        for(int i=0; i<n; i++)
            if(t[i]!=tar[i])
                return false;
        return true;
    }
    
    if(l-(i+1)>=d && dfs(i+1,d)) return true;
    rev(cur, i);
    if(dfs(i+1,d-1))
        return true;
    rev(cur, i);
    return false;
}

int get(){
    string s; cin>>s;
    int res=0;
    for(int i=0; i<s.size(); i++)
        res = (res<<1)+s[i]-'0';
    return res;
}

void input(){
    for(int i=0; i<n; i++)
        cur[i] = get();
    for(int i=0; i<n; i++)
        tar[i] = get();
    sort(cur, cur+n);
    sort(tar, tar+n);
}

int main(int argc, const char * argv[])
{
    int ncase; cin>>ncase;
    for(int ca=1; ca<=ncase; ca++){
        cin>>n>>l;
        input();
        int res=-1;
        for(int d=0; res<0&&d<=l; d++)
            if(dfs(0,d))
                res=d;
        cout<<"Case #"<<ca<<": ";
        if(res<0)
            cout<<"NOT POSSIBLE"<<endl;
        else cout<<res<<endl;
    }
    
    return 0;
}

