#include <iostream>
#include<cmath>
#include<iomanip>
#include <fstream>
using namespace std;
int mi[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};


int divide(int a[],int low,int high){
	int k=a[low];
	do {while (low<high&&a[high]>=k)--high;
	if(low<high){a[low]=a[high];++low;}
	while (low<high&&a[low]<=k)++low;
	if(low<high){a[high]=a[low];--high;}
	}while (low!=high);
	a[low]=k;
	return low;
}
void quicksort(int a[],int s,int e){
	if(s>=e)return ;
	int mid=divide(a,s,e);
	quicksort(a,s,mid-1);
	quicksort(a,mid+1,e);
}

int h[1005][1005]={0};
int f[1005]={0};
int que[1005][1005];
void cal(int a,int b){
    if(h[a][b]) return ;
    int ans=0;
    int root=que[a][b];
    if(f[root]<3) {
        h[a][b]=1;return ;
    }
    for(int i=0;i<f[root];++i){
        if(que[root][i]==a)continue;
        cal(root,i);
    }
    for(int i=0;i<f[root];++i){
        for(int j=i+1;j<f[root];++j)
           {
               if(que[root][i]==a||que[root][j]==a) continue;
               ans=ans>(1+h[root][i]+h[root][j])?ans:(1+h[root][i]+h[root][j]);
           }
    }
    h[a][b]=ans;
}
int main(void) {
//	ifstream cin("B-small-practice.in");
    ifstream cin("B-large.in");
 //   ifstream cin("B-small-attempt0.in");
    ofstream cout("ol.out");
    int k;
    cin>>k;
	for(int round=0;round<k;++round){
		int n, max=1;
		cin>>n;
		for(int i=0;i<=n;++i)f[i]=0;
		for(int i=0;i<=n;++i)for(int j=0;j<=n;++j) h[i][j]=0;
		for(int i=1;i<n;++i){
            int a,b;
            cin>>a>>b;
            que[a][f[a]++]=b;
            que[b][f[b]++]=a;
		}
		for(int i=1;i<=n;++i){
            for(int j=0;j<f[i];++j)
                cal(i,j);
		}
		for(int i=1;i<=n;++i){
            for(int j=0;j<f[i];++j)
               for(int cc=j+1;cc<f[i];++cc)
               {  /*cout<<i<<j<<cc<<h[i][j]<<h[i][cc]<<"   ";  */ max=max>(1+h[i][j]+h[i][cc])?max:(1+h[i][j]+h[i][cc]);}

		}
		cout<<"Case #"<<round+1 <<": "<<n-max<<endl;
    }
	return 0;
}
