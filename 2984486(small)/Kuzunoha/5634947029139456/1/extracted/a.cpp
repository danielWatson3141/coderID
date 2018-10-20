#include<iostream>
#include<string>
#include<set>
using namespace std;

string a[155], b[155];
set<string> s;
bool press[45];

int main()
{
    int T,n,l,c,d,e,anstemp,ans;
    bool hasAnswer, notPossible;
    string str;
    set<string>::iterator it;
    cin >> T;
    for(int tc=1;tc<=T;tc++)
    {
        cin >> n >> l;
        for(c=0;c<n;c++) cin >> a[c];
        for(c=0;c<n;c++) cin >> b[c];
        hasAnswer = false;
        ans = l+l;
        //tes b[0] sama a[c] trus semua temen2nya b
        for(c=0;c<n;c++)
        {
            for(d=0;d<l;d++)
            {
                if(a[c][d]==b[0][d]) press[d] = false;
                else press[d] = true;
            }
            //cout << "Percobaan ke-" << c << endl;
            //for(d=0;d<l;d++) cout << (press[d]?1:0);
            //cout << endl << endl;
            for(d=0;d<n;d++) s.insert(a[d]);
            notPossible = false;
            for(d=0;d<n;d++)
            {
                str = b[d];
                for(e=0;e<l;e++) if(press[e])
                {
                    if(str[e]=='0') str[e] = '1';
                    else str[e] = '0';
                }
                it = s.find(str);
                if(it==s.end())
                {
                    notPossible = true;
                    break;
                }
                else s.erase(it);
            }
            s.clear();
            if(!notPossible)
            {
                hasAnswer = true;
                anstemp = 0;
                for(d=0;d<l;d++) if(press[d]) anstemp++;
                ans = min(ans,anstemp);
            }
        }
        if(hasAnswer) cout << "Case #" << tc << ": " << ans << endl;
        else cout << "Case #" << tc << ": NOT POSSIBLE" << endl;
    }
    return 0;
}
