//
//  main.cpp
//  GoogleRound1Prob2
//
//  Created by happy_1113xie on 14-4-26.
//  Copyright (c) 2014年 happy_1113xie. All rights reserved.
//

#include <fstream>
#include <vector>
using namespace std;

vector<int> vec[2000], son[2000];
int T, n, answer = 2000, sum[2000], d[2000], vx, vy;
bool flag[2000];

void dfs(int x)
{
    son[x].clear();
    flag[x] = false;
    sum[x] = 1;
    for (vector<int>::iterator iter = vec[x].begin(); iter < vec[x].end(); ++iter)
        if (flag[*iter])
        {
            son[x].push_back(*iter);
            dfs(*iter);
            sum[x] += sum[*iter];
        }
    return;
}

void dp(int x)
{
    d[x] = sum[x] - 1;
    int max1 = -1, max2 = -1, v;
    
    for (vector<int>::iterator iter = son[x].begin(); iter < son[x].end(); ++iter)
    {
        dp(*iter);
        v = sum[*iter] - d[*iter];
        
        if (v >= max1)
        {
            max2 = max1;
            max1 = v;
        }
        else
            if (v > max2)
                max2 = v;
    }
    
    if (max1 != -1 && max2 != -1)
        d[x] = d[x] - max1 - max2;
    
    return;
}

int main()
{
    ifstream fin;
    fin.open("/Users/happy_1113xie/Desktop/B-small-attempt0.in");
    ofstream fout;
    fout.open("/Users/happy_1113xie/Desktop/B.out");
    
    fin >> T;
    for (int test = 1; test <= T; ++test)
    {
        answer = 2000;
        
        fin >> n;
        for (int i = 1; i <= n; ++i)
        {
            vec[i].clear();
            son[i].clear();
        }
        
        for (int i = 1; i < n; ++i)
        {
            fin >> vx >> vy;
            vec[vx].push_back(vy);
            vec[vy].push_back(vx);
        }
        
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                flag[j] = true;
            
            flag[i] = false;
            
            dfs(i);
            dp(i);
            
            if (d[i] < answer)
                answer = d[i];
        }
        
        fout << "Case #" << test << ": " << answer << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}
