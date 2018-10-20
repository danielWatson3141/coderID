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

map<int,int> req[50];
char ss[200][200],ss1[200][200];
int N,L;
int result;
void search(int index, int swit, int * z)
{
    if (swit>=result) return;
    if (index ==L) {
        if (swit<result) result = swit;
        return;
    }
    int f[200];
    bool ok;
    map<int,int> mm;
    mm= req[index];
    ok = true;
    for (int i=0; i<N; i++) {
        int t = z[i]*2 + (ss[i][index]-'0');
        f[i] = t;
        mm[t] --;
        if (mm[t]<0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        search(index+1, swit,f);
    }
    mm= req[index];
    ok = true;
    for (int i=0; i<N; i++) {
        int t = z[i]*2 + ('1'- ss[i][index]);
        f[i] = t;
        mm[t] --;
        if (mm[t]<0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        search(index+1, swit+1,f);
    }
}

void work() {

    cin>>N>>L;
    for (int i=0; i<50; i++) req[i].clear();
    for (int i=0; i<N; i++) {
        cin>>ss[i];
    }
    for (int i=0; i<N; i++) {
        cin>>ss1[i];
    }
    result = 200;
    int x[200];
    fill(x,x+200,0);
    for (int i=0; i<L; i++) {
        for (int j=0; j<N; j++) {
            int f = ss1[j][i]-'0';
            x[j]*=2;
            x[j]+=f;
            req[i][x[j]]++;
        }
    }
    fill(x,x+200,0);
    search(0,0,x);

    if (result == 200) {
       cout<<"NOT POSSIBLE";
    }
    else cout<<result;
}
