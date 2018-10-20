//
//  a.cpp
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


void processCase()
{

    int N,L;
    
    inFile >> N >> L;
    
    std::vector <std::string> sw(N);
    std::vector <std::string> dv(N);
    
    for (int i=0; i<N; i++) {
        inFile >> sw[i];
    }
    for (int i=0; i<N; i++) {
        inFile >> dv[i];
    }
    
    std::string cmp[150][150];

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cmp[i][j]= std::string(L,'0');
            for (int k=0; k<L; k++) {
                cmp[i][j][k] += sw[i][k] ^ dv[j][k];
            }
        }
    }
    
//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             std::cout << cmp[i][j] << " ";
//         }
//         std::cout << "\n";
//     }

    int best = L+1;

    for (int i=0; i<N; i++) {
        std::vector <int> used(N);
        std::string test = cmp[i][0];
        int wt=0;
        for (int k=0; k<L; k++) {
            wt += test[k]-'0';
        }
        if (wt>=best)
            continue;
        
        for (int j=0; j<N; j++) {
            bool pass=0;
            for (int ii=0; ii<N; ii++) {
                if (test==cmp[ii][j]) {
                    if (used[ii]) {
                        goto fail;
                    }
                    else {
                        used[ii]=1;
                        pass=1;
                        break;
                    }
                }
            }
            if (!pass) goto fail;
        }
        best = wt;
        fail:
        ;
    }

//     for (int i=0; i<N; i++) {
//         std::cout << sw[i] << " " << dv[i] << "\n";
//     }

    if (best==L+1) {
        std::cout << "NOT POSSIBLE\n";
    }
    else {
        std::cout << best << "\n";
    }
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
