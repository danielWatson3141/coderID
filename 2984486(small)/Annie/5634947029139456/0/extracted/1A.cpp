#include <iostream>
#include <memory>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//#define _LOCAL_USE_

#ifdef _LOCAL_USE_

ifstream fin("1A.in");
ofstream fout("1A.out");
#define cin fin
#define cout fout

#endif
const long long int ONE = 1;

long long int s2ll(const string& s)
{
	int l = s.length();
	long long int rs = 0;
	for(int i = 0; i < l; ++ i){
		if(s[l-1-i] == '1'){
			rs |= (ONE << i);
		}
	}
	return rs;
}

int getMin(long long int status, int c)
{
	int rs = 0;
	while(status > 0){
		if(status%2) ++ rs;
		status /= 2;
	}
	if(c >= 0 && c < rs) rs =c;
	return rs;
}
int main()
{
	int T = 0;
	cin >> T;
	const string yes = "POSSIBLE", no = "NOT POSSIBLE";
	for(int j = 0; j < T; ++ j){
		int n, l;
		cin >> n >> l;

		vector<long long int> out, dev;
		out.assign(n, 0);
		dev.assign(n, 0);

		string temp;
		for(int i = 0; i < n; ++ i){
			cin >> temp;
			out[i] = s2ll(temp);
		}
		for(int i = 0; i < n; ++ i){
			cin >> temp;
			dev[i] = s2ll(temp);
		}
		sort(dev.begin(), dev.end());
			
		cout<<"Case #"<<j+1<<": ";

		int rs = -1;
		for(long long int status = 0; status < (ONE << l); ++ status){
			for(int i = 0; i < n; ++ i) out[i] = (out[i]^status);
			sort(out.begin(), out.end());
			if(mismatch(out.begin(), out.end(), dev.begin()).second == dev.end()){
				rs = getMin(status, rs);
			}
			for(int i = 0; i < n; ++ i) out[i] = (out[i]^status);
		}
		if(rs <0) cout<<no<<endl;
		else cout<<rs<<endl;
	}
	return 0;
}