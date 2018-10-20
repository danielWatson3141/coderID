#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <functional>

#define stop exit(0)
#define nc -1
#define eps 1e-10
#define inf 1000000000
#define mod 1000000007
#define mp make_pair

#define fill(array,value) memset(array,value,sizeof(array))
#define f(i,beg,end) for(int i=beg; i<=end; i++)
#define F(i,beg,end) for(int i=beg; i>=end; i--)
#define Max(a,b) ( (a>b)?a:b )
#define Min(a,b) ( (a<b)?a:b )
#define pi 3.1415926535897932384626433832
#define iread(var) scanf("%d",&var)
#define dread(var) scanf("%f",&var)
#define lread(var) scanf("%lld",&var)
#define input(name) freopen(name,"r",stdin)
#define output(name) freopen(name,"w",stdout)
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef long long ll;

using namespace std;

int n;
double badPair[1024][1024], goodPair[1024][1024];
int permutation[1024];

void init()
{
    cin >> n;
    f(i,0,n-1)
        cin >> permutation[i];
}

vector <int> badPermutation()
{
    vector <int> ans;
    f(i,0,n-1)
        ans.push_back(i);

    f(k,0,n-1)
    {
        int p = rand()%n;
        swap(ans[k],ans[p]);
    }

    return ans;
}

vector <int> goodPermutation()
{
    vector <int> ans;
    f(i,0,n-1)
        ans.push_back(i);

    f(k,0,n-1)
    {
        int p = rand()%(n-k) + k;
        swap(ans[k],ans[p]);
    }

    return ans;
}

void solve(int testIndex)
{
    int isGood = 0, k, l;

    f(i,0,n/2)
        if (permutation[i] > n/2) isGood++;
    f(i,n/2+1,n-1)
        if (permutation[i] > n/2) isGood--;

//    cout << isGood << endl;
    if (isGood>0)
    {
        printf("Case #%d: GOOD\n",testIndex);
    }
    else
        {
        printf("Case #%d: BAD\n",testIndex);
    }
}

void precompute()
{
    const int NUMBER_PERMUTATIONS = 2048;

    vector <int> perm;
    f(i,1,NUMBER_PERMUTATIONS)
    {
        perm = goodPermutation();
        f(j,1,n-1)
            f(i,0,j-1)
                goodPair[perm[j]][perm[i]]+=1.0/NUMBER_PERMUTATIONS;

        perm = badPermutation();
        f(j,1,n-1)
            f(i,0,j-1)
                badPair[perm[j]][perm[i]]+=1.0/NUMBER_PERMUTATIONS;

//        for(int i=0; i<n; i++)
//        {
//            cout << perm[i] << " ";
//        }
//        cout << endl;
//        getch();
    }
//
//    f(i,0,n-1)
//        f(j,0,n-1)
//            printf("%d %d = %.6f\n",i,j,badPair[j][i]);
//    cout << endl << endl;
//
//    f(i,0,n-1)
//        f(j,0,n-1)
//            printf("%d %d = %.6f\n",i,j,goodPair[j][i]);

    double badDiff = 0.0, goodDiff = 0.0;

}

int main()
{
//    srand(time(NULL));
//    precompute();

//	input("test.txt");
	input("C-small-attempt2.in");
    output("C-small-attempt2.out");

	int numberOfTests = 1;
	cin >> numberOfTests;

	f(i,1,numberOfTests)
	{
		init();
		solve(i);
	}

	return 0;
}
