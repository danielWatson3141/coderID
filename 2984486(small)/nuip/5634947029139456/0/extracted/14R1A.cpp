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

int N,L;
string s[20],g[20];

int main(){
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++){
    int i,j,k,re=1000;
    cin>>N>>L;
    for(i=0;i<N;i++)
      cin>>s[i];
    for(i=0;i<N;i++)
      cin>>g[i];
    
    sort(g,g+N);
    bool f=0;
    int tmp=0;
    do{
      f=tmp=0;
      for(i=0;i<L;i++){
        for(j=0;j<N;j++){
          if( (s[j][i]==g[j][i]) != (s[0][i]==g[0][i]) )
            f=1;
          if(f)break;
        }
        if(f)break;
        tmp+=(s[0][i]!=g[0][i]);
      }
      if(f==0)re=min(re,tmp);
    }while(next_permutation(g,g+N));
    cout<<"Case #"<<t<<": ";
    if(re==1000)cout<<"NOT POSSIBLE"<<endl;
    else cout<<re<<endl;
  }
  return 0;
}