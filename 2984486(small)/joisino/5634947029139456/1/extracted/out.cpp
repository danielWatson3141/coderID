#include "stdio.h"
#include "algorithm"

using namespace std;

const int INF = 1000000000;
const int MAX_N = 200;
const int MAX_L = 50;

int main(){

  FILE *fp = fopen( "A-large.in" , "r" );
  FILE *fo = fopen( "outl.out" , "w" );

  int t;
  fscanf( fp , "%d" , &t );

  for( int tc = 1; tc <= t; tc++ ){
    int n , l;
    fscanf( fp , "%d %d" , &n , &l );

    char device[MAX_N][MAX_L];
    char outlet[MAX_N][MAX_L];
    for( int i = 0; i < n; i++ )
      fscanf( fp , "%s\n" , device[i] );

    for( int i = 0; i < n; i++ )
      fscanf( fp , "%s\n" , outlet[i] );

    int ans = INF;
    for( int i = 0; i < n; i++ ){
      // 0th device is in ith outlet
      int res = 0;

      // copy
      char outt[MAX_N][MAX_L];
      for( int j = 0; j < n; j++ )
	for( int k = 0; k < l; k++ )
	  outt[j][k] = outlet[j][k];

      // hanten
      for( int j = 0; j < l; j++ ){
	if( outt[i][j] != device[0][j] ){
	  res++;
	  for( int k = 0; k < n; k++ ){
	    if( outt[k][j] == '0' ) outt[k][j] = '1';
	    else outt[k][j] = '0';
	  }
	}
      }

      //check
      bool ok = true;
      bool used[MAX_N] = {};
      for( int j = 0; j < n; j++ ){
	bool mok = false;
        for( int k = 0; k < n; k++ ){
	  if( used[k] ) continue;
	  bool mmok = true;
	  for( int p = 0; p < l; p++ ){
	    if( outt[j][p] != device[k][p] ){
	      mmok = false;
	      break;
	    }
	  }
	  if( mmok ){
	    used[k] = true;
	    mok = true;
	    break;
	  }
	}
	if( !mok ){
	  ok = false;
	  break;
	}
      }
      
      if( ok ){
	ans = min( ans , res );
      }
    }

    if( ans < INF ) fprintf( fo , "Case #%d: %d\n" , tc , ans );
    else fprintf( fo , "Case #%d: NOT POSSIBLE\n" , tc );
  }

}
