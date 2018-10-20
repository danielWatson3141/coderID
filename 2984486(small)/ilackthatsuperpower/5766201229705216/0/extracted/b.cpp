//
//  b.cpp
//
//

#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <utility>
#include <functional>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>

//#include <boost/multi_array.hpp>


// function prototypes

// utility functions

// reads int vector from text file
void readVec
(
    std::ifstream & inFile,
    std::vector<int> & v,
    int const N // number of elements
)
{
    v.resize(N);
    for (int i=0; i<N; i++)
        inFile >> v[i];
}

// reads int64_t vector from text file
void readVec
(
    std::ifstream & inFile,
    std::vector<int64_t> & v,
    int const N // number of elements
)
{
    v.resize(N);
    for (int i=0; i<N; i++)
        inFile >> v[i];
}

// prints vector of ints to std::cout
void printVec(std::vector<int> const & v)
{
    for (int i=0; i<(int)v.size(); i++)
    {
        if (i>0)
            std::cout << " ";
        std::cout << v[i];
    }
    std::cout << "\n";
}

// prints vector of int64_t to std::cout
void printVec(std::vector<int64_t> const & v)
{
    for (int i=0; i<(int)v.size(); i++)
    {
        if (i>0)
            std::cout << " ";
        std::cout << v[i];
    }
    std::cout << "\n";
}

// globals

std::ifstream inFile;

// functions

void setup()
{
}

int prune(std::vector <int> nodes[1001], int nd, int parent)
{
    int v=0;
    int sz=nodes[nd].size();
    if (sz==1) {
        return 1;
    }
//     if (sz==2) {
//         if (nodes[nd][0]==parent)
//             return 1+prune(nodes, nodes[nd][1], nd);
//         else
//             return 1+prune(nodes, nodes[nd][0], nd);
//     }
    for (int i=0; i<sz; i++) {
        if (nodes[nd][i] != parent) {
            v += prune(nodes, nodes[nd][i], nd);
        }
    }
    return 1+v;
}


int keep(std::vector <int> nodes[1001], int nd, int parent)
{
    int v=0;
    int sz=nodes[nd].size();
//    std::cout << "    sz: " << sz << "\n";
    if (sz==1) {
        return 0;
    }
    if (sz==2) {
        if (nodes[nd][0]==parent)
            return prune(nodes, nodes[nd][1], nd);
        else
            return prune(nodes, nodes[nd][0], nd);
    }
    int kp, pr;
    std::vector <int> d;
    int sum=0;
    for (int i=0; i<sz; i++) {
        if (nodes[nd][i] != parent) {
            kp=keep(nodes, nodes[nd][i], nd);
            pr=prune(nodes, nodes[nd][i], nd);
            d.push_back(pr-kp);
            sum += pr;
        }
    }
    std::sort(d.begin(), d.end());

    v = sum - d[sz-2]-d[sz-3];
 
//            v += prune(nodes, nodes[nd][i], nd);
    return v;
}





void processCase()
{

    int N;
    
    inFile >> N;
    
    std::vector <int> e0(N-1);
    std::vector <int> e1(N-1);
    std::vector <int> nodes[1001];
    
    for (int i=0; i<N-1; i++) {
        inFile >> e0[i] >> e1[i];
        nodes[e0[i]].push_back(e1[i]);
        nodes[e1[i]].push_back(e0[i]);
    }
    
    if (N==2) {
        std::cout << "1\n";
        return;
    }   
    
    int best=N;
    
//    std::cout << "\n";
    for (int r=1; r<=N; r++) {
//        std::cout << "root: " << r << "\n";
        int sz = nodes[r].size();
        if (sz==1)
            continue;
        std::vector <int> kp(sz);
        std::vector <int> pr(sz);
        std::vector <int> d(sz);
        int sum=0;
        for (int i=0; i<sz; i++) {
            kp[i]=keep(nodes, nodes[r][i], r);
            pr[i]=prune(nodes, nodes[r][i], r);
//             std::cout << "  node:  " << nodes[r][i] << "\n";
//             std::cout << "  keep:  " << kp[i] << "\n";
//             std::cout << "  prune: " << pr[i] << "\n";
            d[i] = pr[i]-kp[i];
            sum += pr[i];
        }
        std::sort(d.begin(), d.end());

        int v = sum - d[sz-1]-d[sz-2];
        if (v<best)
            best=v;
        
    }
    

    std::cout << best << "\n";
}


// main

int main(int argc, char const * argv[])
{

    int T;
    
    // make sure filename is provided
    if (argc != 2)
    {
        std::cout << "Expected one argument\n";
        std::exit(0);
    }
    
    // open input file
    inFile.open(argv[1]);
    
    inFile >> T;
    
    
    setup();
    
    std::cout << std::setprecision(9);
    
    for (int caseIndex=1; caseIndex<=T; caseIndex++)
    {
        std::cout << "Case #" << caseIndex << ": ";
        processCase();
    }
    
    return 0;
}
