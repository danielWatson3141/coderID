#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long int tint;

int main()
{
	int t, n, l;
	tint apar[200];
	tint out[200];
	tint mult[200][200];
	map< tint, set<int> > filas;
	map< tint, set<int> > col;

	cin >> t;
	string a, o;
	forn(caso, t)
	{		
		cin >> n >> l;
		tint num;
		forn(i,n){
			num = 0;
			cin >> a;
			forn(j,l){
				if(a[j] == '1') num += (1 << (l-1-j));
			}
			apar[i] = num;
		}
		forn(i,n){
			num = 0;
			cin >> a;
			forn(j,l){
				if(a[j] == '1') num += (1 << (l-1-j));
			}
			out[i] = num;
		}

		/*forn(i,n) cout << apar[i] << " ";
		cout << endl;
		forn(i,n) cout << out[i] << " ";
		cout << endl; cout << endl;*/

		forn(i,n){
			forn(j,n){
				mult[i][j] = apar[i] xor out[j];
				filas[ mult[i][j] ].insert(i);
				col[ mult[i][j] ].insert(j);
			}
		}

		/*forn(i,n){
			forn(j,n){
				cout << mult[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/

		int res = -1;

		map<tint, set<int> >::iterator it;
		map<tint, set<int> >:: iterator auxit = col.begin();
		set<int>:: iterator sit;

		/*cout << "filas " << endl;
		for(it = filas.begin(); it != filas.end(); ++it){
			cout << (it->first) << " : " << endl;
			for(sit = (it->second).begin(); sit != (it->second).end(); sit++){
				cout << *sit << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "columnas " << endl;
		for(it = col.begin(); it != col.end(); ++it){
			cout << (it->first) << " : " << endl;
			for(sit = (it->second).begin(); sit != (it->second).end(); sit++){
				cout << *sit << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		
		for(it = filas.begin(); it != filas.end(); ++it){
			tint val = it->first;
			int cand = 0;
			
			forn(i,l){
				if( val & (1 << i) ) cand++;
			}
			//cout << val << endl;
			if( (res == -1) or (cand < res) ){
				//cout << (it->second).size() << " " << (auxit->second).size() << endl;
				if( ( (it->second).size() == n ) and ( (auxit->second).size() == n) ){
					res = cand;
				}
			}
			auxit++;
		}
		
		cout << "Case #" << (caso+1) << ": ";
		if(res == -1){
			cout << "NOT POSSIBLE" << endl;
		}
		else{
			cout << res << endl;
		}

		filas.clear();
		col.clear();
	}
	
	return 0;
}
