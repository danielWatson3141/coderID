#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//!
//! \brief The main function
//!
int main(int argc, char* argv[])
{
    // Check if valid number of program arguments
    if(argc != 2)
    {
        cerr << "Need only one argument : the input file name" << endl;
        return 0;
    }

    // Compute test name from input inStream name
    string testName = argv[1];
    testName = testName.substr(0, testName.find(".in"));

    // Open (and check) input inStream
    ifstream inStream(testName + ".in");
    if(!inStream.is_open())
    {
        cerr << "The input file \"" << testName << ".in\" does not exist" << endl;
        return 0;
    }

    // Get the number of test cases to process
    unsigned int T = 0;
    inStream >> T;

    // Create a string to get lines and ignore the previous already read one
    string line;
    getline(inStream, line);

    // Open the output file
    ofstream outStream(testName + ".out");

    // Process each test case one by one
    for(unsigned int t = 1 ; t <= T ; t++)
    {
        unsigned int N, L;
        inStream >> N;
        inStream >> L;

        vector<string> initFlows;
        for(unsigned int i = 0 ; i < N ; i++)
        {
            inStream >> line;
            initFlows.push_back(line);
        }

        vector<string> neededFlows;
        for(unsigned int i = 0 ; i < N ; i++)
        {
            inStream >> line;
            neededFlows.push_back(line);
        }

        // Prepare result
        bool possible = false;
        unsigned int result = L;

        // Brut force it badly
        for(unsigned int i = 0 ; i < static_cast<unsigned int>(pow(2, L)) ; i++)
        {
            vector<string> currentFlows = initFlows;
            vector<string> neededFlowsCopy = neededFlows;

            unsigned int l = 0;
            unsigned int r = 0;
            unsigned int tmp = i;
            while(tmp != 0)
            {
                if(tmp % 2 == 1)
                {
                    r++;
                    for(unsigned int n = 0 ; n < N ; n++)
                    {
                        if(currentFlows.at(n).at(l) == '0')
                            currentFlows.at(n).at(l) = '1';
                        else
                            currentFlows.at(n).at(l) = '0';
                    }
                }

                tmp /= 2;
                l++;
            }

            unsigned int nbMatch = 0;
            for(unsigned int n = 0 ; n < N ; n++)
            {
                for(unsigned int n2 = 0 ; n2 < N ; n2++)
                {
                    if(neededFlowsCopy.at(n) == currentFlows.at(n2))
                        nbMatch++;
                }
            }

            if(nbMatch == N)
            {
                possible = true;
                if(r < result)
                    result = r;
            }
        }

        // Output the test case result
        outStream << "Case #" << t << ": ";
        if(possible)
            outStream << result;
        else
            outStream << "NOT POSSIBLE";
        if(t != T)
            outStream << endl;
    }

    // Close input and output files
    outStream.close();
    inStream.close();

    // Exit the program
    return 0;
}
