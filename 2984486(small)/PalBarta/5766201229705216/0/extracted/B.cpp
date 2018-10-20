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

struct Edge
{
	int x;
	int y;
};

class TestCase 
{
public:
	int N;
	vector<Edge> e;

	TestCase()
	{
	
	}
	~TestCase()
	{
	
	}
	void readData(ifstream& inputFile)
	{
		inputFile >> N;
		for (int i=0; i < N-1; i++)
		{
			Edge edge;
			inputFile >> edge.x >> edge.y;
			
			e.push_back(edge);
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
		outputFile << "Case #" << index + 1 << ": " << result; 
		
	}
};

// PART II. - PROBLEM SPECIFIC FUNCTIONS

bool comp (int i,int j) { return (i<j); }

void processTestCase(TestCase& t, TestCaseResult& r)
{
	int deg[1000];
	for(int i=0; i < 1000; i++)
		deg[i] = 0;

	for(int i=0; i < t.e.size(); i++)
	{
		deg[t.e[i].x]++;
		deg[t.e[i].y]++;
	}

	int exc = 0;
	vector<int> twoDegs;
	for(int i=0; i < 1000; i++)
	{
		if (deg[i] == 2)
		{
			twoDegs.push_back(i);
		}
		if (deg[i] > 3)
			exc += deg[i] - 3;
	}

	if (twoDegs.size() != 0)
		r.result = twoDegs.size() - 1 + exc;
	else
		r.result = 1 + exc;

	if (t.N == 2)
		r.result = 1;
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