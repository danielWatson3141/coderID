#include "stdio.h"
#include "algorithm"
#include "vector"
#include "utility"

using namespace std;

typedef pair<int,int> P;

const int INF = 1000000000;
const int MAX_N = 1010;

struct node{
  vector<int> ch;
  int size;
};

vector<int> G[MAX_N];
vector<node> tG;
bool used[MAX_N];
int res;

void dfs( int x ){
  used[x] = true;
  for( int i = 0; i < G[x].size(); i++ ){
    if( !used[ G[x][i] ] ){
      tG[x].ch.push_back( G[x][i] );
      dfs( G[x][i] );
    }
  }

  int chsize = tG[x].ch.size();
  tG[x].size = 0;
  if( chsize == 0 ){
    tG[x].size = 1;
  } else if( chsize == 2 ){
    tG[x].size = 1;
    for( int i = 0; i < chsize; i++ ){
      tG[x].size += tG[ tG[x].ch[i] ].size;
    }
  } else if( chsize == 1 ){
    res += tG[ tG[x].ch[0] ].size;
    tG[x].size = 1;
  } else {
    vector<int> c;
    for( int i = 0; i < chsize; i++ ){
      c.push_back( tG[ tG[x].ch[i] ].size );
    }
    sort( c.begin() , c.end() );
    for( int i = 0; i < c.size()-2; i++ ){
      res += c[i];
    }
    tG[x].size = 1 + c[c.size()-2] + c[c.size()-1];
  }
}

int main(){

  FILE *fp = fopen( "B-large.in" , "r" );
  FILE *fo = fopen( "treel.out" , "w" );
  
  int t;
  fscanf( fp , "%d" , &t );

  for( int tc = 1; tc <= t; tc++ ){
    printf( "%d\n" , tc );
    int n;
    fscanf( fp , "%d" , &n );

    // initialize
    for( int i = 0; i < n; i++ )
      G[i].clear();

    for( int i = 0; i < n-1; i++ ){
      int a , b;
      fscanf( fp , "%d %d" , &a , &b ); a--; b--;
      G[a].push_back( b );
      G[b].push_back( a );
    }

    int ans = INF;
    for( int i = 0; i < n; i++ ){
      // make ith node root
      for( int j = 0; j < n; j++ )
	used[j] = false;

      tG.clear();
      tG.resize( n );

      res = 0;

      dfs( i );

      ans = min( ans , res );
    }

    fprintf( fo , "Case #%d: %d\n" , tc , ans );
  }

  return 0;
}
