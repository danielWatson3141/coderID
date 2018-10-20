#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

int t;
int n,l;

int plug[100];
int flow[100];
int cnt[1048];

char temp[1000];

bool checkFlip(int flip)
{
    memset(cnt,0,sizeof(cnt));
    FOR(i,0,n-1)
    {
        cnt[flow[i]]++;
    }
    FOR(i,0,n-1)
    {
        int sw = flip ^ plug[i];
        if(cnt[sw] == 0) return false;
        cnt[sw]--;
    }
    return true;
}

int countBit(int bits)
{
    int ret = 0;
    while(bits > 0)
    {
        ret += (bits & 1);
        bits = bits >> 1;
    }
    return ret;
}

int solve(int ca)
{
    int ret = INF;
    FOR(flip,0,(1 << l)-1)
    {
        if(checkFlip(flip))
        {
            ret = min(ret,countBit(flip));        
        }
    }
    printf("Case #%d: ",ca);
    if(ret == INF) puts("NOT POSSIBLE");
    else printf("%d\n",ret);
}

int convert(char * str)
{    
    int ret = 0;
    int len = strlen(str);        
    FOR(i,0,len-1)
    {        
        ret = (ret << 1) | (str[i] - '0');
    }
    return ret;
}

int main()
{    
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        scanf("%d %d",&n,&l);
        FOR(i,0,n-1)
        {
            scanf("%s",temp);            
            plug[i] = convert(temp);
        }
        FOR(i,0,n-1)
        {
            scanf("%s",temp);
            flow[i] = convert(temp);
        }
        solve(ca);        
    }
    return 0;
}
