#include <iostream>
#include<stdio.h>
using namespace std;
long long int scan()
{
long long int a;
char c;
while(c<33)
c = getchar();
a = 0;
while(c>33)
{
a = a*2 + c - '0';
c = getchar();
}
return a;
}
int main()
 {
	long long int n,z,l,t,i,j,k,xx,c;
	long long int ini[155],req[155];
	cin>>t;
	for(xx=1;xx<=t;xx++)
    {
        int min=1<<20;
        cin>>n;
        cin>>l;
        for(i=0;i<n;i++)
        {
            ini[i]=scan();
            //cout<<ini[i]<<endl;
        }
        for(i=0;i<n;i++)
        {
            req[i]=scan();
        	//cout<<req[i]<<endl;
        }
        for(i=0;i<n;i++)
        {
            long long int curr=ini[0]^req[i];
            //printf("curr=%lld\n",curr);
            int v[155]={0};
            v[i]=1;
            for(j=1;j<n;j++)
            {
                long long int ne=ini[j]^curr;
            //    printf("ne=%lld\n",ne);
                for(k=0;k<n;k++)
                {
                    if(req[k]==ne)break;
                }
                if(k==n)goto XX;
                else v[k]=1;
            }
            //cout<<"\n";
            for(z=0;z<n;z++)//cout<<v[z]<<" ";
            if(!v[z])goto XX;
            c=0;
            while(curr)
            {
                if(curr&1)c++;
                curr=curr>>1;
            }
            if(c<min)min=c;
            XX: ;
            }
        if(min==1<<20)
            cout<<"Case #"<<xx<<": NOT POSSIBLE"<<endl;
        else
            cout<<"Case #"<<xx<<": "<<min<<endl;
    }
	return 0;
}
