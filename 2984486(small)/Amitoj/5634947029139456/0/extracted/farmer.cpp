#include <algorithm>  
#include <iostream>  
#include <iomanip>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <list>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <iomanip>  
using namespace std;  

#define FOR(i,a,b) for(long i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  

long calc(string s, long L)
{
    long res = 0;
    long k=1;
    FOR(i,0,L)
    {
        if(s[i] == '1')
        {
            res |= (k<<(L-i-1));
        }
    }
    return res;
}

int countSetBits(long n)
{
     int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

int main(int argc, char** argv)
{
    ifstream in;
    in.open(argv[1],ios::in);
    ofstream out;
    out.open(argv[2],ios::out);
    int N = 0;
    in>>N;
    cout << " Total  " << N <<endl;
    REP(caseN,N)
    {
        long M,L;
        cout<<"solving case "<<caseN+1<<endl;
        in >> M >> L;

        vector<long> devices;
        vector<long> outlets;
        
        string s;
        int minBits = -1;
        
        FOR(i,0,M)
        {
            in >> s;
            outlets.push_back(calc(s,L));
        }
        
        FOR(i,0,M)
        {
            in >> s;
            devices.push_back(calc(s,L));
        }
        sort(devices.begin(), devices.end());
        
        long max = 1;
        max = (max<<L);
        for(long i = 0; i < (1<<L); ++i)
        {
            vector<long> flippedOutlets;
            FOR(j, 0, M)
            {
                flippedOutlets.push_back(outlets[j]^i);
            }
            sort(flippedOutlets.begin(),flippedOutlets.end());

            if(flippedOutlets == devices)
            {
                int bits = countSetBits(i);
                if(minBits < 0) minBits = bits;
                else minBits = (minBits < bits) ? minBits : bits;
            }
        }
        
        out << "Case #"<<caseN+1<<": ";
        if(minBits < 0) 
            out << "NOT POSSIBLE";
        else
            out << minBits;
        out << endl;
    }
        
    in.close();
    out.close();
    return 0;
}
