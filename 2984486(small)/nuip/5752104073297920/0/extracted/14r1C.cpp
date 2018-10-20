#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;


int main(){
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++){
    int i,j,k,N,sum;
    cin>>N;cout<<"Case #"<<t<<": ";
    int tmp;
    sum=0;
    for(i=0;i<N;i++){
      cin>>tmp;
      if(i<N/4 && tmp==0)
        break;
 
    }
    if(i!=N)
      cout<<"BAD"<<endl;
    else cout<<"GOOD"<<endl;
  }
  return 0;
}