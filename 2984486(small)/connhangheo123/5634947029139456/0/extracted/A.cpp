#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <complex>
#include <queue>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define sr(x) (int)x.size()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; For(_,a,b) cout << x[_] << ' '; cout << endl;}
#define Bit(s,i) ((s&(1<<i))>0)
#define Two(x) (1<<x)
const int modul = 1000000007;
const int nmax = 200;
const double e = 1e-8;
const double pi = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;
int N,L,stest;
string a[nmax];
string b[nmax];
string flip(string a,string b) {
    string k = "";
    For(i,0,L-1) {
        if (a[i]!=b[i]) k +='1';
        else k+='0';
    }
    return k;
}
int Cal(string k) {
    int cal=0;
    For(i,0,L-1) cal+=(k[i]=='1');
    return cal;
}
bool check(string k) {
    For(i,1,N) {
        string s = flip(a[i],k);
        int Find = false;
        For(j,1,N) if (s==b[j]) {
            Find=true;
            break;
        }
        if (Find==false) return false;
    }
    return true;
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("outputA.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin >> stest;
    For(test,1,stest) {
        cin >> N >> L;
        For(i,1,N) cin >> a[i];
        For(i,1,N) cin >> b[i];
        int res = modul;
        For(j,1,N) {
            string k = flip(a[1],b[j]);
            if (check(k)) {
                //BUG(k);
                res = min(res,Cal(k));
            }
        }
        if (res==modul) cout << "Case #" << test << ": NOT POSSIBLE" << endl;
        else cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}




