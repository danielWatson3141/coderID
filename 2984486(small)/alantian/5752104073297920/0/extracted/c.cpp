#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int n = 1000;

double f[n][n], sf[n], nf[n][n];

void g(){
    memset(f, 0,sizeof(f));
    memset(nf,0,sizeof(nf));

    for( int i = 0; i < n; i++ )
        f[i][i] = 1.0;

    for( int k = 0; k < n; k++ ){
        memset(sf,0,sizeof(sf));
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ )
                sf[i] += f[i][j];
 
        memset(nf,0,sizeof(nf));
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ ){
                double t = 0;
                if ( j == k )
                    t = sf[i];
                else
                    t = f[i][j]*(n-1) + f[i][k];
                t /= n;
                nf[i][j] = t;
            }

        memcpy(f,nf,sizeof(nf));
    }
}

int a[n];

int main(){
    g();
    int T; cin >> T;
    for ( int C = 1; C <=T; C++ ){
        int nn; cin >> nn;
        for( int i = 0; i < n; i++ )
            cin >> a[i];
        double pbad = 0.0;
        for( int i = 0; i < n; i++ )
            pbad += log( f[a[i]][i] );
        double pgood = n * log( 1.0/n );
        string ans;
        if ( pgood > pbad )
            ans = "GOOD";
        else
            ans = "BAD";

        cout << "Case #" <<C << ": " << ans << endl;
//        cout << pgood << " " << pbad << endl;
    }
    return 0;
}
