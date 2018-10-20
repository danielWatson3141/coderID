#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

int run_once(ifstream &fin) {
    int N, L;
    map <long long, int> M;
    fin >> N >> L;
    vector <long long> v1;
    for (int i=0; i<N; i++) {
        long long t = 0;
        for (int j=0; j<L; j++) {
            char c;
            fin >> c;
            t = t << 1;
            if (c == '1') t |= 1;
        }
        v1.push_back(t);
    }
    vector <long long> v2;
    for (int i=0; i<N; i++) {
        long long t = 0;
        for (int j=0; j<L; j++) {
            char c;
            fin >> c;
            t = t << 1;
            if (c == '1') t |= 1;
        }
        v2.push_back(t);
    }
    vector <int> opts;
    for (int i=0; i<L+1; i++) {
        opts.push_back(0);
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            long long t = v1[i] ^ v2[j];
            if (M.count(t)) M[t]++;
            else M[t] = 1;
        }
    }
    int mn = 10000;
    for (auto i = M.begin(); i != M.end(); i++) {
        if (i->second == N) {
            int cnt = 0;
            long long t = i->first;
            while (t != 0) {
                if ((t & 1LL) == 1LL) cnt++;
                t = t >> 1;
            }
            mn = min(mn, cnt);
        }
    }
    return mn;
}

int main() {
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small.out");
    int N;
    fin >> N;
    for (int i=0; i<N; i++) {
        fout << "Case #" << i+1 << ": ";
        int t = run_once(fin);
        if (t == 10000) fout << "NOT POSSIBLE";
        else fout << t;
        fout << endl;
    }
    return 0;
}
