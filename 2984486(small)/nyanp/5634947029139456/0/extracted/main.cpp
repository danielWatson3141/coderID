#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#include <functional>

using namespace std;

vector<string> make(vector<string> init, int L, unsigned int b, int *bit)
{
    *bit = 0;
    for (int i = 0; i < L; i++, b >>= 1) {
        if (b & 0x01) {
            for (string& s : init) {
                s[i] = s[i] == '0' ? '1' : '0';
            }
            (*bit)++;
        }
    }
    sort(init.begin(), init.end());
    return init;
}

int solve(int N, int L, vector<string>& init, vector<string>& dev)
{
    unsigned int p = 2 << (L - 1);
    int minbit = L + 1;
    int bit;

    sort(dev.begin(), dev.end());

    for (unsigned int i = 0; i < p; i++) {
        vector<string> flop = make(init, L, i, &bit);
        if (flop == dev) {
            minbit = min(bit, minbit);
        }
    }

    return minbit == L + 1 ? -1 : minbit;
}


int main(void) {
    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int N, L;
        cin >> N >> L;

        vector<string> init, dev;

        for (int j = 0; j < N; j++) {
            std::string s;
            for (int k = 0; k < L; k++) {
                char c;
                cin >> c;
                s += c;
            }
            init.push_back(s);
        }

        for (int j = 0; j < N; j++) {
            std::string s;
            for (int k = 0; k < L; k++) {
                char c;
                cin >> c;
                s += c;
            }
            dev.push_back(s);
        }

        int res = solve(N, L, init, dev);

        if (res >= 0) {
            printf("Case #%d: %d\n", i + 1, res);
        }
        else {
            printf("Case #%d: NOT POSSIBLE\n", i + 1);
        }

    }
}