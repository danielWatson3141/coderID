using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;
using System.Threading;

namespace GoogleCodeJamPractice
{
    /// <summary>
    /// Reads a tipical Input for Google Code Jam's Problems, started by a line containing T, followed by T
    /// test cases
    /// </summary>
    class CodeJamInput
    {
        string input = File.ReadAllText(@"c:\users\cecilia\documents\visual studio 2010\Projects\GoogleCodeJamPractice\GoogleCodeJamPractice\input.in");

        public CodeJamProblem[] problems;
        string[] lines;
        int currentLine = 0;

        public string NextLine()
        {
            return lines[currentLine++];
        }

        public CodeJamInput()
        {
            lines = input.Replace("\r", "").Split('\n');
            int T = int.Parse(NextLine());

            problems = new CodeJamProblem[T];

            for (int i = 0; i < T; ++i)
            {
                problems[i] = new CodeJamProblem().BuildProblem(this);
                problems[i].Number = i + 1;
            }
        }
    }

    class Program
    {
        static string outputPath = @"c:\users\cecilia\documents\visual studio 2010\Projects\GoogleCodeJamPractice\GoogleCodeJamPractice\output.out";

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            //Reads the input
            CodeJamInput input = new CodeJamInput();
            StringBuilder output = new StringBuilder();

            foreach (CodeJamProblem p in input.problems)
            {
                //Solves each test case
                output.AppendLine(p.GetSolution());
            }

            //Print results to file
            File.WriteAllText(outputPath, output.ToString());
        }
    }

    /// <summary>
    /// Actual class to be implemented during contest, represents a test case
    /// </summary>
    class CodeJamProblem
    {
        public int Number;

        int N;
        int L;

        bool[,] required;
        bool[,] initial;

        /// <summary>
        /// Reads a test case and initializes the class' variables
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public CodeJamProblem BuildProblem(CodeJamInput input)
        {
            string[] letters = input.NextLine().Split(' ');

            N = int.Parse(letters[0]);
            L = int.Parse(letters[1]);

            string[] str_initial = input.NextLine().Split(' ');

            initial = new bool[N,L];
            required = new bool[N,L];

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    initial[i, j] = str_initial[i].ToCharArray()[j] == '1';
                }
            }

            string[] str_required = input.NextLine().Split(' ');

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    required[i, j] = str_required[i].ToCharArray()[j] == '1';
                }
            }

            return this;
        }

        /// <summary>
        /// Solves a test case from the variables
        /// </summary>
        /// <returns></returns>
        public string GetSolution()
        {
            StringBuilder sb = new StringBuilder();
            int switches = 0;

            bool impossible = false;

            for (int i = 0; i < L; i++)
            {
                int bitsRequired = CountBitsOnLine(required, N, i);
                int bitsInitial = CountBitsOnLine(initial, N, i);

                if (bitsInitial == bitsRequired)
                {
                    continue;
                }
                else
                {
                    if (bitsInitial == N - bitsRequired)
                    {
                        switches++;
                        FlipBit(initial, N, i);
                        continue;
                    }
                    else
                    {
                        impossible = true;
                        break;
                    }
                }
            }

            if (impossible)
            {
                return sb.Append("Case #" + Number + ": ").Append("NOT POSSIBLE").ToString();
            }
            else
            {
                List<int> flippableCollumns = GetFlippableCollumns(initial);

                if (flippableCollumns.Count == 0)
                {
                    if (IsPermutation(initial, required))
                    {
                        return sb.Append("Case #" + Number + ": ").Append(switches).ToString();
                    }
                    else
                    {
                        return sb.Append("Case #" + Number + ": ").Append("NOT POSSIBLE").ToString();
                    }
                }
                else
                {
                    for (int i = 0; i < Convert.ToInt64(Math.Pow(2, flippableCollumns.Count)); i++)
                    {
                        bool[,] copy = (bool[,])initial.Clone();

                        for (int j = 0; j < flippableCollumns.Count; j++)
                        {
                            if ((i & (1 << j)) >> j == 1)
                            {
                                FlipBit(copy, N, flippableCollumns[j]);
                            }
                        }

                        if (IsPermutation(copy, required))
                        {
                            return sb.Append("Case #" + Number + ": ").Append(switches + NumberOfSetBits(i)).ToString();
                        }
                    }

                    return sb.Append("Case #" + Number + ": ").Append("NOT POSSIBLE").ToString();
                }
            }
        }

        int NumberOfSetBits(int i)
        {
            i = i - ((i >> 1) & 0x55555555);
            i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
            return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
        }

        public int CountBitsOnLine(bool[,] board, int N, int l)
        {
            int result = 0;

            for (int i = 0; i < N; i++)
            {
                if (board[i, l])
                {
                    result++;
                }
            }

            return result;
        }

        public int FlipBit(bool[,] board, int N, int l)
        {
            int result = 0;

            for (int i = 0; i < N; i++)
            {
                board[i, l] = !board[i, l];
            }

            return result;
        }

        public List<int> GetFlippableCollumns(bool[,] board)
        {
            List<int> result = new List<int>();

            for (int j = 0; j < L; j++)
            {
                int ones = 0;
                int zeros = 0;
                for (int i = 0; i < N; i++)
                {
                    if (board[i, j])
                    {
                        ones++;
                    }
                    else
                    {
                        zeros++;
                    }
                }

                if (ones == zeros)
                    result.Add(j);

            }

            return result;
        }

        public bool IsPermutation(bool[,] initial, bool[,] required)
        {
            List<int> usedLines = new List<int>();
            for (int i = 0; i < N; i++)
            {
                int line = FindLineIndex(initial, required, i, usedLines);

                if (line == -1)
                    return false;
                else
                {
                    usedLines.Add(line);
                }
            }
            return true;
        }

        public string PrintArray(bool[,] array)
        {
            //Used for debugging
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    if (array[i, j])
                        sb.Append("1");
                    else
                        sb.Append("0");
                }
                sb.AppendLine();
            }
            return sb.ToString();
        }

        public int FindLineIndex(bool[,] initial, bool[,] required, int i, List<int> usedLines)
        {
            for (int j = 0; j < N; j++)
            {
                if (!usedLines.Contains(j))
                {
                    bool areEqual = true;
                    for (int z = 0; z < L; z++)
                    {
                        if (initial[i, z] != required[j, z])
                        {
                            areEqual = false;
                            break;
                        }
                    }

                    if (areEqual)
                    {
                        return j;
                    }
                }
            }

            return -1;
        }
    }
}
