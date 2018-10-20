#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <cmath>
#include <vector>
using namespace std;

int count(long n)
{
  int retVal = 0;
  while (n)
  {
    retVal += n & 1;
    n >>= 1;
  }
  return retVal;
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cerr << "Invalid commandline parameters" << endl;
        return -1;
    }

    fstream input(argv[1], fstream::in);
    fstream output(argv[2], fstream::out | fstream::trunc);

    int numTestCases;
    input >> numTestCases;

    int N, L;
    long *original, *required, *temp;
    vector<long> intersection;
    long current;
    int switches = -1;
    char *temps = new char[10];
    char * end;

    for (int i = 0; i < numTestCases; i++)
    {
        input >> N >> L;
        original = new long[N];
        required = new long[N];
        temp = new long[N];
        switches = -1;

        for (int j = 0; j < N; j++)
        {
            input >> current;
            original[j] = strtol(itoa(current, temps, 10), &end, 2);
        }

        for (int j = 0; j < N; j++)
        {
            input >> current;
            required[j] = strtol(itoa(current, temps, 10), &end, 2);
        }

        sort(required, required + N);

        for (int j = 0; j < pow(2.0, L) - 1; j++)
        {
            memcpy(temp, original, sizeof(long) * N);
            intersection.clear();

            for (int k = 0; k < N; k++)
            {
                temp[k] ^= j;
            }

            sort(temp, temp + N);
            set_intersection(temp, temp + N, required, required + N,  back_inserter(intersection));

            if (intersection.size() == N)
            {
                switches = count(j);
                break;
            }
        }

        
        
        
        if (switches == -1)
        {
            output << "Case #" << (i + 1) << ": NOT POSSIBLE" << endl;
        }
        else
        {
            output << "Case #" << (i + 1) << ": " << switches << endl;
        }
    }
}