#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long double f[1001];
int main()
{
    freopen("table","w",stdout);
    printf("double p[1000][1000]=");
    printf("{");
	for(int i=0;i<1000;++i)
	{
	    if(i) printf(",");
        for(int j=0;j<1000;++j)f[j]=0;
        f[i]=1;
        for(int j=0;j<1000;++j)
        {
            for(int k=0;k<1000;++k) if(k!=j) f[k]=999/1000.0*f[k]+f[j]/1000;
            f[j]=1.0/1000;
        }
        printf("{");
        double ret=0;
        for(int j=0;j<1000;++j)
        {
            ret+=f[j];
            if(j) printf(",");
            printf("%.10lf",(double)f[j]);
        }
        if(abs(1-ret)>0.1)
        {

     cout<<endl;
     cout<<ret<<endl;
     cout<<"############################"<<endl;
        while(1);
    }
   printf("}\n");
	}
	printf("}\n");
}


