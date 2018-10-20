#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<iomanip>
#include<cmath>

#define LL long long
#define PB push_back
#define MP make_pair
#define INF 1000000007
#define MOD 1000000007
#define sd(x) scanf("%d", &x)

using namespace std;

    LL n, l;
LL a[200], b[200], c[200];
LL f(LL q){
    LL ans = 0;
    while(q){
        if(q & 1){
            ans++;
        }
        q /= 2;
    }
    return ans;
}
LL find(string s){
    LL ans = 0;
    for(LL i = 0; i < s.length(); i++){
        ans *= 2;
        if(s[i] == '1'){
            ans += 1;
        }
    }
    return ans;
}
LL find_match(LL x){
    LL q = a[0]^b[x];
    LL i;
    for(i = 0; i < n; i++){
        c[i] = a[i]^q;
    }
    sort(c, c + n);
    for(i = 0; i < n; i++){
        if(c[i] != b[i]){
            return -1;
        }
    }
    return f(q);
}

LL solve(){
    cin>>n>>l;
    string s;
    LL i;
    for(i = 0; i < n; i++){
            cin>>s;
            a[i] = find(s);
    }
    for(i = 0; i < n; i++ ){
        cin>>s;
        b[i] = find(s);
    }
    sort(b, b + n);
    LL ans1 = -1, ans;
    for(i = 0; i < n; i++){
        ans = find_match(i);
        if(ans >= 0 && ans1 == -1){
            ans1 = ans;
        }
        else if(ans >= 0 ){
            ans1 = min(ans, ans1);
        }


    }
    if(ans1 == -1){
        cout<<"NOT POSSIBLE"<<endl;
    }
    else{
        cout<<ans1<<endl;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LL test, op = 1;
    cin>>test;
    while(test--){
        cout<<"Case #"<<op<<": ";
        solve();
        op++;

    }
    return 0;
}
