#include <fstream>
#include <string>
#include <vector>
using namespace std;

int l;

void remove(vector<string> & a, int pos){ 
	int lastIndex = a.size()-1; 
	int k;  
	for(k=pos; k < lastIndex; k++) { 
		a[k] = a[k+1]; 
	}  
	a.pop_back();
}

int Switch(string & initial, string & target, string & answer) {
	int change=0;
	for (int i=0;i<l;i++) {
		if (initial[i]!=target[i]) {answer+="1"; change++;}
		else answer+="0";
	}
	return change;
}

bool Find(vector<string> & v, string & f) {
	for (int i=0;i<v.size();i++)
		if (v[i]==f) return true;
	return false;
}

int main() {

	ifstream input("input.txt");
	ofstream out("out.txt");
	int t;
	input >> t;
	for (int i=0;i<t;i++) {
		int n;
		input >> n >> l;
		vector<string> flows;
		vector<string> devices;
		vector<vector<string>> strategies(l+1);
		string temp;
		for (int k=0;k<n;k++) {
			input >> temp;
			flows.push_back(temp);
		}
		for (int k=0;k<n;k++) {
			input >> temp;
			devices.push_back(temp);
		}
		for (int k=0;k<n;k++) {
			string s;
			int rank = Switch(flows[k],devices[0],s);
			strategies[rank].push_back(s);
		}
		bool is_found=false;
		for (int rank=0;!is_found && rank<l+1;rank++) {
			for (int s=0;!is_found && s<strategies[rank].size();s++) {
				bool everything=true;
				for (int k=1;k<n;k++) {
					string temp;
					Switch(devices[k],strategies[rank][s],temp);
					if (!Find(flows,temp)) {everything=false;break;}
				}
				if (everything) {out << "Case #" << (i+1) << ": " << rank << endl; is_found=true;}
			}
		}
		if (!is_found) {out << "Case #" << (i+1) << ": " << "NOT POSSIBLE" << endl;}
	}
	out.close();
	return 0;
}