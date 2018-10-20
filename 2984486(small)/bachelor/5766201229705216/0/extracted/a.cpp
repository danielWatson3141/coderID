#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
typedef vector<string> VS;

bool isMatch(VS v1, VS v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < v1.size(); ++i)
    {
        if(v1[i] != v2[i])
            return false;
    }
    return true;
}

vector<int> getFlipPos(const string &str, const string &pat)
{
    vector<int> res;
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] != pat[i])
            res.push_back(i);
    }
    return res;
}

char flip(char c)
{
    if(c == '0') return '1';
    return '0';
}

VS flipAll(VS v, const vector<int> &fp)
{
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < fp.size(); ++j)
            v[i][fp[j]] = flip(v[i][fp[j]]);
    }
    return v;
}

int main()
{
    int T;
    cin>>T;
    for(int tt = 1; tt <= T; ++tt)
    {
        int N, L;
        cin>>N>>L;
        VS v1, v2;
        string str;
        for(int i = 0; i < N; ++i)
        {
            cin>>str;
            v1.push_back(str);
        }
        for(int i = 0; i < N; ++i)
        {
            cin>>str;
            v2.push_back(str);
        }

        int ans = L + 1;
        for(int i = 0; i < N; ++i)
        {
            vector<int> flipPos = getFlipPos(v1[0], v2[i]);
            if(flipPos.size() >= ans)
                continue;
            VS v3 = flipAll(v2, flipPos);
            if(isMatch(v1, v3))
                ans = flipPos.size();
        }

        cout<<"Case #"<<tt<<": ";
        if(ans <= L)
            cout<<ans<<endl;
        else
            cout<<"NOT POSSIBLE"<<endl;
    }

    return 0;
}
