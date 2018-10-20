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
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 


#define PI acos(-1)
#define CLEAR(A) memset(A,0,sizeof(A))
#define SETMAX(A) memset(A,0x7f,sizeof(A))
#define SETM1(A) memset(A,-1,sizeof(A))
#define SQ(A) (A)*(A)


long long num1s(long long n) {
    long long ret = 0;
    while(n) {
        n = n&(n-1);
        ret++;
    }
    return ret;
}

int main()
{
    cout << setprecision(12) ;
    long long T;
    cin >> T;
    for(long long caseno=0;caseno<T;caseno++) {
        long long N, L;
        cin >> N >> L;
        vector<long long> vi, req;
        string s;
        for(long long i=0;i<N;i++) {
            cin >> s;
            long long temp = 0;
            for(long long j=0;j<s.size();j++) if(s[j] == '1') temp += 1LL<<j;
            vi.push_back(temp);
        }
        for(long long i=0;i<N;i++) {
            cin >> s;
            long long temp = 0;
            for(long long j=0;j<s.size();j++) if(s[j] == '1') temp += 1LL<<j;
            req.push_back(temp);
        }
        sort(req.begin(), req.end());
        long long mini = 1000;
        for(long long i=0;i<vi.size();i++) {
            long long xor_val = vi[i] ^ req[0];
            vector<long long> temp;
            for(long long j=0;j<vi.size();j++) temp.push_back(vi[j] ^ xor_val);
            sort(temp.begin(), temp.end());
            if(req == temp) {
                mini = min(mini, num1s(xor_val));
            }
        }
        if(mini == 1000) {
            cout << "Case #" << caseno+1 << ": " << "NOT POSSIBLE" << endl;
        } else {
            cout << "Case #" << caseno+1 << ": " << mini << endl;
        }
    }
    return 0;
}
