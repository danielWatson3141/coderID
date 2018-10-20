#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>

// STL
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

#define SIZE 1000

int N, L;
bitset<40> state[SIZE];
bitset<40> aim[SIZE];
list<int> branch;

bool eq() {
    map<ul, int> mp;
    int l;
    for (int i = 0; i < N; ++i) {
        l = state[i].to_ullong();
        mp[l] = mp[l] + 1;
        l = aim[i].to_ullong();
        mp[l] = mp[l] - 1;
    }

    for (map<ul,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
        if (it -> second != 0) return false;

    //cout << "eq!" << endl;
    return true;
}

void flip(int idx) {
    for (int i = 0; i < N; ++i) {
        state[i].flip(idx);
    }
}

int count(int idx) {
    int c = 0, a = 0;
    for (int i = 0; i < N; ++i) {
        if (state[i][idx]) ++c;
        if (aim[i][idx]) ++a;
        //cout << state[i] << " " << aim[i] << endl;
    }

    //cout << idx << " " << a << " " << c << endl;

    if (a == c && N-a == c) return 0;
    if (a == c) return 1;
    if (N-a == c) return 2;

    return -1;
}

int solve(int i) {
    if (i >= L)
        return 0;

    int v = count(i);
    if (v == 1) return solve(i+1);
    if (v == 2) {
        flip(i);
        v = solve(i+1);
        if (v == -1) return -1;
        return 1+v;
    }
    if (v == 0) {
        branch.push_back(i);
        return solve(i+1);
    }

    return -1;
}

int brn() {
    if (branch.empty()) {
        if (eq()) return 0;
        else return -1;
    }

    int i = branch.front();
    branch.pop_front();

    int s = brn();
    if (s == 0) {
        branch.push_front(i);   
        return 0;
    }

    flip(i);
    int v = brn();

    flip(i);
    branch.push_front(i);   

    if (v == -1) return s;
    ++v;
    
    if (s == -1) return v;

    return s < v ? s:v;
}


int main() {
    int numcase;

    freopen("A-small-attempt4.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        branch.clear();
        cin >> N >> L;
        for  (int j = 0; j < N; ++j) {
            cin >> state[j];
        }
        for  (int j = 0; j < N; ++j) {
            cin >> aim[j];
        }
        /*for  (int j = 0; j < N; ++j) {
            cout << state[j]<<endl;
            cout << aim[j]<<endl;
        }*/

        int s = solve(0); // min flip
        // cout << s << endl;
        if (s == -1) {
            cout << "Case #" << i + 1 << ": " << "NOT POSSIBLE" << endl;
        } else {
            int c = brn();
            if (c == -1)
                cout << "Case #" << i + 1 << ": " << "NOT POSSIBLE" << endl;
            else
                cout << "Case #" << i + 1 << ": " << s+c << endl;
        }
    }

    return 0;
}
