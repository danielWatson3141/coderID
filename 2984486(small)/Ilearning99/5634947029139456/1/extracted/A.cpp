#include<bits/stdc++.h>
using namespace std;

int N,L;

long long num[155];
long long ori[155];

long long convert(char bin[55])
{
    int i;
	long long ans=0;
	for(i=0;bin[i];i++)
	{
	    ans=ans*2;
	    if(bin[i]=='1')
		    ans=ans+1;
	}
	return ans;
}

bool cmp(long long a,long long b)
{
    return a<b;
}

int cal(long long a)
{
    int ans=0;
	while(a)
	{
	    a=a&(a-1);
		ans++;
	}
	return ans;
}

long long cnum[155];

bool compare(long long mask)
{
    int i;
	for(i=0;i<N;i++)
	{
	    cnum[i]=num[i]^mask;
	}
	sort(cnum,cnum+N,cmp);
	for(i=0;i<N;i++)
	{
	    if(cnum[i]!=ori[i])
		    return false;
	}
	return true;
}

int main()
{
    int T,casen,i,ansout;
	long long temp;
	char inpu[55];
	bool flag;
	scanf("%d",&T);
	for(casen=0;casen<T;casen++)
	{
	    scanf("%d %d",&N,&L);
		for(i=0;i<N;i++)
		{
		    scanf("%s",inpu);
			num[i]=convert(inpu);
			//cout<<num[i]<<endl;
		}
		for(i=0;i<N;i++)
		{
		    scanf("%s",inpu);
			ori[i]=convert(inpu);
			//cout<<ori[i]<<endl;
		}
		temp=0;
		flag=false;
		sort(ori,ori+N,cmp);
		if((N&1))
		{
		    for(i=0;i<N;i++)
			{
			    temp=temp^num[i];
				temp=temp^ori[i];
			}
			//cout<<temp<<endl;
			flag=compare(temp);
			ansout=cal(temp);
		}
		else
		{
		    for(i=0;i<N;i++)
			{
			    temp=temp^num[i];
				temp=temp^ori[i];
			}
			//cout<<temp<<endl;
            if(temp!=0)
			{
                 goto l1;
			}
		    ansout=100;
            for(i=0;i<N;i++)
            {
			    temp=num[0]^ori[i];
				if(compare(temp))
				{
				    flag=true;
					if(ansout>cal(temp))
					{
					    ansout=cal(temp);
					}
				}
			}			
		}
		l1:
		if(flag)
		{
		    printf("Case #%d: %d\n", casen+1, ansout); 
		}
		else
		{
		    printf("Case #%d: NOT POSSIBLE\n", casen+1); 
		}
	}
    return 0;
}