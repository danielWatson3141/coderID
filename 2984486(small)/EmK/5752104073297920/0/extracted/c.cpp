#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>
#include<bitset>
#include<cassert>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

int dx[]  = {0,1,0,-1};
int dy[]  = {1,0,-1,0};
string ds = "SENW";

const double PI = 4.0*atan(1.0);

int eval(const VI& p){
  int x= 0;
  int n = SZ(p);
  FOR(i,SZ(p)) {
    int step = p[i] - i;
    if(1 <= step && step < n/2) x++;
  }
  return x;
}

VI good(int n) {
  VI p(n);
  FOR(i,n) p[i] = i;
  FOR(i,n) {
    int r = rand()%(n-i)+i;
    swap(p[i], p[r]);
  }
  return p;
}

VI bad(int n) {

  VI p(n);
  FOR(i,n) p[i] = i;
  FOR(i,n) {
    int r = rand()%n;
    swap(p[i], p[r]);
  }
  return p;
}

void printgood(int n){
  VI p = good(n);
  //FOR(i,n) cout<<" "<<p[i]; 
  cout<<"  "<<eval(p)<<endl;
}

void printbad(int n){
  VI p= bad(n);
  cout<<"  "<<eval(p)<<endl;
}



void test(int n,int tryNum){
  map<VI,int> c;

  VVI mat(n,VI(n));
  FOR(_,tryNum){
    VI p(n);
    FOR(i,n) p[i] = i;
    FOR(i,n) {
      int r = rand()%n;
      //r = rand()%(n-i)+i;
      swap(p[i], p[r]);
    }
    FOR(i,n) {
      mat[i][p[i]]++;
    }
    c[p]++;
  }
  vector<pair<int,VI> > dat;
  double avg = n;
  for(auto m : c){
    dat.push_back(MP(m.second, m.first));
  }
  sort(ALL(dat));
  reverse(ALL(dat));
  /*for(auto m : dat) {
    cout<<" "<<m.first;
    for(auto x : m.second) cout<<" "<<x; cout<<endl;
    }*/
  FOR(i,n) {
    FOR(j,n) printf(" %+6f", (1.0 * mat[i][j] / tryNum - 1.0 / n)); cout<<endl;
  }
}

double memo[1111][1111];

bool isBad(const VI& perm){
  return eval(perm) >= 400;
}

void tests(){
  int correct = 0;
  FOR(_,12000) {
    int r = rand()%2;
    if(r == 0) {
      if(isBad(bad(1000))) correct++;
    }else{
      if(!isBad(good(1000))) correct++;
    }
  }
  cout<<correct<<endl;
}

int main() {
  //tests();
  //FOR(_,100) printgood(1000);
  //cout<<"---"<<endl;
  //FOR(_,100) printbad(1000);
  //test(16,100000);
  int t,caseNo=1;
  cin>>t;
  while(t--){
    int N ;
    cin>>N;
    VI p(N);
    FOR(i,N) scanf("%d",&p[i]);
    printf("Case #%d: ", caseNo++);
    if(isBad(p)) puts("BAD");
    else puts("GOOD");

  }
  return 0 ;
}
