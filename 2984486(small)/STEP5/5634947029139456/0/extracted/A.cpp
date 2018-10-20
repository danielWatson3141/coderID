#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

const int MAXN = 256;
const int INF = 1029384756;

int N, L;
ll orig[MAXN], req[MAXN], tmp[MAXN];

ll strtoll(string &s)
{
    ll ans = 0;
    for(int i=0; i<L; i++)
    {
        ans <<= 1;
        if(s[i] == '1') ans ^= 1LL;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    
    for(int t=1; t<=T; t++)
    {
        cin>>N>>L;
        string s;
        for(int i=0; i<N; i++)
        {
            cin>>s;
            orig[i] = strtoll(s);
        }
        for(int i=0; i<N; i++)
        {
            cin>>s;
            req[i] = strtoll(s);
        }

        sort(orig, orig + N);

        // for(int i=0; i<N; i++)cout<<orig[i]<<"\t"<<req[i]<<endl;
        
        int ans = INF;
        for(int i=0; i<N; i++)
        {
            ll dif = orig[0] ^ req[i];
            for(int j=0; j<N; j++)
            {
                tmp[j] = req[j] ^ dif;
            }
            sort(tmp, tmp + N);
            bool ok = true;
            for(int j=0; j<N; j++)
            {
                if(tmp[j] != orig[j])
                {
                    ok = false;
                    break;
                }
            }
            
            if(ok)
            {
                int pcnt = 0;
                for(int j=0; j<L; j++)
                {
                    if(dif & (1LL<<j))pcnt++;
                }
                ans = min(ans, pcnt);
            }
        }

        cout<<"Case #"<<t<<": ";
        if(ans == INF)
            cout<<"NOT POSSIBLE";
        else
            cout<<ans;
        cout<<endl;
    }

    return 0;
}
