#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
/*
map<vector<int> ,int> memo;


void bad_permut(int N)
{
    vector<int> v(N);
    for(int c=0;c<N;c++) v[c]=c;
    for(int c=0;c<N;c++) {int z = rand()%N;swap(v[c],v[z]);}
    //for(int c=0;c<N;c++) cout<<v[c]<<" ";
    //cout<<endl;
    memo[v]++;
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
#define cin in
#define cout out
    ifstream in("input.txt");
    ofstream out("output.txt");
    int nb_cas;
    cin>>nb_cas;
    for(int cas=0;cas<nb_cas;cas++)
    {
        cout<<"Case #"<<cas+1<<": ";
        int N;
        cin>>N;
        vector<int> v(N);
        double weight = 1.0/2.0;
        double act = 0;
        double moitie = static_cast<double>(N)/2.0;
        for(int c=0;c<N;c++) {cin>>v[c]; double tmp = rand()%2; if(v[c] > moitie) act += weight * tmp; else act -= weight* tmp;  weight/=2;}
       // cout<<act<<endl;
        if(act > 0) cout<<"GOOD"<<endl;
        else cout<<"BAD"<<endl;
    }

}
