#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int to2(string s) {
   int ans  = 0 ;
   for (int i = 0 , j = 1; i < s.size(); i++) {
      if (s[i] == '1') ans += j;
      j += j;
   }
   return ans;
}
int count1(int x) {
   int ans = 0 ;
   while (x) {ans += (x& 1); x>>=1;}
   return ans;
}
int calc(vector<int> v1, vector<int> v2,int len) {
   int mask = 1 << len ; mask --;
   int ans = 10000000;
   vector<int> v3; v3.resize(v1.size());
   sort(v2.begin(),v2.end());
   for (int sw = 0; sw <= mask ; sw++) {
      int tl = count1(sw);
      if (tl >= ans ) continue;
      for (int  i = 0 ; i < v1.size(); i++)
         v3[i] = ((v1[i] ^ sw) & mask );
      bool eql = true;
      sort(v3.begin(),v3.end());
      for (int i = 0 ; i < v1.size(); i++)
         if (v3[i]!=v2[i]) eql = false;
      if (eql) 
        ans = tl;
   }
   return ans;
}
int main() {
    int t;
    cin >> t;
    for (int c = 1; c<= t; c++)  {
        cout << "Case #" << c <<": ";
        int l, n;
        string s;
        cin >> n >> l; ;
        vector<int> v1,v2;
        for (int i = 0 ; i < n ; i++) {
           cin >> s;
           v1.push_back(to2(s));
//         cout << s <<"!"<<endl;
        }
        for (int i = 0 ; i < n ; i++) {
           cin >> s;
           v2.push_back(to2(s));
  //       cout << s <<"!-"<<endl;
        }
        int ans = calc(v1,v2,l);
        if (ans <=100000) cout << ans << endl; else cout << "NOT POSSIBLE" << endl;
    }

}

