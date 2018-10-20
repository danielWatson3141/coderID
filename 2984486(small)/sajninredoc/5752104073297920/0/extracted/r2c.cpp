#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;


int main(){
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        int N;
        cin >> N;
        vector<int> perm(N);
        for(int i=0;i<N;i++) cin >> perm[i];
        int stat = 0;
        for(int i=0;i<N-1;i++) if(i>perm[i]) stat++;
        if(stat>484){
            cout << "Case #" << t << ": GOOD" << endl;
        }else{
            cout << "Case #" << t << ": BAD" << endl;
        }

    }
    
    return 0;
}