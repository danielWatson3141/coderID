#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ifstream cin("input.in");
    ofstream cout("output.txt");
    int t, z;
    cin>>t;
    for (z=0;z<t;++z)
    {
        int n, k, i, j, r, res, x;
        cin>>n>>k;
        res=k+1;
        vector<string> v(n), out(n);
        set<string> in;
        string S;
        for (i=0;i<n;++i)
        {
            cin>>out[i];
        }
        for (i=0;i<n;++i)
        {
            cin>>S;
            in.insert(S);
        }
        bool b;
        for (i=0;i<n;++i)
        {
            string s;
            b=1;
            for (j=0;j<n;++j)
            {
                s=out[j];
                r=0;
                for (x=0;x<k;++x)
                {
                    if (S[x]!=out[i][x])
                    {
                        s[x]='0'+(1-(s[x]-'0'));
                        ++r;
                    }
                }
                if (in.find(s)==in.end())
                {
                    b=0;
                    break;
                }
            }
            if (b)
            {
                res=min(r, res);
            }
        }
        cout<<"Case #"<<z+1<<": ";
        if (res==k+1)
        {
            cout<<"NOT POSSIBLE\n";
        }
        else
        {
            cout<<res<<"\n";
        }
    }
    return 0;
}
