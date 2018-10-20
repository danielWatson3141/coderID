#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#define FOR(i,n) for (int i = 0 ; i< n;i++)
#define FORI(i,s,e) for (int i = s ; i<= e;i++)
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define FZ(x) memset(x,0,sizeof(x))
using namespace std;
FILE* fin;
FILE* fout;
int nTESTS;

int n,l;
char init[200][100];
char needed[200][100];
int minim;
unordered_map <string, int> m;

string xorString(char* s1, char*s2)
{
    string res ="";
    FOR(i,l)
    {
        if ((s1[i]-'0') ^ (s2[i]-'0'))
        {
            res+="1";
        }
        else
            res+="0";
    }
    return res;
}
void read()
{
     fscanf(fin,"%d %d",&n,&l);

     FOR(i,n)
     {
         fscanf(fin,"%s",&init[i]);
     }
     FOR(i,n)
     {
         fscanf(fin,"%s",&needed[i]);
     }
}

void solve()
{
    m.clear();
    FOR(i,n)
        FOR(j,n)
        {
            string res = xorString(init[i],needed[j]);
            m[res]++;
        }
    minim = l+1;
    for (auto& x: m)
    if  (x.second == n)
    {
        int nr1 = 0;
        FOR(i,l)
        if (x.first[i] == '1')
        nr1++;
        minim = min(minim,nr1);
    }

}

void write()
{
    if (minim == l+1)
    fprintf(fout,"NOT POSSIBLE");
    else
    fprintf(fout,"%d",minim);
}



int main()
{
    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");

    fscanf(fin,"%d",&nTESTS);

    FOR(crtTest,nTESTS)
    {
        read();
        solve();
        fprintf(fout,"Case #%d: ",crtTest+1);
        write();
        fprintf(fout,"\n");
    }
    fclose(fout);

    return 0;
}
