#include <cstdio>
#include <iostream>
using namespace std ;
int n , L ;
int a[200][50] , b[200][50] ;
bool flag[50] ;

bool finds( int b[50] ) {

    for ( int k = 0 ; k < n ; ++k ) {

        bool check = true ;
        for (int l = 0 ; l < L ; ++l )
            if ( (b[l]^flag[l] ) != a[k][l] )
                check = false ;
        if (check)
            return true ;
    }
    return false ;
}


int main()
{
    int T ;
    int test = 1 ;


    cin >> T ;
    while (T--) {
        cin >> n >> L;

        bool ansfind = false ;
        int ans = 0 ;

        for ( int i = 0 ; i < n ; ++i )
            for ( int j = 0 ; j < L; ++j )
                scanf("%1d",&a[i][j]);
        for ( int i = 0 ; i < n ; ++i )
            for ( int j = 0 ; j < L; ++j )
                scanf("%1d",&b[i][j]);

        for ( int i = 0 ; i < n ; ++i )
            for ( int j = i+1 ; j < n ; ++j ) {

                bool f = true ;
                for ( int l = 0 ; l < L ; ++l )
                    if ( b[i][l] != b[j][l] )
                        f = false ;
                if ( f ) {
                    ansfind = false ;
                    goto fail ;
                }
            }

        for ( int i = 0 ; i < n ; ++i ) {

            int cnt = 0 ;
            for ( int j = 0 ; j < L ; ++j ) {
                flag[j] = false ;
                if ( a[i][j] != b[0][j] ) {
                    flag[j] = true ;
                    ++cnt ;
                }
            }

            bool find = true ;
            for ( int j = 0 ; j < n ; ++j ) {

                if ( finds(b[j]) == false )
                    find = false ;
            }
            if (find==true) {

                if ( cnt < ans || ansfind == false )
                    ans = cnt ;
                ansfind = true ;
            }
        }
        fail:
        printf("Case #%d: ",test++);
        if ( ansfind )
            printf("%d\n",ans);
        else
            printf("NOT POSSIBLE\n");
    }
    return 0;
}
