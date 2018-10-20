/*
 * =====================================================================================
 *
 *       Filename:  pa.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年04月26日 08时55分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZeXue Li (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
long long getDec(long long bin)
{
    long long ret = 0;
    int cur = 0;
    int div = bin;
    while(div != 0)
    {
        int tmp = div % 10;
        int val = 1 & tmp;
        ret = ret | (val << cur);
        cur++;
        div = div / 10;
    }
    return ret;
}
int getDis(long long dis)
{
    int ret = 0;
    long long distance = dis;
    while(distance != 0)
    {
        if(distance & 1)
        {
            ret++;
        }
        distance = distance >> 1;
    }
    return ret;
}
int main()
{
    int _T, idx = 0;
    cin >> _T;
    vector<long long> src;
    unordered_set<long long> dst;
    while(idx < _T)
    {
        src.clear();
        dst.clear();
        idx++;
        int N, L;
        cin >> N >> L;
        int idxn = 0;
        while(idxn < N)
        {
            long long tmp;
            cin >> tmp;
            src.push_back(getDec(tmp));
            idxn++;
        }
        idxn = 0;
        while(idxn < N)
        {
            long long tmp;
            cin >> tmp;
            dst.insert(getDec(tmp));
            idxn++;
        }
        bool notfound = false;
        int step = -1;
        for(unordered_set<long long>::iterator it = dst.begin(); it != dst.end(); it++)
        {
            long long cur = *it;
            for(int i = 0; i < src.size(); i++)
            {
                long long tmp = cur ^ src[i];
                notfound = false;
                for(int j = 0; j < src.size(); j++)
                {
                    if(i != j)
                    {
                        long long rst = src[j] ^ tmp;
                        if(dst.find(rst) == dst.end())
                        {
                            notfound = true;
                            break;
                        }
                    }
                }
                if(!notfound)
                {
                    int tstep = getDis(tmp);
                    if(step == -1 || tstep < step)
                        step = tstep;
                }
            }
        }
        cout << "Case #" << idx << ": ";
        if(step < 0)
        {
            cout << "NOT POSSIBLE" << endl;
        }else
        {
            cout << step << endl;
        }
    }
    return 0;
}
