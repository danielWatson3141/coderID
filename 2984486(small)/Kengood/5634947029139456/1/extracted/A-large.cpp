#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;

int cases , Case = 1;
////////////



char ok(vector<string> a , vector<string>b)
{
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i = 0 ; i < a.size(); ++i)
		if( a[i] != b[i] )
			return 0;
	return 1;
}

int main()
{	
	
	scanf("%d" , &cases);	
	while( cases-- )
	{

		

		int n , l;
		cin >> n >> l;
		vector<string> a(n) , b(n);
		for(int i = 0 ; i < n; ++i) cin >> a[i];
		for(int i = 0 ; i < n; ++i) cin >> b[i];


		int ans=0;
		printf("Case #%d: " , Case++ );
		pair<int , pair<int, vector<string> >  > cur;
		cur.first = 0;
		cur.second.first = l-1;
		cur.second.second = b;
		queue< pair<int , pair<int, vector<string> > > > q;
		q.push(cur);
		set< pair<int, vector<string> > > vis;
		while( !q.empty() )
		{
			cur = q.front(); q.pop(); 
			if( ok(a,cur.second.second) )
			{
				printf("%d\n" , cur.first);
				goto next;
			}
			if( cur.second.first < 0 ) continue;

			if(vis.find( cur.second ) == vis.end() )
			{
				vis.insert(cur.second);
				int aa[2]={0} , bb[2]={0};
				for(int i = 0 ; i < n; ++i)
				{
					++aa[  a[i][cur.second.first] == '1'  ];
					++bb[  b[i][cur.second.first] == '1'  ];
				}

				if( aa[0] > aa[1] ) swap(aa[0],aa[1]);
				if( bb[0] > bb[1] ) swap(bb[0],bb[1]);

				if( aa[0] == bb[0] && aa[1] == bb[1] )
				{
					--cur.second.first;
					q.push( cur );
					for(int i = 0 ; i < n; ++i)
						cur.second.second[i][cur.second.first+1] = 
						cur.second.second[i][cur.second.first+1] == '1' ? '0' : '1';
					++cur.first;
					q.push( cur );
				}

			}
			if(q.size() > 10000) break;
		}
			
		puts("NOT POSSIBLE");

		

		
		
		
		
		next:;
	}

	

	return 0;
}

