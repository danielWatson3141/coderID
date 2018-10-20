#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;


string flip(string s1, string s2, int L){
    string ret(L, '1');
    for(int i=0;i<L;i++) if(s1[i]==s2[i]) ret[i]='0';
    
    return ret;
}

int wt(string s){
    int cnt = 0;
    for(int i=0;i<s.length();i++) if(s[i]=='1') cnt++;
    return cnt;
}

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N, L;
        cin >> N >> L;
        
        int minsw = L+1;
        vector<string> outlets(N);
        set<string> devices;
        
        
        for(int i=0;i<N;i++) cin >> outlets[i];
        string curdevice;
        for(int i=0;i<N;i++){
            cin >> curdevice;
            devices.insert(curdevice);
        }
        
        for(int i=0;i<N;i++){
            string fstr = flip(outlets[i], curdevice, L);
            int cursw = wt(fstr);
            bool good = true;
            for(int j=0;j<N;j++){
                if(devices.count(flip(outlets[j], fstr, L))==0) good=false;
            }
            if(good){
                if(cursw<minsw) minsw = cursw;
            }
        }
        if(minsw<=L){
            cout << "Case #" << t << ": " << minsw << endl;
        }else{
            cout << "Case #" << t << ": NOT POSSIBLE" << endl;
        }
    }
    
    return 0;
}