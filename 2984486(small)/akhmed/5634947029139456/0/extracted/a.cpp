//
//  main.cpp
//  Round1A2014
//
//  Created by Ahmed Mohammed Abdurahman on 4/26/14.
//  Copyright (c) 2014 Better LLC. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>



using namespace std;

int main(int argc, const char * argv[])
{
    if (argc < 3) { printf("Usage: %s <input file> <output file>\n", argv[0]); exit(1);}
    
    // open files
    ifstream fin(argv[1], ios::in|ios::ate);
    if (!fin.is_open()) { printf("Unable to open input file\n"); exit(1);}
    fin.seekg(0);
    
    ofstream fout(argv[2], ios::out|ios::ate);
    if (!fout.is_open()) { printf("Unable to open output file\n"); exit(1);}
    fout.seekp(0);
    
    fout.precision(7);
    fout.setf(ios::fixed);
    
    
    // solve test cases
    uint64_t testcase_count;
    fin >> testcase_count;
    for (uint64_t tcase = 0; tcase < testcase_count; tcase++)
    {
        int N, L;
        fin >> N >> L;
        
        int c1[L]; memset(c1, 0, sizeof(int) * L);
        uint64_t c[N];
        for (int i = 0; i < N; i++)
        {
            c[i] = 0;
            
            for (int j = 0; j < L; j++)
            {
                char ch;
                fin >> ch;
                if (ch == '1')
                {
                    c[i] |= (1 << j);
                    c1[j]++;
                }
            }
        }
        
        int d1[L]; memset(d1, 0, sizeof(int) * L);
        uint64_t d[N];
        for (int i = 0; i < N; i++)
        {
            d[i] = 0;
            
            for (int j = 0; j < L; j++)
            {
                char ch;
                fin >> ch;
                if (ch == '1')
                {
                    d[i] |= (1 << j);
                    d1[j]++;
                }
            }
        }
        sort(d, d+N);
        
        bool possible = true;
        uint64_t f = 0;
        vector<int> fu;
        for (int i = 0; i < L; i++)
        {
            if (c1[i] + d1[i] == N)
            {
                if (c1[i] == d1[i]) fu.push_back(i);
                else f |= (1 << i);
            }
            else if (c1[i] != d1[i])
            {
                possible = false;
                break;
            }
        }
        
        int min = L+1;
        if (possible)
        {
            int p = 1 << fu.size();
            uint64_t lef = 0;
            for (int i = 0; i < p; i++)
            {
                uint64_t ef = f;
                for (int j = 0; j < fu.size(); j++) if (i & (1 << j)) ef ^= (1 << fu[j]);
                
                uint64_t t = ef;
                ef ^= lef;
                lef = t;
                
                for (int j = 0; j < N; j++) c[j] ^= ef;
                
                sort(c, c+N);
                
                int j = 0;
                for (; j < N; j++) if (c[j] != d[j]) break;
                
                if (j == N)
                {
                    int f1 = 0;
                    for (int i = 0; i < L; i++) if (lef & (1 << i)) f1++;
                    if (f1 < min) min = f1;
                }
            }
            
            possible = min != L+1;
        }
        
        if (possible) fout << "Case #" << (tcase + 1) << ": " << min << endl;
        else fout << "Case #" << (tcase + 1) << ": NOT POSSIBLE" << endl;
    }
    
    
    fin.close();
    fout.close();
    
    return 0;
}

