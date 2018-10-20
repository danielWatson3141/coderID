#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<
using namespace std;

int big(int n, vector< vector<int> > v){

    int x;
    vector<int> u;
    go(a, v.size()){
        if(v[a][0]==n){
            x=v[a][1];
            v.erase(v.begin()+a);
            u.push_back(big(x, v));
            a-=1;
        }
        else if(v[a][1]==n){
            x=v[a][0];
            v.erase(v.begin()+a);
            u.push_back(big(x, v));
            a-=1;
        }

    }
    if(u.size()<2){
        return 1;
    }
    else{
        sort(u.begin(),u.end());
        return u[u.size()-1]+u[u.size()-2]+1;
    }


}

int main()
{
ofstream fout ("output.txt");
    ifstream fin ("input.txt");

    vector< vector<int> > v;
    int n, m, x, y;
    fin >> n;
    go(a,n){
       fin >> m;
       v.resize(0);
       v.resize(m-1);
       go(b,m-1){
            v[b].resize(0);
            v[b].resize(2);
            fin >> x >> y;
            v[b][0]=x;
            v[b][1]=y;
       }
       int k=-1;
       go(b,m){
           x=m-big(b+1, v);
            if(k<0||k>x){
                k=x;
            }
       }
       case(a+1) k << endl;

    }

}




