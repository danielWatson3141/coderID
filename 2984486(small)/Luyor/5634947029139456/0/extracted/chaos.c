#include <stdio.h> 
long long a[45],b[45];
int n,m,ans;

void sort(long long a[]){
	int i,j;long long tmp;
	for (i=0;i<n-1;i++){
		for (j=i+1;j<n;j++){
			if (a[i]>a[j]){
				tmp=a[i];a[i]=a[j];a[j]=tmp;
			}
		}
	}
}

int compare(int x){
	int i;
	for (i=0;i<n;i++){
		if ((a[i]>>x)!=(b[i]>>x))return 0;
	}
	return 1;
}

int search(int x,int y){
	if (ans<=y) return m+1;
	if (x==m){
		ans=y;
	}else{
		int i,j,k;
		if (compare(m-x-1))k=search(x+1,y);
		for (i=0;i<n;i++)b[i]=b[i]^(1<<m-x-1);
		sort(b);
		if (compare(m-x-1))j=search(x+1,y+1);
		for (i=0;i<n;i++)b[i]=b[i]^(1<<m-x-1);
		if (j>k)k=j;return k;
	}
}

int main(){
	FILE *in,*out;
	in=fopen("chaos.in","r");
	out=fopen("chaos.out","w");
	
	int i,t;
	fscanf(in,"%d",&t);
	for (i=1;i<=t;i++){
		int j,k;
		char w;
		for (j=0;j<n;j++){a[j]=0;b[j]=0;}
		fscanf(in,"%d%d",&n,&m);fscanf(in,"%c",&w);
		for (j=0;j<n;j++){
			for (k=m-1;k>=0;k--){
				fscanf(in,"%c",&w);
				if (w=='1')a[j]+=1<<k;
			}
			fscanf(in,"%c",&w);
		}
		for (j=0;j<n;j++){
			for (k=m-1;k>=0;k--){
				fscanf(in,"%c",&w);
				if (w=='1'){b[j]+=1<<k;}
			}
			fscanf(in,"%c",&w);
		}
		sort(a);sort(b);
		ans=m+1;
		search(0,0);
		fprintf(out,"Case #%d: ",i);
		if (ans>m)fprintf(out,"NOT POSSIBLE\n");
		else fprintf(out,"%d\n",ans);
	}
	fclose(in);fclose(out);
	return 0;
} 