#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

string run_once(ifstream& fin) {
    int N; fin >> N;
    int t;
    for (int i=0; i<N; i++) fin >> t;
    if (rand() % 2 == 0) return "BAD";
    return "GOOD";
}

int main() {
    ifstream fin("C-small-attempt0.in");
    ofstream fout("C-small.out");
    srand (time(NULL));
    int N;
    fin >> N;
    for (int i=0; i<N; i++) {
        fout << "Case #" << i+1 << ": ";
        fout << run_once(fin);
        fout << endl;
    }
    return 0;
}
