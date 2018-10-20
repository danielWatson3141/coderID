#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	int t,te;
	int i,j,k;
	cin>>t;
	int n,l;
	int cc;
	bool x[152];
	char a[152][42],b[152][42],c[152][42];
	for(te=1;te<=t;te++){
		cin>>n>>l;
		int minc=1000;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		for(i=0;i<n;i++){
			cc=0;
			for(k=0;k<l;k++)
				if(b[0][k]!=a[i][k])
					cc++;
			for(j=0;j<n;j++){
				x[j]=false;
				for(k=0;k<l;k++)
				{
					if(b[0][k]==a[i][k])
						c[j][k]=a[j][k];
					else
						c[j][k]=(1-(a[j][k]-'0'))+'0';
					
				}
				c[j][l]=a[j][l];
			}
			x[i]=true;
			bool bb=true;
			int ccc=1;
			for(j=1;j<n;j++){
				for(k=0;k<n;k++)
				{
					if(x[k]==false)
					{
						if(strcmp(b[j],c[k])==0){
							x[k]=true;
							ccc++;
							break;
						}
					}
				}
			}
			if(ccc==n){
				if(cc<minc)
					minc=cc;
			}
		}
		cout<<"Case #"<<te<<": ";
		if(minc<=l)
			cout<<minc<<endl;
		else
			cout<<"NOT POSSIBLE"<<endl;

	}
	return 0;
}