#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int minNum=-1;
bool invalidCheck(vector<string>& outlet, vector<string>& flow, const int till) {
    int N=outlet.size();
    vector<string> left, right;
    for (int i=0;i<N;++i) {
        string s1, s2;
        for (int j=0;j<till;j++) {
            s1.push_back(outlet[i][j]); 
            s2.push_back(flow[i][j]);
        }
        left.push_back(s1);
        right.push_back(s2);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for (int i=0;i<N;++i) {
        if (left[i]!=right[i]) {
            return false;
        }
    }
    return true;
}
void dfs(int level, int L, int num,
        vector<string>& outlet, vector<string>& flow) {
    if (minNum>=0 && num>=minNum) {
        return;
    }
    int N=outlet.size();
    if (level==L) {
        vector<string> tmp;
        for (int i=0;i<N;++i) {
            tmp.push_back(outlet[i]);
        }
        sort(tmp.begin(), tmp.end());
        for (int i=0;i<N;++i) {
            if (tmp[i]!=flow[i]) {
                return;
            }
        }
        if (minNum==-1) {
            minNum=num;
        } else {
            minNum=min(minNum, num);
        }
        return;
    }
    if (level%10==0 && level>0) {
        if (!invalidCheck(outlet, flow, level)) {
            return;
        }
    }
    for (int i=0;i<outlet.size();++i) {
        outlet[i][level]=(outlet[i][level]=='1')?'0':'1';
    }
    dfs(level+1, L, num+1, outlet, flow);
    for (int i=0;i<outlet.size();++i) {
        outlet[i][level]=(outlet[i][level]=='1')?'0':'1';
    }
    dfs(level+1, L, num, outlet, flow);
}
int solve(const int N, const int L,
        vector<string>& outlet, vector<string>& flow) {
    minNum=-1;
    sort(flow.begin(), flow.end());
    dfs(0,L,0,outlet,flow);
    return minNum;
}
int main(int argc, char* argv[]) {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int N,L;
        cin>>N>>L;
        vector<string> outlet;
        vector<string> flow;
        for (int i=0;i<N;++i) {
            string s;
            cin>>s;
            outlet.push_back(s);
        }
        for (int i=0;i<N;++i) {
            string s;
            cin>>s;
            flow.push_back(s);
        }
        int ans=solve(N,L,outlet,flow);
        if (ans>=0) {
            cout<<"Case #"<<t<<": "<<ans<<endl;
        } else {
            cout<<"Case #"<<t<<": "<<"NOT POSSIBLE"<<endl;
        }
    }
    return 0;
}
