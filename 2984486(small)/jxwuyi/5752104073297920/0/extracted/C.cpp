#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
#include<ctime>
#include<cmath>
using namespace std;
#define LL long long

#define mkp(a,b) make_pair(a,b)

map<vector<int>, int> R;
vector<pair<int,vector<int> > > A;
int N,L;

int sqr(int a){return a*a;}

int main() {
  N = 1000;
  cout << pow(2, 0.2)<<endl;
  double expect =0;
  for(int i=0;i<N;++i){
    double cur=0;
    for(int j=0;j<N;++j)
      //if(j != i)
        cur += (i-j>10);//(abs(j-i)>10);//pow(min(20,abs(j - i)),1.2);
    expect += cur / (double)(N-1 );
  }
  expect+=10;
  printf("%.6lf\n", expect);
  cout << expect<<endl;
  //expect/=2;
  FILE *inf = fopen("C.in","r");
  FILE *ouf = fopen("C.out","w");
  
  int test;fscanf(inf, "%d", &test);
  for(int no=1;no<=test;++no){
    int x;vector<int>A;
    int n;
    fscanf(inf, "%d", &n);
    double tmp=0;
    for(int i=0;i<n;++i) {
      fscanf(inf, "%d", &x);
      //A.push_back(x);
      tmp += (x-i)>10;
      //(abs(x-i)>10);//pow(min(abs(x - i), 20), 1.2);
        //x * pow(i+1, 0.2);
    }
    fprintf(ouf, "Case #%d: %s\n", no, (tmp > expect ? "BAD": "GOOD"));
  }
  fclose(inf);
  fclose(ouf);
}


