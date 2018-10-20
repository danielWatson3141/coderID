#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))
set<int> neighs[1001];
int N;
int M[1001][1001];
int MM[1001][1001];

int tree_size(int root, int parent){
    int &sol = MM[root][parent];
    if(sol!=-1){
        return sol;
    }
    int total=1;
    for(set<int>::iterator it = neighs[root].begin(); it!=neighs[root].end();++it){
        if(*it == parent){
            continue;
        }
        total+=tree_size(*it, root);
    }
    return sol = total;
}

int needed(int root, int parent){
    int &sol = M[root][parent];
    if(sol!=-1){
        return sol;
    }
    vector<int> subs;
    vector<int> sizes;
    vector<int> diffs;
    int total_subs=0;
    int total_sizes=0;
    for(set<int>::iterator it = neighs[root].begin(); it!=neighs[root].end();++it){
        if(*it == parent){
            continue;
        }
        int sub = needed(*it, root);
        int sz = tree_size(*it, root);
        subs.push_back(sub);
        sizes.push_back(sz);
        total_subs += sub;
        total_sizes += sz;
        diffs.push_back(sz-sub);
    }
    if(subs.size()==0){
        return sol = 0;
    }else if(subs.size()==1){
        return sol = sizes[0];
    }else if(subs.size()==2){
        return sol = subs[0]+subs[1];
    }
    sort(diffs.rbegin(), diffs.rend());
    return sol = total_sizes-(diffs[0]+diffs[1]);
}

int main(int argc, char *argv[]){
    int T;
    cin >> T;
    for(int c=1;c<=T;++c){
        cin>>N;
        for(int i=1;i<=N;++i){
            neighs[i].clear();
        }
        for(int i=0;i<N-1;++i){
            int x, y;
            cin>>x>>y;
            x;
            y;
            neighs[x].insert(y);
            neighs[y].insert(x);
        }
        memset(M, -1,sizeof(M));
        memset(MM, -1,sizeof(MM));

        int best=N-1;
        for(int i=1;i<=N;++i){
            int opt = needed(i, 0);
            if(opt<best){
                best = opt;
            }
        }
        cout<<"Case #"<<c<<": "<<best<<endl;
    }
	return 0;
}
