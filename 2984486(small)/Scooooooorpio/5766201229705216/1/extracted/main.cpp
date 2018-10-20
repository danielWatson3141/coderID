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
#include <ctime>
#include <cstring>
#include <cassert>
using namespace std;

void prework();
void work();

int main(int argc, char *argv[])
{
#if 1
auto t1 = freopen("1.in","r",stdin);
if (t1== nullptr) {
    cerr <<"no file"<<endl;
    return 0;
}
auto t2 = freopen("output.txt","w",stdout);
#endif

    prework();

    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Case #"<<i+1<<": ";
        work();
        cout<<endl;
        cerr<<"Case #"<<i+1<<"  over"<<endl;
    }

    cerr<<"end!!!!!!!!!!"<<endl;

}

void prework() {
}

int N;
vector<int> edges[1100];
int  z[1100][1100];
int  tot[1100][1100];
int gettot(int root, int now)
{
    if (tot[root][now] != -1) return tot[root][now];
    int r = 1;
    for (int i=0; i<edges[now].size(); i++) {
        int son = edges[now][i];
        if (son == root) continue;
        r += gettot(now,son);
    }
    return tot[root][now] = r;
}

int get(int root, int now)
{
    if (z[root][now]!=-1) return z[root][now];
    int result;
    result = gettot(root, now) -1;
    int all = edges[now].size();
    if (root!=0) all--;
    if (all<=1) return z[root][now] = result;
    int t0 = 0;
    int t1 = 3000;
    int t2 = 3000;
    for (int i=0; i<edges[now].size(); i++) {
        int son = edges[now][i];
        if (son == root) continue;
        int f = gettot(now,son);
        int f1 = get(now,son);
        t2 += f;
        if ( t1+f1 <t2) t2 = t1+f1;
        t1 += f;
        if (t0+f1<t1) t1 = t0+f1;
        t0 += f;
    }
    return z[root][now] = t2;
}

void work() {
    cin >>N;
    fill(edges,edges+1100, vector<int>());
    for (int i=1; i<N; i++) {
        int a,b;
        cin >>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    memset(z,-1,sizeof(z));
    memset(tot,-1,sizeof(tot));

    int result = N-1;
    for (int i=1; i<=N; i++) {
        int a = get(0,i);
        if (a<result) result = a;
    }
    cout<<result;
}
