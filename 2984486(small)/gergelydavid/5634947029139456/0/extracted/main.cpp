///Created by Gergely David.
///CNPR - Beclean


#include <fstream>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <cstdio>
#define ll long long
#define ull unsigned long long
#define fi first
#define se second

using namespace std ;


const int NMAX = 100 ;
const int INF = 0x3f3f3f3f ;



//ifstream fin ("A-small-practice.in") ;
//ifstream fin ("A-large-practice.in") ;
ifstream fin("input.in") ;
ofstream fout ("output.out") ;


void Read() ;
void Solve() ;
void Out() ;

inline int min(long long a, long long b)
{
    if(a < b) return a ;
    else return b ;
}

struct struc
{
};

string A[12];
string B[12];
long long  N, L , sol;


int schimba(int i)
{

    for(int j = 0 ; j < N; ++ j)
    {
        if(A[j][i]=='0')
        {
            A[j][i]='1';
        }
        else
        {
            A[j][i]='0';
        }
    }
    return 0;
}

int verifica(int suma)
{
    int i,j,mark[12];
    int cnot=0;
    for(int i = 0 ; i < 12; ++ i)
    {
        mark[i]=0;
    }
    for(int i = 0 ; i < N; ++ i)
    {
        for(j = 0 ; j < N ; ++ j)
        {
            if(A[i]==B[j]&&mark[j]==0)
            {
                mark[j]=1;
                ++ cnot;
            }
        }
    }
    if(cnot == N)
    {
        sol=min(sol,suma);
    }
    return 0;
}
int reco(int i,int suma)
{
    int j;
    if(i==L)
    {
        verifica(suma);
        return 0;
    }

    reco(i+1,suma);
    for(i = 0 ; i < N ; ++ i)
    {
        if(A[j][i]=='0')
        {
            A[j][i]='1';
        }
        else
        {
            A[j][i]='0';
        }
    }

    reco(i+1,suma + 1);
    return 0;
}
int T, contor = 0 ;
int main()
{

    fin >> T ;
    while(T)
    {
        ++ contor ;
        int i,j,k;
        fin >> N ;

        fin >> L ;
        for(int i = 0 ; i < N ; ++ i)
        {
            fin>>A[i];
        }
        for(int i = 0 ; i < N ; ++ i)
        {
            fin>>B[i];
        }
        sol=10000000;
        reco(0,0);

        fout << "Case # " << contor << ": " ;
        if(sol!=10000000)
        {
            fout << sol;
        }
        else
        {
            fout <<"NOT POSSIBLE";
        }
        fout << '\n' ;
        -- T ;
    }
    return 0;
}
