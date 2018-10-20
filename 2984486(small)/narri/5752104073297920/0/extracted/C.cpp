#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

const int NN = 1000;
long double data[NN+5][NN+5];
long double data2[NN+5][NN+5];
long double colsums[NN+5];

void preprocess(void)
{
    const double NP = 1.0/NN;
    //(loc, value)
    for(int i=0;i<NN;++i)
    {
        data[i][i] = 1.0;
    }
    for(int at=0;at<NN;++at)
    {
        if(at % 10 == 0)
        cerr << "ITER " << at << endl;
        memset(data2, 0, sizeof(data2));

        for(int nloc=0;nloc<NN;++nloc)
        {
            for(int n=0;n<NN;++n)
            {
                long double qq = 0.0;
                if(nloc == at)
                {
                    //takes values evenly from everything else
                    qq += NP;
#if 0
                    for(int t=0;t<NN;++t)
                    {
                        qq += NP * data[t][n];
                    }
#endif
                }
                else {
                    qq = data[nloc][n] * (1.0 - NP) + 
                         data[at][n] * NP;
                }
                data2[nloc][n] = qq;
            }
        }
#if 0
        for(int n=0;n<NN;++n)
        {
            for(int ns=0;ns<NN;++ns)
            {
                data2[ns][n] += NP * data[at][n];
            }
            //data2[at][n] += NP * data[ns][n];
        }
#endif
        memcpy(data, data2, sizeof(data));
    }
#if 0
    for(int i=0;i<NN;++i)
    {
        for(int j=0;j<NN;++j)
        {
            cerr << data[i][j] << " ";
        }
        cerr << endl;
    }
#endif
}

void solve_case(const int cn)
{
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;++i)
    {
        int a;cin >> a;v.push_back(a);
    }
    long double qq = 0;
    for(int i=0;i<N;++i)
    {
        qq += data[i][v[i]];
    }
    std::string out;
    if(qq > 1.005)
    {
        out = "BAD";
    }
    else {
        out = "GOOD";
    }
    printf("Case #%d: %s\n", cn, out.c_str());
}

int main(int argc, char **argv)
{
    preprocess();
    cerr << "DONE PREPROCESSING" << endl;
    int CASES;
    cin >> CASES;
    for(int cn=1;cn<=CASES;++cn)
    {
        solve_case(cn);
    }
    return 0;
}
