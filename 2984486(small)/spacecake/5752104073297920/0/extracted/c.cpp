#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <random>

using namespace std;

default_random_engine generator(time(0));

void readData(int& n,vector<int>& p,istream& cin) {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {  
        cin >> p[i];
    }
}

inline int nextInt(uniform_int_distribution<int>& u) {
    return u(generator);
}

vector<int> good(int n = 1000) {
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
   
    for (int k = 0; k < n; k++) {
        uniform_int_distribution<int> distribution(k ,n - 1);
        swap(p[k], p[nextInt(distribution)]);
    }
    return p;
}

vector<int> bad(int n = 1000) {
    vector<int> p(n);
    uniform_int_distribution<int> distribution(0,n - 1);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    
    for (int k = 0; k < n; k++) {
        swap(p[k], p[nextInt(distribution)]);
    }

    return p;
}

int inversions(vector<int>& p) {
    int ret = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        for (int j = i + 1; j < (int)p.size(); j++) {
            ret += (p[i] > p[j]);
        }
    }

    return ret;
}

void print(vector<int>& v,ostream& cout) {
    for (auto& x : v) cout << x << " "; cout << "\n";
}


void go(ostream& cout) {
    double avg1 = 0.0;
    double avg2 = 0.0;
    int t = 1000;
    for (int i = 1; i <= t; i++) {
        vector<int> v = good(1000);
        avg1 += inversions(v);
        v = bad(1000);
        avg2 += inversions(v);
    }

    avg1 /= t;
    avg2 /= t;
    cout.precision(6);
    cout << fixed << avg1 << "\n" << avg2 << "\n";
    
}

string solve(vector<int>& p) {
    int num = inversions(p);
    if (num > 246500) return "GOOD";
    return "BAD";
}


int main() {
    ifstream cin("test.in");
    ofstream cout("test.out"); 
    int testCount;
    cin >> testCount;
    int g = 0;
    for (int testCase = 1; testCase <= testCount; testCase++) {
               int n;
        vector<int> p;
        readData(n, p, cin);
      //  g += solve(p) == "GOOD";
        cout << "Case #" << testCase << ": " << solve(p) << "\n";
    }   
   // cout << g << "\n";
    return 0;
}
