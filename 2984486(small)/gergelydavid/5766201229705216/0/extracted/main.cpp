///Created by Gergely David.
///CNPR - Beclean

#include <iostream>
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



//ifstream fin ("B-small-practice.in") ;
//ifstream fin ("B-large-practice.in") ;
ifstream fin("input.in") ;
ofstream fout ("output.out") ;


void Read() ;
void Solve() ;
void Out() ;


struct struc
{
};

int T ;
vector <int> V ;
queue <int> Q ;


inline int min(int a, int b)
{
    if(a > b) return b ;
    else return a ;
}
inline int max(int a, int b)
{
    if(a < b) return b ;
    else return a ;
}


int N ;
vector <int> AA, BB ;
vector <vector <int> > S ;
vector <bool> adevar ;
vector <int> down ;
int DD[1009][3] ;

int fun (int ind, int xxx)
{
    if (xxx == 3)
    {
        return 10000;
    }
    if (ind == AA.size())
    {
        if (xxx == 1)
        {
            return 10000;
        }
        return 0;
    }

    int &result = DD[ind][xxx];
    if (result != -1)
    {
        return result;
    }
    result = fun (ind+1, xxx) + BB[ind];
    result = min (result, AA[ind]+fun(ind+1, xxx+1));
    return result;
}

int cal (vector <int> S, vector <int> a)
{
    AA= S;
    BB = a;
    if (S.size() == 0)
    {
        return 0;
    }
    if (S.size() == 1)
    {
        return a[0];
    }
    memset (DD, -1, sizeof(DD));
    return fun (0, 0);
    /*
    fdjsdf
    col
    d
    sad
    a
    sd
    asd
    */
}

int f (int x, int p)
{
    vector <int> AA;
    vector <int> BB;

   for(long long  i = 0 ; i < S[x].size() ; ++ i)
    {

        //jsdfjhsfjs
        ///sdfjsdhfjsdfsd
        int xx = S[x][i];
        if (xx == p)
        {
            continue;
        }
        int xxx = f (xx, x);
        AA.push_back (xxx);
        BB.push_back(down[xx]);
    }

    return cal (AA, BB);
}

void ff (int sd, int p)
{
    down[sd] = 1;
//asdhd
    for(long long  i = 0 ; i < S[sd].size()  ; ++ i)
    {
        int xx = S[sd][i];
        if (xx == p)
        {
            continue;
        }
        ff (xx, sd);
        down[sd] += down[xx];
    }
}


int contor = 0 ;

int main()
{
    fin >> T ;


    while(T)
    {

        ++ contor ;
         fout << "Case #" << contor <<": " ;
         fin >> N ;

        S.clear() ;
        S.resize(N) ;

        int sum = N ;
        for(int i = 0 ; i < N - 1 ; ++ i)
        {
            int xx, yy ;
            fin >> xx >> yy ;
            -- xx ;
            -- yy ;
            S[xx].push_back(yy) ;
            S[yy].push_back(xx) ;
        }



        for (int j = 0; j < N; ++ j) {
            adevar.resize (N);
            down.resize (N);
            for (int i = 0; i < adevar.size(); ++ i) {
                adevar[i] = false;
                down[i] = 0;
            }
            ff (j, j);
            sum = min (sum, f(j, j));

        }
        fout << sum << '\n';

        -- T ;
    }


    fin.close() ;
    fout.close() ;
    return 0 ;
}



