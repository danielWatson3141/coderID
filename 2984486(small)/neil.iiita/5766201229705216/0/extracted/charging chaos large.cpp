#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define frl(a, b, c) for( (a) = (b);( a) < (c); (a++))
#define fru(a, b, c) for( (a) = (b); (a) <= (c); (a++))
#define frd(a, b, c) for( (a) = (b); (a) >= (c); (a--))
#define mst(a, b) memset(a, b, sizeof(a))
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sc(a) scanf("%c", &a)

#define pb(a) push_back(a)
#define mp make_pair
#define nwl puts("");
#define sp << " " <<

#define sz size()
#define bg begin()
#define en end()
#define X first
#define Y second

#define vi vector <int>
#define vs vector <string>
#define ll long long int
#define dec int i = 0, j= 0, k = 0;

#define i(n) cin >> n;
#define p(s) cout << s;
#define pau system("pause");
vector<string> inp;
vector<string> out;
int n, l;
bool match(int pos){
    cout << "here\n";
    int taken[200];
    mst(taken, 0);
    dec;
    frl(i, 0, n){cout << inp[i] << endl;
        bool flag = false;
        frl(j, 0, n){
            if(!taken[j] && inp[i].substr(0, pos+1) == out[j].substr(0, pos+1)){
                taken[j] = 1;
                flag = true;
                cout << i sp j << endl;
                break;
            }
        }
        if(!flag)
            return 0;
    }
    return 1;
}
bool isflip(int pos){
    int taken[200];
    mst(taken, 0);
    dec;
    frl(i, 0, n)
        if(inp[i][pos] == '1')
            inp[i][0] = '0';
        else
            inp[i][0] = '1';
    frl(i, 0, n){
        bool flag = false;
        frl(j, 0, n){
            if(!taken[j] && inp[i].substr(0, pos+1) == out[j].substr(0, pos+1)){
                taken[j] = 1;
                flag = true;
                break;
            }
        }
        if(!flag)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    dec;
    cin >> t;
    string str;
    while(t--){
        inp.clear();
        out.clear();
        cin >> n >> l;
        frl(i, 0, n){
            cin >> str;
            inp.push_back(str);
        }
        frl(i, 0, n){
            cin >> str;
            out.push_back(str);
        }
        int cnt = 0;
        bool flag = true;
        for(i = 0; i < l; i++){
            if(match(i))
                continue;
            else if(isflip(i)){
                cnt++;
            } else {
                flag = false;
                break;
            }
        }
        cout << cnt << endl;
        if(!flag)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << cnt << endl;
    }
}






























