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
string cha(string s1,string s2){
    string ans="";
    int n=s2.length();
    for(int i=0;i<n;++i)
      ans+=(s1[i]==s2[i])?"0":"1";
    return ans;
}

int main(void) {
//	ifstream cin("A-small-attempt1.in");
    ifstream cin("A-large.in");
 //   ifstream cin("i.in");
    ofstream cout("ol.out");
    int k;
    cin>>k;
	for(int round=0;round<k;++round){
		int n, l;
		cin>>n>>l;
		bool flag=0;
		int min=50;
		string a[200], b[200], c[200][200];
		for(int i=0;i<n;++i) cin>>a[i];//cout<<a[i];
		for(int i=0;i<n;++i) cin>>b[i];
		for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                c[i][j]=cha(a[i],b[j]);
            }
		}
		for(int time=0;time<n;++time){
            string chu=c[0][time];// cout<<"chu  "<<chu;
            int i=1;
            for(;i<n;++i){
                int j=0;
                for(;j<n;++j)
                    if(c[i][j]==chu) break;
                if(j==n) break;
            }//cout<<i;
            if(i==n){
                flag=1;
                int count=0;
                for(int x=0;x<l;++x) count+=bool(chu[x]=='1');
                min=min<count?min:count;
            }
		}
	    if(flag==0)cout<<"Case #"<<round+1 <<": "<< "NOT POSSIBLE" <<endl;
	    else cout<<"Case #"<<round+1 <<": "<<min<<endl;
    }
	return 0;
}
