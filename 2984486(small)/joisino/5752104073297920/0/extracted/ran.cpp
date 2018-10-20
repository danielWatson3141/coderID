#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "algorithm"
#include "vector"
#include "functional"

using namespace std;

int main(){
  
  srand( (unsigned int)time( NULL ) );

  FILE *fp = fopen( "C-small-attempt3.in" , "r" );
  FILE *fo = fopen( "rans.out" , "w" );

  int d[20] = {};

  int c[30] = {};

  int t , n;
  fscanf( fp , "%d %d", &t , &n );

  vector<int> a(n);
  vector<int> ini(n);
  for( int k = 1; k <= t; k++ ){
    for( int i = 0; i < n; i++ )
      fscanf( fp , "%d" , &ini[i] );

    a = ini;
    for( int i = n-1; i >= 0; i-- ){
      int p = rand()%n;
      swap( a[i] , a[p] );
    }

    int bres = n;
    for( int i = 0; i < n; i++ )
      if( a[i] == i ) bres--;

    a = ini;
    for( int i = n-1; i >= 0; i-- ){
      int p = rand()%(n-i)+i;
      swap( a[i] , a[p] );
    }

    int gres = n;
    for( int i = 0; i < n; i++ )
      if( a[i] == i ) gres--;

    if( bres < gres ) fprintf( fo , "Case #%d: BAD\n" , k );
    else if( bres > gres ) fprintf( fo , "Case #%d: GOOD\n" , k );
    else if( rand()%2 == 0 ) fprintf( fo , "Case #%d: BAD\n" , k );
    else fprintf( fo , "Case #%d: GOOD\n" , k );
  }


  return 0;
}

