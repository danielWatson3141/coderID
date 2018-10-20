//
//  main.cpp
//  2B
//
//  Created by Xiaowei Ma on 20/02/2014.
//  Copyright (c) 2014 Xiaowei Ma. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;


struct Node
{
    int id;
    vector<int> conID;
    Node(int val=0){}

};

struct Ans
{
    int sum;
    int deleted;
};

bool myFun(const Ans & a1, const Ans & a2)
{
    return ((a1.sum-a1.deleted) < (a2.sum - a2.deleted));
}

vector<Node> nodes;

Ans solve(int fatherID, int rootID)
{
    vector<Ans> sonsAns;
    
    for (int i = 0; i < nodes[rootID].conID.size(); i++)
    {
        if (fatherID == nodes[rootID].conID[i])
            continue;
        
        Ans currentAns = solve(rootID, nodes[rootID].conID[i]);
        sonsAns.push_back(currentAns);
    }
    
    Ans realAns;
    realAns.sum = 1;
    realAns.deleted = 0;
    
    if (sonsAns.size() == 0)
        return realAns;
    
    if (sonsAns.size() == 1)
    {
        realAns.sum += sonsAns[0].sum;
        realAns.deleted = sonsAns[0].sum;
        return realAns;
    }
    
    for (int i = 0; i < sonsAns.size(); i++)
    {
        realAns.sum += sonsAns[i].sum;
    }
    
    sort(sonsAns.begin(), sonsAns.end(), myFun);
    
    realAns.deleted = realAns.sum - 1 - (sonsAns[sonsAns.size()-1].sum - sonsAns[sonsAns.size()-1].deleted + sonsAns[sonsAns.size()-2].sum - sonsAns[sonsAns.size()-2].deleted);
    return realAns;
    
}



int main()
{
    //--------------- I/O ---------------------------------
    ifstream in;
    in.open("/Users/xiaoweima/Desktop/2B/2B/in.in");
    
    ofstream out;
    out.open("/Users/xiaoweima/Desktop/2B/2B/out.out");
    
    
    int T;
    in>>T;
    
  
    //-------------  sovle  ------------------------------
    
    for (int ca = 1; ca <= T; ca++)
    {
        int n;
        in>>n;
        
        nodes.clear();
        nodes.assign(n+1, 0);
        
        for (int i = 1; i < n; i++)
        {
            int x, y;
            in>>x>>y;            
            nodes[i].id = i;
            
            nodes[x].conID.push_back(y);
            nodes[y].conID.push_back(x);
        }
        nodes[n].id = n;
        
        int ans = 1000000000;
        
        for (int i = 1; i <= n; i++)
        {
            Ans tempAns = solve(-1, i);
            ans = ans < tempAns.deleted ? ans : tempAns.deleted;
        }
        
        out<<"Case #"<<ca<<": "<<ans<<endl;
        
    }
    
    
    
    
    //------------  finishing  -----------------------------
    in.close();
    out.close();
    return 0;
}

