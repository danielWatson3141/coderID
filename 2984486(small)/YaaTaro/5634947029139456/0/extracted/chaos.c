#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i,n,q,j,r,s,l,min,ch,k,count;
char a[200][50],b[200][50],c[200][50];
int cmp(const void* a,const void*  b){
	return strcmp(a,b);
}
char che(char bb){
	return (bb=='0')?'1':'0';
}
int main(){
	freopen("A-small-attempt0.in","r+",stdin);
	freopen("A-small-attempt0.out","w+",stdout);
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		min=100;
		printf("Case #%d: ",i);
		scanf("%d %d",&n,&l);
		for(j=0;j<n;j++)
			scanf("%s",a[j]);
		for(j=0;j<n;j++)
			scanf("%s",b[j]);
		qsort(b,n,sizeof b[0],cmp);
	/*	for(j=0;j<n;j++)
			printf("%s ",b[j]);
		printf("\n");*/
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				count=0;
				for(r=0;r<n;r++)
					strcpy(c[r],a[r]);
			/*	for(r=0;r<n;r++)
						printf("%s ",c[r]);
					printf("\n");*/
				for(r=0;r<l;r++){
					if(a[j][r]!=b[k][r]){
						for(s=0;s<n;s++)
							c[s][r]=che(c[s][r]);
						count++;
					}
				}
			/*	if(j==0&&k==1){
					printf("\n");
					for(r=0;r<n;r++)
						printf("%s ",c[r]);
					printf("\n");
				}*/
				ch=1;
				qsort(c,n,sizeof c[0],cmp);
				for(r=0;r<n;r++){
					if(strcmp(c[r],b[r])){
						ch=0; break;
					}
				}
				if(ch){
					if(count<min)
						min=count;
				}
			}
		}
		if(min==100)	printf("NOT POSSIBLE\n");
		else			printf("%d\n",min);
	}
	return 0;
}
