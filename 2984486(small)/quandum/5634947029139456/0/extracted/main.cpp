#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#define _USE_MATH_DEFINES
#define maxn 154
using namespace std;
string oulet[maxn],dev[maxn]; int n,l, res;
bool d[maxn],used[maxn];
string s;
int testt(string a,string b){
    int rs=0,i,j; memset(d,0,sizeof(d));
    for (i=0;i<l;i++)
        if (a[i]!=b[i]){
            d[i]=true; rs++;
        }
    memset(used,false,sizeof(used));
    for (i=0;i<n;i++){
        s.clear();
        for (j=0;j<l;j++){
            if (d[j]==false) s.push_back(oulet[i][j]);
            else s.push_back('0'+('1'-oulet[i][j]));

        }
        for (j=0;j<n;j++) if (s==dev[j]&&used[j]==false){
            used[j]=true;
            //cout<<s<<" ~ "<<dev[j]<<"  ";
            break;
        }
        if (j>=n) return l+5;
    }

    if (rs<=l) return rs;

}
int main(){
    int ntest,test,i,j;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> ntest;
    for (test=1;test<=ntest;test++){

        cin >> n >> l;
        for (i=0;i<n;i++) cin>>oulet[i];
        for (i=0;i<n;i++) cin>>dev[i];
        if (test>1) cout<<endl;
        cout<<"Case #"<<test<<": ";
        res=l+5;
        for (i=0;i<n;i++)
            res=min(res,testt(oulet[i],dev[0]));
        if  (res<=l) cout<<res;
        else cout<<"NOT POSSIBLE";

    }
    fclose(stdin);  fclose(stdout);
    return 0;
}
