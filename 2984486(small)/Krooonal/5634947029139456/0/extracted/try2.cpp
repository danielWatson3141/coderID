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

int main()
{
	int __A;
	scanf("%d" , &__A);
	
	int i , j , k , cnt , gcnt;
	bool flag;
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
		
		//L is at max 10 so trying bruteforce
		gcnt = MOD;
		for(i=0 ; i<(1 << L) ; i++)
		{
			cnt = 0;
			for(j=0 ; j<L ; j++)
			{
				if(i & (1 << j))
				{
					cnt++;
					//flip the jth bit
					for(k = 0 ; k<N ; k++)
					{
						if(vs1[k][j] == '0')
							vs1[k][j] = '1';
						else
							vs1[k][j] = '0';
					}
				}
			}
			sort(all(vs1));
			flag = true;
			for(k=0 ; k<N ; k++)
			{
				for(j=0 ; j<L ; j++)
				{
					if(vs1[k][j] != vs2[k][j])
					{
						flag = false;
						break;
					}
				}
				if(!flag)
					break;
			}
			if(flag)
			{
				gcnt = min(cnt , gcnt);
			}
			
			for(j=0 ; j<L ; j++)
			{
				if(i & (1 << j))
				{
					//flip the jth bit
					for(k = 0 ; k<N ; k++)
					{
						if(vs1[k][j] == '0')
							vs1[k][j] = '1';
						else
							vs1[k][j] = '0';
					}
				}
			}
			sort(all(vs1));
			
		}
		if(gcnt == MOD)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n" , gcnt);
		
	}
	return 0;
}
