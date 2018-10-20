#include <cstdio>
#define N 3033
int CAS,cas,i,a[N],nx[N],tl[N],v[N],c[N],son[N],fa[N],f[N],mn1,mn2,min,x,y,tag,l,r,rt,k,ln,n,j,siz[N];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
    scanf("%d",&CAS);
	for (cas=1; cas<=CAS; ++cas)
	{
		for (i=1; i<=ln; ++i) nx[i]=0;
		scanf("%d",&n);
		for (i=1; i<=n; ++i) tl[i]=i;
		ln=n;
		for (i=1; i<n; ++i)
		{
			scanf("%d%d",&x,&y);
			a[tl[x]=nx[tl[x]]=++ln]=y;
			a[tl[y]=nx[tl[y]]=++ln]=x;
		}
		min=10000000;
		for (rt=1; rt<=n; ++rt)
		{
//			printf("rt=%d\n",rt);
			l=0; c[r=1]=rt;
			v[rt]=++tag; fa[rt]=0;
			while (l<r)
			{
				son[k=c[++l]]=0;
				siz[k]=0;
				for (i=nx[k]; i!=0; i=nx[i])
				if (v[a[i]]!=tag)
				{
					v[c[++r]=a[i]]=tag;
					fa[a[i]]=k;
					++son[k];
				}
			}
			for (i=r; i>1; --i) siz[fa[c[i]]]+=(++siz[c[i]]);
			++siz[rt];
			for (i=r; i>=1; --i)
			{
				k=c[i];
				if (son[k]==0)
				{
					f[k]=0;
					continue;
				}
				if (son[k]==1)
				{
					f[k]=siz[k]-1;
					continue;
				}
				mn1=mn2=100000;
				for (j=nx[k]; j!=0; j=nx[j])
				if (a[j]!=fa[k])
				{
					if (f[a[j]]-siz[a[j]]<=mn1) mn2=mn1,mn1=f[a[j]]-siz[a[j]]; else
					if (f[a[j]]-siz[a[j]]<mn2) mn2=f[a[j]]-siz[a[j]];
				}
				f[k]=siz[k]-1+mn1+mn2;
				
//				printf("f %d = %d  siz=%d mn1=%d mn2=%d\n",k,f[k],siz[k],mn1,mn2);
				
			}
			if (f[rt]<min) min=f[rt];
			
		}
		printf("Case #%d: %d\n",cas,min);
	}
	return 0;
}
				
