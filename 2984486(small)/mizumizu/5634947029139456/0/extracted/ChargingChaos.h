inline VS split(const string& s, const string& delim) {
	VS v;
	size_t start = 0, end = 0;
	while ((end = s.find(delim, start)) != string::npos) {
		v.push_back(s.substr(start, end - start));
		start = end + delim.length();
	}
	v.push_back(s.substr(start));
	return v;
}

struct Case {
	int N;
	int L;
	VS outlet;
	VS device;
};

class ChargingChaos {

public:
	Case readCase( ifstream& ifs ) {
		string line;
		Case c;
		if (getline(ifs, line)) { 
			istringstream si(line);
			si >> c.N >> c.L ;
		}
		if (getline(ifs, line)) {
			c.outlet = split(line, " ");
		}
		if (getline(ifs, line)) {
			c.device = split(line, " ");
		}
		return c;
	}
	bool check(VS outlet, VS device) {
		VS a(outlet);
		VS b(device);
		sort(ALL(a));
		sort(ALL(b));
		FOR(i, 0, a.size()) if (a[i]!=b[i]) return false;
		return true;
	}
	int solve( Case c ) {
		if (check(c.outlet,c.device)) return 0;
		
		FOR(i,1,c.outlet[0].length()+1) {
			string bits(c.outlet[0].length(), '0');
			FOR(b,0,i) bits[b] = '1';
			do {
				//P(bits);
				VS work(c.outlet);
				FORV(o,work) FOR(b,0,bits.length()) {
					if (bits[b] == '1') {
						(*o)[b] = ((*o)[b] == '0' ? '1' : '0');
					}
				}
				if (check(work, c.device)) return i;
			} while(prev_permutation(ALL(bits)));
		}
		return -1;
	}
};
