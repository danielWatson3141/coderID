//#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream cin("A-large.in");
ofstream cout("A-large.out");

int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
       cout << "Case #" << t+1 << ": ";
       int N,L;
       cin >> N >> L;
       int orig[150][40];
       int dest[150][40];
       int temp[150][40];
       for (int i=0; i<N; i++) {
            string s;
            cin >> s;
            for (int j=0; j<L; j++) {
                if (s[j] == '0') orig[i][j] = 0; 
                if (s[j] == '1') orig[i][j] = 1;
            }
       }
       for (int i=0; i<N; i++) {
            string s;
            cin >> s;
            for (int j=0; j<L; j++) {
                if (s[j] == '0') dest[i][j] = 0; 
                if (s[j] == '1') dest[i][j] = 1;
            }
       }
       int mindiff = 60;
       for (int r=0; r<N; r++) {
           int ndiff = 0;
         for (int i=0; i<N; i++) {
            for (int j=0; j<L; j++) {
                  temp[i][j] = orig[i][j];
            }
         }
         for (int j=0; j<L; j++) {
            if (dest[0][j] != orig[r][j]) { ndiff++;
                for (int k=0; k<N; k++) {
                    temp[k][j] = 1-temp[k][j];
                }
            }
         }
         if (ndiff >= mindiff) continue;
         int tag[150]; for (int i=0; i<N; i++) tag[i] = 1; int ntot = 1;
         tag[r] = 0;
         for (int i=1; i<N; i++) {
         for (int k=0; k<N; k++) {
            if (tag[k]) {
                bool iseq = true;
                for (int l=0; l<L; l++) {
                    if (dest[i][l] != temp[k][l]) {
                       iseq = false; break; 
                    }
                }
                if (iseq) { ntot++; tag[k] = 0; break; }
            }
         }
         }
        if (ntot == N) { mindiff = ndiff; }
       }
       if (mindiff == 60) cout << "NOT POSSIBLE" << endl; else cout << mindiff << endl;
    }
return 0;
}
