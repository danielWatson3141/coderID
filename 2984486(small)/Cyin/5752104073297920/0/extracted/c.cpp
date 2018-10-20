#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<iostream>
#include<vector>
using namespace std;
int n;
void test(){
    int i,j,k,l,o,sum=0;
    int x;
    map<int,int> h;
    for (i=0;i<4;i++)
    for (j=0;j<4;j++)
    for (k=0;k<4;k++)
    for (l=0;l<4;l++)
    {
        int b[4]={0,1,2,3};
        swap(b[0],b[i]);
        swap(b[1],b[j]);
        swap(b[2],b[k]);
        swap(b[3],b[l]);
        x=0;
        for (o=0;o<4;o++) x=x*10+b[o];
        h[x]++;
        
    }
    map<int,int>::iterator it;
    for(it=h.begin();it!=h.end();++it)
        cout<<"key: "<<it->first <<" value: "<<it->second<<endl;
} 
int a[2][1010],b[1010];
int vis[1010];  
int geta(int p){
    vector <int> x;
    double limit;
    int i,j,left,sum,last;
    x.clear();
    if (p==0) limit=1.0/4.0;
    else limit=3.0/4.0;
    for (i=0;i<n;i++) a[p][i]=0;
    for (i=0;i<n;i++){
        left=n-i;
        int k=(int)(left*limit);
        x.push_back(k+1);
        limit=(limit-double(k)/left)*left;
    }
    memset(vis,0,sizeof(vis));
    for (i=0;i<n;i++){
        sum=0;
        for (j=0;j<n;j++){
            if (!vis[j]){
                sum++;
                last=j;
            }
            if (sum==x[i]) break;
        }
        vis[last]=1;
        a[p][i]=last;
    }   
}  
int check(int x[1010],int y[1010]){
    int i;
    for (i=0;i<n;i++)
        if (x[i]<y[i]) return -1;
        else if (x[i]>y[i]) return 1;
    return 0;
}
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout); 
    int ca,cc,sum;
    int i,j;
//    test();
//    n=4;
//    geta(0);
//    geta(1);
//    for (i=0;i<n;i++) printf("%d ",a[0][i]);
 //   printf("\n");
//    for (i=0;i<n;i++) printf("%d ",a[1][i]);
//    printf("\n");
    scanf("%d",&ca);
    for (cc=1;cc<=ca;cc++){
        scanf("%d",&n);
//        geta(0);
//        geta(1);
        for (i=0;i<n;i++) scanf("%d",&b[i]);
//        if (check(b,a[0])>=0&&check(b,a[1])<0) printf("Case #%d: BAD\n",cc);
//        else printf("Case #%d: GOOD\n",cc);
        sum=0;
        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
                if (b[i]<b[j]) sum++; 
        if (sum>=1&&sum<=(n-1)/2) printf("Case #%d: BAD\n",cc);
        else printf("Case #%d: GOOD\n",cc);      
    }
    return 0;
}
