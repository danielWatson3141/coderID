#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <string>
#include <cstring>

using namespace std;

#define DEBUG 0
#define all(C) (C).begin() , (C).end()
#define tr(C , it) for(typeof((C).begin()) it = (C).begin() ; it != (C).end() ; it++)
#define present(C , key) ((C).find(key) != (C).end())
#define cpresent(C , key) (find(all(C) , key) != (C).end())
#define sz(a) int((a).size())
#define pb push_back
#define MOD 1000000007


typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int , int> PI;

int N , L;
string s1 , s2;
vector<string> vs1 , vs2;
int cnt;
bool comp(int pos)
{
	int i;
	bool flag , flag2;
	if(pos >= L)
		return true;
	//check if it is already matching
	flag = true;
	for(i=0 ; i<N ; i++)
	{
		if(vs1[i][pos] != vs2[i][pos])
		{
			flag = false;
			break;
		}
	}
	if(flag && comp(pos+1))
		return true;
		
	//flip the bit and then check
	
	cnt++;
	//printf("at pos %d flipping %d\n" , pos , cnt);
	for(i=0 ; i<N ; i++)
	{
		//cout << vs1[i] << endl;
		if(vs1[i][pos] == '0')
			vs1[i][pos] = '1';
		else
			vs1[i][pos] = '0';
	}
	sort(all(vs1));
	flag = true;
	for(i=0 ; i<N ; i++)
	{
		if(vs1[i][pos] != vs2[i][pos])
		{
			flag = false;
			break;
		}
	}
	flag2 = false;
	if(flag)
	{
		flag2 = comp(pos+1);
	}
	if(!flag2)
		cnt--;
	for(i=0 ; i<N ; i++)
	{
		if(vs1[i][pos] == '0')
			vs1[i][pos] = '1';
		else
			vs1[i][pos] = '0';
	}
	sort(all(vs1));
	return flag2;
	
}

int main()
{
	int __A;
	scanf("%d" , &__A);
	int i;
	
	
	for(int _i = 1 ; _i <= __A ; _i++)
	{
		printf("Case #%d: " , _i);
		
		scanf("%d %d" , &N , &L);
		vs1.clear();
		vs2.clear();
		for(i=0 ; i<N ; i++)
		{
			cin >> s1;
			vs1.pb(s1);
		}
		for(i=0 ; i<N ; i++)
		{
			cin >> s2;
			vs2.pb(s2);
		}
		sort(all(vs1));
		sort(all(vs2));
		cnt = 0;
		if(comp(0))
		{
			printf("%d\n" , cnt);
		}
		else
		{
			printf("NOT POSSIBLE\n");
		}
	}
	return 0;
}
