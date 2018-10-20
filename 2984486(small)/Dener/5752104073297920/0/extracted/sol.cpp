#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;

void dosmth()
{
    double e = 0;
    int tests = 10000;
    for (int qwer = 0; qwer < tests; qwer++) {
        vector< int > p(1000);
        for (int i = 0; i < p.size(); i++)
        {
            p[i] = i;
        }
        
        for (int i = 0; i < p.size(); i++)
        {
            int q = rand() % (p.size() - i) + i;
//             int q = rand() % p.size();
            swap(p[i], p[q]);
        }
        
        int in_place = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == i) {
                in_place = 1;
                break;
            }
        }
            
        e += in_place;
    }
    cout << e / tests << endl;
}

void solve(int test_num)
{
    int n;
    scanf("%d", &n);
    vector< int > p(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    
    int in_place = 0;
    for (int i = 0; i < n; i++){
        if (p[i] > i) {
            in_place++;
        }
    }
    
    double aver_dist = 0;
    for (int i = 0; i < n; i++) {
        aver_dist += abs(p[i] - i);
    }
    aver_dist /= n;
    
    if (in_place <= 509)
        printf("Case #%d: GOOD\n", test_num + 1);
    else if (in_place > 519)
        printf("Case #%d: BAD\n", test_num + 1);
    else if (rand() % 2) {
        printf("Case #%d: GOOD\n", test_num + 1);
    } else {
        printf("Case #%d: BAD\n", test_num + 1);
    }
    
}

int main()
{
//     srand(time(0));
//     dosmth();
//     return 0;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
}