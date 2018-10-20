#include <stdio.h>
#include <map>
#include <stdarg.h>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;
template<class T>
struct arr{
	T *p;
	int sz;
	arr(int n=0){if((sz=n)>0)p=new T[n];else p=0;}
	void resize(int n){
		if(n==sz)return;
		delete[]p;
		if((sz=n)>0)p=new T[n];else p=0;
	}
	arr<T>& operator=(const arr<T>&a){
		resize(a.sz);
		for(int i=0; i<sz; i++)p[i]=a.p[i];
		return *this;
	}
	arr(const arr<T>&a){
		p=0; sz=0;*this = a;
	}
	void clear(){resize(0);}
	~arr(){delete []p;p=0;}
	void swap(arr<T> &a){std::swap(a.p,p); std::swap(sz,a.sz);}
	operator T*(){return p;}
};
typedef arr<int> intarr;
typedef arr<double> doublearr;
typedef arr<string> stringarr;

struct file{
	FILE *f;
	file(){f=0;}
	file(const char* n, const char *mode){
		f = fopen(n, mode);
	}
//	bool operator !()const{return !f;}
	~file(){if(f)fclose(f); f=0;}
	bool read(const char *fmt, ...);
	void write(const char *fmt, ...);
	bool operator!()const{return !f;}
private:
	file(const file&);
	file&operator=(const file&f);
};
int power(int i, int n){
	int res=1, t=1;
	for(;n;n>>=1){
		t*=i;
		if(n&1)res*=t;
	}
	return res;
}
int read_int(const char *&str, const map<string,int> &m, char end);
const char* space(const char *&str){
	while(*str == ' ')str++;
	return str;
}
int read_s(const char *&str, const map<string,int> &m){
	space(str);
	char s0[100], *ps = s0;
	if(!*str)return -1;
	if(*str=='('){
		++str;
		return read_int(str, m, ')');
	}
	if(*str>='0'&&*str<='9'){
		int r=*str-'0';
		for(str++; *str>='0'&&*str<='9'; str++)
			r=r*10+(*str-'0');
		return r;
	}
	while((*str>='a'&&*str<='z')||(*str>='A'&&*str<='Z')||*str=='_')
		*(ps++)=*(str++);
	*ps=0;
	if(!m.count(s0))return -1;
	return m.find(s0)->second;
}
int read_exp(const char *&str, const map<string,int> &m){
	space(str);
	int f = read_s(str, m), n;
	if(f <0)return -1;
	char ch = *space(str);
	if(ch!='^')return f;
	str++;
	n = read_exp(str, m);
	if(n<0)return -1;
	return power(f,n);
}
int read_mul(const char *&str, const map<string,int> &m){
	space(str);
	int f = read_exp(str, m), n;
	if(f <0)return -1;
	for(;;){
		char ch = *space(str);
		if(ch!='*'&&ch!='/'&&ch!='%')return f;
		str++;
		n = read_exp(str, m);
		if(n<0)return -1;
		switch(ch){
			case '*': f*=n; break;
			case '/': f/=n; break;
			case '%': f%=n; break;
		}
	}
	return f;
}
int read_int(const char *&str, const map<string,int> &m, char end){
	int f = read_mul(str, m), n;
	if(f <0)return -1;
	for(;;){
		char ch = *(str++);
		if(ch==end)break;
		space(str);
		n = read_mul(str, m);
		if(n<0)return -1;
		switch(ch){
			case '+': f+=n; break;
			case '-':f-=n; break;
			default: return -1;
		}
	}
	return f;
}
int read_int(const char *str, const map<string,int> &m){
	return read_int(str, m, 0);
}

bool file::read(const char *fmt, ...){
	map<string, int> m;
	va_list l;
	va_start(l, fmt);
	int d, i,sz; double lf;
	long long ld;
	intarr *ad; doublearr *af;
	const char *f0;
	char s[100];
	bool ok=true;
	for(;ok && *fmt;fmt++){
		switch(*fmt){
			case ' ':continue;
			case 'f':
				if(fscanf(f, "%lf", &lf)!=1){ok=false; break;}
				*va_arg(l,double*)=lf;
				break;
			case 'd':
				if(fscanf(f, "%d", &d)!=1){ok=false; break;}
				if(fmt[1]=='>'){
					if(fmt[2]!='>')*va_arg(l,int*)=d;
					else fmt++;
					for(i=0;fmt[i+2]&&fmt[i+2]!=' '; i++)
						s[i]=fmt[i+2];
					s[i] = 0;
					if(!i)ok=false;
					else m[s] = d;
					fmt += i+2;
				}else *va_arg(l,int*)=d;
				break;
			case 'l':
				if(fscanf(f, "%lld", &ld)!=1){ok=false; break;}
				*va_arg(l,long long*)=ld;
				break;
			case 's':
				if(fscanf(f, "%s", va_arg(l,char*))!=1)ok=false;
				break;
			case 'a':
				f0 = fmt+2;
				if(fmt[2]!='['){
					if(fscanf(f, "%d", &sz)!=1||sz<0){ok=false; break;}
				}else{
					f0 = fmt+3;
					sz = read_int(f0, m, ']');
					if(sz<0){ok=false; break;}
				}
				if(fmt[1]=='d'){
					ad = va_arg(l,intarr*);
					intarr a(sz);
					for(i=0; i<sz; i++){
						if(fscanf(f, "%d", a.p+i)!=1){ok=false;break;}
					}
					if(ok)ad->swap(a);
				}else if(fmt[1]=='f'){
					af = va_arg(l,doublearr*);
					doublearr a(sz);
					for(i=0; i<sz; i++){
						if(fscanf(f, "%lf", a.p+i)!=1){ok=false;break;}
					}
					if(ok)af->swap(a);
				}else if(fmt[1]=='s'){
					stringarr *as = va_arg(l,stringarr*);
					stringarr a(sz);
					for(i=0; i<sz; i++){
						if(fscanf(f, "%s", s)!=1){ok=false; break;}
						a.p[i] = s;
					}
					if(ok)as->swap(a);
				}else {ok = false; break;}
				fmt = f0-1;
				break;
			default: ok = false;
		}
	}
	va_end(l);
	return ok;
}

int cmp_double(const void *d1, const void *d2){
	if(*(double*)d1<*(double*)d2)return -1;
	if(*(double*)d1>*(double*)d2)return 1;
	return 0;
}
template<class T>
T gcd(T i, T j){
	while(j){
		T k = i%j;
		i=j; j=k;
	}
	return i;
}
typedef unsigned long uint;
typedef unsigned long long ull;


#include <set>

typedef set<ull> sll;
bool operator==(const sll&x, const sll &y){
	if(x.size()!=y.size())return false;
	for(sll::const_iterator it = x.begin(), ity = y.begin();
		it!=x.end(); ++it, ++ity)
		if(*it!=*ity)return false;
	return true;
}
int bitcount(ull l){
	int r = 0;
	for(;l; l>>=1)
		if(l&1)r++;
	return r;
}
int solve(int n, int l, ull *dev, ull *r){
	doublearr wp(n), owp(n), oowp(n), tt(n);
	sll sd, sr;
	int i, j, k, t, w, mn=l+1;
	for(i=0; i<n; i++)
		sd.insert(dev[i]);
	for(i=0; i<n; i++){
		ull a = dev[0]^r[i];
		sr.clear();

		for(j=0; j<n; j++)
			sr.insert(r[j]^a);
		if(sr==sd){
			mn = min(mn, bitcount(a));
		}
	}
	return mn>l ? -1 : mn;
}

ull mask(string &s){
	ull res = 0;
	for(uint i=0; i<s.length(); i++)
		if(s[i]=='1')res |= ull(1)<<i;
	return res;
};
int main(){
	file fin("input.txt","r"), fout("output.txt","w");
	if(!fin){printf("no input\n"); return 0;}
	int i, j, T=0, n, dwr=0, wr=0;
	if(!fin.read("d",&T))return 0;
//	char *str=0;
	for(i=1; i<=T; i++){
		//printf("test %d\n", i);
		int n, l;
		stringarr ss, ss1;
		if(!fin.read("d>n d>l as[n]as[n]", &n, &l, &ss, &ss1))break;
		arr<ull> a(ss.sz), b(ss.sz);
		for(j=0; j<n; j++){
			a[j] = mask(ss[j]);
			b[j] = mask(ss1[j]);
		}
		int r = solve(n,l,a,b);
		if(r>=0)fprintf(fout.f, "case #%d: %d\n", i, r);
		else fprintf(fout.f, "case #%d: NOT POSSIBLE\n", i, r);
	}
	return 0;
}