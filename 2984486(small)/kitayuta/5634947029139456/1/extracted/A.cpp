#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string xor_str(string a,string b){
    string ret;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) ret+='1';
        else ret+='0';
    }
    return ret;
}
int count(string a){
    int cnt=0;
    for(char c:a) if(c=='1') cnt++;
    return cnt;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ix=1;ix<=T;ix++){
        printf("Case #%d: ",ix);
        int N,L;
        scanf("%d%d",&N,&L);
        vector<string> os(N),ds(N);
        string ins;
        for(int i=0;i<N;i++) cin>>os[i];
        for(int i=0;i<N;i++) cin>>ds[i];
        sort(begin(ds),end(ds));
        int mi=100;
        for(int i=0;i<N;i++){
            string cha=xor_str(os[i],ds[0]);
            vector<string> nos(os);
            for(int i=0;i<N;i++){
                nos[i]=xor_str(cha,os[i]);
            }
            sort(begin(nos),end(nos));
            if(nos==ds){
                mi=min(mi,count(cha));
            }
        }
        if(mi==100) printf("NOT POSSIBLE");
        else printf("%d",mi);
        printf("\n");
    }
}
