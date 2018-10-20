#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    int T; cin >> T;
    vector<pair<int, int>> cases;
    for (int I = 1; I <= T; I++) {
        string good = "GOOD";
        string bad = "BAD";
        int pos_biased = 0;
        int neg_biased = 0;
        int n; cin >> n;
        vector<int> input(n);
        for (int &x : input) cin >> x;
        int magic = n*0.69314718056;
        for (int i = 0; i < input.size(); i++) {
            if (i < magic && i == input[i] - 1) neg_biased++;
            if (i == input[i] + 1) pos_biased++;
        }
        cases.push_back(make_pair(pos_biased - neg_biased, I));
    }
    map<int, string> results;
    sort(cases.begin(), cases.end());
    for (int i = 0; i < cases.size(); i++) {
        if (i < (cases.size() / 2)) {
            results[cases[i].second] = "BAD";
        } else {
            results[cases[i].second] = "GOOD";
        }
    }
    for (int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": " << results[I] << endl;
    }
    return 0;
}

