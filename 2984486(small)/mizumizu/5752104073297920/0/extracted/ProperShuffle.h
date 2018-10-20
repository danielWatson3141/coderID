struct Case {
	int N;
	VI  P;
};

class ProperShuffle {

public:
	template<class T>
	inline T toint(const string& s) {
		T v;
		istringstream si(s);
		si >> v;
		return v;
	}
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
	Case readCase( ifstream& ifs ) {
		string line;
		Case c;
		if (getline(ifs, line)) { 
			istringstream si(line);
			si >> c.N;
		}
		if (getline(ifs, line)) {
			VS vs = split(line, " ");
			FORV(s,vs) c.P.push_back(toint<int>(*s));
		}
		return c;
	}
	
	string solve( Case c ) {
		LL sum = 0;
		FOR(i,0,c.N) {
			sum += c.P[i];
		}
				
		LL sum1 = 0;
		FOR(i,0,c.N/2) {
			sum1 += c.P[i];
		}
		LL sum2 = 0;
		FOR(i,c.N/2,c.N) {
			sum2 += c.P[i];
		}
		if (sum1>sum2)
			return "BAD";
		else 
			return "GOOD";
	}
};
