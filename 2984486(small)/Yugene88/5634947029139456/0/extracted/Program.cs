using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ChargingChaos
{
    class Program
    {
        static void Main(string[] args)
        {
            #region Google Code Jam Qualification Round 2014 Cookie Clicker Alpha
            // ----------------------------------------------------------------------------------------------------
            string inputFileName = "D:\\A-small-attempt0.in";
            string outputFileName = "D:\\A-small-attempt0.out";
            // ----------------------------------------------------------------------------------------------------
            if (File.Exists(outputFileName))
            {
                File.Delete(outputFileName);
            }
            using (StreamWriter streamWriter = new StreamWriter(outputFileName, true))
            using (StreamReader streamReader = new StreamReader(inputFileName, System.Text.Encoding.Default))
            {
                int testCaseCount = 1;
                int totalTestCase = int.Parse(streamReader.ReadLine());
                while (testCaseCount <= totalTestCase)
                {
                    #region input
                    // ----------------------------------------------------------------------------------------------------
                    string[] inputStringArray = streamReader.ReadLine().Split(' ');
                    int n = int.Parse(inputStringArray[0]);
                    int l = int.Parse(inputStringArray[1]);
                    char[,] start = new char[n, l];
                    inputStringArray = streamReader.ReadLine().Split(' ');
                    for (int i = 0; i < inputStringArray.Length; i++)
                    {
                        char[] charArray = inputStringArray[i].ToCharArray();
                        for (int j = 0; j < charArray.Length; j++)
                        {
                            start[i, j] = charArray[j];
                        }
                    }
                    char[,] target = new char[n, l];
                    inputStringArray = streamReader.ReadLine().Split(' ');
                    for (int i = 0; i < inputStringArray.Length; i++)
                    {
                        char[] charArray = inputStringArray[i].ToCharArray();
                        for (int j = 0; j < charArray.Length; j++)
                        {
                            target[i, j] = charArray[j];
                        }
                    }
                    // ----------------------------------------------------------------------------------------------------
                    #endregion
                    char[] operationString = new char[l];
                    while (true)
                    {
                        #region carry
                        // ----------------------------------------------------------------------------------------------------
                        for (int index = 0; index < l; index++)
                        {
                            if (operationString[index] == '0')
                            {
                                operationString[index] = '1';
                                break;
                            }
                            else
                            {
                                operationString[index] = '0';
                            }
                        }
                        // ----------------------------------------------------------------------------------------------------
                        #endregion
                        #region flipping
                        // ----------------------------------------------------------------------------------------------------
                        char[,] newStart = new char[n, l];
                        for (int i = 0; i < n; i++)
                        {
                            for (int j = 0; j < l; j++)
                            {
                                newStart[i, j] = start[i, j];
                                if (operationString[j] == '1')
                                {
                                    if (newStart[i, j] == '0')
                                    {
                                        newStart[i, j] = '1';
                                    }
                                    else
                                    {
                                        newStart[i, j] = '0';
                                    }
                                }                                
                            }
                        }
                        // ----------------------------------------------------------------------------------------------------
                        #endregion
                        #region match
                        // ----------------------------------------------------------------------------------------------------
                        bool allMatch = true;
                        bool outletsMatch = true;
                        for (int targetIndex = 0; targetIndex < n; targetIndex++)
                        {                            
                            for (int startIndex = 0; startIndex < n; startIndex++)
                            {
                                outletsMatch = true;
                                for (int i = 0; i < l; i++)
                                {
                                    if (newStart[startIndex, i] != target[targetIndex, i])
                                    {
                                        outletsMatch = false;
                                        break;
                                    }
                                }
                                if (outletsMatch)
                                {
                                    break;
                                }
                            }
                            if (!outletsMatch)
                            {
                                allMatch = false;
                                break;
                            }
                        }
                        if (allMatch)
                        {
                            int operationCount = 0;
                            for (int index = 0; index < operationString.Length; index++)
                            {
                                if (operationString[index] == '1')
                                {
                                    operationCount++;
                                }
                            }
                            streamWriter.WriteLine("Case #" + testCaseCount.ToString() + ": " + operationCount.ToString());
                            break;
                        }
                        // ----------------------------------------------------------------------------------------------------
                        #endregion                        
                        #region check end
                        // ----------------------------------------------------------------------------------------------------
                        bool isCompleted = true;
                        for (int index = 0; index < operationString.Length; index++)
                        {
                            if (operationString[index] == '0')
                            {
                                isCompleted = false;
                                break;
                            }
                        }
                        if (isCompleted)
                        {
                            streamWriter.WriteLine("Case #" + testCaseCount.ToString() + ": NOT POSSIBLE");
                            break;
                        }
                        // ----------------------------------------------------------------------------------------------------
                        #endregion
                    }
                    testCaseCount++;
                }
            }
            // ----------------------------------------------------------------------------------------------------
            #endregion
        }


    }
}
