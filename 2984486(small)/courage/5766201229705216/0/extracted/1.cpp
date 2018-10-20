#include <cstdio>
#include <cstring>
int n,te,x,y,ans,pp,pt;
bool v[1010];
int min(int a,int b){
	return a < b ? a : b;
}
struct rec{
	int x;
	rec *next;
};
rec *a[1010],pool1[200010],*t;
rec *getRec(){
	return &pool1[pp++];
}
struct node{
	int size;
	node *l,*r;
};
node *root,pool2[100010];
node *getNode(){
	return &pool2[pt++];
}
int sz(node *x){
	if (x == NULL) return 0;
	return x->size;
}
node *build(int x,bool &y){
	if (!y) return NULL;
	v[x] = 1;
	int num = 0;
	node *k = getNode();
	k->l = k->r = NULL;
	k->size = 1;
	rec *p = a[x];
	while (p != NULL){
		if (!v[p->x]){
			v[p->x] = 1;
			if (num == 0){
				num++;
				k->l = build(p->x,y);
			}else if (num == 1){
				num++;
				k->r = build(p->x,y);
			}else{
				y = 0;
				return NULL;
			}
		}
		p = p->next;
	}
	k->size += sz(k->l) + sz(k->r);
	return k;
}
int g(node *x){
	if (x == NULL) return 0;
	int a = g(x->l),b = g(x->r);
	if (x->l == NULL){
		if (x->r == NULL) return a + b;
		int tmp = sz(x->r) + a + b;
		x->size -= sz(x->r);
		x->r = NULL;
		return tmp;
	}
	if (x->r == NULL){
		int tmp = sz(x->l) + a + b;
		x->size -= sz(x->l);
		x->l = NULL;
		return tmp;
	}
	return a + b;
}
int f(int x){
	pt = 0;
	bool flag = 1;
	memset(v,0,sizeof v);
	root = build(x,flag);
	if (!flag) return n;
	return g(root);
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&te);
	for (int T = 1;T <= te;T++){
		pp = 0;
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) a[i] = NULL;
		for (int i = 1;i < n;i++){
			scanf("%d%d",&x,&y);
			t = getRec();
			t->x = y;
			t->next = a[x];
			a[x] = t;
			t = getRec();
			t->x = x;
			t->next = a[y];
			a[y] = t;
		}
		ans = n;
		for (int i = 1;i <= n;i++) ans = min(ans,f(i));
		printf("Case #%d: %d\n",T,ans);
	}
}
