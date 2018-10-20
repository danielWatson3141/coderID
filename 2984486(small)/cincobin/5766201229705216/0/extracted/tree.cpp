#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int num, n;
    int a, b;
    ifstream fin;
    ofstream fout;
    fin.open("treesmall.in", std::ifstream::in);
    fout.open("treesmall.out", std::ofstream::out);
    fin>>num;
    for(int k = 0; k < num; k++)
    {
        fin>>n;
        int max = 0;
        vector<vector<int> > adj(n);
        for(int i = 0; i < n-1; i++)
        {
            fin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        for(int i = 0; i < n - 1; i++)
        {
            vector<int> tag(n, 0);
            int count = 0;
            queue<int> q;
            tag[i] = 1;
            q.push(i);
            count++;
            while(!q.empty())
            {
                a = q.front();
                q.pop();
                if(adj[a].size() >= 2)
                {
                    for(int x = 0; x < adj[a].size()-1; x++)
                    {
                        for(int y = x+1; y < adj[a].size(); y++)
                        {
                            if(tag[adj[a][x]] == 0 && tag[adj[a][y]] == 0)
                            {
                                tag[adj[a][x]] = 1;
                                tag[adj[a][y]] = 1;
                                q.push(adj[a][x]);
                                q.push(adj[a][y]);
                                count+=2;
                            }
                        }
                    }
                }
            }
            if(count > max)
                max = count;
        }
        
        fout<<"Case #"<<k+1<<": "<<n-max<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}
