#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
pair< int , int > pii ;
map< int , int > my_map ;

#define fi(i,a,b) for( i = a ; i <= b ; i++ )
#define fd(i,a,b) for( i = a ; i >= b ; i-- )
#define dbg(x) cout << #x << ":" << x << endl


char str[300],ch;
string org_flow[160] , chg_flow[160] , req_flow[160] ;
map< string , int > mapsi ;
int main()
{
	long long int k,i=1,t,flag=0;
	char ch,s;

	ifstream ip("in.txt");
	ofstream op("out.txt");
	ip>>t;
	//p.get(ch);
    //cout << t << endl ;
	int n , l ;

	for(k=1;k<=t;k++)
	{

		//p.getline(str,300);
		ip >> n >> l ;
		mapsi.clear() ;
        cout << n << " " << l << endl ;
		for( i = 0 ; i < n ; i++  ) { ip >> org_flow[i] ; chg_flow[i] = org_flow[i] ; }
        for( i = 0 ; i < n ; i++  ) { ip >> req_flow[i] ; mapsi[ req_flow[i] ]++; }

        bool status[160] , flag ;
        int min_count = INT_MAX , counter , j ;
        cout << "test case :" << endl ;

        for(  i = 0 ; i < n ; i++ ) {

            memset( status , false , sizeof(status ) ) ;
            for( j = 0 ; j < n ; j++ ) chg_flow[j] = org_flow[j] ;
            flag = false ;
            cout << "checking each : " << endl ;

                for( j = 0 ; j < n ; j++ ) {

                    int l = 0 ;

                    if( j == 0 ) {
                            counter = 0 ;
                        while( chg_flow[i][l] && req_flow[j][l] ) {
                            if( chg_flow[i][l] != req_flow[j][l] ) {
                                    status[l] = true ; counter++ ;
                            }
                            l++ ;
                        }
                        cout << " j = 0 " << endl ;
                    }

                        l = 0 ;

                        for( l = 0 ; l < n ; l++ ) {
                            int s = 0 ;
                            while( chg_flow[l][s] ) {
                                if( status[s] ) {
                                    if( chg_flow[l][s] == '1' ) chg_flow[l][s] = '0' ;
                                    else chg_flow[l][s] = '1' ;
                                }
                                s++ ;
                            }
                            if( !mapsi[ chg_flow[l] ] ) { flag = true ; break ; }
                            cout << "iterating all " << endl ;
                        }
                        if( !flag ) { if( min_count > counter ) min_count = counter ; }

                }
        }



		op<<"Case #"<<k<<": ";
		if( min_count == INT_MAX ) op << "NOT POSSIBLE" << endl ;
		else op << min_count << endl ;
	}
	ip.close();
	op.close();
	return 0;
}
