#line 2 "TorusSailing.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int N;
int a[1024];
int c[1024];


vector< PII > ans;

void add(int pos)
{
    pos++;
    while(pos<=N)
    {
        c[pos]++;
        pos+=pos&(-pos);
    }
}
int cal(int pos)
{
    pos++;
    int ret=0;
    while(pos)
    {
        ret+=c[pos];
        pos-=pos&(-pos);
    }
    return ret;
}

int main()
{
    ans.clear();
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        scanf("%d",&N);
        memset(c,0,sizeof(c));
        int ni=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            ni+=cal(a[i]);
            //cout<<cal(a[i])<<" "<<i<<endl;
            add(a[i]);
            //for(int i=0;i<=N;i++) cout<<c[i]<<" ";cout<<endl;
        }
        //cout<<ni<<endl;
        ans.push_back(PII(ni,cas));
    }
    string output[300];
    sort(ans.begin(),ans.end());
    int Mid = casT/2;
    int Yu  = 255000;
    int goodnum=0;
    for(int i=0;i<casT;i++)
    {
        if(ans[i].first<Yu)
        {
            output[ans[i].second]="GOOD";
            goodnum++;
        }
        else output[ans[i].second]="BAD";
    }
    //cout<<Mid<<endl;for(int i=0;i<casT;i++) cout<<i<<" : "<<ans[i].first<<endl;
    for(int cas=1;cas<=casT;cas++)
    {
        cout<<"Case #"<<cas<<": "<<output[cas]<<endl;
    }
    //cout<<goodnum<<endl;

    return 0;
}

