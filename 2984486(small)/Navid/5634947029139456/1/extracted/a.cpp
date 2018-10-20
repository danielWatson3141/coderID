#include<iostream>
#include<vector>
using namespace std;

int possible(vector<long long> device, vector<long long> out, long long sw) {
	for(int i=0;i<out.size();i++) {
		out[i] ^= sw;
	}
	sort(out.begin(),out.end());
	for(int i=0;i<out.size();i++) {
		if (device[i+1]!=out[i])
			return 0;
	}
	return 1;
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int n, l;
		cin>> n >> l;
		vector<long long> outlet;
		vector<long long> device;
		for(int i=0;i<n;i++) {
			string s;
			cin>>s;
			long long a = 0;
			for(int j=0;j<l;j++) {
				a<<=1;
				a |= s[j]-'0';
			}
			outlet.push_back(a);
		}
		for(int i=0;i<n;i++) {
			string s;
			cin>>s;
			long long a = 0;
			for(int j=0;j<l;j++) {
				a<<=1;
				a |= s[j]-'0';
			}
			device.push_back(a);
		}
		sort(device.begin(),device.end());
		int ans = -1;
		for(int i=0;i<n;i++) {
			long long sw = device[0]^outlet[i];
			long long temp = sw;
			long long tans = 0;
			vector<long long> o = outlet;
			o.erase(o.begin()+ i);
			while(temp>0) {
				tans += temp & 1;
				temp>>=1;
			}
			if (possible(device, o, sw)) {
				if(ans==-1 || tans<ans)
					ans = tans;
			}
		}
		if (ans==-1)
			cout<<"Case #"<<tn+1<<": NOT POSSIBLE"<<endl;
		else
			cout<<"Case #"<<tn+1<<": "<<ans<<endl;
	}
}
