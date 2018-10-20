//includes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

using namespace std;

#define inf 1e8

int main()
{
    freopen("/Users/arkanathpathak/Downloads/A-small-attempt3.in","r",stdin);
    freopen("/Users/arkanathpathak/Downloads/A-small-output1","w",stdout);
    cout.precision(15);
    int test;
    cin >> test;
    vector<int> imp;
    int aaaa = 0;
    for(int k=0;k<test;k++)
    {
        int n, l;
        cin >> n>> l;
        char num1[15][15];
        vector<pair<int, string> > num2(15);
        
        
        for(int i=0;i<n;i++)
        {
            string s;cin>> s;
            for(int j=0;j<l;j++) num1[i][j] = s[j];
        }
        
        for(int i=0;i<n;i++)
        {
            string s;cin>> s;
            num2[i].second = s;
            num2[i].first = i;
        }
        
        int countmin = 1000;
        //        sort(num2.begin(),num2.begin()+n);
        int fn = 0;
        
        do{
            
            int poss[n];
//            for(pair<int, string> temp:num2) cout << temp.second <<" "; cout << endl;
            int cc = 0;
            int count = 0;
            for(int i=0;i<l;i++)
            {
                int check = 0;
                for(int j=0;j<n;j++)
                {
//                    cout << num1[j][i] << " " << num2[j].second[i]<< endl;
                    if(num1[j][i]==num2[j].second[i]) continue;
                    else {check = 1; break;}
                }
                
                if(check==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(num1[j][i]!=num2[j].second[i]) continue;
                        else {check = 2; break;}
                        
                    }
                }
                
                poss[i] = check;
                if(check == 2){count = 1000; cc = 1; break;}
            }
            if(cc) continue;
            for(int i=0;i<l;i++)
            {
                if(poss[i]==0) continue;
                else if(poss[i]==1) count++;
                else {
                    count = 1000;
                    break;
                }
            }
            countmin = min(count, countmin);
            
        }
        while(next_permutation(num2.begin(), num2.begin()+n));
        if(countmin==1000) cout << "Case #"<<k+1<<": NOT POSSIBLE"<<endl;
        else cout << "Case #"<<k+1<<": "<<countmin<<endl;
        
    }
    return 0;
}