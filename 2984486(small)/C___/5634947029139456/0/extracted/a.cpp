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
static int convertToBytes(const char* str1)
{
   int tot=0;
   FOR(i, 0, strlen(str1)-1) {
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
     int outlet[N], required[N];
     vector<int> V1, V2;
     V1.clear();
     V2.clear();
     char a[L];
     FOR(i, 1, N) {
            cin >> a;
            outlet[i-1]=convertToBytes(a);
            }
     FOR(i, 1, N) {
            cin >> a;
            required[i-1]=convertToBytes(a); 
            V1.PB(outlet[0]^required[i-1]);    
            }  
     FOR(i, 1, N-1)  { 
     FOR(j, 0, N-1) {
            if(find(V1.begin(), V1.end(), outlet[i]^required[j])!=V1.end()) V2.PB(outlet[i]^required[j]);
            }
            V1.clear();
            V1.swap(V2); 
            V2.clear();
            }
            int minimo = 0;            
     for(std::vector<int>::size_type i = 0; i != V1.size(); i++) {
     int cont=contaTrocas(V1[i]);
     if (i==0 || minimo>cont) minimo=cont;
     }
     
     if(V1.empty())	 cout << "NOT POSSIBLE";
     else cout << minimo;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	int Te;
	scanf("%d", &Te);
	for (int Ti = 1; Ti <= Te; Ti++) {        		
		printf("Case #%d: ", Ti);
		doit();
		printf("\n", Ti);
	}
}
