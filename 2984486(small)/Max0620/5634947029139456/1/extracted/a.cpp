#include <iostream>
#include <map>

using namespace std;

map<long long, int> store;
map<long long, int> s2;

string input[2][160];
void process() {
    int n,l;
    cin>>n>>l;
    store.clear();
    s2.clear();
    
    int  i,j,k;
    for(i=0;i<n;i++){
        cin>>input[0][i];
    }
    for(i=0;i<n;i++) {
        cin>>input[1][i];
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            long long t = 0;
            int nc = 0;
            for(k=0;k<l;k++) {
                
                if (input[0][i][k] == input[1][j][k]) {
                    t = t*2;
                    
                } else {
                    t = t*2 + 1;
                    nc++;
                }
            }
            store[t]++;
            s2[t] = nc;
        }
    }
    
    int ret = 100;
    for (map<long long,int>::iterator it=store.begin(); it!=store.end(); ++it) {
        if (it->second == n && s2[it->first] < ret) {
            ret = s2[it->first];
        }
    }
    if (ret == 100) {
        cout<<"NOT POSSIBLE";
    } else {
        cout<<ret;
    }
    
    
}

int main() {
    int t,i;
    cin>>t;
    for(i=0;i<t;i++) {
        cout<<"Case #" <<(i+1)<<": ";
        process();
        cout<<endl;
    }
    return 0;
}