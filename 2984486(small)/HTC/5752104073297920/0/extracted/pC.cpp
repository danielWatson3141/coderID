#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
int a[1005];
int main (){
    int T,N;
    cin >> T;
    for(int ca=1;ca<=T;ca++){
        cout << "Case #" << ca << ": ";
        cin >> N;
        double avg,avg2;
        int sum = 0,sum2=0;
        for(int i=0;i<N;i++){
            cin >> a[i];
            if(a[i] < N/2 && i < N/2)sum2++;
            sum += abs(i-a[i]);
        }
        //cout <<sum<< "\n";
        avg = (double)sum / (double)N;
        avg2 = (double)sum2 / (double)N;
        if(avg < 328 && avg2 > 0.257)cout << "BAD\n";
        else if(rand()%4 == 0 && (avg < 328 || avg2 > 0.257))cout << "BAD\n";
        else cout <<"GOOD\n";
    }
    return 0;
}

