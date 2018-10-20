#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 


#define PI acos(-1)
#define CLEAR(A) memset(A,0,sizeof(A))
#define SETMAX(A) memset(A,0x7f,sizeof(A))
#define SETM1(A) memset(A,-1,sizeof(A))
#define SQ(A) (A)*(A)


int calc(int node, int parent, vector<int> *edges) {
    int numChildren = -10;

    if(parent == -1) numChildren = edges[node].size();
    else numChildren = edges[node].size()-1;
    if(numChildren <= 1) return 1;
    vector<int> nodeCount;
    for(int i=0;i<edges[node].size();i++) {
        if(edges[node][i] != parent) {
            int ret = calc(edges[node][i], node, edges);
            nodeCount.push_back(ret);
        }
    }
    sort(nodeCount.begin(), nodeCount.end());
    return 1+nodeCount[nodeCount.size()-1] + nodeCount[nodeCount.size()-2];
}

int f(int n, vector<int> * edges) {

    int maxi = 0;
    for(int root=1;root<=n;root++) {
        maxi = max(maxi, calc(root, -1, edges));
    }
    
    return n-maxi;
}


int main()
{
    cout << setprecision(12) ;
    int T;
    cin >> T;
    for(int caseno=0;caseno<T;caseno++) {
        int N;
        cin >> N;
        vector<int> edges[1002];
        for(int i=0;i<N-1;i++) {    
            int A, B;
            cin >> A >> B;
            edges[A].push_back(B);
            edges[B].push_back(A);
        }
        cout << "Case #" << 1+caseno << ": " << f(N, edges) << endl;
    }
    return 0;
}
