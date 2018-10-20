#include<iostream>
#include<vector>

using namespace std;
vector<int> *tree;

int count(int n,int root) {

	int c=1;
	for(int i=0;i<tree[n].size();i++) {
		if(tree[n][i]==root) continue;
		c+=count(tree[n][i],n);
	}
	return c;

}

int count_children(int n,int &q) {

	int children=999999;
	for(int i=0;i<tree[n].size();i++) {
		int c=count(tree[n][i],n);
		if(c<children) {
			children=c;
			q=i;
		}
	}
	return children;

}

int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=0; n<nCases; n++) {
		cout<<"Case #"<<n+1<<": ";
		int N;
		cin>>N;	
		tree = new vector<int> [N];
		int nodes[N];
		for(int i=0;i<N;i++) nodes[i]=0;
		for(int i=0;i<N-1;i++) {
			int x,y;
			cin>>x>>y;
			x--;y--;
			tree[x].push_back(y);
			tree[y].push_back(x);
			nodes[x]++;
			nodes[y]++;
		}
		
		int wrong=0;
		vector<int> badnodes;
		for(int i=0;i<N;i++) {
			if(nodes[i]!=1 && nodes[i]!=3) {
				wrong++;
				badnodes.push_back(i);
			}
		}
		
		if(N==2) {
			cout<<1<<endl;
			delete [] tree;
			continue;
		}
		
		if(wrong==0) {
			cout<<1<<endl;
			delete [] tree;
			continue;
		}
		if(wrong==1) {
			cout<<0<<endl;
			delete [] tree;
			continue;
		}
		int changes=0;
		while(wrong>1) {
			int children=9999999;
			int q=0;
			int i0=0;
			for(int i=0;i<badnodes.size();i++) {
				int qq;
				int c=count_children(badnodes[i],qq);
				if(c<children) {
					children=c;
					q=qq;
					i0=i;
				}
			}
			int k=badnodes[i0];
			tree[k].erase(tree[k].begin()+q);
			nodes[k]--;
			if(nodes[k]==1 || nodes[k]==3) {
				badnodes.erase(badnodes.begin()+i0);
				wrong--;
			}
			changes+=children;
		}
		cout<<changes<<endl;
		delete [] tree;
	}
	
	return 0;
	
}
