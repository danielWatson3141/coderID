#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <complex>
#include <typeinfo>
#include <iostream>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORe(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORrev(i,a,b) for(int i = (b); i >= (a); ++i)
#define REP(i,a) FOR(i,0,a)
#define REP1(i,a) FOR(i,1,a)

#define LET(x,val) typeof(val) x = (val)
#define ALL(it) (it).begin(),(it).end()
#define PB push_back
#define MP make_pair

#ifdef DEBUG
#define DEB(x) cout << __FILE__ << ":" << __LINE__ << ":" << #x << ":" << x << endl;
#else
#define DEB(x)
#endif


vector<int> a;
vector<int> b;

int S2I(string a){
    /*int size = a.length();
    int sum = 0;
    for(int num_bits = 1; num_bits <= size; num_bits++) {
      sum <<= 1;
      sum += a[num_bits - 1] - '0';
    }
    return sum;*/
    const char* t = a.c_str();
    int r = strtol(t, NULL, 2);
    return r;
}

bool same (vector<int>a, vector<int>b){
    return equal(a.begin(), a.end(), b.begin());
    
/*    for(ui i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;*/
}

int BitCount(unsigned int u)
{
     unsigned int uCount;

     uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
     return ((uCount + (uCount >> 3)) & 030707070707) % 63;
     /*int count = 0;
     while (u > 0){
        count = count + 1;
        u = u & (u-1);
     }
     return count;*/
}

ui next_bin(ui x){
    ui t = (x | (x-1)) +1;
    ui w = t | ((((t & -t) / (x & -x)) >> 1) - 1);
    return w;
}

ui next_round(ui bits){
    return (1 << bits) - 1;    
}

int main(int argc, char** argv){
  int cas, n;
  ui l;  
  vector<int>::iterator it;
  string input;
  scanf("%d\n", &cas);
  REP(i,cas){
    a.clear();
    b.clear();
    scanf("%d %u\n", &n, &l);
    REP(j, n){
        cin >> input;
        a.push_back(S2I(input));
    }
    REP(j, n){
        cin >> input;
        b.push_back(S2I(input));
    }
    sort(b.begin(), b.end());
    //cout << "b is " << endl;
    //for(it = b.begin(); it < b.end(); ++it){
    //        cout << *it << endl;
    //   }
       sort(a.begin(), a.end());
    if(same(a,b)){
      //      cout << "same" << endl;
            printf("Case #%d: 0\n", i+1);
            continue;
        }
    
   
    ui h = 1;
    ui bits = 1;
    ui num = (ui)1<<l;
        
        while(h <= num){
    
            //cout << "trying " << h << endl;
            for(it = a.begin(); it < a.end(); ++it){
                *it = *it ^ h;
            }
            sort(a.begin(), a.end());
            //for(it = a.begin(); it < a.end(); ++it){
            //    cout << *it << endl;
            //}
            
            if(same(a,b)){
              //  cout << "same" << endl;
                break;
            } else {
                for(it = a.begin(); it < a.end(); ++it){
                    *it = *it ^ h;
                }
            }
            
            h = next_bin(h);
            if((h >= num) && (bits < l)){
                //cout << "next round" << endl;
                bits++;
                h = next_round(bits);
            }
            //cout << "h is now " << h << endl;
    }
    if(h > num){
        printf("Case #%d: NOT POSSIBLE\n", i+1);    
    } else {
        printf("Case #%d: %d\n", i+1, BitCount(h));
    }
  }

  return EXIT_SUCCESS;
}
