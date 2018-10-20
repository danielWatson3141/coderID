#include <utility>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int A[150][40];
int B[150][40];

bool used[150];
int toggle[40];

int res = numeric_limits<int>::max();

void search(int N, int L, int h) {
    if (h == N) {
        int cnt = 0;
        for (int i = 0; i < L; i++) {
            if (toggle[i] > 0) cnt++;
        }
        res = min(res, cnt);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        bool pass = true;
        for (int j = 0; j < L; j++) {
            if (B[h][j] != (A[i][j] ^ toggle[j])) {
                pass = false;
                break;
            }
        }
        if (!pass) continue;
        used[i] = true;
        search(N, L, h + 1);
        used[i] = false;
    }
}

int main() {
    ifstream ifs("/Users/Raffaele/Desktop/CodeJam/2014/1/small.in");
    cin.rdbuf(ifs.rdbuf());
    
    int T = 0;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        int N, L;
        cin >> N >> L;
        string tmp;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            for (int j = 0; j < tmp.length(); j++) {
                A[i][j] = tmp[j] - '0';
            }
        }
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            for (int j = 0; j < tmp.length(); j++) {
                B[i][j] = tmp[j] - '0';
            }
        }
        fill_n(used, 150, false);
        res = numeric_limits<int>::max();
        for (int i = 0; i < N; i++) {
            fill_n(toggle, 40, 0);
            for (int j = 0; j < L; j++) {
                toggle[j] = A[i][j] ^ B[0][j];
            }
            used[i] = true;
            search(N, L, 1);
            used[i] = false;
        }
        cout << "Case #" << test << ": ";
        if (res != numeric_limits<int>::max()) {
            cout << res << endl;
        } else {
            cout << "NOT POSSIBLE" << endl;
        }
    }

    return 0;
}



