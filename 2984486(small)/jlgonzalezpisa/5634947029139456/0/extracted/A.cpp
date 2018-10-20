#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

int main () {

    int T, N, L;
    freopen ( "input.in", "r", stdin );
    freopen ( "output.out", "w", stdout );
    
    cin >> T;
    
    for ( int n=1; n<=T; n++ ) {
        
        cin >> N >> L;    
        int count, min = INT_MAX;
        string read;
         
        // Clean bitsets
        vector < bitset<10> > req, //( N, bitset<10>() ), 
                            init,// (N, bitset<10>() ), 
                            reqAux;// (N, bitset<10>() );
        
        
        // read init
        for ( int i=0; i<N; i++ ) {
            cin>>read;
            init.push_back( bitset<10>( read ) ) ;
        }
        
        // read req
         for ( int i=0; i<N; i++ ) {
            cin>>read;
            req.push_back( bitset<10>( read ) ) ;
        }
        
        // Traverse req 
        for ( int r=0; r<N; r++ ) {
            
            // Traverse init
            for ( int i=0; i<N; i++ ) {
                count = 0;
                vector < bitset<10> > changes ( init );
                
                // Count necessary changes
                for ( int j=0; j<L; j++ ) {
                
                    if ( req[r][j] != init[i][j] ) {
                        // flip all j indexes in changes
                        for ( int k=0; k<N; k++ ) { 
                            changes [k].flip(j);
                        }
                        count ++;
                    }
                    
                    // Verify all others matching
                    vector < bitset<10> > reqAux( req );
                    vector < bitset<10> >::iterator found;
                    for ( int k=0; k<N; k++ ) {
                    
                        found = find ( reqAux.begin(), reqAux.end(), changes[k] );
                        
                        if ( found != reqAux.end() ) {
                            reqAux.erase ( found );
                        } 
                        
                    }
                    
                    // compare with min
                    if ( reqAux.empty() && count < min) {
                    
                        min = count;
                        
                    } // End min comparing
                    
                } // End counting necessary changes
                

            } // End traversing init
        
        } // End traversing  req
        
        
        if ( min < INT_MAX ) {
            cout << "Case #" << n << ": " << min << endl;
        }
        else {
            cout << "Case #" << n << ": NOT POSSIBLE" << endl;
        }
        
    
    }
    
    fclose ( stdin );
    fclose ( stdout );
    return 0;
    

}

/***************** function ***************/

/***************** *** ***************/
