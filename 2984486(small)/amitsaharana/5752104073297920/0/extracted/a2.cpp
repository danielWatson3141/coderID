//Programmer: Amit Saharana, IIT Delhi 
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
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
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <fstream> 
#include <cassert> 
using namespace std; 
 
#define ll long long 
#define gc getchar
#define pc putchar 
#define endl '\n'

vector<int> a;

int main(){
#ifdef amit
	freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 
	freopen("err.txt","w",stderr); 
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	for(int z=1; z<=t; z++) {
		cout<<"Case #"<<z<<": ";
		int n;
		cin>>n;
		a.resize(n);
		for(int i=0; i<n;i ++) cin>>a[i];
		int tot = 0;
		for(int i=0; i<n;i ++) if(a[i]==i) tot++;
		if(tot>5) cout<<"BAD"<<endl;
		else cout<<"GOOD"<<endl;
	}
	return 0;
}