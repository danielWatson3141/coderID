////////////////////////////////////////////////////////////////
//                                                            //
//  Google Code Jam Template                                  //
//  by MooseBoys                                              //
//                                                            //
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////
//                                            //
//  Generic Code                              //
//                                            //
////////////////////////////////////////////////

////////////////////////////////
//  Standard Includes         //
////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <map>
#include <functional>
#include <random>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include <Windows.h>
#include "BigIntegerLibrary.hh" // from http://mattmccutchen.net/bigint/
//#include "boost/math/common_factor.hpp" // from http://www.boost.org/


////////////////////////////////
//  Typedefs and Macros       //
////////////////////////////////

typedef long long           LL;
typedef unsigned long long  ULL;


////////////////////////////////
//  Debug Helpers             //
////////////////////////////////

// colored console messages
#define GoodMessage(message) {setColor(GOOD);std::cout<<message<<std::endl;setColor(NORMAL);}
#define BadMessage(message) {setColor(BAD);std::cout<<message<<std::endl;setColor(NORMAL);}
#define ImportantMessage(message) {setColor(IMPORTANT);std::cout<<message<<std::endl;setColor(NORMAL);}
enum consoleColor{ NORMAL, GOOD, BAD, IMPORTANT };
inline void setColor(consoleColor c)
{
    WORD wAttributes = 0x07;
    if (c == GOOD) wAttributes = 0x0A;
    if (c == BAD) wAttributes = 0x0C;
    if (c == IMPORTANT) wAttributes = 0xF9;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);
}


////////////////////////////////
//  Common Functions          //
////////////////////////////////

// find and open a problem input
int loadProblemFile(std::ifstream &inputFile, std::string &inputFileName)
{
    for (char cProblem = 'A'; cProblem <= 'Z'; cProblem++)
    {
        inputFileName = std::string(1, cProblem) + "-test";
        inputFile.open(inputFileName + ".in", std::ifstream::in);
        if (inputFile.is_open()) return 0;
        inputFileName = std::string(1, cProblem) + "-large";
        inputFile.open(inputFileName + ".in", std::ifstream::in);
        if (inputFile.is_open()) return 0;
        for (char cAttempt = '9'; cAttempt >= '0'; cAttempt--)
        {
            inputFileName = std::string(1, cProblem) + "-small-attempt" + cAttempt;
            inputFile.open(inputFileName + ".in", std::ifstream::in);
            if (inputFile.is_open()) return 0;
        }
    }
    return -1;
}

// load and create problem input and output streams
int getProblemIO(std::ifstream &input, std::ofstream &output)
{
    std::string fileName;
    if (loadProblemFile(input, fileName)){ BadMessage("could not find any input files to load"); return -1; }
    else{ GoodMessage("successfully loaded input file \"" << fileName << ".in\""); }
    output.open(fileName + ".out", std::ofstream::out);
    if (output.is_open()){ GoodMessage("successfully created output file \"" << fileName << ".out\""); }
    else{ BadMessage("could not create output file \"" << fileName << ".out\""); return -1; }
    return 0;
}

// BigInteger helper
BigUnsigned lcm(BigUnsigned a, BigUnsigned b)
{
    if (a == 0 && b == 0) return 0;
    else return (a * b) / gcd(a, b);
}


////////////////////////////////////////////////
//                                            //
//  Problem-Specific Code                     //
//                                            //
////////////////////////////////////////////////

using namespace std;

string xor(string a, string b)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] == b[i]) a[i] = '0';
        else a[i] = '1';
    }
    return a;
}

int ones(string a)
{
    int ret = 0;
    for (int i = 0; i < (int)a.size(); i++) if (a[i] == '1') ret++;
    return ret;
}

// problem entrypoint
int CodeJamMain()
{
    //// BigInteger reference
    //string s;
    //cin >> s;
    //BigInteger bi1 = stringToBigInteger(s);
    //cin >> s;
    //BigInteger bi2 = stringToBigInteger(s);
    //BigInteger bi3 = bi1 * bi2;
    //cout << bigIntegerToString(bi3) << endl;
    //BigUnsigned bu1 = stringToBigUnsigned(bigIntegerToString(bi1));
    //BigUnsigned bu2 = stringToBigUnsigned(bigIntegerToString(bi2));
    //BigUnsigned bu3 = gcd(bu1, bu2);
    //cout << bigUnsignedToString(bu3) << endl;
    //BigUnsigned b4 = lcm(bu1, bu2);
    //cout << bigUnsignedToString(b4) << endl;

    ifstream input;
    ofstream output;

    if (getProblemIO(input, output)) return -1;
    cout << fixed << setprecision(16);
    output << fixed << setprecision(16);

    // create grid of devices ^ outlets
    // find element with fewest set bits such that the element exists in every row

    int T;
    input >> T;
    for (int caseNum = 0; caseNum < T; caseNum++)
    {
        int N;
        input >> N;
        int L;
        input >> L;

        vector<string> devices;
        for (int i = 0; i < N; i++)
        {
            string device;
            input >> device;
            devices.push_back(device);
        }

        vector<string> outlets;
        for (int i = 0; i < N; i++)
        {
            string outlet;
            input >> outlet;
            outlets.push_back(outlet);
        }

        vector<vector<string>> grid(N, vector<string>(N));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                grid[i][j] = xor(devices[i], outlets[j]);
            }
        }

        vector<string> solutions;
        for (int i = 0; i < N; i++)
        {
            string candidate = grid[0][i];
            bool good = true;
            for (int j = 1; j < N; j++)
            {
                auto it = find(grid[j].begin(), grid[j].end(), candidate);
                if (it == grid[j].end())
                {
                    good = false;
                    break;
                }
            }
            if (good) solutions.push_back(candidate);
        }

        if (solutions.size() == 0)
        {
            string answer = "NOT POSSIBLE";
            output << "Case #" << caseNum + 1 << ": ";
            output << answer << endl;
            GoodMessage("Case #" << caseNum + 1 << ": " << answer);
        }
        else
        {
            int answer = L;
            for (auto& solution : solutions) answer = min(answer, ones(solution));
            output << "Case #" << caseNum + 1 << ": ";
            output << answer << endl;
            GoodMessage("Case #" << caseNum + 1 << ": " << answer);
        }
    }

    return 0;
}

////////////////////////////////////////////////
//                                            //
//  Generic Entrypoint                        //
//                                            //
////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    int ret = CodeJamMain();
    if (ret == 0){ GoodMessage(">>>> SUCCESS <<<<"); }
    else{ BadMessage(">>>> FAILURE <<<<"); }
    system("pause");
    return ret;
}
