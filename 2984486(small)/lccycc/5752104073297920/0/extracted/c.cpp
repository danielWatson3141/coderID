#include <iostream>
using namespace std;
int a[1000 + 10];
int n;
int main(){
	int T, cas = 0;
	int badcnt = 0;
	for (cin>>T; T--;){
		cas++;
		cout<<"Case #"<<cas<<": ";
		cin>>n;
		for (int i = 0; i<n; i++) cin>>a[i];
		int bad = 0;
		for (int i = 0; i<n; i++) bad += (a[i] == i);

		cerr<<bad<<endl;
		bool isbad = (bad>1);

		badcnt += isbad;
		if (bad>1) cout<<"BAD"<<endl;else cout<<"GOOD"<<endl;
	}
	cerr<<badcnt<<endl;
	return 0;
}

