#include <stdio.h>
#include <cmath>
#include <vector>
#include <map>

#define f(i,n) for(int i =0; i <n;i++)

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	f(t,T)
	{
		int n,l;
		scanf("%d %d",&n,&l);
		char a[150][41];
		char b[150][41];

		f(i,n)
		{
			scanf("%s",&(a[i]));
		}
		f(i,n)
		{
			scanf("%s",&(b[i]));
		}
		
		int minn=100;
		f(i, 1<<l)
		{
			bool yes [200];
			f(j,n)
				yes[j] = false;
			char c[150][41];
			f(k,n)
				f(j,l)
					c[k][j] = a[k][j];

			int m = 0;
			f(k,n)
			{
			f(j,l)
			{
				
				if(i&(1<<j))
				{
					//printf("flip %d\n",j);
					c[k][j] = c[k][j]=='0'?'1':'0';
					m++;
				}
				
			}
		}
			m = m/n;

			f(p,n)
			{
				f(j,n)
				{
					bool tr = true;
					f(k,l)
					{
						if(c[p][k]!=b[j][k])
						{
							tr = false;
							break;
						}
					}

					if(tr)
						yes[j] = true;	

				}
			}

			bool tr = true;	
			f(j,n)
			{
				tr = tr& yes[j];
			}

			if(tr)
			{
				minn = minn<m?minn:m;
			}
		}


		if(minn<100)
			printf("Case #%d: %d\n",t+1,minn);
		else
			printf("Case #%d: NOT POSSIBLE\n",t+1);
	}

	return 0;
}
