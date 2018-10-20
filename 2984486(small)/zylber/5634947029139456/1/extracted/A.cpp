#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;


map<string, int> objs;
string needs[256];
string powers[256];
int flips[256];
int cant[256];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    cin >> T;

    for(int tc=1; tc<=T; tc++)
    {
        objs.clear();
        int N, L;
        cin >> N >> L;

        for(int i=0; i<N; i++)
        {
            cin >> needs[i];
            objs[needs[i]]=i+1;
        }

        for(int i=0; i<N; i++)
        {
            cin >> powers[i];
        }

        int ans=L+1;
        for(int i=0; i<N; i++)
        {
            memset(cant,0,sizeof(cant));
            int sum=0, valid=1;
            //cout << i << endl;
            for(int j=0; j<L; j++)
            {
                flips[j]=(needs[i][j]!=powers[0][j])?1:0;
                sum+=flips[j];
                //cout << flips[j] << " ";
            }
            //cout << endl;
            for(int j=0; j<N; j++)
            {
                string newpow;
                for(int k=0; k<L; k++)
                {
                    char cur=0;
                    if(powers[j][k]=='1') cur=1;
                    if(flips[k]) cur^=1;
                    cur+='0';

                    newpow+=cur;
                }

                if(!objs.count(newpow))
                {
                    valid=0;
                }
                else
                {
                    cant[objs[newpow]]++;
                }
            }

            for(int j=1; j<=N; j++)
                if(cant[j]!=1) valid=0;

            if(valid) ans=min(ans, sum);
        }

        cout << "Case #" << tc << ": ";
        if(ans>L) cout << "NOT POSSIBLE"; else cout << ans;
        cout << endl;
    }
}
