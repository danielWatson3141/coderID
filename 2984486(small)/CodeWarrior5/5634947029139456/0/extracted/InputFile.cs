using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeWarrior5
{
    /// <summary>
    /// Class for parsing the input file.
    /// All exeptions to te thrown outside.
    /// </summary>
    class InputFile
    {
        System.IO.StreamReader rdr = null;
        
        /// <summary>
        /// Consctruct an object with file specified.
        /// </summary>
        /// <param name="filename">Filename</param>
        public InputFile(string filename)
        {
            rdr = new System.IO.StreamReader(filename + ".in");
        }

        /// <summary>
        /// Read next line with one integer value
        /// </summary>
        /// <returns>The int read</returns>
        public int readNextLineInt()
        {
            return Int32.Parse(rdr.ReadLine());
        }

        /// <summary>
        /// Read next line with all integer values.
        /// </summary>
        /// <returns></returns>
        public int[] readNextLineIntArr()
        {
            string nextLine = rdr.ReadLine();
            char[] seperators = {' ', ' '};
            string[] strItems = nextLine.Split(seperators);
            int[] retVal = new int[strItems.Length];

            for(int count=0; count < strItems.Length; count++)
            {
                retVal[count] = Int32.Parse(strItems[count]);
            }
            return retVal;
        }

        public string[] readNextLineStringArr()
        {
            string nextLine = rdr.ReadLine();
            char[] seperators = { ' ', ' ' };
            return nextLine.Split(seperators);
        }

        /// <summary>
        /// Read next line with all integer values.
        /// </summary>
        /// <returns></returns>
        public double[] readNextLineDoubleArr()
        {
            string nextLine = rdr.ReadLine();
            char[] seperators = { ' ', ' ' };
            string[] strItems = nextLine.Split(seperators);
            double[] retVal = new double[strItems.Length];

            for (int count = 0; count < strItems.Length; count++)
            {
                retVal[count] = double.Parse(strItems[count]);
            }
            return retVal;
        }

        /// <summary>
        /// Reads the next line in string format.
        /// </summary>
        /// <returns></returns>
        public string readLine()
        {
            return rdr.ReadLine();
        }

        /// <summary>
        /// Closes the stream.
        /// </summary>
        public void Close()
        {
            rdr.Close();
        }
    }
}
