#include<stdio.h>
#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define pb(x) push_back(x)
#define For(i,s,e) for(i=s;i<e;i++)
#define ss(a) scanf("%s",a)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sf(a) scanf("%f",&a)
#define sd(a) scanf("%lf",&a)
#define ps(a) printf("%s\n",a)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define pd(a) printf("%lf\n",a)
#define LL long long
#define MOD 1000000

using namespace std;
 
int n;
vector <int> aa,bb;
vector < vector <int> > graph;
vector <bool> parent;
vector <int> child;
int sol[1009][3];

int tree_d (int index, int x)
{
    if (x == 3) {
        return 10000;
    }
    if (index == aa.size()) {
        if (x == 1) {
            return 10000;
        }
        return 0;
    }
 
    int &result = sol[index][x];
    if (result != -1) {
        return result;
    }
    result = tree_d (index+1, x) + bb[index];
    result = min (result, aa[index]+tree_d(index+1, x+1));
    return result;
} 

int fnd (vector <int> s, vector <int> a)
{
    aa = s;
    bb = a;
    if (s.size() == 0) {
        return 0;
    }
    if (s.size() == 1) {
        return a[0];
    }
    memset (sol, -1, sizeof(sol));
    return tree_d (0, 0);
}
 
int f (int x, int p)
{
    vector <int> aa;
    vector <int> bb;
    int i,sum=0;
    For(i, 0, graph[x].size()) {
        int xx = graph[x][i];
        if (xx == p) {
            continue;
        }
        int xxx = f (xx, x);
        aa.pb (xxx);
        bb.pb (child[xx]);
    }
    return fnd (aa, bb);
}
 
int init (int x, int p)
{
    child[x] = 1;
    int i,sum=0;
    For(i, 0, graph[x].size()) {
        int xx = graph[x][i];
        if (xx == p) {
            continue;
        }
        init (xx, x);
        child[x] += child[xx];
    }
}
 
int main()
{ 
    int t,i=1,j,x,y,c=1;
    si(t);
    while (t--) { 
        si(n);
        graph.clear();  
	graph.resize (n);
        int out = n;
        For(i,0,n-1) {
            si(x);si(y);
            x--;
            y--;
            graph[x].pb (y);
            graph[y].pb (x);
        } 
       For(j,0,n) {
            parent.resize (n);
            child.resize (n);
            For(i,0,parent.size()) {
                parent[i] = false;
                child[i] = 0;
            }
            init (j, j);
            out = min (out, f(j, j));
        }
        printf("Case #%d: %d\n",c,out);
	c++;
    }
    return 0;
}
