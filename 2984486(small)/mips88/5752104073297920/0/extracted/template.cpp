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

int n;
int a[1000];


#define NRTRIALS 10000000
int distribBAD[1000][1000];
int distribGOOD[1000][1000];
int best;
double PGood = 1.0;
double PBad = 1.0;

void read()
{
    fscanf(fin,"%d",&n);

    FOR(i,n)
    fscanf(fin,"%d",&a[i]);


}


void solve()
{
    PGood = 1.0;

    FOR(i,n)
    {
        PGood = PGood * distribGOOD[i][a[i]]*1.0/distribBAD[i][a[i]];
    }
 }

void write()
{
    cout << PGood<< endl;
    cout << PBad<< endl;
    if (PGood > 1.0)
            fprintf(fout,"GOOD");
    else
            fprintf(fout,"BAD");
}

void badAlg()
{
    FOR(i,n)
    a[i] = i;

    FOR(i,n)
    {
        int x = rand() % n;
        swap(a[x],a[i]);
    }
}

void goodAlg()
{
    FOR(i,n)
    a[i] = i;

    FOR(i,n)
    {
        int x = i + rand() % (n-i);
        swap(a[x],a[i]);
    }
}


int gen()
{
    FILE* fdg = fopen("dGOOD.txt","w");
    FILE* fdb = fopen("dBAD.txt","w");

    FOR(i,NRTRIALS)
    {
        goodAlg();
        FOR(j,n)
        {
            distribGOOD[j][a[j]] = distribGOOD[j][a[j]] + 1;
        }

        badAlg();
        FOR(j,n)
        {
            distribBAD[j][a[j]] = distribBAD[j][a[j]] + 1;
        }

    }
    FOR(i,n)
    {
    FOR(j,n)
    {
         fprintf(fdb,"%d ",(int) distribBAD[i][j]);
         fprintf(fdg,"%d ",(int) distribGOOD[i][j]);
    }
         fprintf(fdb,"\n");
         fprintf(fdg,"\n");

    }
    fclose(fdb);
    fclose(fdg);
}

int test()
{
    fin = fopen("input.txt","w");
    fprintf(fin,"200\n");
    FOR(i,100)
    {
        goodAlg();
        fprintf(fin,"%d\n",n);
        FOR(j,n)
        fprintf(fin,"%d ",a[j]);
        fprintf(fin,"\n");
    }
    FOR(i,100)
    {
        badAlg();
        fprintf(fin,"%d\n",n);
        FOR(j,n)
        fprintf(fin,"%d ",a[j]);
        fprintf(fin,"\n");
    }
    fclose(fin);
}

int main()
{
    n = 1000;
    //gen();
    //test();

    FILE* fdg = fopen("dGOOD.txt","r");
    FILE* fdb = fopen("dBAD.txt","r");

    FOR(i,n)
    {
        FOR(j,n)
        {
            fscanf(fdb,"%d ",&distribBAD[i][j]);
            fscanf(fdg,"%d ",&distribGOOD[i][j]);
        }
    }

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
