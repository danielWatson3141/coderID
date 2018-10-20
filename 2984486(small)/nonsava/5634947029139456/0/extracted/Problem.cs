using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;


namespace nonsava.gcj
{
	class Problem
	{
		#region Main

		static string RESULTFILE = @"..\..\..\__out.txt";

		static void Main( string[] args )
		{
			if( 0 < args.Length ) {
				CASEFILE = args[0];
			} else if( 1 < args.Length ) {
				MAXTHREADS = int.Parse( args[1] );
			}

			DateTime startTime = DateTime.Now;

			int count;
			Problem[] testcases;

			using( TextReader reader = new StreamReader( CASEFILE ) ) {
				string line = reader.ReadLine();
				count = int.Parse( line );
				testcases = new Problem[count];

				for( int i = 0; i < count; i++ )
					testcases[i] = new Problem( reader );
			}

			Initialize();

			Thread[] threadPool = new Thread[MAXTHREADS];
			for( int t = 0; t < MAXTHREADS; t++ )
				threadPool[t] = null;

			for( int next = 0;; ) {
				if( count <= next ) {
					bool finished = true;
					for( int t = 0; t < MAXTHREADS; t++ )
						if( threadPool[t] != null && threadPool[t].IsAlive ) {
							finished = false;
							break;
						}
					if( finished )
						break;
				}

				for( int t = 0; t < MAXTHREADS; t++ ) {
					if( threadPool[t] != null && !threadPool[t].IsAlive )
						threadPool[t] = null;

					if( threadPool[t] == null && next < count ) {
						Console.WriteLine( "----------------------------------------------------- {0}/{1} ({2:F3}[sec])", next + 1, count, ( DateTime.Now - startTime ).TotalSeconds );
						testcases[next].WriteParams();

						threadPool[t] = new Thread( new ThreadStart( testcases[next++].Solv ) );
						threadPool[t].Start();
					}
				}

				Thread.Sleep( 100 );
			}

			Console.WriteLine( "\n#############################################################################\n" );
			using( TextWriter writer = new StreamWriter( RESULTFILE ) ) {
				for( int i = 0; i < count; i++ )
					testcases[i].WriteResult( writer, i + 1 );
			}

			TimeSpan span = DateTime.Now - startTime;
			Console.WriteLine( "\n#############################################################################\n" );
			Console.WriteLine( "{0:F3}[sec] = {1:F3}[min]", span.TotalSeconds, span.TotalMinutes );
			if( BEEP )
				Console.Beep( 1000, 5000 );
			Console.ReadKey();
		}


		string Result;

		private void WriteResult( TextWriter writer, int number )
		{
			writer.WriteLine( "Case #{0}: {1}", number, Result );
			Console.WriteLine( "Case #{0}: {1}", number, Result );
		}

		#endregion


		////////////////////////////////
		//static string CASEFILE = @"..\..\..\__in_sample.txt";

		static string CASEFILE = @"..\..\..\A-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\A-large.in";

		static int MAXTHREADS = 1;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		int N;
		int L;
		char[,] A;
		//char[,] X;
		string[] X;
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			N = int.Parse( strs[0] );
			L = int.Parse( strs[1] );
			A = new char[N,L];
			//X = new char[N,L];
			X = new string[N];

			line = reader.ReadLine();
			strs = line.Split( new char[] { ' ' } );
			for( int i = 0; i < N; i++ ) {
				for(int j=0;j<L;j++)
					A[i,j] = strs[i][j];
			}
			line = reader.ReadLine();
			strs = line.Split( new char[] { ' ' } );
			for( int i = 0; i < N; i++ ) {
				//for(int j=0;j<L;j++)
				//    X[i,j] = strs[i][j];
				X[i] = strs[i];
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1}", N, L );
			for( int i = 0; i < N; i++ ) {
				for(int j=0;j<L;j++)
					Console.Write( "{0}", A[i,j] );
				Console.Write( " " );
			}
			Console.WriteLine();
			for( int i = 0; i < N; i++ ) {
				//for(int j=0;j<L;j++)
				//    Console.Write( " {0}", X[i,j] );
				//Console.Write( " " );
				Console.Write( " {0}", X[i] );
			}
			Console.WriteLine();
			////////////////////////////////
		}


		private void Solv()
		{
			////////////////////////////////
			int min = int.MaxValue;
			for(int i = 0; i < (1<<L); i++) {
				char[,] a = new char[N,L];
				//List<char[]> x = new List<char[]>();
				List<string> x = new List<string>();
				for (int j=0;j<N;j++) {
					//char[] xx = new char[L];
					//x.Add(xx);
					x.Add(X[j]);
					for (int k=0;k<L;k++) {
						 a[j,k] = A[j,k];
						 //xx[k] = X[j,k];
					}
				}

				int count = 0;
				int n = i;
				for(int l=0; l<L; l++) {
					if ((n&1)==1) {
						for(int j = 0; j < N; j++)
							a[j,l] = (a[j,l] == '0') ? '1' : '0';
						count++;
					}
					n >>= 1;
				}
				List<string> aa = new List<string>();
//Console.WriteLine("**********************************");
				for (int j=0;j<N;j++) {
					char[] q = new char[L];
					for (int k=0;k<L;k++) {
						q[k] = a[j,k];
					}
//Console.WriteLine("************* q = " + new String(q));
					aa.Add(new String(q));
				}

				bool ok = true;
				for (int j=N-1;j>=0;j--) {
					int index = x.IndexOf(aa[j]);
					if (index != -1) {
						x.RemoveAt(index);
						aa.RemoveAt(j);
					} else {
						ok = false;
						break;
					}					
				}
				if(ok && count < min)
					min = count;
			}
			Result = min < int.MaxValue ? min.ToString() : "NOT POSSIBLE";
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
