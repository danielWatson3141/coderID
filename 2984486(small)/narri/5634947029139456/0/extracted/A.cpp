#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define VV vector

int dp(const vector<string> &outlets,
       const vector<string> &devices,
       const int at,
       const int L,
       const VV<pair<VV<int>, VV<int> > > &groups)
{
    if(at == L){
        for(int i=0;i<groups.size();++i)
        {
            if(groups[i].first.size() != 1){
                cerr << groups[i].first.size() << endl;
                return 10000;
            }
        }
        return 0;
    }
    int out = 10000;
    //do nothing?
    {
        VV<pair<VV<int>,VV<int> > > Q;
        VV<pair<VV<int>,VV<int> > > W;
        bool q_bad = false;
        bool w_bad = false;
        for(int i=0;i<groups.size();++i)
        {
            const pair<VV<int>, VV<int> > &p = groups[i];
            VV<int> A, B;
            VV<int> C, D;
            for(int t=0;t<p.first.size();++t)
            {
                if(outlets[p.first[t]][at] == '0') {
                    A.push_back(p.first[t]);
                }
                else {
                    B.push_back(p.first[t]);
                }
            }

            for(int t=0;t<p.second.size();++t)
            {
                if(devices[p.second[t]][at] == '0') {
                    C.push_back(p.second[t]);
                }
                else {
                    D.push_back(p.second[t]);
                }
            }
            if(A.size() == C.size() && B.size() == D.size()) {
                if(!A.empty())
                Q.push_back(make_pair(A,C));
                if(!B.empty())
                Q.push_back(make_pair(B,D));
            }
            else {
                q_bad = true;
            }
            if(A.size() == D.size() && B.size() == C.size()) {
                if(!A.empty())
                W.push_back(make_pair(A,D));
                if(!B.empty())
                W.push_back(make_pair(B,C));
            }
            else {
                w_bad = true;
            }
        }
        if(!q_bad)
        {
            out = min(out, dp(outlets, devices, at+1, L, Q));
        }
        if(!w_bad)
        {
            out = min(out, 1+dp(outlets, devices, at+1, L, W));
        }
    }
    return out;
}

void solve_case(const int cn)
{
    int N, L;
    vector<string> outlets;
    vector<string> devices;
    cin >> N >> L;
    for(int i=0;i<N;++i)
    {
        string S;
        cin >> S;
        outlets.push_back(S);
    }
    for(int i=0;i<N;++i)
    {
        string S;
        cin >> S;
        devices.push_back(S);
    }
    sort(outlets.begin(), outlets.end());
    sort(devices.begin(), devices.end());
    VV<pair<VV<int>,VV<int> > > qq;
    vector<int> z;
    for(int i=0;i<N;++i)
    {
        z.push_back(i);
    }
    qq.push_back(make_pair(z,z));
    int out = dp(outlets, devices, 0, L, qq);
    if(out > L)
    {
        printf("Case #%d: NOT POSSIBLE\n", cn);
    }
    else {
        printf("Case #%d: %d\n", cn, out);
    }
}

int main(int argc, char **argv)
{
    int CASES;
    cin >> CASES;
    for(int cn=1;cn<=CASES;++cn)
    {
        solve_case(cn);
    }
    return 0;
}
