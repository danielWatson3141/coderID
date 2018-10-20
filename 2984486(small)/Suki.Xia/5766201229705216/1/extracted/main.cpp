#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 1001
ifstream fin("/Users/sukixia/Documents/c_plus_plus/CodingTest/CodingTest/file.in");
//ofstream fout("/Users/sukixia/Documents/c_plus_plus/CodingTest/CodingTest/file.out");
FILE *fout;

int edge[MAXN][MAXN];
int nodenum[MAXN];
int ans[MAXN];
int final_ans;
int N;

void solve_prob(int cur, int fa)
{
    int temp;
    vector<int> children;
    for (int p=1; p<=edge[cur][0]; p++)
        if (edge[cur][p] != fa)
            children.push_back(edge[cur][p]);
    int ch_num = children.size();
    
    if (ch_num == 0)
    {
        nodenum[cur] = 1;
        ans[cur] = 0;
        return;
    }
    
    int total_children = 0;
    for (temp=0; temp<ch_num; temp++)
    {
        solve_prob(children[temp], cur);
        total_children += nodenum[children[temp]];
    }
    if (ch_num == 1)
    {
        nodenum[cur] = total_children + 1;
        ans[cur] = total_children;
        return;
    }
    
    int min1=N, min2=N;
    
    for (temp=0; temp<ch_num; temp++)
    {
        int cid = children[temp];
        int sub = ans[cid]-nodenum[cid];
        if (sub<min1)
        {
            min2 = min1;
            min1 = sub;
        }
        else if (sub<min2)
        {
            min2 = sub;
        }
    }
    nodenum[cur] = total_children+1;
    ans[cur] = total_children+min1+min2;
}

int main()
{
    int t;
    int j,k,l;
  
    fout = fopen("/Users/sukixia/Documents/c_plus_plus/CodingTest/CodingTest/file.out", "w");
    fin>>t;
    for (int i=1; i<=t; i++)
    {
        fin>>N;
        for (j=0; j<N; j++) edge[j][0] = 0;
        for (j=1; j<N;j++)
        {
            fin>>k>>l;
            k--;
            l--;
            edge[k][0]++;
            edge[k][edge[k][0]] = l;
            edge[l][0]++;
            edge[l][edge[l][0]] = k;
        }
        if (N==2)
        {
            final_ans = 1;
        }
        else if (N==3) {
            final_ans = 0;
        } else
        {
            final_ans = N;
            int cur_best;
            for (k=0; k<N; k++)
            {
                for (l=0; l<N; l++)
                {
                    ans[l] = N;
                    nodenum[l] = 0;
                }
                solve_prob(k,-1);
                if (final_ans > ans[k])
                {
                    final_ans = ans[k];
                }
            }
        }
        fprintf(fout, "Case #%d: %d\n", i, final_ans);
    }
    fclose(fout);
    return 0;
}
