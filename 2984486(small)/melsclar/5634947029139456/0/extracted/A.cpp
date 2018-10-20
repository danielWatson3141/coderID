#include <iostream>
#include <cstdio>
using namespace std;

long long int  begin[256], end[256];

long long int toBits( long long int m ) {
	long long int res = 0;
	long long int pow = 1;
	while( m != 0 ) {
		res += pow*(m%10);
		m/=10;
		pow *=2;
	}
	return res;
}

int main () {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,n,l,aux;
	cin >> t;
	for( int tc=1; tc<=t;tc++ ) {
		cin >> n >> l;
		for(int i=0;i<n;i++) {
			cin >> aux;
			begin[i] = toBits(aux);
		}
		for( int i =0;i<n;i++ ) {
			cin >> aux;
			end[i] = toBits(aux);
		}
		
		int minCantSwitch = 100000000;
		for( int i=0;i<n;i++ ) {
			// el primero de begin matcheara con el i esimo de end
			int beginAux[256];
			int cantSwitch = 0;
			for( int j=0; j< n; j++ ) {
				beginAux[j] = begin[j];
			}
			
			//cout << "lalala" << i << endl;
			for( int j = 0; j < l; j++ ) {
				// EL J DE BEGIN0 ES DISTINTO AL J DE ENDI
				//cout << (1<<j) << " "<< beginAux[0] << " " << (beginAux[0] & (1 << j)) << " " <<(end[i] & (1 << j)) << endl;
				if( (beginAux[0] & (1 << j)) != (end[i] & (1 << j)) ) {
					//SWITCHEO EN TODOS LOS DE BEGIN AUX
					//cout << i << " " << j << endl;
					for( int k = 0; k < n ; k++ ) {
						beginAux[k] = (beginAux[k] ^ (1 << j));
						//cout << beginAux[k] << " " ;
					}
					cantSwitch++;
				}
			}
			
			bool matcheo = true;
			for( int j = 0; j < n; j++ ) {
				bool existe = false;
				for( int k = 0; k < n; k++ ) {
					if( end[j] == beginAux[k] ) {
						existe = true;
						break;
					}
				}
				if( !existe ) {
					matcheo = false;
					break;
				}
			}
			
			if ( matcheo && cantSwitch < minCantSwitch ) {
				minCantSwitch = cantSwitch;
			}
		}
		
		if ( minCantSwitch > 1000000 ) {
			cout << "Case #" << tc << ": NOT POSSIBLE"<<endl;
		}
		else {
			cout << "Case #" << tc << ": " << minCantSwitch << endl;
		}
	}
	return 0;
}
