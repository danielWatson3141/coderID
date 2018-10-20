#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
#include <iomanip>
#include <pthread.h>
#include <semaphore.h>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <algorithm>

#define ABS(a) ((a)<0?(-(a)):(a))
#define SIGN(a) (((a)>0)-((a)<0))
#define SQR(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define PI (3.1415926535897932384626433832795)
#define INF (2147483647)
#define LLINF (9223372036854775807LL)
#define INF2 (1073741823)
#define EPS (0.00000001)

#define MOD (1000000007)

#define y1 stupid_cmath
#define y0 stupid_cmath_too

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> &t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> &t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }
void dout(){cout<<endl;} template<typename Head, typename... Tail> void dout(Head H, Tail... T){cout<<H<<" "; dout(T...);}

ifstream in("input.txt");
ofstream out("output.txt");

// Не забудь в main добавить вызов gcj_solve()
#define MAX_T 101
#define MAX_Threads 4
sem_t sem[MAX_T], sem_count, sem_stack;
pthread_t pthread[MAX_T];
stack<int> thread_stack;

int thread_pop(){
	sem_wait(&sem_stack);
	int r = thread_stack.top();
	thread_stack.pop();
	sem_post(&sem_stack);
	return r;
}
void thread_push(int a){
	sem_wait(&sem_stack);
	thread_stack.push(a);
	sem_post(&sem_stack);
}

class Answer{
public:
	int ans;
	friend ostream& operator <<(ostream& out, const Answer &a){
		out<<a.ans;
		//out<< setprecision(12) <<a.ans;
		return out;
	}
};
Answer ans[MAX_T];

int N[MAX_Threads];
vector<int> g[MAX_Threads][1009];

int ms[MAX_Threads][1009];

int dfs(int num_th, int v, int p=-1){

	ms[num_th][v] = 1;
	int t1=0, t2=0, t, c=0;

	for(auto to : g[num_th][v]){
		if(to != p){
			++c;
			t = dfs(num_th, to, v);
			ms[num_th][v] += ms[num_th][to];

			t = ms[num_th][to] - t;
			if(t>=t1) t2=t1, t1=t;
			else if(t>t2) t2=t;

		}
	}

	if(c==0) return 0;
	if(c==1) return ms[num_th][v]-1;
	return ms[num_th][v]-1-t1-t2;
}

void* solve(void *_id){
	const int id = *(int*)_id;
	const int num_th = thread_pop();

	for(int i=0; i<1009; ++i){
		g[num_th][i].clear();
	}
	// считывание данных из потока in

	in>>N[num_th];
	for(int i=0;i<N[num_th]-1;++i){
		int a, b;
		in>>a>>b;
		g[num_th][a].push_back(b);
		g[num_th][b].push_back(a);
	}

	// завершение считывания
	sem_post(&sem[id+1]);
	// основное решение

	int res=INF;
	for(int i=1;i<=N[num_th];++i){
		res = min(res, dfs(num_th, i));
	}

	// окончание решения
	//sem_wait(&sem[id]);
	// вывод данных

	//out<<"Case #"<<id<<": ";

	ans[id].ans = res;

	cout<<"Write in "<<id<<endl;
	// окончание вывода
	thread_push(num_th);
	sem_post(&sem[id+1]);
	sem_post(&sem_count);
	pthread_exit(0);
}

void gcj_solve(){
	cout<<"Start solver.\n";
	int T;
	char s[99];
	in>>T;

	sem_init(&sem_count, 0, MAX_Threads);
	sem_init(&sem_stack, 0, 1);
	sem_init(&sem[1], 0, 2);
	for(int ii=2; ii<=T; ++ii) sem_init(&sem[ii], 0, 0);
	for(int ii=0; ii<MAX_Threads; ++ii) thread_stack.push(ii);

	for(int ii=0; ii<T;){
		cout<<"Wait start "<<ii<<" thread.\n";
		sem_wait(&sem[ii+1]);
		sem_wait(&sem_count);
		++ii;
		cout<<"Go "<<ii<<" thread.\n";
		if(pthread_create(&pthread[ii], NULL, solve, &ii) != 0){
			sprintf(s, "Creating the %d thread", ii);
			perror(s);
			return ;
		}
	}
	for(int ii=1; ii<=T; ++ii){
		if(pthread_join(pthread[ii], NULL) != 0){
			sprintf(s, "Joining the %d thread", ii);
			perror(s);
			return ;
		}
	}
	for(int ii=1; ii<=T; ++ii) out<<"Case #"<<ii<<": "<<ans[ii]<<endl;
	cout<<"End solver.\n";
}

int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gcj_solve();

	return 0;
}

int cpp4cf_main()
{
	freopen("B.cpp","r",stdin);

	char s[99];
	bool f;

	while(true) {
		cin>>s;
		if(cin.eof()) break;
		if(strstr(s,"/*")) {
			cin>>s;
			if(strstr(s,"Test")) {
				cin>>s;
				if(strstr(s,"on")) {
					cout<<"Output: ";
					cpp4cf_main();
					cout<<"\nAnswer: ";
					f = false;
					while(true) {
						cin>>s;
						if(strstr(s,"*/")) break;
						if(strstr(s,"//")) {
							if(f) cout<<endl;
							else f = true;
						}else cout<<s<<" ";
					}
					cout<<"\n\n";
				}
			}
		}
	}

	return 0;
}

