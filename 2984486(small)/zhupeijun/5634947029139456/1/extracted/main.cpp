#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000;

char b[155][45];
char d[155][45];

int main()
{
    freopen("a-large.in", "r", stdin);
    freopen("a-large.out", "w", stdout);
    int ci, cn;
    cin >> cn;

    for(ci = 1; ci <= cn; ci ++) {

    int N, L, i, j, k, ans = INF, ti, tj;
    vector<string> dest;

    cin >> N >> L;

    for(i = 0; i < N; i++)
        cin >> b[i];
    for(i = 0; i < N; i++) {
        cin >> d[i];
        dest.push_back(d[i]);
    }

    sort(dest.begin(), dest.end());

    for(i = 0; i < 1; i++) {
        for(j = 0; j < N; j++) {
            int mark[45], cnt = 0;
            memset(mark, 0, sizeof(mark));
            for(k = 0; k < L; k++) {
                if(b[i][k] != d[j][k]) {
                    mark[k] = 1;
                    cnt ++;
                }
            }

            vector<string> st;
            for(ti = 0; ti < N; ti++) {
                string s = "";
                for(tj = 0; tj < L; tj++) {
                    if(mark[tj]) {
                        if(b[ti][tj] == '1') s.append("0");
                        else s.append("1");
                    } else {
                        if(b[ti][tj] == '1') s.append("1");
                        else s.append("0");
                    }
                }
                st.push_back(s);
            }
            sort(st.begin(), st.end());

            for(ti = 0;ti < N; ti++) {
                if(st[ti] != dest[ti]) break;
            }

            if(ti == N) ans = min(ans, cnt);
        }
    }

    cout << "Case #" << ci << ": ";

    if(ans == INF)
        cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
    }
    return 0;
}
