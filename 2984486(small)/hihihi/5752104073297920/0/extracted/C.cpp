#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int main() {
    srand((unsigned)time(NULL));
    int tc;
    scanf("%d",&tc);
    for ( int _case = 1 ; _case <= tc ; _case ++ ) {
        printf("Case #%d: ",_case);
        int N;
        scanf("%d",&N);
        vector<int> v(N),in(N);
        for ( int i = 0 ; i < N ; i++ ) 
            scanf("%d",&in[i]);
        for ( int k = 0 ; k < 5000 ; k++ ) {
            bool ok = true;
            for ( int i = 0 ; i < N ; i++ ) 
                v[i] = i;
            for ( int i = 0 ; i < N ; i++ ) {
                int t = i+(rand()%(N-i));
                swap(v[i],v[t]);
            }
            int cnt=0;
            for ( int i = 0 ; i < N ; i++ ) 
                if ( v[i] == in[i] ) cnt++;
            if ( (double)cnt/N <= 0.0059999999999 ) ok =false;
            if ( ok ) {
                printf("GOOD\n");
                goto NEXT;
            }
        }
        printf("BAD\n");
NEXT:;
    }
    return 0;
}
