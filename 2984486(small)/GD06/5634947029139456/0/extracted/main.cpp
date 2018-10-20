//
//  main.cpp
//  GoogleRound1
//
//  Created by happy_1113xie on 14-4-26.
//  Copyright (c) 2014年 happy_1113xie. All rights reserved.
//

#include <fstream>
#include <string>
using namespace std;

string s;
long num1[200], num2[200];
long state = 0, fbit = 0;
bool flag[200], isfind, iscount;
int answer, tot;
int T, n, l;

void change(string& str, long& num)
{
    num = 0;
    for (int j = 0; j < l; ++j)
    {
        num = num * 2 + (str[j] - '0');
    }
    
    return;
}

int main()
{
    ifstream fin;
    fin.open("/Users/happy_1113xie/Desktop/A-small-attempt0.in");
    ofstream fout;
    fout.open("/Users/happy_1113xie/Desktop/A.out");
    
    fin >> T;
    
    for (int test = 1; test <= T; ++test)
    {
        answer = 50;
        
        fin >> n >> l;
        for (int i = 1; i <= n; ++i)
        {
            fin >> s;
            change(s, num1[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            fin >> s;
            change(s, num2[i]);
        }
        
        for (int i = 1; i <= n; ++i)
        {
            iscount = true;
            
            for (int j = 1; j <= n; ++j)
                flag[j] = true;
            
            flag[i] = false;
            state = num1[1] ^ num2[i];
            
            for (int j = 2; j <= n; ++j)
            {
                fbit = num1[j] ^ state;
                isfind = false;
                
                for (int k = 1; k <= n; ++k)
                    if (fbit == num2[k] && flag[k])
                    {
                        flag[k] = true;
                        isfind = true;
                        break;
                    }
                
                if (! isfind)
                {
                    iscount = false;
                    break;
                }
            }
            
            if (iscount)
            {
                tot = 0;
                while (state != 0)
                {
                    tot += state & 1;
                    state = state >> 1;
                }
                
                if (tot < answer)
                    answer = tot;
            }
        }
        
        
        if (answer == 50)
            fout << "Case #" << test << ": NOT POSSIBLE" << endl;
        else
            fout << "Case #" << test << ": " << answer << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}