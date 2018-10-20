#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string.h>

#define SZ(c) c.size()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define SORT(a) sort(a.begin(),a.end())
#define tests int test; scanf("%d",&test); while(test--)
#define dbg(n) cout<<#n<<" = "<<n<<endl;

using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(int n) {string str; stringstream s; s<<n; s>>str; return str;}
int MAX(int a,int b) {if(a >b) return a; return b;}
int MIN(int a,int b) {if(a <b) return a; return b;}
int ABS(int a) {if(a >0) return a; return -a;}

int diff(string first, string second, int number)
{
    int len = first.size();
    int counter = 0;
    for(int i=0; i<len; i++)
    {
        if(first[i] != second[i])
            counter++;
    }
    if(counter == number)
        return 1;
    return 0;
}

//bool check(string[] first, string[] second)
//{
//    int len = first.size();
//    int used[len];
//    for(int i=0; i<len; i++)
//        used[i] =0;
//    for(int i=0; i<len;i++)
//    {
//        for(int j=0; j<len; j++)
//        {
//            if((!used[j]) && (first[i] == first[j]))
//            {
//                used[j] = 1;
//                beeak;
//            }
//        }
//    }
//    for(int i=0; i<len; i++)
//    {
//        if(!used[j])
//            return 0;
//    }
//    return 1;
//}
//
//
void modify(string arr[], int bit, int len)
{
    for(int i=0; i<len; i++)
    {
        if(arr[i][bit] == '1')
            arr[i][bit] = '0';
        else
            arr[i][bit] = '1';

    }
}
int main()
{
    freopen("charging.txt", "r", stdin);
    freopen("chargingSmall.txt", "w", stdout);
    int test;
    scanf("%d\n",&test);

    int number,flips;

    for(int running =1 ; running <=test; running++)
    {
        cin>>number>>flips;
        string outlets[number], devices[number];
        string copyOutlets[number];
        for(int i=0; i<number; i++)
        {
            cin>>outlets[i];

        }
        for(int i=0; i<number; i++)
        {
            cin>>devices[i];
        }

        int answer = 10000, counter =0;
        for(int i=0; i<= (1<<flips); i++)
        {
            counter =0;
            for(int k=0; k<number; k++)
            {
                copyOutlets[k] = outlets[k];
            }
            for(int j=0; j<=flips; j++)
            {
                if( i & (1<<j))
                {
                    counter++;
                    modify(copyOutlets, j, number);
                }
            }
             int flag =0;
            {
                int len = number;
                int used[len];
                for(int index=0; index<len; index++)
                    used[index] =0;
                for(int index=0; index<len; index++) {
                    for(int jNew=0; jNew<len; jNew++) {
                        if((!used[jNew]) && (copyOutlets[index] == devices[jNew])) {
                            used[jNew] = 1;
                            break;
                        }
                    }
                }
                flag =1;
                for(int index=0; index<len; index++) {
                    if(!used[index])
                    {
                        flag =0;
                        break;

                    }
                }

            }
            if(flag == 1)
                answer = MIN(answer, counter);
        }
        if(answer == 10000)
        {
            printf("Case #%d: NOT POSSIBLE\n", running);
        }
        else
        {
            printf("Case #%d: %d\n", running, answer);
        }
    }
    return 0;

}


