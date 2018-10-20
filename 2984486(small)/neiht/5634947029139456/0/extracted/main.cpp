#include <iostream>
#include <vector>

using namespace std;

vector<string> toggle(const vector<string>& flows, int sw) {
    string tmp;
    vector<string> newFlows;
    for (auto& s : flows) {
        tmp = s;
        tmp[sw] = s[sw] == '0' ? '1' : '0';
        newFlows.push_back(tmp);
    }

    return newFlows;
}

bool check(const vector<string>& flows, const vector<string>& require) {
    for (auto& f : flows) {
        bool checked = false;
        for (auto& r : require) {
            if (f == r) checked = true;
        }
        if (!checked) return false;
    }

    return true;
}

int generator(const vector<string>& flows, const vector<string>& require,
              int curSw, int numSw) {
    if (curSw == numSw) {
       if (check(flows, require)) {
          return 0;
       } else {
          return -(numSw * 2);
       }
    }

    int noToggle = generator(flows, require, curSw+1, numSw);
    if (noToggle >= 0) {
        return noToggle;
    } else {
        return 1 + generator(toggle(flows, curSw), require, curSw+1, numSw);
    }
}

int main() {
    int t; // number of test cases
    int curCase = 1;

    int n, l;

    cin >> t;

    while (t--) {
        cout << "Case #" << curCase << ": ";

        vector<string> flows;
        vector<string> require;
        string tmp;
        cin >> n >> l;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            flows.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            require.push_back(tmp);
        }

        int r = generator(flows, require, 0, l);
        if (r >= 0) {
            cout << r << endl;
        }
        else {
            cout << "NOT POSSIBLE" << endl;
        }

        curCase++;

        //vector<string> test = toggle(flows, 1);
        //for (int i = 0; i < n; i++) {
        //    cout << flows[i] << " ";
        //}
        //cout << endl;
        //for (int i = 0; i < n; i++) {
        //    cout << test[i] << " ";
        //}
        //cout << endl;
        //cout << check(test, require) << endl << endl;

    }
    return 0;
}
