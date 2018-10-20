#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

const int threshold = 1000/4/4+3;

int main(){
  int testcase;
  int ans = 0;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    int n;
    cin >> n;
    int a, cnt = 0;
    for(int i=0;i<n;i++){
      cin >> a;
      if(i<n/4 && a<n/4)cnt++;
    }

    cerr << cnt << endl;
    cout << "Case #" << casenum << ": ";
    if(cnt>=threshold)cout << "GOOD" << endl;
    else cout << "BAD" << endl, ans++;
  }
  cerr << ans << endl;
}
