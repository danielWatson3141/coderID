#include "StdAfx.h"
#include "InputFileReader.h"
#include <iomanip>

using namespace std;

InputFileReader::InputFileReader(string fileName)
: m_fileName(fileName)
, fileOut ("C:\\jam.out")
{
}

InputFileReader::~InputFileReader(void)
{
   fileOut.close();
}

// memory opt
void InputFileReader::readFile()
{
	ifstream file (m_fileName.c_str());

	while (!file.eof())
	{
      m_testCaseCount = 0;
		readValue(file, m_testCaseCount);
		for (int  i = 0; i <  m_testCaseCount; i++)
		{
			readTestCase(file, fileOut, i);
		}
		fileOut.close();
		file.close();
	}
}
