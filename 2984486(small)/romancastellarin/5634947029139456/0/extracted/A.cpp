#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#define forn(a,b) for((a)=0; (a)<(b); ++(a))
#define forr(a,c,b) for((a)=(c); (a)<=(b); ++(a))
using namespace std;
const int maxl = 50;

ifstream fin("entrada.txt");
ofstream fout("salida.txt");

int N, L, R ;
vector<int> P;
vector<string> Outlet, Device, Test;

void test(int S){
    Test = Outlet;
    int i, e;
    forn(i, L)
        if( P[i] )
            forn(e, N)
                Test[e][i] = ( Test[e][i] == '0' ? '1' : '0' );

    sort(Test.begin(),Test.end());
    forn(i, N)
        if( Test[i] != Device[i] ) break;
    if( i == N ) R = min(R, S);
}

void dfs(int level, int S){
    if( level == L ){
        test(S);
        return;
    }
    P[level] = 0;
    dfs(level+1,S);
    P[level] = 1;
    dfs(level+1,S+1);
}

int main(){
    int _C, _T, i, e;
    string str;

    fin>>_T;
    forr(_C,1,_T){
        P.clear();
        Outlet.clear();
        Device.clear();
        R = (1<<26);

        fout<<"Case #"<<_C<<": ";
        fin>>N>>L;
        P.resize(L,0);

        forn(i, N){
            fin>>str;
            Outlet.push_back(str);
        }

        forn(i, N){
            fin>>str;
            Device.push_back(str);
        }

        sort(Device.begin(),Device.end());

        dfs(0,0);

        if( R == (1<<26) ) fout<<"NOT POSSIBLE"<<endl;
        else fout<<R<<endl;

    }

    return 0;
}
