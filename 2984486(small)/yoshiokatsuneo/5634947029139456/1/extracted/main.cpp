//
//  main.cpp
//  googlecodejam
//
//  Created by Yoshioka Tsuneo on 4/12/14.
//  Copyright (c) 2014 Yoshioka Tsuneo. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stdexcept>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cassert>
#include <unistd.h>
#include <string.h>

#include <stack>

#include <thread>

#define decltype(X) __typeof(X)
#define REP(i, n) for(int i=0; i<(int)n; i++)
#define FOR(it, c) for(decltype((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define ALL(c) (c).begin(), (c).end()

#define EPS 0.000001
using namespace std;

typedef long long ll;

#include <mutex>
#include <condition_variable>
using namespace std;

class semaphore{
private:
    mutex mtx;
    condition_variable cv;
    int count;
    
public:
    semaphore(int count_ = 0):count(count_){;}
    void notify()
    {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }
    void wait()
    {
        unique_lock<mutex> lck(mtx);
        
        while(count == 0){
            cv.wait(lck);
        }
        count--;
    }
};

void print_outlets(const vector< vector<int> > &outlets)
{
#ifdef MYDEBUG
    printf("---outlets---\n");
#endif
    for(int i=0;i<outlets.size();i++){
        for(int j=0;j<outlets[i].size();j++){
            cout << outlets[i][j];
        }
        cout << endl;
    }
}
void show_groups( vector< pair< vector< vector<int> >, vector<vector<int> > >    > &groups)
{
#ifdef MYDEBUG
    cout << "------------groups start----------" << endl;
#endif
    for(int g=0;g<groups.size();g++){
        int gsize = (int)groups[g].first.size();
        cout << "--- group:" << g << "---" << endl;
        for(int i=0;i<gsize;i++){
            for(int j=0;j<(int)groups[g].first[i].size();j++){
                cout << groups[g].first[i][j];
            }
            cout << " ";
            for(int j=0;j<(int)groups[g].second[i].size();j++){
                cout << groups[g].second[i][j];
            }
            cout << endl;
        }
    }
#ifdef MYDEBUG
    cout << "------------groups end----------" << endl;
#endif
}
int count_zeronum(vector< vector<int> > &outlets, int pos)
{
    int count = 0;
    for(int i=0;i<(int)outlets.size();i++){
        if(outlets[i][pos]==0){
            count++;
        }
    }
    return count;
}
int dfs(int pos, vector< pair< vector< vector<int> >, vector<vector<int> > >    > &groups, int N, int L)
{
#ifdef MYDEBUG
    printf("dfs: pos=%d\n", pos);
    show_groups(groups);
#endif
    
    if(pos == L){
        return 0;
    }
    
    int result = INT_MAX;
    
    vector< vector< vector<int> > > next_groups1, next_groups2;
    
    int flip = -1;
    for(int g=0;g<groups.size();g++){
        int gsize = (int)groups[g].first.size();
        int zeronum1 = count_zeronum(groups[g].first, pos);
        int zeronum2 = count_zeronum(groups[g].second, pos);
        if(zeronum1 == zeronum2 && zeronum1 == gsize - zeronum1){
            ;
        }else if(zeronum1 == zeronum2){
            if(flip == 1){
                return INT_MAX;
            }
            flip = 0;
        }else if(zeronum1 == gsize - zeronum2){
            if(flip == 0){
                return INT_MAX;
            }
            flip = 1;
        }else{
            return INT_MAX;
        }
    }
#ifdef MYDEBUG
    printf("flip=%d\n", flip);
#endif
    if(flip == -1 || flip == 0){
        vector< pair< vector< vector<int> >, vector< vector<int> > > >next_groups;
        for(int g=0;g<groups.size();g++){
            vector< vector<int> > zero_groups1, zero_groups2, one_groups1, one_groups2;
            int gsize = (int)groups[g].first.size();
            for(int j=0;j<gsize;j++){
                if(groups[g].first[j][pos] == 0){
                    zero_groups1.push_back(groups[g].first[j]);
                }else{
                    one_groups1.push_back(groups[g].first[j]);
                }
                if(groups[g].second[j][pos] == 0){
                    zero_groups2.push_back(groups[g].second[j]);
                }else{
                    one_groups2.push_back(groups[g].second[j]);
                }
            }
            if(one_groups1.size()>0){
                next_groups.push_back(make_pair(one_groups1, one_groups2));
            }
            if(zero_groups1.size()>0){
                next_groups.push_back(make_pair(zero_groups1, zero_groups2));
            }
        }
        int ret = dfs(pos+1, next_groups, N, L);
        if(ret != INT_MAX){
            result = min(result, ret);
        }
    }
    
    if(flip == -1 || flip == 1){
        vector< pair< vector< vector<int> >, vector< vector<int> > > >next_groups;
        for(int g=0;g<groups.size();g++){
            vector< vector<int> > zero_groups1, zero_groups2, one_groups1, one_groups2;
            int gsize = (int)groups[g].first.size();
            for(int j=0;j<gsize;j++){
                if(groups[g].first[j][pos] == 1){
                    zero_groups1.push_back(groups[g].first[j]);
                }else{
                    one_groups1.push_back(groups[g].first[j]);
                }
                if(groups[g].second[j][pos] == 0){
                    zero_groups2.push_back(groups[g].second[j]);
                }else{
                    one_groups2.push_back(groups[g].second[j]);
                }
            }
            if(one_groups1.size()>0){
                next_groups.push_back(make_pair(one_groups1, one_groups2));
            }
            if(zero_groups1.size()>0){
                next_groups.push_back(make_pair(zero_groups1, zero_groups2));
            }
        }
        int ret = dfs(pos+1, next_groups, N, L);
        if(ret != INT_MAX){
            result = min(result, ret + 1);
        }
    }
    return result;
}

int testcase_itr(vector< pair< vector< vector<int> >, vector<vector<int> > >    > &groups, int N, int L)
{
    int num = dfs(0, groups, N, L);
    return num;
}

vector< vector<int> > read_for_outlets(istream &in, int N, int L)
{
    vector< vector<int> > outlets;

    for(int i=0;i<N;i++){
        vector<int> outlet;
        for(int j=0;j<L;j++){
            char c;
            in >> c;
            int val = -1;
            if(c == '0'){
                val = 0;
            }else if(c=='1'){
                val = 1;
            }else{
                printf("c=%c, unknown!\n", c);
                exit(1);
            }
            outlet.push_back(val);
        }
        outlets.push_back(outlet);
        
    }
    return outlets;

}


int  testcase(istream &in, int t)
{
    int N, L;
    in >> N >> L;
    
    vector< vector<int> >outlets1, outlets2;
    
    outlets1 = read_for_outlets(in, N, L);
    outlets2 = read_for_outlets(in, N, L);
    
    vector< pair< vector<vector<int>>, vector< vector<int> > > > groups;
    groups.push_back(make_pair(outlets1, outlets2));
    

    return testcase_itr(groups, N, L);
}


// #define MULTI_THREAD

#ifdef MULTI_THREAD
semaphore sem(6);
vector< pair<bool, double> > g_results;

void testcase_for_multithread(int t, double C, double F, double X)
{
    g_results[t].second = testcase_itr(C, F, X);
    g_results[t].first = true;
    // sleep(rand()/(RAND_MAX/3.0));
    sem.notify();
}
#endif

int main(int argc, const char * argv[])
{
    // sleep(1000);
    // insert code here...
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    string fname = "/dev/stdin";
    if(argc>=2){
        fname = argv[1];
    }
    ifstream in(fname);
    if(!in){
        cout << "File open error:" << fname << endl;
        exit(1);
    }
    int T;
    in >> T;
    
#ifndef MULTI_THREAD
    for(int t=0;t<T;t++){
        auto result = testcase(in, t);
        if(result == INT_MAX){
            cout << "Case #" << t+1 << ": " << "NOT POSSIBLE" << endl;
        }else{
            cout << "Case #" << t+1 << ": " << result << endl;
        }
        
    }
#else
    vector<thread> threads;
    g_results.resize(T);
    int cur_result = 0;
    for(int t=0;t<T;t++){
        sem.wait();
        while(g_results[cur_result].first == true){
            cout << "Case #" << cur_result+1 << ": " << g_results[cur_result].second << endl;
            cur_result++;
        }
        double C, F, X;
        
        in >> C >> F >> X;
        
        // thread th(testcase_for_multithread, t, C, F, X );
        threads.push_back(thread(testcase_for_multithread, t, C, F, X ));
    }
    while(cur_result<T){
        sem.wait();
        while(g_results[cur_result].first == true){
            cout << "Case #" << cur_result+1 << ": " << g_results[cur_result].second << endl;
            cur_result ++;
        }
    }
    for(int t=0;t<T;t++){
        threads[t].join();
    }
#endif
    // std::cout << "Hello, World!\n";
    return 0;
}


