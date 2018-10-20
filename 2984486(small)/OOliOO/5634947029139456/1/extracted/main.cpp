#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#define ll long long
#define life false

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

void flip(vector<string>& muisti, int n){
    for(string &s:muisti){
        if(s[n]=='1')
            s[n]='0';
        else
            s[n]='1';
    }
}

int main(){
    int t;
    fin>>t;
    for(int asdasd=0; asdasd<t; asdasd++){
        int N,L;
        fin>>N>>L;
        string muisti[N];
        unordered_set<string> laitteet;
        for(int i=0; i<N; i++)
            fin>>muisti[i];
        for(int i=0; i<N; i++){
            string a;
            fin>>a;
            laitteet.insert(a);
        }
        int minv=1000000;
        string tarkastin=*laitteet.begin();
        for(int i=0; i<N; i++){
            vector<string> m;
            int v=0;
            for(int a=0; a<N; a++)
                m.push_back(muisti[a]);

            for(int sij=0; sij<L; sij++)
                if(m[i][sij]!=tarkastin[sij]){
                    v++;
                    flip(m,sij);
                }
            for(string s:m)
                if(!laitteet.count(s))
                    goto havio;
            minv=min(minv,v);

            havio:;
        }
        fout<<"Case #"<<asdasd+1<<": ";
        if(minv==1000000)
            fout<<"NOT POSSIBLE"<<endl;
        else
            fout<<minv<<endl;

    }
    return 0;
}
