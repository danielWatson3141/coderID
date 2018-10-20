#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool match(vector<string> flows, vector<string> devices)
{
    sort(flows.begin(), flows.end());
    sort(devices.begin(), devices.end());
    for (int i = 0; i < flows.size(); ++i) {
        if (flows[i] != devices[i]) {
            return false;
        }
    }
    return true;
}

bool turn_switch(int& min_turn, int turns, int bit, int length, vector<string> flows, const vector<string>& devices)
{
    if (bit == length) {
        if (match(flows, devices)) {
            if (min_turn > turns) {
                min_turn = turns;
            }
            return true;
        } else {
            return false;
        }
    } else {
        if (match(flows, devices)) {
            if (min_turn > turns) {
                min_turn = turns;
            }
            return true;
        }
        bool able1 = turn_switch(min_turn, turns, bit + 1, length, flows, devices);
        // turn the switch at bit
        for (auto it = flows.begin(); it != flows.end(); ++it) {
            if ((*it)[bit] == '0') {
                (*it)[bit] = '1';
            } else {
                (*it)[bit] = '0';
            }
        }
        bool able2 = turn_switch(min_turn, ++turns, bit + 1, length, flows, devices);
        return able1 || able2;
    }
}

int main()
{
    int T, N, L;
    string flow;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> L;
        vector<string> flows, devices;
        for (int j = 0; j < N; ++j) {
            cin >> flow;
            flows.push_back(flow);
        }
        for (int j = 0; j < N; ++j) {
            cin >> flow;
            devices.push_back(flow);
        }
        int min_turns = L + 1;
        bool able = turn_switch(min_turns, 0, 0, L, flows, devices);
        cout << "Case #" << i + 1 << ": ";
        if (!able) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << min_turns << endl;
        }
    }
    return 0;
}

