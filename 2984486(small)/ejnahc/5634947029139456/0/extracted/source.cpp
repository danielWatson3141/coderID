#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
const int MAX = 987654321;

bool isSame(vector<string>& a, vector<string>& b) {
    for (int i=0; i<a.size(); i++) {
        bool ss = false;
        for (int j=0; j<b.size(); j++) {
            if (a[i] == b[j]) {
                ss = true;
                break;
            }
        }

        if (!ss) return false;
    }
    return true;
}

char reverse(char r) {
    return (r == '0' ? '1' : '0');
}

int go(int start, vector<string> plays, vector<string> wannabe) {
    for (int i=0; i<plays.size(); i++) {
        plays[i][start] = reverse(plays[i][start]);
    }

    if (isSame(plays, wannabe))
        return 1;

    int ret = MAX;
    for (int i=start+1; i<L; i++) {
        ret = min(ret, 1 + go(i, plays, wannabe));
    }

    return ret;
}

int main() {
    int tc;
    cin >> tc;

    for (int _tc=1; _tc<=tc; ++_tc) {
        printf("Case #%d: ", _tc);

        vector<string> plays;
        vector<string> wannabe;

        cin >> N >> L;
        for (int i=0; i<N; i++) {
            string s_plays;
            cin >> s_plays;
            plays.push_back(s_plays);
        }

        for (int i=0; i<N; i++) {
            string s_wannabe;
            cin >> s_wannabe;
            wannabe.push_back(s_wannabe);
        }

        if (isSame(plays, wannabe))
            printf("0");
        else {
            int ret = MAX;
            for (int i=0; i<L; i++) {
                ret = min(ret, go(i, plays, wannabe));
            }

            if (ret == MAX)
                printf("NOT POSSIBLE");
            else printf("%d", ret);
        }

        printf("\n");
    }
}