#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;

ll N, L;

int min(ll a, ll b) {
	if(a < b) {
		return a;
	} else {
		return b;
	}
}

bool is_good(vl outlet, vl device, ll p)
{
	ll mask = (1 << (p+1)) - 1;
	vl newoutlet;
	vl newdevice;
	for(int i = 0; i < N; i++) {
		newoutlet.push_back(outlet[i] & mask);
		newdevice.push_back(device[i] & mask);
	}

	sort(newoutlet.begin(), newoutlet.end());
	sort(newdevice.begin(), newdevice.end());

	for(int i = 0; i < N; i++) {
		//cout << newdevice[i] << " " << newoutlet[i] << endl;
		if(newdevice[i] != newoutlet[i]) {
			return false;	
		}
	}
	return true;
}

ll MAX = 10000;

ll solve(vl outlet, vl device, ll p)
{
	if (p == L) {
		return 0;
	}
	
	ll s1 = MAX;
	if(is_good(outlet, device, p)) {
		s1 = solve(outlet, device, p+1);
	}

	for(int i = 0; i < N; i++) {
//		cout << "o " << outlet[i];
		outlet[i] ^= (1 << (p));
	//	cout << " " << outlet[i] << endl;
	}
	ll s2 = MAX;
	if(is_good(outlet, device, p)) {
		s2 = solve(outlet, device, p+1) + 1;
	}
	//ll s2 = solve(outlet, device, p+1) + 1;
	//cout << "s12 " << s1 << " " << s2 << endl;
	return min(s1, s2);
}


int main()
{

	ll T;
//	vector<string> outlet;
	//vector<string> device;

	cin >> T;
	for(int t = 1; t <= T; t++) {
		vl outlet;
		vl device;
		cin >> N >> L;
		for(int i = 0; i < N; i++) {
			string s;
			cin >> s;
			ll b = 0;
			for(unsigned long  i = 0; i < s.size(); i++) {
				if(s[i] == '1') {
					b += 1;
				}
				b = b << 1;
			}
			b = b >> 1;
			outlet.push_back(b);
		}

		for(int i = 0; i < N; i++) {
			string s;
			cin >> s;

			ll b = 0;
			for(unsigned long  i = 0; i < s.size(); i++) {
				if(s[i] == '1') {
					b += 1;
				}
				b = b << 1;
			}
			b = b >> 1;
			device.push_back(b);
			//cout << s << " " << b << endl;
		}
/*
		for(int i = 0; i < N; i++) {
			cout << "nw " << outlet[i] << " " << device[i] << endl;
		} */
		ll res = solve(outlet, device, 0);

		if(res < MAX) 
			cout << "Case #" << t << ": " << res << endl;
		else
			cout << "Case #" << t << ": NOT POSSIBLE" << endl;
	}
	return 0;
}
