#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>

using namespace std;

int main(){
  int T;
  cin>>T;
  int dc[120];
  for(int i=1;i<=T;i++){
    int a[1000];
    int N;
    cin>>N;
    for(int j=0;j<N;j++){
      cin>>a[j];
    }
    int c=0;
    for(int j=1;j<N;j++){
      c+=abs(a[j-1]-a[j])<=1;
    }
    dc[i-1]=c;
  }
  vector<int> v(begin(dc),end(dc));
  sort(begin(v),end(v));
  int m=v[60];
  for(int i=1;i<=T;i++){
    cout<<"Case #"<<i<<": "<<((dc[i-1]>=m)?"BAD":"GOOD")<<endl;
  }
  return 0;
}
