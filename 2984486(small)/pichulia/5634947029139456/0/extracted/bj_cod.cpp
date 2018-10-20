#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, m;
char aa[200][99];
char bb[200][99];
string a[200];
string b[200];
string c[200];
string d[200];
int mask[200];
int al,bl, cl, dl;
bool aable;
long long int gg[152], hh[152];
long long int g[152];
long long int h[152];
pair<string, int> p[1<<20];
pair<string, int> q[1<<20];
int gl, hl;
void bfs()
{
	int i, j, k,l;
}
int process()
{
	aable = true;
	int res=999999;
	int i, j, k, l;
	for(i=0;i<n;i++)
	{
		gg[i] = 0;
		hh[i] = 0;
		for(j=0;j<m;j++)
		{
			gg[i] *= 2;
			gg[i] += c[i][j] - '0';
		}
		for(j=0;j<m;j++)
		{
			hh[i] *= 2;
			hh[i] += d[i][j] - '0';
		}
	}
	int mi, mj;
	mi = (m-cl)/2;
	gl = 1<<mi;
	hl = 1<<(m-cl-mi);
	for(i=0; i<gl; i++)
	{
		string xx="";
		k=0;
		j=i;
		while(j)
		{
			k++;
			j&=(j-1);
		}
		for(j=0;j<n;j++)
			g[j] = gg[j] ^ i;
		sort(g,g+n);
		for(j=0;j<n;j++)
		{
			xx += (g[j]>>32);
			xx += (g[j]>>24)&255;
			xx += (g[j]>>16)&255;
			xx += (g[j]>>8)&255;
			xx += (g[j])&255;
		}
		p[i] = make_pair(xx,k);
	}
	for(i=0; i<hl; i++)
	{
		string xx="";
		k=0;
		j=i;
		while(j)
		{
			k++;
			j&=(j-1);
		}
		for(j=0;j<n;j++)
			h[j] = hh[j] ^ (i<<mi);
		sort(h,h+n);
		for(j=0;j<n;j++)
		{
			xx += (h[j]>>32);
			xx += (h[j]>>24)&255;
			xx += (h[j]>>16)&255;
			xx += (h[j]>>8)&255;
			xx += (h[j])&255;
		}
		q[i] = make_pair(xx,k);
	}
	sort(p,p+gl);
	sort(q,q+hl);
	for(i=j=0;i<gl && j<hl;)
	{
		if(p[i].first < q[j].first)
			i++;
		else if(p[i].first > q[j].first)
			j++;
		else
		{
			int pr, qr;
			pr = p[i].second;
			qr = q[j].second;
			for(k=i+1;k<gl;k++)
			{
				if(p[i].first != p[k].first)
					break;
				pr = min(pr, p[k].second);
			}
			for(l=j+1;l<hl;l++)
			{
				if(q[j].first != q[l].first)
					break;
				qr = min(qr, p[l].second);
			}
			res = min(res, pr+qr);
			i=k;
			j=l;
		}
	}
	return res;
}
int main()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small-attempt0.out","wt",stdout);
	int t, tv;
	scanf("%d",&t);
	tv=0;
	while(t--)
	{
		int i, j, k, l;
		tv++;
		printf("Case #%d: ",tv);
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",aa[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",bb[i]);	
		}
		for(i=0;i<n;i++)
		{
			a[i] = "";
			b[i] = "";
			c[i] = "";
			d[i] = "";
			mask[i] = 0;
		}
		al=bl=cl = dl = 0;
		int res=0;
		bool able = true;
		for(i=0;i<m;i++)
		{
			int ss,sd;
			ss=sd=0;
			for(j=0;j<n;j++)
				ss+=aa[j][i]-'0';
			for(j=0;j<n;j++)
				sd+=bb[j][i]-'0';
			if(ss == sd)
			{
				if(ss+sd != n)
				{
					for(j=0;j<n;j++)
					{
						a[j] += aa[j][i];
						b[j] += bb[j][i];
					}
					al++;
					bl++;
				}
				else
				{
					mask[i] = 1;
				}
				continue;
			}
			else if(ss + sd == n)
			{
				res++;
				for(j=0;j<n;j++)
					aa[j][i] ^= 1;
				for(j=0;j<n;j++)
				{
					a[j] += aa[j][i];
					b[j] += bb[j][i];
				}
				al++;
				bl++;
			}
			else
				able = false;
		}
		for(i=0;i<m;i++)
			if(mask[i] == 1)
			{
				mask[i] = 0;
				for(j=0;j<n;j++)
				{
					a[j] += aa[j][i];
					b[j] += bb[j][i];
				}
			}
		if(!able){printf("NOT POSSIBLE\n");continue;}
		sort(a,a+n);
		sort(b,b+n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<al;j++)
			{
				if(a[i][j] != b[i][j])
					able = false;
			}
		}
		for(i=0;i<n;)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=0;k<al;k++)
					if(a[i][k] != a[j][k])
						break;
				if(k<al)
					break;
			}
			for(l=al;l<m;l++)
			{
				int ss, sd;
				ss = sd = 0;
				for(k=i;k<j;k++)
				{
					ss += a[k][l] - '0';
					sd += b[k][l] - '0';
				}
				if(ss == sd)
				{
					if(ss + sd != (j-i))
					{
						if(mask[l] == 0)
							mask[l] = 2;
						if(mask[l] == 1)
							able = false;
					}
				}
				else if(ss + sd == (j-i))
				{
					if(mask[l] == 0)
					{
						res++;
						mask[l] = 1;
					}
					if(mask[l] == 2)
						able = false;
				}
				else
					able = false;
			}
			i=j;
		}
		for(i=0;i<m;i++)
		{
			if(mask[i] == 1)
			{
				mask[i] = 0;
				for(j=0;j<n;j++)
				{
					c[j] += (a[j][i])^1;
					d[j] += (b[j][i]);
				}
				cl++;dl++;
			}
			else if(mask[i] == 2)
			{
				mask[i] = 0;
				for(j=0;j<n;j++)
				{
					c[j] += (a[j][i]);
					d[j] += (b[j][i]);
				}
				cl++;dl++;
			}
			else
			{
				mask[i] = 3;
			}
		}
		for(i=0;i<m;i++)
		{
			if(mask[i] == 3)
			{
				mask[i] = 0;
				for(j=0;j<n;j++)
				{
					c[j] += a[j][i];
					d[j] += b[j][i];
				}
			}
		}
		sort(c,c+n);
		sort(d,d+n);
		if(!able){printf("NOT POSSIBLE\n");continue;}
		if(cl == m){ printf("%d\n",res); continue;}
		if(m - cl == 1)
		{
			printf("%d\n",res);continue;
		}
		res += process();
		if(res > 50){printf("NOT POSSIBLE\n");continue;}
		else printf("%d\n",res);
	}
}