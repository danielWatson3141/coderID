#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("/Users/sukixia/Documents/c_plus_plus/CodingTest/CodingTest/file.in");
//ofstream fout("/Users/sukixia/Documents/c_plus_plus/CodingTest/CodingTest/file.out");
FILE *fout;

unsigned long long tr[151][151];
unsigned long long source[151];
unsigned long long target[151];

typedef struct
{
    int snum;
    int idx;
} T1;
T1 switch_num[151];

unsigned long long str2int(string str, int len)
{
    int k;
    unsigned long long ans = 0;
    for (k=0;k<len;k++)
    {
        int d = str[k]-48;
        ans = ans*2+d;
    }
    return ans;
}

int get_switch_num(unsigned long long p)
{
    int ans = 0;
    while (p>0)
    {
        int temp = p % 2;
        ans += temp;
        p = p/2;
    }
    return ans;
}

bool mycomp(const T1& a, const T1& b)
{
    return (a.snum<b.snum);
}

int main()
{
    int t;
    int N,L;
    string s;
    int j,k,m;
    int good[151];
    
    fout = fopen("/Users/sukixia/Documents/c_plus_plus/CodingTest/CodingTest/file.out", "w");
    fin>>t;
    for (int i=1; i<=t; i++)
    {
        fin>>N>>L;
        for (j=0; j<N; j++)
        {
            fin>>s;
            source[j] = str2int(s,L);
        }
        for (j=0; j<N; j++)
        {
            fin>>s;
            target[j] = str2int(s,L);
        }
        for (j=0; j<N; j++)
            for (k=0; k<N; k++)
            {
                tr[j][k] = source[j]^target[k];
            }
        for (k=0; k<N; k++)
        {
            switch_num[k].idx = k;
            switch_num[k].snum = get_switch_num(tr[0][k]);
        }
        sort(switch_num, switch_num+N, mycomp);
        
        int final_ans = 10000;
        
        for (j=0; j<N; j++)
        {
            for (k=0; k<N; k++) good[k] = 0;
            
            int idx = switch_num[j].idx;
            int snum = switch_num[j].snum;
            unsigned long long cur_tr = tr[0][idx];
            
            good[idx] = 1;
            for (k=1; k<N; k++)
            {
                for (m=0; m<N; m++)
                    if (tr[k][m] == cur_tr) break;
                if (m>=N || good[m]>0) break;
                good[m] = 1;
            }
            if (k>=N)
            {
                final_ans = snum;
                break;
            }
        }
        fprintf(fout,"Case #%d: ", i);
        if (final_ans <= L)
        {
            fprintf(fout, "%d\n", final_ans);
        }
        else
        {
            fprintf(fout, "NOT POSSIBLE\n");
        }
    }
    fclose(fout);
    return 0;
}
