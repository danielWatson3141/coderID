#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define mp(a,b) make_pair(a,b)

const int N = 4e5;
const int mod = 1000000007;
const int inf = 1e9;
const double pi =  acos(-1.0);
const double eps = 1e-8;

struct unionset
{
    int fat[1003],len;
    void init(int x)
    {
        len = x;
        for(int i=0;i<x;i++)
            fat[i] = i;
        return ;
    }
    int getf(int x)
    {
        if(fat[x] == x)
            return x;
        return fat[x] = getf(fat[x]);
    }
    void un(int x,int y)
    {
        fat[getf(y)] = getf(x);
        return ;
    }
};

struct tree_array
{
    int c[1003];
    int v[1003],len;
    int get_low(int x) {return x&(-x);}
    void init(int x)
    {
        len = x;
        for(int i=0;i<x;i++)
            c[i] = v[i] = 0;
        return ;
    }
    void add(int x,int value)///v[x] += v
    {
        v[x] += value;
        while(x<=len)
        {
            c[x] += value;
            x += get_low(x);
        }
        return ;
    }
    int sum(int x)/// sigma(1,x)
    {
        int ans = 0;
        while(x>0)
        {
            ans += c[x];
            x -= get_low(x);
        }
        return ans;
    }
};

int pow_mod(int a,int b,int c)
{
    long long ans = 1,tmp = a;
    while(b){
        if(b&1)ans = ans*tmp%c;
        tmp = tmp*tmp%c;
        b>>=1;
    }
    return ans;
}

long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}

/// -----------------------------------------------------------------

class ColorfulCoins
{
    public:
        int minQueries(vector<long long> values)
        {
            int xx[100];
            int n = values.size()-1;
            for(int i=0;i<values.size();i++)
                xx[i] = values[i+1]/values[i];
            if(n == 0)return 0;
            int cnt = n,tag[100] = {0};
            while(cnt>0){
                int id = 0,bb = 0;
                for(int i=0;i<n;i++)
                if(tag[i]==0&&xx[i]>bb){
                    id = i;
                    bb = xx[i];
                }
                tag[id] = 1;
                cnt --;
            }
        }
};
vector<int> qnext[1003];

int gao(int u,int v){
    int cnt = 0;
    cnt = qnext[v].size();
    if(u!=-1)cnt--;
    if(cnt <= 1)return 1;
    cnt = 0;
    int cnttmp = 0;

    for(int i=0;i<qnext[v].size();i++)
    if(qnext[v][i] != u){
        int tmp = gao(v,qnext[v][i]);
        if(i>0)
            cnt = max(cnt,tmp+cnttmp);
        cnttmp = max(tmp,cnttmp);
    }
    return cnt+1;
}

int main()
{
    int cas=1, t,i,j,k;
    scanf("%d",&t);
    for(cas = 1;cas<=t;cas++){
        int n;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            qnext[i].clear();
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            qnext[x].push_back(y);
            qnext[y].push_back(x);
        }
        int ans = n;
        for(i=1;i<=n;i++)
            ans = min(ans,n-gao(-1,i));
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
