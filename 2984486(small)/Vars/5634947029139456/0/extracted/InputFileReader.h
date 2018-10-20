#pragma once

#include <string>
#include <vector>

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

class InputFileReader
{
public:
	InputFileReader(std::string fileName);
	~InputFileReader(void);
	void readFile();
protected:
	virtual void readTestCase( std::ifstream & file, std::ofstream & fileOut, int i ) = 0;

   template <typename T>
   void readValue( std::ifstream & file, std::vector<T> & inputVtr) 
   {
      std::string inputString;
      getline(file, inputString);
      std::istringstream inputStringLineStream(inputString);
      T buf;
      while (inputStringLineStream >> buf)
      {
         inputVtr.push_back(buf);
      }
   }

   void readValue( std::ifstream & file, std::string & val ) 
   {
      getline(file, val);
   }

   template <typename T>
   void readValue( std::ifstream & file, T & val ) 
   {
      std::string inputString;
      getline(file, inputString);
      std::istringstream inputStringLineStream(inputString);
      inputStringLineStream >> val;
   }

   template <typename T1, typename T2>
   void readValue( std::ifstream & file, std::pair<T1, T2> & inputPair) 
   {
	   std::string inputString;
	   getline(file, inputString);
	   std::istringstream inputStringLineStream(inputString);
	   T1 buf1;
	   inputStringLineStream >> buf1;
	   inputPair.first = buf1;
	   T2 buf2;
	   inputStringLineStream >> buf2;
	   inputPair.second = buf2;
   }

private:
	std::string m_fileName;
	int m_testCaseCount;
   std::ofstream fileOut;
};
