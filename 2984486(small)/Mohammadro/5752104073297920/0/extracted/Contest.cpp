#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define xx first
#define yy second
#define ll long long
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
using namespace std;
int t,n;
int main(){
    ifstream cin("ans.in");
    ofstream cout("ans.out");
    srand(time(NULL));
    cin>>t;
    for(int l=1;l<=t;l++){
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
        }
        int sum=0;
        for(int i=1;i<=10000000;i++)sum+=i;
        int ran=rand()%2;
        cout<<"Case #"<<l<<": ";
        if(ran==1){
            cout<<"GOOD";
        }
        else{
            cout<<"BAD";
        }
        cout<<endl;
    }
}
