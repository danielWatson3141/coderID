#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[1000100];
bool ok(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return false;
    return true;
}
int main(){
    long long ans;
    int T,k;
    freopen("A-large-practice (2).in","r",stdin);
    freopen("As.out","w",stdout);
    cin>>T;
    for(int cas = 1; cas <= T; cas++){
        ans = 0;
        scanf("%s %d",str,&k);
        int l = strlen(str);
        int cnt = 0,last = -1;
        for(int i = 0; i < l; i++){
            if(ok(str[i])){
                cnt++;
                if(cnt >= k) last = i - k + 1;
            }else{
                cnt = 0;
            }
           // cout<<i<<" "<<cnt<<" "<<last<<" "<<ans<<endl;

            ans += last + 1;

        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }

    return 0;
}
