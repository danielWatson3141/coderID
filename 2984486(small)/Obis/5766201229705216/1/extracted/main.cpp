#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <set>

#define ll long long

using namespace std;

vector<int> edges[1000];
bool disc[1000];
int rem = 0;
int weight[1000];

void dfs (int v)
{ 
    int childs = 0;
    
    disc[v] = true;
    
    vector<int> children;
    
    for (int i = 0; i < edges[v].size(); i++)
    {
        if (!disc[edges[v][i]])
        {
            childs++;
            children.push_back(edges[v][i]);
            dfs(edges[v][i]);
        }
    }
    
    if (childs == 0)
    {
        weight[v] = 1;
        //cout << "child" << endl;
    } else
    {
        vector<int> childWeights;
        
        int sumWeight = 0;
        for (int i = 0; i < childs; i++)
        {
            childWeights.push_back(weight[children[i]]);
            sumWeight += weight[children[i]];
        }
        
        //cout << sumWeight << endl;
        
        sort(childWeights.begin(), childWeights.end());
        
        if (childs == 1)
        {
            rem += childWeights[0];
          //  cout << childWeights[0] << endl;
            weight[v] = 1;
        } else if (childs > 2)
        {
            for (int i = 0; i < childs-2;i++)
            {
                rem += childWeights[i];
                sumWeight -= childWeights[i];
            }
            weight[v] = 1 + sumWeight;
        } else
            weight[v] = 1 + sumWeight;
    }
}
    

int main()
{
    ifstream cin ("B-large.in");
    ofstream cout ("out.txt");
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
    
       int n;
       cin >> n;
       
       int best = 1000000000;
       
       for (int j = 0; j < n; j++)
            edges[j].clear();
       
       for (int j = 0; j < n-1; j++)
       {
            int x, y;
            cin >> x >> y;
            x--; y--;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        
        for (int j = 0; j < n; j++)
        {
            memset(disc, 0, sizeof(disc));
            rem = 0;
            dfs(j);
            //cout << rem << endl;
            
            best = min(best, rem);
        }    
                
        if (best < 1000000000) 
            cout << "Case #" << i+1 << ": " << best << endl;
    }
   //while (true) {}
}
                

