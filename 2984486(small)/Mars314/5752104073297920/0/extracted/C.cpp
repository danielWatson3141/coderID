#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <time.h>
using namespace std;
const int N = 1005;
int n;
int ans(){
    if(rand()%2==1)cout <<"GOOD" << endl;
    else cout <<"BAD" << endl;
}
int main(){
    srand(time(0));
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
    printf("Case #%d: ",t);
    ans();
    }
}
