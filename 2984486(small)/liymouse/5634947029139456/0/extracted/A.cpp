#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int main()
{
	freopen("A-small-attempt2.in" , "r" , stdin);
	freopen("A-small-attempt2.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        char s1[160][50];
        char s2[160][50];
        int n , L;
        scanf("%d %d" , &n , &L);
        for (int i = 0; i < n; i ++) scanf("%s" , s1[i]);
        for (int i = 0; i < n; i ++) scanf("%s" , s2[i]);
        int ans = 0;
        int a[50] = {0};
        for (int i = 0; i < L; i ++)
        {
            int one1 = 0 , zero1 = 0;
            int one2 = 0 , zero2 = 0;
            for (int j = 0; j < n; j ++)
            {
                if (s1[j][i] == '0') zero1 ++;
                if (s1[j][i] == '1') one1 ++;
                if (s2[j][i] == '0') zero2 ++;
                if (s2[j][i] == '1') one2 ++;
            }
            if (zero1 == zero2 && one1 == one2)
            {
                if (zero1 == one1) a[i] = 2;
                else a[i] = 0;
            }
            else if (zero1 == one2 && zero2 == one1) {ans ++; a[i] = 1;}
            else {ans = -1; break;}
        }
        if (ans == -1) printf("NOT POSSIBLE\n");
        else
        {
            int res = 0;
            
            set<string> ress;
            for (int ii = 0; ii < n; ii ++)
            {
                int mina = L + 1;
                set<string> ss;
                for (int i = 0; i < n; i ++)
                {
                    char b[50] = {0};
                    ans = 0;
                    for (int j = 0; j < L; j ++)
                        if (s1[ii][j] == s2[i][j]) b[j] = '0';
                        else b[j] = '1';
                    for (int j = 0; j < L; j ++)
                        if (a[j] != 2 && b[j]-'0' != a[j]) {ans = -1; break;}
                        else if (b[j] == '1') ans ++;
                    if (ans != -1) ss.insert((string)b);
                }
                if (ii == 0) ress = ss;
                else
                {
                    set<string> tmp;
                    std::set<string>::iterator it = ress.begin();
                    while(it!=ress.end())
                    {
                        if (ss.find(*it) != ss.end()) tmp.insert(*it);
                        it ++;
                    }
                    ress = tmp;
                }
            }
            std::set<string>::iterator it = ress.begin();
            int minans = L+1;
            while(it!=ress.end())
            {
                int ans = 0;
                for (int i = 0; i < (*it).length(); i ++) if ((*it)[i] == '1') ans ++;
                if (ans < minans) minans = ans;
                it ++;
            }
            printf("%d\n" , minans);
        }
    }
    return 0;
}