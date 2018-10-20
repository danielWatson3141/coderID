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

int parcours(vector<vector<int> > &liste_adjacence,vector<bool> &visites,int mask,int root)
{
    if(mask & (1<<root)) return liste_adjacence.size();
    int parcourus = 0;
    vector<int> dfs;
    dfs.push_back(root);
    visites[root]=true;
    while(dfs.size())
    {
        int act = dfs.back();
        parcourus++;
        dfs.pop_back();
        int compte = 0;
        for(int c=0;c<liste_adjacence[act].size();c++)
        {
            int next = liste_adjacence[act][c];

            if(!visites[next] && (mask & (1<<next)) == 0)
            {
                compte++;
                dfs.push_back(next);
                visites[next]=true;
            }
        }
        if(compte != 2 && compte != 0) return 100000000;
    }
    return liste_adjacence.size() - parcourus;
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
        for(int c=0;c<(1<<(N+1));c++)
        {
            for(int c2=0;c2<N;c2++)
            {
                vector<bool> visites(N,false);
                int z = parcours(liste_adjacence,visites,c,c2);
                mini = min(mini,z);
            }
        }
        cout<<mini<<endl;
    }
}
