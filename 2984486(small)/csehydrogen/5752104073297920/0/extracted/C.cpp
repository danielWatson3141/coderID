#include <cstdio>
#include <cstdlib>





int a[1000],n;
double goodavg[1001];
double badavg[1001];
double good=249250.57142857142857142857142857;
double bad=239990.33333333333333333333333333;

void goodd(){
	int k,p,tmp;
	for(k=0;k<n;k++)
		a[k]=k;
	for(k=0;k<n;k++){
		p=rand()%(n-k)+k;
		tmp=a[p]; a[p]=a[k]; a[k]=tmp;
	}
}

void badd(){
	int k,p,tmp;
	for(k=0;k<n;k++)
		a[k]=k;
	for(k=0;k<n;k++){
		p=rand()%n;
		tmp=a[p]; a[p]=a[k]; a[k]=tmp;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ti,t,i,j,k,inv,sum,cnt=50;
	for(n=1;n<=1000;n++){
		sum=0;
		for(k=0;k<cnt;k++){
			goodd();
			inv=0;
			for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)
					if(a[i]>a[j])
						inv++;
			sum+=inv;
		}
		goodavg[n]=(double)sum/cnt;
		sum=0;
		for(k=0;k<cnt;k++){
			badd();
			inv=0;
			for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)
					if(a[i]>a[j])
						inv++;
			sum+=inv;
		}
		badavg[n]=(double)sum/cnt;
	}
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		inv=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(a[i]>a[j])
					inv++;
		double mid=(goodavg[n]+badavg[n])/2;
		printf("Case #%d: ",ti);
		if(inv>mid){
			printf("GOOD\n");
		}else{
			printf("BAD\n");
		}
	}
	return 0;

}

/*#include <cstdio>
#include <cstdlib>
#include <ctime>

int n=1000,cnt=5000;
int a[1000];

void good(){
	int k,p,tmp;
	for(k=0;k<n;k++)
		a[k]=k;
	for(k=0;k<n;k++){
		p=rand()%(n-k)+k;
		tmp=a[p]; a[p]=a[k]; a[k]=tmp;
	}
}

void bad(){
	int k,p,tmp;
	for(k=0;k<n;k++)
		a[k]=k;
	for(k=0;k<n;k++){
		p=rand()%n;
		tmp=a[p]; a[p]=a[k]; a[k]=tmp;
	}
}

int main(){
	srand(time(NULL));
	
	int l,i,j,inv,sum;

	sum=0;
	for(l=0;l<cnt;l++){
		bad();
		inv=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(a[i]>a[j])
					inv++;
		sum+=inv;
	}
	printf("avg : %d %d\n",sum,sum/cnt);

	system("PAUSE");
	return 0;
}*/