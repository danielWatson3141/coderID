using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeWarrior5
{
    class OutputFile
    {
        System.IO.StreamWriter writer = null;
        int CurrentPos = 1;

        public OutputFile(string filename)
        {
            writer = new System.IO.StreamWriter(filename + ".out", false);
        }

        /// <summary>
        /// Adds the result for the next test case
        /// </summary>
        /// <param name="result">Result string</param>
        public void WriteNextTestResult(string result)
        {
            writer.WriteLine("Case #" + CurrentPos + ": " + result);
            CurrentPos++;
        }

        /// <summary>
        /// Adds next line of result part of last result.
        /// </summary>
        /// <param name="result">string result</param>
        public void AppendResult(string result)
        {
             writer.WriteLine(result);
        }

        public void Close()
        {
            writer.Close();
        }
    }
}
