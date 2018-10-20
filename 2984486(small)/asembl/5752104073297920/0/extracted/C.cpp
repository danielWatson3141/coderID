#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std ;
const int MAXN = 1000 ;
const int TESTS = 100000 ;
int n = 1000 ;
int a[MAXN] , x[MAXN] ;
int cnt[MAXN][MAXN] ;

inline int pickrand( int n ) {
    do
    {
        int p = rand() ;
        if ( p < 32767 / n * n ) {
            p = p % n ;
            return p ;
        }
    }while (true);
}

void getBAD() {
    for ( int i = 0 ; i < n ; ++i ) {
        a[i] = i ;
    }
    for ( int i = 0 ; i < n ; ++i ) {
        int p = pickrand(n) ;
        swap(a[i],a[p]);
    }
}
void getGOOD() {
    for ( int i = 0 ; i < n ; ++i ) {
        a[i] = i ;
    }
    for ( int i = 0 ; i < n ; ++i ) {
        int p = pickrand(n-i) ;
        swap(a[i],a[i+p]);
    }
}
bool equ() {
    for ( int i = 0 ; i < n ; ++i )
        if ( a[i] != x[i] ) return false ;
    return true ;
}
int main() {

    int T = 120 ,test = 1 ;
    int res1 = 0 , res2 = 0 ;

    srand((int)time(NULL));
    for ( int i = 0 ; i < 120 ; ++i ) {

        res1=res2=0;
        getBAD();
        for ( int j = 0 ; j < n ; ++j ) {
            //  cnt[a[j]][j] ++ ;
            if ( a[j] <= j )
                res1 ++ ;
        }


          getGOOD();
        for ( int j = 0 ; j < n ; ++j ) {
            //  cnt[a[j]][j] ++ ;
            if ( a[j] <= j )
                res2 ++ ;
        }
        //cout << res1 << " " << res2 << endl ;
    }



    cin >> T ;
    while ( T-- ) {
        cin >> n ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> x[i] ;
        }
        int c = 0 ;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( x[i] <= i )
                ++c ;
        }
        int x = 0 ;
        if (c <= 486)
            x = 1 ;
        printf("Case #%d: %s\n",test++,x>0?"GOOD":"BAD");
    }



    return 0;
}
