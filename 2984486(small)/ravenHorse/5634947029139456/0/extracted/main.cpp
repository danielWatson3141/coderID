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

const int INF = 151;

vector<int> flow[150];
vector<int> dev[150];

int solve(vector<int> &flowIndex, vector<int> &devIndex, int bit, int maxBit, bool change)
{
    if (bit > maxBit) return 0;
    
    int numZeroFlow = 0, numZeroDev = 0;
    
    for (int i = 0; i < flowIndex.size(); i++)
    {
        if (flow[flowIndex[i]][bit] == 0)
            numZeroFlow++;
    }
    for (int i = 0; i < devIndex.size(); i++)
    {
        if (dev[devIndex[i]][bit] == 0)
            numZeroDev++;
    }
    
    int numOneFlow = flowIndex.size() - numZeroFlow;
    int numOneDev = devIndex.size() - numZeroDev;
    
    if (numZeroDev != numOneDev)
    {
        if (numZeroDev == numZeroFlow && change==false)
        {
            vector<int> flowZero;
            vector<int> flowOne;
            vector<int> devZero;
            vector<int> devOne;
            
            for (int i = 0; i < flowIndex.size(); i++)
            {
                if (flow[flowIndex[i]][bit] == 0)
                    flowZero.push_back(flowIndex[i]);
                else
                    flowOne.push_back(flowIndex[i]);
            }
            
            for (int i = 0; i < devIndex.size(); i++)
            {
                if (dev[devIndex[i]][bit] == 0)
                    devZero.push_back(devIndex[i]);
                else
                    devOne.push_back(devIndex[i]);
            }
            
            return min(solve(flowOne, devOne, bit+1, maxBit, true) + solve(flowZero, devZero, bit+1, maxBit, true), solve(flowOne, devOne, bit+1, maxBit, false) + solve(flowZero, devZero, bit+1, maxBit, false));
            
        }
        else if (numZeroDev == numZeroFlow && change==true)
        {
            return INF;
        }
        else if (numZeroDev == numOneFlow && change == true)
        {
            vector<int> flowZero;
            vector<int> flowOne;
            vector<int> devZero;
            vector<int> devOne;
            
            for (int i = 0; i < flowIndex.size(); i++)
            {
                if (flow[flowIndex[i]][bit] == 0)
                    flowZero.push_back(flowIndex[i]);
                else
                    flowOne.push_back(flowIndex[i]);
            }
            
            for (int i = 0; i < devIndex.size(); i++)
            {
                if (dev[devIndex[i]][bit] == 0)
                    devZero.push_back(devIndex[i]);
                else
                    devOne.push_back(devIndex[i]);
            }
            
            return 1 + min(solve(flowZero, devOne, bit+1, maxBit, true) + solve(flowOne, devZero, bit+1, maxBit, true), solve(flowZero, devOne, bit+1, maxBit, false) + solve(flowOne, devZero, bit+1, maxBit, false));

        }
        else if ( numZeroDev == numOneFlow && change == false)
        {
            return INF;
        }
        else
        {
            return INF;
        }
    }
    else
    {
        if (numZeroDev == numZeroFlow && change == true)
        {
            vector<int> flowZero;
            vector<int> flowOne;
            vector<int> devZero;
            vector<int> devOne;
            
            for (int i = 0; i < flowIndex.size(); i++)
            {
                if (flow[flowIndex[i]][bit] == 0)
                    flowZero.push_back(flowIndex[i]);
                else
                    flowOne.push_back(flowIndex[i]);
            }
            
            for (int i = 0; i < devIndex.size(); i++)
            {
                if (dev[devIndex[i]][bit] == 0)
                    devZero.push_back(devIndex[i]);
                else
                    devOne.push_back(devIndex[i]);
            }
            
            return 1 + min(solve(flowZero, devOne, bit+1, maxBit, true) + solve(flowOne, devZero, bit+1, maxBit, true), solve(flowZero, devOne, bit+1, maxBit, false) + solve(flowOne, devZero, bit+1, maxBit, false));

        }
        else if (numZeroDev == numZeroFlow && change == false) {
            vector<int> flowZero;
            vector<int> flowOne;
            vector<int> devZero;
            vector<int> devOne;
            
            for (int i = 0; i < flowIndex.size(); i++)
            {
                if (flow[flowIndex[i]][bit] == 0)
                    flowZero.push_back(flowIndex[i]);
                else
                    flowOne.push_back(flowIndex[i]);
            }
            
            for (int i = 0; i < devIndex.size(); i++)
            {
                if (dev[devIndex[i]][bit] == 0)
                    devZero.push_back(devIndex[i]);
                else
                    devOne.push_back(devIndex[i]);
            }

            return min(solve(flowOne, devOne, bit+1, maxBit, true) + solve(flowZero, devZero, bit+1, maxBit, true), solve(flowOne, devOne, bit+1, maxBit, false) + solve(flowZero, devZero, bit+1, maxBit, false));
        }
        else
        {
            return INF;
        }
    }
   
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
        int n, l;
        in>>n>>l;
        
        
        for (int i = 0; i < 150; i++)
        {
            flow[i].assign(l, 0);
        }
        
        for (int i = 0; i < n; i++)
        {
            string s;
            in>>s;
            
            for (int j = 0; j < s.size(); j++)
            {
                flow[i][j] = s[j] - '0';
            }
        }
        
        
        
        for (int i = 0; i < 150; i++)
        {
            dev[i].assign(l, 0);
        }
        
        for (int i = 0; i < n; i++)
        {
            string s;
            in>>s;
            
            for (int j = 0; j < s.size(); j++)
            {
                dev[i][j] = s[j] - '0';
            }
        }
        
        vector<int> flowIndex(n, 0);
        vector<int> devIndex(n, 0);
        
        for (int i = 0; i < n; i++)
        {
            flowIndex[i] = i;
            devIndex[i] = i;
        }
        
        int ans = min( solve(flowIndex, devIndex, 0, l-1, true), solve(flowIndex, devIndex, 0, l-1, false));
        
        if (ans < INF)
            out<<"Case #"<<ca<<": "<<ans<<endl;
        else
            out<<"Case #"<<ca<<": "<<"NOT POSSIBLE"<<endl;
        
    }
    
    
    
    
    //------------  finishing  -----------------------------
    in.close();
    out.close();
    return 0;
}

