#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
set<int> neigh[1000];
bool vis[1000];
int count(int root) {
     
    vis[root] = true;
    vector<int> vl;
    for (set<int>::iterator iV = neigh[root].begin(); iV!=neigh[root].end(); iV++) {
       if (!vis[*iV]) {
           vl.push_back(count(*iV));
       }
    }
    vis[root] = false;
    if (vl.size() <= 1) return 1; 
    sort(vl.begin(),vl.end());
    return 1+vl[vl.size()-1]+vl[vl.size()-2];


}
int main() {
    int t;
    cin >> t;
    for (int c = 1; c<= t; c++)  {
        int ans = 100000;
        int n;
        cin >> n;
        for (int i =0; i<n; i++)
           neigh[i].clear();
        for (int i = 1; i<n; i++) {
           int a,b;
           cin >> a >> b;
            a--;b --;
            neigh[a].insert(b);
            neigh[b].insert(a);
        }
        for (int i = 0; i<n; i++) vis[i] = false;
        for (int i= 0 ; i<n; i++) {
           int t = count(i);
           //cout << i+1<<":"<<t<<endl;
           
           if ( n - t < ans) ans = n-t;
        }
        cout << "Case #" << c <<": "<<ans<<endl;
    }

}

