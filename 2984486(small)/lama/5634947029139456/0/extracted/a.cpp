#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

int T;

bool isCorrect(vector<string> devices, vector<string> outlets, vector<int> what) {
    set<string> switchedOutlets;
    for (int i = 0; i < outlets.size(); ++i) {
        string s = outlets[i];
        for (int j = 0; j < what.size(); ++j)
            s[what[j] - 1] = (s[what[j] - 1] == '0' ? '1' : '0');
        switchedOutlets.insert(s);
    }
    // cout << "---" << endl;
    // for (set<string>::iterator it=switchedOutlets.begin(); it!=switchedOutlets.end(); ++it)
    //     cout << ' ' << *it;
    // cout << endl << "---" << endl;

    for (int i = 0; i < devices.size(); ++i)
        if (switchedOutlets.find(devices[i]) == switchedOutlets.end())
            return false;
    return true;
}

int main() {
    cin >> T;
    for (int Ti = 1; Ti <= T; ++Ti) {
        // Input
        vector<string> devices, outlets;
        int N, L;
        cin >> N >> L;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            devices.push_back(s);
        }
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            outlets.push_back(s);
        }

        // Bfs
        int res = -1;
        queue<vector<int> > q;
        vector<int> v;
        q.push(v);

        while (!q.empty()) {
            vector<int> what = q.front(); q.pop();
            // for (int i = 0; i < what.size(); ++i) {
            //     cout << what[i];
            // }
            // cout << endl;

            if (isCorrect(devices, outlets, what)) {
                res = what.size();
                break;
            }

            int largest = (what.size() == 0 ? 0 : what.back());

            for (int i = largest + 1; i <= L; ++i) {
                vector<int> newWhat (what);
                newWhat.push_back(i);
                q.push(newWhat);
            }
        }

        // Output result
        cout << "Case #" << Ti << ": ";
        if (res == -1)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << res << endl;
    }

    return 0;
}