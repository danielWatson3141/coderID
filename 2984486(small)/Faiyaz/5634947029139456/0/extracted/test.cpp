/*
Bismillahir Rahmanir Rahim
Coder: Ahmad Faiyaz
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>


# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)

#define EPS 1e-11
#define inf 1234567891
#define LL long long

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))

#define pb push_back
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define pii pair<int,int>
#define UNIQUE(c) (c).resize( unique( all(c) ) - (c).begin() )

#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
#define CIN ios_base::sync_with_stdio(0);
///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
vector <string> l, r, tmp;
int n, ln;
int main(){
    #if defined( faiyaz_pc )
        READ("A-small-attempt2.in");
        WRITE("smallnew.out");
    #endif
int t;
    int chk= 1;
    string s;
    CIN;
    cin>>t;
    while(t--){
        l.clear();r.clear();
        cin>>n>>ln;

        for(int i=0;i<n;i++){

            cin>>s;
            l.pb(s);
        }

        for(int i=0;i<n;i++){

            cin>>s;
            r.pb(s);
        }
        sort(all(l));
        sort(all(r));
        int cnt = inf;
        for(int i=0;i< (1<<ln);i++){
            tmp = l;
            int c = 0;
            for(int j=0;j<ln;j++){
                if(i & (1<<j)){
                    c++;
                    for(int k=0;k<l.size();k++){
                        if(tmp[k][j] == '1'){
                            tmp[k][j] = '0';
                        }else{
                            tmp[k][j] = '1';
                        }
                    }
                }
            }
            sort(all(tmp));
            if(tmp == r){
                cnt = min(cnt, c);
            }
        }
        cout<<"Case #"<<chk++<<": ";
        if(cnt == inf){
            cout<<"NOT POSSIBLE\n";
        }else{
            cout<<cnt<<"\n";
        }
    }
    return 0;
}
