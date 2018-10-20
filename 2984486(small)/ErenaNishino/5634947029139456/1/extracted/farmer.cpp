#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
    int caseNumber;
    int lineNumber = 0;
    int socketNumber = 0;
    int combNumber = 0; 
    int index = 0;
    string text[100000];
    string line;
    ifstream myfile("input.txt");
    ofstream outputFile("output.txt");
    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            text[index] = line;
            index++;
        } 
    }
    myfile.close();
    caseNumber = atoi(text[0].c_str());
    int testNumber = 0;
    while (testNumber < caseNumber)
    {
        stringstream ss(text[1 + 3 * testNumber]);
        string buf;
        ss >> buf;
        socketNumber = atoi(buf.c_str());
        ss >> buf;
        combNumber = atoi(buf.c_str());
        bool ori[socketNumber][combNumber];
        bool req[socketNumber][combNumber];
        int result;
        int tResult[socketNumber];
        stringstream ss2(text[2 + 3 * testNumber]);
        string buf2;
        stringstream ss1(text[3 + 3 * testNumber]);
        string buf1;
        for (int i = 0; i < socketNumber; i++)
        {
            tResult[i] = 0;
            ss2 >> buf2;
            ss1 >> buf1;
            for (int j = 0; j < combNumber; j++)
            {
                if(buf2[j] == '0')
                {
                    ori[i][j] = false;
                }
                else
                {
                    ori[i][j] = true;
                }
                if(buf1[j] == '0')
                {
                    req[i][j] = false;
                }
                else
                {
                    req[i][j] = true;
                }
            }
        }
        for (int i = 0; i < socketNumber; i++)
        {
            bool change[socketNumber][combNumber];
            bool s[combNumber];
            for (int j = 0; j < combNumber; j++)
            {
                if(ori[0][j] != req[i][j])
                {
                    s[j] = true;
                }
                else
                    s[j] = false;
            }
            for (int a = 0; a < combNumber; a++)
            {
                if(s[a] == true)
                {
                    tResult[i] = tResult[i] + 1;
                    cout << tResult[i] << endl;
                }
            }
            for (int a = 0; a < socketNumber; a++)
            {
                for (int b = 0; b < combNumber; b++)
                {
                    if(s[b] == true)
                    {
                        change[a][b] = !ori[a][b];        
                    }
                    else
                    {
                        change[a][b] = ori[a][b];
                    }
                }
            }
            for (int k = 0; k < socketNumber; k++)
            {
                bool sw1 = false;
                for (int a = 0; a < socketNumber; a++)
                {
                    bool sw = false;
                    for (int b = 0; b < combNumber; b++)
                    {
                        if(change[k][b] != req[a][b])
                        {
                            sw = true;
                            break;
                        }
                    }
                    if (sw == false)
                    {
                        sw1 = false;
                        break;
                    }
                    else
                    {
                        sw1 = true;
                    }
                }
                if (sw1 == true)
                {
                    tResult[i] = 9999;
                    break;
                }
            }
        }
        result = 9999;
        for (int i = 0; i < socketNumber; i++)
        {
            if (tResult[i] < result)
            {
                result = tResult[i];
            }
        }
        string resultString;
        if (result != 9999)
           outputFile << "Case #" << testNumber + 1 << ": " << result << endl;
        else
           outputFile << "Case #" << testNumber + 1 << ": " << "NOT POSSIBLE" << endl;
        testNumber++;
    }
    outputFile.close();
    return 0;
}
