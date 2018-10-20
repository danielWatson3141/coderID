#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int N, L;
vector<string> tobe;
vector<string> asis;

vector<int> getFlipOrder(int device) {
    vector<int> flipOrder;
    for (int i = 0; i < L; ++i) {
        if (asis[0][i] != tobe[device][i])
            flipOrder.push_back(i);
    }
    return flipOrder;
}

void _flip(vector<string>& arr, int col) {
    for (int i =0 ; i < N; ++i) {
        if (arr[i][col] == '0')
            arr[i][col] = '1';
        else
            arr[i][col] = '0';
    }
}

vector<string> flip(vector<int>& order) {
    vector<string> change = asis;
    for (int i = 0; i < order.size(); ++i)
        _flip(change, order[i]);

    sort(change.begin(), change.end());

    return change;
}



int solve() {
    int flipCnt = 999999;

    sort(tobe.begin(), tobe.end());

    for (int i = 0; i < N; ++i) {
        vector<int> flipOrder = getFlipOrder(i);

        if (flipOrder.size() > flipCnt)
            continue;

        auto changed = flip(flipOrder);

        if (changed == tobe)
            flipCnt = flipOrder.size();
    }

    return flipCnt;
}


int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> N >> L;

        asis = vector<string>(N, "");
        tobe = vector<string>(N, "");

        for (int i = 0; i < N; ++i) 
            cin >> asis[i];
        for (int i = 0; i < N; ++i)
            cin >> tobe[i];

        
        int answer = solve();

        printf("Case #%d: ", test);
        if (answer == 999999)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << answer << endl;
    }

    return 0;
}
