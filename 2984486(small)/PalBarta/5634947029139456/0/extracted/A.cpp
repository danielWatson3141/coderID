#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gmpxx.h"
typedef mpz_class bigint; 
using namespace std;

// PART I. - INPUT-OUTPUT STRUCTURES

struct Flow
{
	vector<char> switches;
};

class TestCase 
{
public:
	int N, L;
	vector<Flow> outlets;
	vector<Flow> devices;

	TestCase()
	{
	
	}
	~TestCase()
	{
	
	}
	void readData(ifstream& inputFile)
	{
		inputFile >> N >> L;
		char s;
		for (int i=0; i < N; i++)
		{
			inputFile.get(s);
			Flow outlet;
			for (int j=0; j < L; j++)
			{
				char c;
				inputFile.get(c);
				outlet.switches.push_back(c);
			}
			outlets.push_back(outlet);
		}

		for (int i=0; i < N; i++)
		{
			inputFile.get(s);
			Flow device;
			for (int j=0; j < L; j++)
			{
				char c;
				inputFile.get(c);
				device.switches.push_back(c);
			}
			devices.push_back(device);
		}
	}
};

struct TestCaseResult
{
	int result; 
	TestCaseResult()
	{
		
	}

	void printResultToFile(ofstream& outputFile, int index)
	{
		if (result == -1)
		{
			outputFile << "Case #" << index + 1 << ": " << "NOT POSSIBLE"; 
		}
		else
		{
			outputFile << "Case #" << index + 1 << ": " << result; 
		}
	}
};

// PART II. - PROBLEM SPECIFIC FUNCTIONS

bool comp (int i,int j) { return (i<j); }

void processTestCase(TestCase& t, TestCaseResult& r)
{
	int num = pow(2.0, t.L);
	vector<int> found;
	for (int k=0; k < num; k++)
	{
		bool sol = true;
		for (int i=0; i < t.N; i++)
		{
			bool foundPair = true;
			for (int j=0; j < t.N; j++)
			{
				Flow o = t.outlets[i];
				Flow d = t.devices[j];

				foundPair = true;

				for(int a=0; a < t.L; a++)
				{
					int mask = 1 << a;
					int sw = mask & k;
					
					char c = o.switches[t.L - a -1];
					if (sw >= 1 && c=='0')
						c='1';
					else if (sw >= 1 && c=='1')
						c='0';

					if (c != d.switches[t.L - a -1])
					{
						foundPair=false;
						break;
					}
				}

				if(foundPair)
					break;
			}

			if (!foundPair)
				sol = false;
		}
		if (sol)
			found.push_back(k);
	}

	if (found.empty())
	{
		r.result = -1;
		return;
	}

	int minOnes = INT_MAX;
	int index = -1;
	for (int j=0; j < found.size(); j++)
	{
		int n = found[j];
		
		unsigned int count = 0;
		while(n)
		{
			count += n & 1;
			n >>= 1;
		}

		if (count < minOnes)
		{
			minOnes = count;
			index = j;
		}
	}

	r.result = minOnes;
}

// PART III. - BOILERPLATE CODE FOR INPUT-OUTPUT PROCESSING

class InputData
{
	vector<TestCase> testCases;

private:
	bool readInputFile(const string& inputFilePath);

public:
	InputData(const string& inputFilePath);
	
	int getNumberOfTestCases() { return testCases.size(); }
	TestCase& getTestCase(int index) { return testCases[index];}
};

class ResultData
{
	vector<TestCaseResult> testCaseResults;

public:
	
	bool writeOutputFile(const string& outputFilePath);
	void addResult(TestCaseResult result) { testCaseResults.push_back(result); }
	void addResult(int index, TestCaseResult result) { testCaseResults.insert(testCaseResults.begin() + index, result); }

};

bool ResultData::writeOutputFile(const string& outputFilePath)
{
	ofstream outputFile(outputFilePath);
	
	if (!outputFile.is_open())
		return false;

	for (unsigned int i=0; i < testCaseResults.size(); i++)
	{
		TestCaseResult testCaseResult = testCaseResults[i];
		testCaseResult.printResultToFile(outputFile, i);
		if (i != testCaseResults.size() - 1)
			outputFile << endl;
	}

	return true;
}

InputData::InputData(const string& inputFilePath)
{
	readInputFile(inputFilePath);
}

bool InputData::readInputFile(const string& inputFilePath)
{
	ifstream inputFile(inputFilePath);

	if (!inputFile.is_open())
		return false;

	string line;
	getline(inputFile, line);
	istringstream inputStringStream(line);
	int numOfTestCases = 0;
	inputStringStream >> numOfTestCases;

	for (int i = 0; i < numOfTestCases; i++)
	{
		TestCase testCase;
		testCase.readData(inputFile);
		testCases.push_back(testCase); 
	}

	return true;
}

void processInputData(InputData& inputData, ResultData& resultData)
{
	int numberOfTestCases = inputData.getNumberOfTestCases();
	for (int testCaseIndex = 0; testCaseIndex < numberOfTestCases; testCaseIndex++)
	{
		TestCase testCase = inputData.getTestCase(testCaseIndex);
		TestCaseResult result;
		cout << '\r' << "Test cases processed: " << testCaseIndex << "/" << numberOfTestCases;
		processTestCase(testCase, result);
		resultData.addResult(testCaseIndex, result);
	}
}

void main(int argc, char* argv[])
{
	// Check command line arguments
	if (argc < 3)
	{
		cerr << "Incorrect parameters. Usage: application.exe <input file path> <output file path>" << endl;
		return;
	}

	// Prepare data structures
	string inputFilePath = argv[1];
	InputData inputData(inputFilePath);
	ResultData resultData;

	// Process data
	processInputData(inputData, resultData);

	// Write results
	string outputFilePath = argv[2];
	resultData.writeOutputFile(outputFilePath);
}