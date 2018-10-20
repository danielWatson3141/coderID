#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

inline void flip(const int idx, vector<string> &streams) {
    for (auto &s : streams)
        s[idx] = s[idx] == '0' ? '1' : '0';
}

int recurse(int idx, const int L, vector<string> &outlets, vector<string> &devices, const int flips_so_far) {
    if (idx == L) {
        sort(outlets.begin(), outlets.end());
        if (equal(outlets.begin(), outlets.end(), devices.begin()))
            return flips_so_far;
        return -1;
    }

    // first try not flip
    int res = recurse(idx+1, L, outlets, devices, flips_so_far);
    if (res > -1)
        return res;

    // flip i-th bit
    flip(idx, outlets);

    res = recurse(idx+1, L, outlets, devices, flips_so_far+1);
    if (res > -1)
        return res;

    // restore
    flip(idx, outlets);
    return -1;
}

int minimal_flips(vector<string> &outlets, vector<string> &devices) {
    const int L = outlets[0].length();

    // the canonical order
    sort(devices.begin(), devices.end());

    return recurse(0, L, outlets, devices, 0);
}

inline void read_config(vector<string> &cont, const int N) {
    string s;
    for (int i = 0;i < N;++i) {
        cin >> s;
        cont.push_back(s);
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0;i < T;++i) {
        int N, L;
        cin >> N >> L;
        vector<string> outlets;
        vector<string> devices;
        read_config(outlets, N);
        read_config(devices, N);

        int mf = minimal_flips(outlets, devices);
        if (mf == -1)
            cout << "Case #" << (i+1) << ": NOT POSSIBLE";
        else
            cout << "Case #" << (i+1) << ": " << mf;
        cout << endl;
    }
}
