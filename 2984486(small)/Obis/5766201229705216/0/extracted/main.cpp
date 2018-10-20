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

vector<int> edges[15];
bool yra[15];
bool disc[15];
bool good = false;

void dfs (int v)
{ 
    int childs = 0;
    
    disc[v] = true;
    
    for (int i = 0; i < edges[v].size(); i++)
    {
        if (!disc[edges[v][i]] && yra[edges[v][i]])
        {
            childs++;
            dfs(edges[v][i]);
        }
    }
    
    if (!(childs == 0 || childs == 2))
        good = false;
}
    

int main()
{
    ifstream cin ("B-small-attempt0.in");
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
        
        for (int j = 0; j < (1 << (n)); j++)
        {            
            int rem = 0;
            for (int k = 0; k < n; k++)
            {
                if (((1 << k) & j) != 0)
                    yra[k] = true;
                else
                {
                    rem++;
                    yra[k] = false;
                }
            }
            
            for (int k = 0; k < n; k++)
            {
                good = false;
                memset(disc, 0, sizeof(disc));
                if (yra[k])
                {
                    good = true;
                    dfs(k);
                }
                
                for (int l = 0; l < n; l++)
                    if (yra[l] && !disc[l])
                        good = false;
                
                if (good)
                {
                    best = min(best, rem);
                }
            }
        }
                
        if (best < 1000000000) 
            cout << "Case #" << i+1 << ": " << best << endl;
    }
   //while (true) {}
}
                

