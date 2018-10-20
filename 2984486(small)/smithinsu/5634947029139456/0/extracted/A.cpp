#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

vector < string > v1, v2;
string phone[256], board[256];
int main() {
  int T,n,l;
  cin>>T;
  int kase = 1;
  while(T--) {
    cin>>n>>l;
    v1.clear();
    v2.clear();
    for(int i=0;i<n;i++) {
      cin>>board[i];
    }
    for(int i=0;i<n;i++) {
      cin>>phone[i];
      v2.push_back(phone[i]);
    }
    sort(v2.begin(), v2.end());
    int ans = l+1;
    for(int i=0;i<n;i++) {
      int cou = 0;
      v1.clear();
      for(int k=0;k<l;k++) {
        cou += (phone[0][k] != board[i][k]);
      }
      for(int j=0;j<n;j++) {
        string cur(l, '0');
        for(int k=0;k<l;k++) {
          if(phone[0][k] != board[i][k]) {
            cur[k] = (char)(1 - (board[j][k] - '0')) + '0';
          } else {
            cur[k] = board[j][k];
          }
        }
        v1.push_back(cur);
      }
      sort(v1.begin(), v1.end());
      if(v1 == v2) {
        ans = min(ans, cou);
      }
    }
    printf("Case #%d: ",kase++);
    if(ans < l+1) {
      printf("%d\n",ans);
    } else {
      printf("NOT POSSIBLE\n");
    }
  }
  return 0;
}
