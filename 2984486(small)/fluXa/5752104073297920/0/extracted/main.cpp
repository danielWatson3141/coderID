#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;


void solve(int count) {
    int num;
    scanf("%d\n", &num);
    int sum;
    for (int i = 0; i < num; ++i) {
        int r;
        scanf("%d", &r);
        int delta = r - i; // 1 has highest chance? 0 lowest < 0 increase >1 decrease
        if (delta > 0) sum += num - delta;
        //else sum += -delta;
    }
   // printf("%d\n", sum);
    
    if (sum > 350000) printf("BAD\n");
    else printf("GOOD\n");
}

int main(int argc, const char * argv[])
{
   /* srand48(time(NULL));
    for (int i = 0; i < 10; ++i) {
        printf("1000\n");
        int a[1000];
        int n = 1000;
        for (int k = 0; k < n ; ++k) a[k] = k;
        for (int k = 0; k < n ; ++k) {
            //int p = k + (lrand48() % (n - k));
            int p = (lrand48() % n);
            int tmp = a[k];
            a[k] = a[p];
            a[p] = tmp;
        }
        for (int k = 0; k < n ; ++k) printf("%d ", a[k]);
        printf("\n");
    }
    return 0;*/
    
    
	int numCases = 0;
    
  	scanf("%d\n", &numCases);
    
    for (int count = 1; count <= numCases; ++count) {
        printf("Case #%d: ", count);
        solve(count);
    }
    return 0;
}

