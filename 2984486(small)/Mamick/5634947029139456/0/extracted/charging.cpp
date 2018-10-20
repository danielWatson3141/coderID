#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
vector<string> targets;
vector<bool> flipped;
vector<string> initial;

inline bool isEqual(const string& s1, const string&s2) {
    // cout << s1 << " " << s2 << endl;
    for (int i = 0; i < s1.length(); i++) {
        // cout << i << " " << flipped[i] << " " << s1[i] << " " << s2[i] << endl;
        if (s1[i] != (!flipped[i] ? s2[i] : (s2[i] == '0' ? '1' : '0'))) {
            return false;
        }
    }
    return true;
}
bool works() {
    for (int i = 0; i < targets.size(); i++) {
        bool works = false;
        for (int j = 0; j < initial.size(); j++) {
            if (isEqual(targets[i], initial[j])) {
                works = true;
                break;
            }
        }
        if (works == false) return false;
    }
    return true;
}

int setFlipped(const string& s1, const string& s2) {
    int count = 0;
    // cout << s1 << " " << s2 << endl;
    for (int i = 0; i < s1.length(); i++) {
        // cout << s1[i] << " " << s2[i] << endl;
        if (s1[i] == s2[i]) {
            flipped[i] = false;
        } else {
            count++;
            flipped[i] = true;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases++) {
        targets.clear(); flipped.clear(); initial.clear();
        int n,l;
        cin >> n >> l;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            initial.push_back(tmp);
            flipped.push_back(false);
        }
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            targets.push_back(tmp);
        }
        int best = -1;
        for (int i = 0; i < n; i++) {
            int num = setFlipped(targets[i], initial[0]);
            // cout << num << endl;
            if ((num < best || best == -1) && works()) {
                best = num;
            }
        }
        if (best == -1)
        cout << "Case #" << cases << ": " << ("NOT POSSIBLE") << endl;
        else
        cout << "Case #" << cases << ": " << (best) << endl;
    }
}