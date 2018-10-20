#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef struct node{
	int value;
	int a[1000];
	int link; 
}node;

vector< node > tree;
int find(node node,int father){
	int t;
	t=0;
	int s[1000];
	int c=0,m1=0,m2=0;
	for(int i=0;i<1000;i++)
		s[i]=0;
	for(int i=0;i<node.link;i++){
		if(node.a[i]!=father && node.a[i]!=0)
			t++;
	}
	if(t==0||t==1)
		return 1;
	else{
		for(int i=0;i<node.link;i++){
			if(node.a[i]!=father && node.a[i]!=0){
				s[c]=find(tree[node.a[i]-1],node.value);	
				c++;
			}
		}
		for(int i=0;i<c;i++){
			if(s[i]>m1 && s[i]>m2){
				if(m1>m2)
					m1=s[i];
				else
					m2=s[i];
			}
			else if(s[i]>m1){
				m1=s[i];
			}	
			else if(s[i]>m2){
				m2=s[i];
			}
		}
		return m1+m2+1;
	}
	
}
int main(){
	int T;
	cin>>T;
	int n;
	int p,q;
	node tnode;
	int ans;
	int m;
	for(int x=1;x<=T;x++){
		cin>>n;
		//reset
		ans=n;
		for(int i=0;i<1000;i++)
			tnode.a[i]=0;
		tnode.link=0;
		for(int i=0;i<n;i++){
			tnode.value=i+1;
			tree.push_back(tnode);
		}
		//cout<<tree.size()<<endl;
		for(int i=0;i<n-1;i++){
			cin>>p;
			cin>>q;
			tree[p-1].a[tree[p-1].link]=q;
			tree[p-1].link++;
			tree[q-1].a[tree[q-1].link]=p;
			tree[q-1].link++;
		}
		for(int i=0;i<n;i++){
			m=find(tree[i],-1);
			if(n-m < ans )
				ans = n-m;
		}

		printf("Case #%d: %d\n",x,ans);

		tree.clear();


	}
	return 0;
}