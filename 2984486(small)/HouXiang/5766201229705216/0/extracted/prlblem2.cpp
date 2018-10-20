// prlblem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std; 

// const int D = 15;
const int D = 1002;

int a[D][D]; 
int du[D]; 
vector<int> bian[D];
int visited[D]; 
int nodes = 0; 

int nodenum(int node) {
    int ans = 1; 
    for (int i=1; i<=nodes; i++) {
        if (a[node][i] == 1) {
            a[node][i] = a[i][node] = 0; 
            ans += nodenum(i);
            a[node][i] = a[i][node] = 1; 
        }
    }

    return ans; 
}

int ans(int node) {
    if (du[node] == 0) return 0;
    if (du[node] < 2) {
        for (int i=1;i<=nodes; i++) {
            if (a[node][i] == 1) {
                a[node][i] = a[i][node] = 0; 

                int ta = nodenum(i);

                a[node][i] = a[i][node] = 1; 
                return ta;
            }
        }
                
    }
    else if (du[node] == 2) {
        int ta = 0; 
        for (int i=1; i<=nodes; i++) {
            if (a[node][i] == 1) {
                du[i]--;
                a[node][i] = a[i][node] = 0; 
                ta += ans(i);
                a[node][i] = a[i][node] = 1; 
                du[i]++;
            }
        }
        return ta; 
    }
    else {
        int ta = 0x7fffffff;
        vector<int> findnodes; 
        for (int i=1; i<=nodes; i++) 
            if (a[node][i] == 1) findnodes.push_back(i);

        for (int i=0; i<findnodes.size(); i++) 
            for (int j=i+1; j<findnodes.size(); j++) {
                    int ind1 = findnodes[i], ind2 = findnodes[j];

                    int tta = 0; 
                    du[ind1]--;
                    a[node][ind1] = a[ind1][node] = 0; 
                    tta += ans(ind1);
                    a[node][ind1] = a[ind1][node] = 1; 
                    du[ind1]++;

                    du[ind2]--;
                    a[node][ind2] = a[ind2][node] = 0; 
                    tta += ans(ind2);
                    a[node][ind2] = a[ind2][node] = 1; 
                    du[ind2]++;

                    for (int k=0; k<findnodes.size(); k++) {
                        if (k != i && k!= j) {
                            a[node][findnodes[k]] = a[findnodes[k]][node] = 0; 
                            tta += nodenum(findnodes[k]);
                            a[node][findnodes[k]] = a[findnodes[k]][node] = 1; 
                        }
                    }

                    ta = ta > tta ? tta : ta; 
            }
        return ta; 
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream inf(argv[1]); 
    // ifstream inf("D:\\codejam\\prlblem2\\Debug\\test.txt"); 

    int n = 0; 
    inf >> n; 
    for (int ca=1; ca<=n; ca++) {
        memset(a, 0, sizeof(a));
        memset(du, 0, sizeof(du));

        for (int i=0; i<D; i++) 
            bian[i].clear();
 
        inf >> nodes; 
        for (int i=1; i<=(nodes-1); i++) {
            int n1, n2; 
            inf >> n1 >> n2;
            a[n1][n2] = a[n2][n1] = 1; 
        }

        for (int i=1; i<=nodes; i++) {
            int d = 0; 
            for (int j=1; j<=nodes; j++) {
                if (a[i][j] == 1) d++;
            }
            du[i] = d; 
        }

        int res = 0x7fffffff;
        for (int i=1; i<=nodes; i++) {
            int t = ans(i);
            res = t < res ? t : res; 
        }

        cout << "Case #" << ca << ": " << res << endl; 
    }

	return 0;
}

