#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;

const char *infile="B-small-attempt0.in";
const char *outfile="pb-small.out";

//int n;

void getnum(int x, int fa, int num[], const vector<int> adj[], int n) {
    num[x]=1;
    for (int i=0; i<adj[x].size(); i++) {
        int y=adj[x][i];
        if (y != fa) {
            getnum(y, x, num, adj, n);
            num[x] += num[y];
        }
    }
}

void getDel(int x, int fa, int del[], const int num[], const vector<int> adj[], int n) {
    del[x]=num[x]-1;
    for (int i=0; i<adj[x].size(); i++) {
        int y=adj[x][i];
        if (y != fa) {
            getDel(y, x, del, num, adj, n);
        }
    }
    
    for (int i=0; i<adj[x].size(); i++) {
        int y1=adj[x][i];
        if (y1 != fa) {
            for (int j=i+1; j<adj[x].size(); j++) {
                int y2=adj[x][j];
                if (y2 != fa) {
                    int ans1 = num[x]-1-num[y1]-num[y2]+del[y1]+del[y2];
                    del[x] = min(del[x], ans1);
                }
            }
        }
    }
}

int getAns(const vector<int> adj[], int n) {
    int ans=n;
    int num[n];
    int del[n];
    for (int root=0; root<n; root++) {
        for (int i=0; i<n; i++) num[i]=0;
        getnum(root, -1, num, adj, n);
        
        for (int i=0; i<n; i++) del[i]=n;
        
        getDel(root, -1, del, num, adj, n);
        
        if (del[root] < ans) ans = del[root];
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
    for (int count=1; count<=test; count++) {
        int n;
        fin >> n;
        vector<int> adj[n];
        for (int i=1; i<=n-1; i++) {
            int x, y;
            fin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        int ans=getAns(adj, n);
        fout << "Case #" << count << ": " << ans << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
