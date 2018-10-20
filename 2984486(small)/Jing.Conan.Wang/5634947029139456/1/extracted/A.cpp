
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef long long INT;
typedef vector<INT> IntVec;
typedef vector<IntVec> Mat;


int solRecur(vector<string> A, vector<string> B, int k) {
    int N = A.size();
    int L = A[0].size();
    if (k > L) {
        return 0;
    }
    bool f = true;
    for (int i = 0; i < N; ++i) {
        if (A[i][k] != B[i][k]) {
            f = false;
            break;
        }
    }
    int num = INT_MAX/2;
    if (f) {
        // int e = solRecur(A, B, k+1);
        // if (e >= 0) {
            // return e;
        // }
        num = min(num, solRecur(A, B, k+1));
    }

    // flip
    for (int i = 0; i < N; ++i) {
        A[i][k] = (1 - (A[i][k] - '0')) + '0';
    }
    sort(A.begin(), A.end());

    bool f2 = true;
    for (int i = 0; i < N; ++i) {
        if (A[i][k] != B[i][k]) {
            f2 = false;
            break;
        }
    }
    if (f2) {
        num = min(num, solRecur(A, B, k+1) + 1);
    }
    return num;

}

string sol(vector<string> A, vector<string> B) {
    int N = A.size();
    int L = A[0].size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int res = solRecur(A, B, 0);

    // for (auto v : A) cout << v << " "; 
    // cout << endl; 
    // for (auto v : B) cout << v << " "; 
    // cout << endl; 

    // int res = 0;
    // for (int k = 0; k < L; ++k) {
    //     bool f = true;
    //     for (int i = 0; i < N; ++i) {
    //         if (A[i][k] != B[i][k]) {
    //             f = false;
    //             break;
    //         }
    //     }

    //     if (f) continue;

        // flip
        // for (int i = 0; i < N; ++i) {
        //     A[i][k] = (1 - (A[i][k] - '0')) + '0';
        // }
        // sort(A.begin(), A.end());
        // bool f2 = true;
        // for (int i = 0; i < N; ++i) {
        //     if (A[i][k] != B[i][k]) {
        //         f2 = false;
        //         break;
        //     }
        // }
        // if (f2)  res += 1;
        // else return "NOT POSSIBLE";

    // }
    if (res < INT_MAX/2) {
        ostringstream convert;
        convert << res;
        return convert.str();
    }
    return "NOT POSSIBLE";

}

int main(int argc, char *argv[]) {
    // ifstream inFile("A.tiny");
    // ifstream inFile("A-small-attempt2.in");
    ifstream inFile("A-large.in");
    // ofstream outFile("A-small-attempt2.out");
    ofstream outFile("A-large.out");
    istream &in = inFile;
    ostream &out = outFile;
    // istream &in = cin;
    // ostream &out = cout;
    int T;
    in >> T;
    for (int i = 0; i < T; ++i) {
        int N, L;
        in >> N >> L;
        vector<string> bits;
        for (int j = 0; j < N; ++j) {
            string tmp;
            in >> tmp;
            bits.push_back(tmp);
        }
        // for (auto v : bits) cout << v << " "; 
        // cout << endl; 


        vector<string> dBits;
        for (int j = 0; j < N; ++j) {
            string tmp;
            in >> tmp;
            dBits.push_back(tmp);
        }
        // for (auto v : dBits) cout << v << " "; 
        // cout << endl; 
        out << "Case #" << i+1 << ": " << sol(bits, dBits) << endl;

    }
    return 0;
}

