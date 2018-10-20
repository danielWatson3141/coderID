/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
string out[200], devs[200];
int N, L;
bool valid(int p){
    multiset<string> outs, dev;
    multiset<string>::iterator it1, it2;
    for(int i = 0;i<N;i++){
        outs.insert(out[i].substr(p, out[i].length()-p));
        dev.insert(devs[i].substr(p, devs[i].length()-p));
    }
    for(it1 = outs.begin(); it1 != outs.end(); it1++){
        it2 = dev.find(*it1);
        if(it2 == dev.end())
            return false;
        dev.erase(it2);
    }
    return true;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cin>>N>>L;
        for(int i = 0;i<N;i++)
            cin>>out[i];
        for(int i = 0;i<N;i++)
            cin>>devs[i];
        int ans = -1;
        for(int i = 0;i<N;i++){
            int l = 0;
            vector<int> ch;
            for(int j = 0;j<L;j++){
                if(out[0][j] != devs[i][j])
                    ch.push_back(j);
            }
            l = ch.size();
            for(int j = 0;j<ch.size();j++){
                for(int k = 0;k<N;k++)
                    out[k][ch[j]] = (out[k][ch[j]]=='0'?'1':'0');
            }
            if(valid(0))
                ans = (ans == -1?l:min(l, ans));
            for(int j = 0;j<ch.size();j++){
                for(int k = 0;k<N;k++)
                    out[k][ch[j]] = (out[k][ch[j]] == '0'?'1':'0');
            }
        }
        cout<<"Case #"<<z<<": ";
        if(ans != -1)
            cout<<ans<<endl;
        else
            cout<<"NOT POSSIBLE"<<endl;
    }
}
