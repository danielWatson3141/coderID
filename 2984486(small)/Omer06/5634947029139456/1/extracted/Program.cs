using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem1
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.StreamWriter writer = new System.IO.StreamWriter(@"C:\Users\Omer\Documents\Visual Studio 2013\Projects\Round1A GoogleCodeJam\Problem1\Output\Q1.txt");
            string[] lines = System.IO.File.ReadAllLines(@"C:\Users\Omer\Documents\Visual Studio 2013\Projects\Round1A GoogleCodeJam\Problem1\Input\A-large.in"); int indexForLines = 0;
            int NumberOfTestCases = Int32.Parse(lines[indexForLines]);
            int TCFirstLineIndex = 1;
            for(int index=1;index<=NumberOfTestCases;index++)
            {
                string[] firstLine = lines[TCFirstLineIndex].Split(' ');
                int N = Convert.ToInt32(firstLine[0]);
                int L = Convert.ToInt32(firstLine[1]);

                string[] outlets = lines[TCFirstLineIndex+1].Split(' ');
                string[] devices = lines[TCFirstLineIndex + 2].Split(' ');
                int result = GetConstantDifference(outlets, devices);

                if(devices.Length>outlets.Length || result==-1)
                {
                    writer.WriteLine("Case #" + index.ToString() + ": NOT POSSIBLE");
                }
                else
                {
                    writer.WriteLine("Case #" + index.ToString() + ": "+result.ToString());
                }
                TCFirstLineIndex += 3;
            }
            writer.Close();

            Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }

        private static int GetConstantDifference(string[] outlets, string[] devices)
        {
            int result=-1;
            HashSet<string> myOutlets = new HashSet<string>();
            for (int i = 0; i < outlets.Length;i++ )
                myOutlets.Add(outlets[i]);

            HashSet<string> myDevices = new HashSet<string>();
            for (int i = 0; i < devices.Length; i++)
                myDevices.Add(devices[i]);

            string firstDevice = myDevices.First();
            for (int i = 0; i < myOutlets.Count;i++ )
            {
                string bitsToFlip = GetBitsToFlip(firstDevice, myOutlets.ElementAt(i));
                HashSet<string> myOutlets2 = new HashSet<string>();
                for (int k = 0; k < myOutlets.Count; k++)
                        myOutlets2.Add(myOutlets.ElementAt(k));

                HashSet<string> myDevices2 = new HashSet<string>();
                for (int m = 0; m < myDevices.Count; m++)
                    myDevices2.Add(myDevices.ElementAt(m));

                for(int j=0;j<myDevices.Count;j++)
                {
                    string outletForDevice=GetOutletAfterFlipping(myDevices.ElementAt(j), bitsToFlip);
                    if (myOutlets2.Contains(outletForDevice))
                    {
                        myOutlets2.Remove(outletForDevice);
                        myDevices2.Remove(myDevices.ElementAt(j));
                    }
                }
                
                if(myDevices2.Count==0)
                {
                    int number = GetBitsFlipped(bitsToFlip);
                    if (number < result && result!=-1) result = number;
                    if (result == -1) result = number;
                }
            }
            return result;
        }

        private static int GetBitsFlipped(string bitsToFlip)
        {
            int count=0;
            for(int i=0;i<bitsToFlip.Length;i++)
            {
                if (bitsToFlip[i] == '1') count++;
            }
            return count;
        }

        private static string GetOutletAfterFlipping(string mydevice, string bitsToFlip)
        {
            string output = "";
            for(int i=0;i<bitsToFlip.Length;i++)
            {
                if(bitsToFlip[i]=='0')
                {
                    if(mydevice[i]=='0')
                        output=String.Concat(output, "0");
                    else if(mydevice[i]=='1')
                        output = String.Concat(output, "1");
                }
                else if (bitsToFlip[i] == '1')
                {
                    if (mydevice[i] == '1')
                        output = String.Concat(output, "0");
                    else if (mydevice[i] == '0')
                        output = String.Concat(output, "1");
                }
            }
            return output;
        }

        private static string GetBitsToFlip(string firstDevice, string outlet)
        {
            string Bits = "";
            for(int i=0;i<firstDevice.Length;i++)
            {
                if(firstDevice[i]==outlet[i])
                {
                    Bits=String.Concat(Bits, "0");
                }
                else
                {
                    Bits = String.Concat(Bits, "1");
                }
            }
            return Bits;
        }
    }
}
