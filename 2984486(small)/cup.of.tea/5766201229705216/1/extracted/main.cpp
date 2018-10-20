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

map<pair<int,int>,int> memo;


int go(int act,int prec,vector<vector<int> > &liste_adjacence)
{
    pair<int,int> p = make_pair(act,prec);
    if(memo.find(p)!=memo.end())
    {
        return memo[p];
    }
    memo[p]=0;
    for(int c=0;c<liste_adjacence[act].size();c++)
    {
        int n1 = liste_adjacence[act][c];
        if(n1==prec) continue;
        for(int c2=c+1;c2<liste_adjacence[act].size();c2++)
        {
            int n2 = liste_adjacence[act][c2];
            if(n2==prec) continue;
            memo[p] = max(memo[p],go(n1,act,liste_adjacence)+go(n2,act,liste_adjacence)+2);
        }
    }
    return memo[p];
}

int main()
{
    ios_base::sync_with_stdio(false);
#define cin in
#define cout out
    ifstream in("input.txt");
    ofstream out("output.txt");
    int nb_cas;
    cin>>nb_cas;
    for(int cas=1;cas<=nb_cas;cas++)
    {
        cout<<"Case #"<<cas<<": ";
        memo.clear();
        int N;
        cin>>N;
        vector<vector<int> > liste_adjacence(N);
        int mini = 100000000;
        for(int c=0;c<N-1;c++)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            liste_adjacence[a].push_back(b);
            liste_adjacence[b].push_back(a);
        }
        for(int c=0;c<N;c++)
        {
            mini = min(mini,N-1-go(c,-1,liste_adjacence));
        }
        printf("\n");
        cout<<mini<<endl;
    }
}
