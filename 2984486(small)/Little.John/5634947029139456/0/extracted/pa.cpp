#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;

//#define DEBUG

const char *infile="A-small-attempt1.in";
const char *outfile="pa-small.out";

bool canConvert(string outlet[], const string device[], int n, const bool flip[]) {
    int L = outlet[0].size();
    for (int j=0; j<L; j++) {
        if (flip[j]) {
            for (int i=0; i<n; i++)
                if (outlet[i][j]=='0') outlet[i][j]='1';
                else outlet[i][j]='0';
        }
    }
    
    sort(outlet, outlet+n);
    
#ifdef DEBUG
    cout << "outlet after sort: ";
    for (int i=0; i<n; i++) 
        cout << outlet[i] << ' ';
    cout << endl;
#endif
    
    for (int i=0; i<n; i++)
        if (outlet[i] != device[i]) return false;
    
    return true;
}

int getAns(const string outlet[], const string device[], int n) {
    int L = outlet[0].size();
    int ans=L+1;
    for (int i=0; i<n; i++) {

#ifdef DEBUG
    cout << "now " << i << ":" << endl;
#endif

        int curAns = 0;
        bool flip[L];
        for (int j=0; j<L; j++) 
            flip[j]=false;
        
        for (int j=0; j<L; j++)
            if (outlet[0][j] != device[i][j]) {
                curAns++;
                flip[j]=true;
            }
        
        if (curAns >= ans) continue;
        
        string tmp[n];
        for (int i=0; i<n; i++)
            tmp[i]=outlet[i];
        if (canConvert(tmp, device, n, flip)) {
            ans = curAns;
        }        
    }
    
    return ans;
}

int main() {
    ifstream fin(infile);
    assert(fin);
    ofstream fout(outfile);
    assert(fout);
    
    int test;
    fin >> test;
    
    //cout << "test=" << test << endl;
    
    for (int count=1; count<=test; count++) {
        int n, L;
        fin >> n >> L;
        string outlet[n], device[n];
        for (int i=0; i<n; i++) 
            fin >> outlet[i];
        for (int i=0; i<n; i++) 
            fin >> device[i];
        
        sort(device, device+n);
    
    #ifdef DEBUG
        cout << "outlet: ";
        for (int i=0; i<n; i++) cout << outlet[i] << ' ';
        cout << endl;
        cout << "device (after sort): ";
        for (int i=0; i<n; i++) cout << device[i] << ' ';
        cout << endl;
    #endif
        
        fout << "Case #" << count << ": ";
        int ans=getAns(outlet, device, n);
        if (ans<=L) fout << ans << endl;
        else fout << "NOT POSSIBLE" << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}
