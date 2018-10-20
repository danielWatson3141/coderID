//
//  main.cpp
//  GoogleRound1Prob3
//
//  Created by happy_1113xie on 14-4-26.
//  Copyright (c) 2014年 happy_1113xie. All rights reserved.
//

#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("/Users/happy_1113xie/Desktop/C-small-attempt0.in");
    ofstream fout;
    fout.open("/Users/happy_1113xie/Desktop/C.out");
    
    int T, n, num, sum, tot;
    
    fin >> T;
    for (int test = 1; test <= T; ++test)
    {
        sum = 0; tot = 0;
        fin >> n;
        for (int i = 1; i <= n; ++i)
        {
            fin >> num;
            sum += num;
            if (i <= n / 2) tot += num;
        }
        
        if (tot >= sum / 2)
            fout << "Case #" << test << ": GOOD" << endl;
        else
            fout << "Case #" << test << ": BAD" << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}