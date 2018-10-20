import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class CJ_1A_2014 {

	public CJ_1A_2014(){}
	public static void main( String[] asArguments ){
		doProblem();
	}
	
	static void doProblem(){
		StringBuffer sbError = new StringBuffer();
		StringBuffer sbAnswer = new StringBuffer();
//		String sAbsolutePath_input = "R:\\dev\\codejam\\1A\\A-example.in";
//		String sAbsolutePath_output = "R:\\dev\\codejam\\1A\\A-example.out";
//		String sAbsolutePath_input = "R:\\dev\\codejam\\1A\\A-small-attempt0.in";
//		String sAbsolutePath_output = "R:\\dev\\codejam\\1A\\A-small-attempt0.out";
		String sAbsolutePath_input = "R:\\dev\\codejam\\1A\\A-large.in";
		String sAbsolutePath_output = "R:\\dev\\codejam\\1A\\A-large.out";
		ArrayList<String> listLines = zLoadLines( sAbsolutePath_input, 50000, sbError );
		int ctTestCases = 0;
		try {
			ctTestCases = Integer.parseInt( listLines.get( 0 ) );
			System.out.println( "test case count: " + ctTestCases ); 
		} catch( Throwable t ) {
			System.err.println( "count test cases: " + t );
			System.exit( -1 );
		}
		int xLine = 1;
		for( int xTestCase = 1; xTestCase <= ctTestCases; xTestCase++ ){
			int iAnswer = 0;
			String sNL = listLines.get( xLine );
			String sOutlets = listLines.get( xLine + 1 );
			String sDevices = listLines.get( xLine + 2 );
			xLine += 3;

			String[] sN = split( sNL, ' ' );
			String[] asOutlets = split( sOutlets, ' ' );
			String[] asDevices = split( sDevices, ' ' );
			int iN = Integer.parseInt( sN[0] ); // number of outlets/devices
			int iL = Integer.parseInt( sN[1] ); // number of bits
			System.out.println( "N: " + iN );
			System.out.println( "L: " + iL );

			boolean[][] listOutlets = new boolean[iN][iL];
			boolean[][] listDevices = new boolean[iN][iL];
			for( int xN = 0; xN < iN; xN++ ){
				for( int xBit = 0; xBit < iL; xBit++ ){
					if( asOutlets[xN].charAt( xBit ) == '0' ) listOutlets[xN][xBit] = false; else listOutlets[xN][xBit] = true;
					if( asDevices[xN].charAt( xBit ) == '0' ) listDevices[xN][xBit] = false; else listDevices[xN][xBit] = true;
				}
			}

			boolean[][][] xor = new boolean[iN][iN][iL];
			for( int xOutlet = 0; xOutlet < iN; xOutlet++ ){
				for( int xDevice = 0; xDevice < iN; xDevice++ ){
					for( int xBit = 0; xBit < iL; xBit++ ){
						if( listOutlets[xOutlet][xBit] == listDevices[xDevice][xBit] ) xor[xOutlet][xDevice][xBit] = false; else xor[xOutlet][xDevice][xBit] = true;
					}
				}
			}

			boolean[] used = new boolean[iN];
			int ctSolutions = 0;
			int iBestSolution = Integer.MAX_VALUE;
			for( int xN = 0; xN < iN; xN++ ){
				Arrays.fill( used, false );
				int xDevice = 0;
				boolean[] xorBase = xor[xN][xDevice];
				while( true ){
					xDevice++;
					if( xDevice == iN ){ // found solution
						ctSolutions++;
						int ctSwitches = 0;
						for( int xBit = 0; xBit < iL; xBit++ ) if( xorBase[xBit] ) ctSwitches++;
						if( ctSwitches < iBestSolution ) iBestSolution = ctSwitches;
						break;
					}
					boolean zFoundMatch = false;
					for( int xOutlet = 0; xOutlet < iN; xOutlet++ ){
						if( ! used[xOutlet] && compareXOR( xorBase, xor[xOutlet][xDevice], iL ) ){
							if( zFoundMatch ){
								System.out.println( "multiple matches" );
							} else {
								used[xOutlet] = true;
							}
							zFoundMatch = true;
//							break;
						}
					}
					if( ! zFoundMatch ) break; // no solution for this switch pattern
				}
			}

			// write output
			if( ctSolutions == 0 ){
				sbAnswer.append( "Case #" + xTestCase + ": NOT POSSIBLE\n" );
			} else {
				sbAnswer.append( "Case #" + xTestCase + ": " + iBestSolution + "\n" );
			}
		}
		fileSave( sAbsolutePath_output, sbAnswer.toString(), sbError );
		System.out.println( "wrote " + ctTestCases + " cases" );
	}

	static boolean compareXOR( boolean[] xor1, boolean[] xor2, int len ){
		for( int x = 0; x < len; x++ ) if( xor1[x] != xor2[x] ) return false;
		return true;
	}

	// loads lines in a file into an array list of lines
	// content can include newlines if in quotation marks
	// End of Line:
	//   PC - carriage return plus line feed
	//   Macintosh - carriage return
	//   UNIX - line feed (usually called "new line" in UNIX parlance)
	// ASCII code in decimal: LF = 10; CR = 13
	public static ArrayList<String> zLoadLines( String sAbsolutePath, int iEstimatedSize, StringBuffer sbError){
		if( sAbsolutePath == null ){ sbError.append("path missing"); return null; }
		StringBuffer sbContent = new StringBuffer(iEstimatedSize);
		if( !fileLoadIntoBuffer( sAbsolutePath, sbContent, sbError ) ){
			sbError.insert(0, "error loading file (" + sAbsolutePath + "): ");
			return null;
		}
		return zLoadLines( sbContent, sbError );
	}
	
	public static ArrayList<String> zLoadLines( StringBuffer sbContent, StringBuffer sbError ){
		return zLoadLines( sbContent.toString(), sbError );
	}
		
	public static ArrayList<String> zLoadLines( String sContent, StringBuffer sbError ){ 
		int lenContent = sContent.length();
		ArrayList<String> listLines = new ArrayList<String>();
		StringBuffer sbLine = new StringBuffer(120);
		int pos = 0;
		int eState = 1;
		while( pos < lenContent ){
			char c = sContent.charAt(pos);
			switch( eState ){
				case( 1 ): // in line
					if( c == 13 ){
						eState = 2; // after CR
					} else if( c == 10 ){ // end of UNIX line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
					} else {
						sbLine.append(c);
					}
					pos++;
					break;
				case( 2 ): // after CR
					if( c == 10 ){ // reached end of PC line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						pos++;
						eState = 1;
					} else if( c == 13 ){ // two mac lines in a row (stay in CR state)
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						pos++;
					} else { // single mac line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						eState = 1;
					}
			}
		}
		if( sbLine.length() > 0 ) listLines.add(sbLine.toString()); // add any unterminated lines at end
		return listLines;
	}
	
	public static boolean fileLoadIntoBuffer( String sAbsolutePath, StringBuffer sbResource, StringBuffer sbError){
		File file = new File(sAbsolutePath);
		if( !file.exists() ){
			sbError.append("file not found");
			return false;
		}
		java.io.InputStream inputstreamResource = null;
		try {
			inputstreamResource = new FileInputStream(file);
		} catch(Exception ex) {
			sbError.append("unable to open file: " + ex);
			return false;
		}
		return zLoadString( inputstreamResource, sbResource, sbError );
	}
	
	public static boolean zLoadString( java.io.InputStream inputstreamResource, StringBuffer sbResource, StringBuffer sbError){
		if( inputstreamResource == null ){
			sbError.append("resource input stream does not exist");
			return false;
		}
		BufferedReader brFileToBeLoaded = null;
		try {
			int iFileCharacter;
			brFileToBeLoaded = new BufferedReader(new InputStreamReader(inputstreamResource));
			while(true) {
				iFileCharacter = brFileToBeLoaded.read();
				if(iFileCharacter==-1) break;
				sbResource.append((char)iFileCharacter);
			}
		} catch(Exception ex) {
			sbError.append("Failed to read resource: " + ex);
			return false;
		} finally {
			try {
				if(brFileToBeLoaded!=null) brFileToBeLoaded.close();
			} catch(Exception ex) {
				sbError.append("Failed to close resource: " + ex);
				return false;
			}
		}
		return true;
	}
		public static boolean fileSave( String sAbsolutePath, String sContent, StringBuffer sbError){
		File file = new File(sAbsolutePath);
		return fileSave( file, sContent, sbError );
	}

	public static boolean fileSave(  File file, String sContent, StringBuffer sbError ){

		// if file does not exist, create it
		try {
			if( ! file.exists() ){
				file.createNewFile();
			}
		} catch( Exception ex ) {
			sbError.append("failed to create file " + file + ": " + ex );
			return false;
		}


		// open file
		java.io.FileOutputStream fos = null;
		try {
		    fos = new java.io.FileOutputStream(file);
		} catch(Exception ex) {
			sbError.append("failed to open file for writing: " + ex);
			return false;
		}

		// save to file
		try {
			fos.write( sContent.getBytes() );
		} catch(Exception ex) {
			System.err.println("write failure (" + sContent.length() + " bytes): " + ex);
			return false;
		} finally {
			try {
				if( fos!=null ) fos.close();
			} catch(Exception ex) {}
		}
		return true;
	}

	public static String[] split( String s, char c ){
		if( s == null ) return null;
		int ctChar = getOccurrenceCount(s, c);
		int ctSegments = ctChar + 1;
		String[] asSegments = new String[ctSegments];
		if( ctChar == 0 ){ // minimal case
			asSegments[0] = s;
			return asSegments;
		}
		int len = s.length();
		int xSegment = 0;
		int posStartOfSegment = 0;
		for(int pos = 0; pos < len; pos++){
			if( s.charAt(pos) == c ){
				asSegments[xSegment] = s.substring(posStartOfSegment, pos);
				posStartOfSegment = pos + 1; // skip delimiter
				xSegment++;
			}
		}
		asSegments[xSegment] = s.substring(posStartOfSegment, len);
		return asSegments;
	}

	public static int getOccurrenceCount(String s, char c){
		if( s == null ) return 0;
		int len = s.length();
		if( len == 0 ) return 0;
		int iCount = 0;
		for(int pos = 0; pos < len; pos++){
			if( s.charAt(pos) == c ) iCount++;
		}
		return iCount;
	}
	
}