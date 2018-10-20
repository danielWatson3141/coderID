#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

using namespace std;

string XOR(string a, string b){
    string ret;
    for(int i=0;i<a.size();i++)
        if(a[i]==b[i]) ret+='0';
        else ret+='1';
    return ret;
}
bool chk (vector <string> vs1, vector <string> vs2, string x){
    vector <string> temp;
    for(int i=0;i<vs1.size();i++){
        temp.push_back(XOR(vs1[i],x));
        
    }
    sort(vs2.begin(),vs2.end());
    sort(temp.begin(),temp.end());
    return (temp==vs2);
}

bool cmp(string s1, string s2){
    if(count(s1.begin(),s1.end(),'1') < count(s2.begin(),s2.end(),'1') ) return true;
    else return false;
}
int main(int argc, const char * argv[])
{

    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int N, L;
        cin >> N >>L;
        //cout << "N=" << N << endl;
        vector <string> cur, req;
        for(int i=0;i<N;i++){
            string s;
            cin >> s;
            cur.push_back(s);
        }
        for(int i=0;i<N;i++){
            string s;
            cin >> s;
            req.push_back(s);
        }
        
        bool cor = false;
        string x;
        vector <string> cands;
        for(int i=0;i<N;i++){
            x = XOR(cur[0],req[i]);//check that N is at least 1;
            cands.push_back(x);
            
        }
        sort(cands.begin(),cands.end(),cmp);
        for(int i=0;i<N;i++){
            x = cands[i];
            cor = chk(cur,req,x);
            if(cor) break;
            
        }
        if(cor){
            cout << "Case #"<<t+1 <<": " << count(x.begin(),x.end(),'1') << endl;
        }
        else{
            cout << "Case #"<<t+1 <<": " << "NOT POSSIBLE" << endl;
        }
    }
    return 0;
}

