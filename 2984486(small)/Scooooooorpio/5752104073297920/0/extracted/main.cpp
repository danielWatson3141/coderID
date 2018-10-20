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
void rr1(int n) {
    int z[1000];
    for (int i=0; i<n; i++) z[i] = i;
    for (int i=0; i<n; i++) {
        int f = rand() % (n-i);
        swap(z[i],z[i+f]);
    }
    int r =0;
    for (int i=0; i<n; i++) if (z[i] >i) r++;
    cerr<<r<<endl;
}
void rr2(int n) {
    int z[1000];
    for (int i=0; i<n; i++) z[i] = i;
    for (int i=0; i<n; i++) {
        int f = rand() % n;
        swap(z[i],z[f]);
    }
    int r =0;
    for (int i=0; i<n; i++) if (z[i] >i) r++;
    cerr<<r<<endl;
}

void prework()
{
    for (int i=0; i<1000; i++) {
//        rr2(1000);
    }
}

void work() {
    int n;
    cin >>n;
    int t = 0;
    for (int i=0; i<n ;i++) {
        int x ;
        cin >>x;
        if (x>i) t++;
    }
    if (t>=511) cout<<"BAD";
    else cout<<"GOOD";
}
