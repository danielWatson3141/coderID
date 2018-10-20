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

vector<int> vl[1001];
vector<int> pvl[1001];
bool kayty[1001];
int w[1001];
bool poistettu[1001];


void clearvl(){
    for(int i=0; i<=1000; i++)
        vl[i].clear();
}
void clearall(){
    for(int i=0; i<=1000; i++){
        kayty[i]=w[i]=poistettu[i]=0;
        pvl[i].clear();
    }
}

void puu(int n){
    kayty[n]=1;
    for(int a:vl[n])
        if(!kayty[a]){
            pvl[n].push_back(a);
            puu(a);
        }
}

int painot(int n){
    int p=1;
    for(int a: pvl[n]){
        p+=painot(a);
    }
    w[n]=p;
    return p;
}

int etsiminimi(int p){
    int minimi=1000000;
    int nodessa;
    for(int a:pvl[p]){
        if(w[a]<minimi&&!poistettu[a]){
            nodessa=a;
            minimi=w[a];
        }
    }
    return nodessa;
}

int karsi(int n){
    int ret=0;
    int koko=pvl[n].size();
    while(koko!=0&&koko!=2){
        int poista=etsiminimi(n);
        poistettu[poista]=true;
        ret+=w[poista];
        koko--;
    }
    for(int a:pvl[n])
        if(!poistettu[a])
            ret+=karsi(a);
    return ret;
}

int main(){
    int t;
    fin>>t;
    for(int asdasd=0; asdasd<t; asdasd++){
        int N;
        fin>>N;
        for(int i=0; i<N-1; i++){
            int a,b;
            fin>>a>>b;
            vl[a].push_back(b);
            vl[b].push_back(a);
        }
        int v=1000000;
        for(int i=1;i<=N;i++){
            puu(i);
            painot(i);
            int asd=karsi(i);
            v=min(v,asd);
            clearall();
        }
        clearvl();
        fout<<"Case #"<<asdasd+1<<": "<<v<<endl;
    }
    return 0;
}
