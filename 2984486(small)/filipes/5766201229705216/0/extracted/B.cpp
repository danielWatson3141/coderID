#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int n,mm,a,b,x,kolo;
vector<vector<int> > v;
vector<int> pod;
vector<bool> je;

void dfs(int kde){
	je[kde]=true;
//	cout<<"tusom: "<<kde<<endl;
	int ma=0;
	int a1=0,a2=0;
	for(int i=0;i<v[kde].size();i++){
//		cout<<"p";
		if(je[v[kde][i]]) continue;
//		cout<<"i";
		dfs(v[kde][i]);
		x=v[kde][i];
		ma++;
		if(pod[x]>=a1){
			a2=a1; a1=pod[x];
		}
		if(pod[x]>a2 && pod[x]<a1) a2=pod[x];

	}
	pod[kde]=a1+a2;
	if(ma>1) pod[kde]+=2;
	else pod[kde]=0;
//	kolo+=pod[kde];
	return;

}

int main(){
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n;
		v.resize(0);
		v.resize(n,vector<int> (0));
		pod.resize(n);
		je.resize(n);
		mm=-1;
		for(int i=0;i<n-1;i++){
			cin>>a>>b; a--; b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}


		for(int i=0;i<n;i++){
	//		cout<<i<<" *\n";
			for(int j=0;j<n;j++) je[j]=false;
			kolo=1;
			dfs(i);
			kolo=1+pod[i];
	/*		for(int j=0;j<n;j++){
				printf("%d=%d  ",j,pod[j]); cout<<endl;
				if(pod[j]!=0) kolo+=2;
			}
			cout<<"kolo "<<kolo<<endl;*/
			mm=max(mm,kolo);


		}
	//	cout<<mm<<endl;
		printf("Case #%d: %d\n",t+1,n-mm);



	}
	return 0;
}
