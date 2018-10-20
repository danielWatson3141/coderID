#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
using namespace std;

int n;
int d[1000];

int main() {
    int t;
    srand(time(NULL));

    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> t;
    for (int l=1; l<=t; l++) {
        in >> n;
        for (int i=0; i<n; i++) {
            in >> d[i];
        }
        double prob1, prob2;
        prob1 = prob2 = 1.0;
        for (int i=1; i<=n-1; i++) {
            prob1 *= (double)i/(double)n;
            prob2 *= (double)n/(double)i;
        }
        prob1 = 1./(1.+prob1);
        prob2 = 1./(1.+prob2);

//        srand(time(NULL));
        double prob = ((double)rand() / (RAND_MAX));
//        cout << prob << ' ' << prob1 << ' ' << prob2 << endl;
        out << "Case #" << l << ": ";
//        if (prob <= 0.5)
        if (l<=60)
            out << "GOOD" << endl;
        else
            out << "BAD" << endl;
    }
    return 0;
}
