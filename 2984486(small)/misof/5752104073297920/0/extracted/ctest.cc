#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;
const double pp = 1./N;

vector< vector<double> > P(N, vector<double>(N)); // kde, co

void computeP() {
    for (int n=0; n<N; ++n) P[n][n] = 1.;
    for (int k=0; k<N; ++k) {
        vector< vector<double> > NP(N, vector<double>(N,0.0));
        for (int q=0; q<N; ++q) if (q!=k) {
            for (int i=0; i<N; ++i) NP[q][i] += (1-pp)*P[q][i];
            for (int i=0; i<N; ++i) NP[q][i] += pp*P[k][i];
            for (int i=0; i<N; ++i) NP[k][i] += pp*P[q][i];
        }
        for (int i=0; i<N; ++i) NP[k][i] += pp*P[k][i];
        /*
        double sum = 0.;
        for (int q=0; q<N; ++q) for (int i=0; i<N; ++i) sum += NP[q][i];
        cout << sum << endl;
        */
        P = NP; // lol, cool :D
    }
}

int main() {
    computeP();
    int T; cin >> T;
    for (int t=1; t<=T; ++t) {
        int NN; cin >> NN;
        vector<int> A(N);
        for (int n=0; n<N; ++n) cin >> A[n];
        double llgood=0, llbad=0;
        for (int n=0; n<N; ++n) llgood += log( pp );
        for (int n=0; n<N; ++n) llbad  += log( P[n][A[n]] );
        cout << "Case #" << t << ": " << (llgood > llbad ? "GOOD" : "BAD") << "\n";
    }
}
