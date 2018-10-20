#include <bits/stdc++.h>

using namespace std;

char actual[222][222], need[222][222];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int tests;
  scanf("%d", &tests);

  for(int testNo = 1; testNo <= tests; testNo++) {
    printf("Case #%d: ", testNo);
    int N, L;
    scanf("%d %d", &N, &L);

    for(int i = 0; i < N; i++)
      scanf("%s", actual[i]);

    for(int i = 0; i < N; i++)
      scanf("%s", need[i]);

    int ans = 10000;
    bool can = false;

    bool flip[222][222];

    memset(flip, 0, sizeof(flip));

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < L; j++) {
        if(actual[0][j] != need[i][j])
          flip[i][j] = true;
      }
    }

    vector <string> required;

    for(int i = 0; i < N; i++) {
      required.push_back(string(need[i]));
    }

    for(int i = 0; i < N; i++) {
      vector <string> current;
      bool ok = true;

      for(int k = 0; k < N; k++) {
        string cur = "";
        for(int j = 0; j < L; j++) {
          if(flip[i][j]) {
            if(actual[k][j] == '0') cur.push_back('1');
            else cur.push_back('0');
          } else {
            if(actual[k][j] == '1') cur.push_back('1');
            else cur.push_back('0');
          }
        }

        current.push_back(cur);
      }

      sort(current.begin(), current.end());
      
      for(vector <string>::iterator it = required.begin(); it != required.end(); ++it) {
        vector <string> :: iterator it2 = lower_bound(current.begin(), current.end(), *it);
        if(it2 == current.end()) {
          ok = false;
          break;
        } else if(*it2 != *it){
            ok = false;
            break;
        } else {
          current.erase(it2);
        }
      }

      if(ok) {
        can = true;
        int cnt = 0;
        for(int j = 0; j < L; j++) {
          if(flip[i][j]) cnt++;
        }

        ans = min(ans, cnt);
      }

    }
    if(can) printf("%d\n", ans);
    else puts("NOT POSSIBLE");
  }

  return 0;
}