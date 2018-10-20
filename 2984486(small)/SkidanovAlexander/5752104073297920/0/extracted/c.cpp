#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

void gen_good(vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++ i)
    {
        int idx = rand() % (i + 1);
        if (i != idx) swap(vec[i], vec[idx]);
    }
}

void gen(vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++ i)
    {
        int idx = rand() % vec.size();
        if (i != idx) swap(vec[i], vec[idx]);
    }
}

void identity(vector<int>& vec)
{
    for( int i = 0; i < 1000; ++ i)
    {
        vec.push_back(i);
    }
}

double doit1(vector<int>& vec)
{
    double ret = 0;
    for (int i = 500; i < vec.size(); ++ i)
    {
        ret += ((double)(vec[i] * vec[i]) * vec[i] * vec[i] * (i - 500) * vec[i]); 
    }
    for (int i = 0; i < vec.size() - 500; ++ i)
    {
        ret -= ((double)(vec[i] * vec[i]) * vec[i] * vec[i] * (500 - i) * vec[i]); 
    }
    return ret;
}

double doit2(vector<int>& vec)
{
    double ret = 0;
    for (int i = 500; i < vec.size(); ++ i)
    {
        ret += ((double)(vec[i] * vec[i]) * vec[i] * vec[i] * (i - 500)); 
    }
    for (int i = 0; i < vec.size() - 500; ++ i)
    {
        ret -= ((double)(vec[i] * vec[i]) * vec[i] * vec[i] * (500 - i)); 
    }
    return ret;
}

double doit3(vector<int>& vec)
{
    double ret = 0;
    for (int i = 500; i < vec.size(); ++ i)
    {
        ret += ((double)(vec[i] * vec[i]) * vec[i] * vec[i]); 
    }
    return ret;
}

const double moo2 = 2401667596902599.0;
const double moo1 = 2406033680577325568.0;
const double moo3 = 104338990875408.0;

bool doit(vector<int>& vec)
{
    double a1 = doit1(vec);
    double a2 = doit2(vec);
    double a3 = doit3(vec);

    if (a1 < moo1 * 0.5) return true;
    if (a2 < moo2 * 0.5) return true;
    if (a3 < moo3 * 0.5) return true;
    if (a1 > moo1 * 1.5) return false;
    if (a2 > moo2 * 1.5) return false;
    if (a3 > moo3 * 1.5) return false;

    return (a1 < moo1) + (a2 < moo2) + (a3 < moo3) >= 2;
}

int main()
{
/*    srand(time(0));
    vector<double> v1, v2;

    int correct = 0;
    int correct2 = 0;
    for (int i = 0; i < 60; ++ i)
    {
        vector<int> vec;
        identity(vec);
        gen_good(vec);

        correct += doit(vec);
        correct2 +=   doit(vec);
        v1.push_back(doit3(vec));

        vec.clear();
        identity(vec);
        gen(vec);

        correct += !doit(vec);
        v2.push_back(doit3(vec));
    }

    double a1 = 0, a2 = 0;
    for (int i = 0; i < v1.size(); ++ i)
    {
        a1 += v1[i];
        a2 += v2[i];
    }
    printf("%lf %lf %d (%d %d) %lf\n", a1 / v1.size(), a2 / v1.size(), correct, correct2, correct - correct2, (a1 + a2) / (2 * v1.size()));
    /**/

    int tt;
    scanf("%d", &tt);
    for (int t = 1; t <= tt; ++ t)
    {
        int n;
        scanf("%d", &n);
        vector<int> v;
        for (int i = 0; i <n; ++ i)
        {
            int a;
            scanf("%d", &a);
            v.push_back(a);
        }
        printf("Case #%d: ", t);
        if (doit(v))
        {printf("GOOD\n");} else printf("BAD\n");
    }/**/
}

