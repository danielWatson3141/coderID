#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;
typedef bitset<1024> BS;

int fill_count(const int N, const vector<vector<int> > &G,
         const int at,
         BS &bs, vector<int> &vout)
{
    const vector<int> &v = G[at];
    int out = 1;
    for(int i=0;i<v.size();++i)
    {
        if(bs[v[i]]){continue;}
        bs[v[i]] = true;
        out += fill_count(N,G,v[i],bs,vout);
    }
    vout[at] = out;
    return out;
}

int eval(const int N, const vector<vector<int> > &G,
         const int at,
         BS &bs, const vector<int> &ccc)
{
    const vector<int> &v = G[at];
    int besties[2];
    int zq[2];
    int out = N*2;
    besties[0] = -10;
    besties[1] = -10;
    zq[0] = zq[1] = 0;
    int oct = 0;
    for(int i=0;i<v.size();++i)
    {
        const int q = v[i];
        if(bs[q]){continue;}
        ++oct;
        bs[q] = true;
        int sc = eval(N, G, q, bs,ccc);
        sc = ccc[q] - sc;
        //cerr << "QQ" << ccc[q] - sc << endl;
        if(sc > besties[0]){
            besties[1] = besties[0];
            zq[1] = zq[0];
            besties[0] = sc;
            zq[0] = ccc[q];
        }
        else if(sc > besties[1])
        {
            besties[1] = sc;
            zq[1] = ccc[q];
        }
    }
    out = min(out, ccc[at]-1);
    if(oct >= 2) {
       // cerr << besties[0] << " " << besties[1] << endl;
        out = min(out, (-besties[0]) + (-besties[1]) + (ccc[at]-1));//-zq[0]-zq[1]));
    }
    //cerr << at << " " << out << endl;
    return out;
}

void solve_case(const int cn)
{
    int N;
    cin >> N;
    vector<vector<int> > G(N, vector<int>());
    int A,B;
    for(int i=0;i+1<N;++i)
    {
        cin >> A >> B;
        --A;
        --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    int out = N*2;
    for(int i=0;i<N;++i)
    {
        BS bs;
        vector<int> ccc(N, -1);
        bs.reset();
        bs[i] = true;
        fill_count(N,G,i,bs,ccc);
        bs.reset();
        bs[i] = true;
        out = min(out, eval(N, G, i, bs,ccc));
    }
    printf("Case #%d: %d\n", cn, out);
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
