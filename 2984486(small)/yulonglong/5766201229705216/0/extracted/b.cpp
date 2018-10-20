#include <bits/stdc++.h>
#define msize 20
#define INF 2100000000
using namespace std;

int nbor[msize];
vector<int> adjm[msize];
vector<int> oriadjm[msize];
int orinbor[msize];
int num1with3[msize];
bool deleted[msize];

void init(){
	num1with3[0]=2;
	num1with3[1]=3;
	for(int i=2;i<msize;i++){
		num1with3[i]=num1with3[i-1]+1;
	}
}

bool isFullBinaryTree(int n){
	int count[msize];
	memset(count,0,sizeof(count));
	for(int i=1;i<=n;i++){
		count[nbor[i]]++;
	}
	if(count[2]!=1){
		return false;
	}
	else if(num1with3[count[3]]!=count[1]){
		return false;
	}
	else{
		for(int i=4;i<=n;i++){
			if(nbor[i]>3){
				return false;
			}
			if ((nbor[i]==0)&&(!deleted[i])){
				return false;
			}
		}
		return true;
	}
}

void copyToOri(int n){
	for(int i=0;i<=n;i++){
		oriadjm[i]=adjm[i];
		orinbor[i]=nbor[i];
	}
	return;
}

void copyFromOri(int n){
	for(int i=0;i<=n;i++){
		adjm[i]=oriadjm[i];
		nbor[i]=orinbor[i];
	}
	return;
}

void remove(int vertex){
	for(int i=0;i<(int)adjm[vertex].size();i++){
		int vertex2 = adjm[vertex][i];
		nbor[vertex2]--;
		vector<int>::iterator it;
		for(it=adjm[vertex2].begin();it!=adjm[vertex2].end();it++){
			if(*it==vertex){
				adjm[vertex2].erase(it);
				break;
			}
		}
	}
	adjm[vertex].clear();
	nbor[vertex]=0;
	return;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	init();
	int tc;
	cin >> tc;
	for(int d=1;d<=tc;d++){
		memset(nbor,0,sizeof(nbor));
		for(int i=0;i<msize;i++){
			adjm[i].clear();
		}
		int n;
		cin >> n;
		for(int i=1;i<n;i++){
			int x,y;
			cin >> x >> y;
			adjm[x].push_back(y);
			adjm[y].push_back(x);
			nbor[x]++;
			nbor[y]++;
		}
		if(n==2){
			printf("Case #%d: 1\n",d);
			continue;
		}
		
		copyToOri(n);
		int count=INF;
		for(int i=0;i<((1<<n)-1);i++){
			copyFromOri(n);
			memset(deleted,false,sizeof(deleted));
			int tempCount=0;
			int tempi=i;
			//cout << "tempi " << tempi << endl;
			for(int j=1;tempi>0;j++){
				if((tempi&1)==1){
					remove(j);
					deleted[j]=true;
					tempCount++;
				}
				tempi=tempi>>1;
			}
			
			//cout << "fail " << tempCount << endl;
			if(isFullBinaryTree(n)){
				//cout << "pass " << tempCount << endl;
				if(count>tempCount){
					count=tempCount;
				}
			}
		}
		printf("Case #%d: %d\n",d,count);
		
	}
	return 0;
}
