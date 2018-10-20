#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<queue>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,n,m) for(int i = (int)n; i <= (int)m; i++)
#define FOD(i,n,m) for(int i = (int)n; i >= (int)m; i--)
#define EACH(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

typedef long long i64;
typedef pair<int, int> PI;

#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))

#define PB push_back
#define MP make_pair
#define X first
#define Y second
template<class T> void fmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void fmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> T sqr(const T &a) { return a * a; }
static int convertToBytes(const char* str1, int in, int fm)
{
   int tot=0;
   if (strlen(str1)<fm) fm = strlen(str1);
   FOR(i, in, fm-1) {
       tot=tot*2;
       tot+=str1[i]-'0';                
   }
   return tot;
}

static int contaTrocas(int n)
{
   int tot=0;
   while(n>0) {
       tot+=n%2;
       n/=2;               
   }
   return tot;
}

void doit() {
     int N, L;
     cin >> N >> L;
     int outlet[N][4], required[N][4];
     vector<int> V1[4], V2[4];
     V1[0].clear();
     V2[0].clear();
     V1[1].clear();
     V2[1].clear();
     V1[2].clear();
     V2[2].clear();
     V1[3].clear();
     V2[3].clear();
     char a[L];
     FOR(i, 1, N) {
            cin >> a;
            outlet[i-1][0]=convertToBytes(a, 0,10);
            outlet[i-1][1]=convertToBytes(a, 10, 20);
            outlet[i-1][2]=convertToBytes(a, 20, 30);
            outlet[i-1][3]=convertToBytes(a, 30, 40);
            }
     FOR(i, 1, N) {
            cin >> a;
            required[i-1][0]=convertToBytes(a, 0, 10);
            required[i-1][1]=convertToBytes(a, 10, 20);
            required[i-1][2]=convertToBytes(a, 20, 30);
            required[i-1][3]=convertToBytes(a, 30, 40);
            V1[0].PB(outlet[0][0]^required[i-1][0]);    
            V1[1].PB(outlet[0][1]^required[i-1][1]);    
            V1[2].PB(outlet[0][2]^required[i-1][2]);    
            V1[3].PB(outlet[0][3]^required[i-1][3]);    
            }  

          FOR(i, 1, N-1)  { 
     FOR(j, 0, N-1) {
            if(find(V1[0].begin(), V1[0].end(), outlet[i][0]^required[j][0])!=V1[0].end()
              && find(V1[1].begin(), V1[1].end(), outlet[i][1]^required[j][1])!=V1[1].end()
              && find(V1[2].begin(), V1[2].end(), outlet[i][2]^required[j][2])!=V1[2].end()
              && find(V1[3].begin(), V1[3].end(), outlet[i][3]^required[j][3])!=V1[3].end()) {
                                V2[0].PB(outlet[i][0]^required[j][0]);
                                V2[1].PB(outlet[i][1]^required[j][1]);
                                V2[2].PB(outlet[i][2]^required[j][2]);
                                V2[3].PB(outlet[i][3]^required[j][3]);
                                }
            }
            V1[0].clear();
            V1[0].swap(V2[0]); 
            V2[0].clear();
            V1[1].clear();
            V1[1].swap(V2[1]); 
            V2[1].clear();
            V1[2].clear();
            V1[2].swap(V2[2]); 
            V2[2].clear();
            V1[3].clear();
            V1[3].swap(V2[3]); 
            V2[3].clear();
            }
            int minimo = 0;            
     for(std::vector<int>::size_type i = 0; i != V1[0].size(); i++) {
     int cont=contaTrocas(V1[0][i])+contaTrocas(V1[1][i])+contaTrocas(V1[2][i])+contaTrocas(V1[3][i]);
     if (i==0 || minimo>cont) minimo=cont;
     }
     if(V1[0].empty() || V1[1].empty() || V1[2].empty() || V1[3].empty())	 cout << "NOT POSSIBLE";
     else cout << minimo;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	int Te;
	scanf("%d", &Te);
	for (int Ti = 1; Ti <= Te; Ti++) {        		
		printf("Case #%d: ", Ti);
		doit();
		printf("\n", Ti);
	}
}
