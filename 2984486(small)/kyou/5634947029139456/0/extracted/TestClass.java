package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.FilenameFilter;
import java.io.IOException;
import java.nio.file.Files;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Map.Entry;

public class TestClass {

	public static void main (String[] args) throws IOException {
		TestClass testClass = new TestClass();
		
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt"));
		
		/*
		int caseNum = 1;
		while(true) {
			String line = reader.readLine();
			if(line.equals("0 0")) {
				break;
			}
			String[] tokens = line.split(" ");
			int rowMax = Integer.parseInt(tokens[0]);
			int columnMax = Integer.parseInt(tokens[1]);
			int rockNum = Integer.parseInt(reader.readLine());
			Boolean[][] rockPositions = new Boolean[rowMax][columnMax];
			for(Boolean[] rockPosition : rockPositions) {
				Arrays.fill(rockPosition, false);
			}
			if(rockNum != 0) {
				tokens = reader.readLine().trim().replace("  ", " ").split(" ");
				for(int i=0; i<rockNum; i++) {
					rockPositions[Integer.parseInt(tokens[i*2])][Integer.parseInt(tokens[i*2+1])] = true;
				}
			}
			
			EarthPosition pos = testClass.new EarthPosition();
			int foodCount = testClass.getFoodCount(rowMax, columnMax, rockPositions, pos);
			writer.write("Case " + caseNum + ": " + foodCount + " " + pos.row + " " + pos.column + " " + pos.direction + "\n");
			writer.flush();
			caseNum++;
		}*/

		int caseNum = Integer.parseInt(reader.readLine());
		for(int i=0; i<caseNum; i++) {
			reader.readLine();
			String[] tokens = reader.readLine().split(" ");
			List<Integer> src = new ArrayList<Integer>();
			List<Integer> dst = new ArrayList<Integer>();
			for(String token : tokens) {
				src.add(Integer.parseInt(token, 2));
			}
			tokens = reader.readLine().split(" ");
			for(String token : tokens) {
				dst.add(Integer.parseInt(token, 2));
			}
			
			writer.write("Case #" + (i+1) + ":");
			int tmp = testClass.pa(src, dst);
			writer.write(" " + (tmp == -1 ? "NOT POSSIBLE" : tmp));
			writer.write("\n");

			writer.flush();
		}
		reader.close();
		writer.close();
	}
	
	private class Outlet implements Comparable<Outlet>{
		public int i;

		@Override
		public int compareTo(Outlet g) {
			return NumberOfSetBits(i) - NumberOfSetBits(g.i);
		}

		public Outlet(int i) {
			this.i = i;
		}
	}
	
	public int pa(List<Integer> src, List<Integer> dst) {
		Collections.sort(src);
		Collections.sort(dst);
		if(src.equals(dst)) {
			return 0;
		}
		
		List<Outlet> xor = new ArrayList<Outlet>();
		
		for(int s : src) {
			for(int d : dst) {
				xor.add(new Outlet(s ^ d));
			}
		}
		
		Collections.sort(xor);
		
		for(Outlet x : xor) {
			List<Integer> tmp = new ArrayList<Integer>();
			for(int s : src) {
				tmp.add(x.i ^ s);
			}
			Collections.sort(tmp);
			if(tmp.equals(dst)) {
				return NumberOfSetBits(x.i);
			}
		}
		
		return -1;
	}
	
	int NumberOfSetBits(int i)
	{
	     i = i - ((i >> 1) & 0x55555555);
	     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
	}
	
	private class EarthPosition {
		public int row;
		public int column;
		String direction;
		
		public EarthPosition(int row, int column, String direction) {
			this.row = row;
			this.column = column;
			this.direction = direction;
		}
		
		public EarthPosition() {}
	}
	
	public int getFoodCount(int rowMax, int columnMax, Boolean[][] rockPositions, EarthPosition retPos) {
		int ret = 0;
		String[] directions = {"E", "N", "S", "W"};
		
		for(int i=0; i<rowMax; i++) {
			for(int j=0; j<columnMax; j++) {
				if(rockPositions[i][j]) {
					continue;
				}
				
				for(int k=0; k<4; k++) {
					Boolean[][] usedPositions = new Boolean[rockPositions.length][rockPositions[0].length];
					copyTwoDimArray(rockPositions, usedPositions);
					
					int food = 1;
					EarthPosition position = new EarthPosition(i, j, directions[k]);
					usedPositions[i][j] = true;
					int dirIndex, rowIt, columnIt;
					boolean first = true;
					while(true) {
						if(position.direction.equals("E")) {
							dirIndex = 0;
							rowIt = 0;
							columnIt = 1;
						} else if(position.direction.equals("S")) {
							dirIndex = 1;
							rowIt = 1;
							columnIt = 0;
						} else if(position.direction.equals("W")) {
							dirIndex = 2;
							rowIt = 0;
							columnIt = -1;
						} else {
							dirIndex = 3;
							rowIt = -1;
							columnIt = 0;
						}
						
						if(first) {
							first = false;
							if(!isPosLegal(i + rowIt, j + columnIt, rowMax, columnMax, rockPositions)) {
								break;
							}
						}
						
						if(stepNext(position, dirIndex, rowIt, columnIt, rowMax, columnMax, usedPositions)) {
							food++;
						} else {
							if(food > ret) {
								ret = food;
								retPos.row = i;
								retPos.column = j;
								retPos.direction = directions[k];
							}
							break;
						}
					}
				}
			}
		}
		
		return ret;
	}
	
	public boolean stepNext(EarthPosition position, int dirIndex, int rowIt, int columnIt, int rowMax, int columnMax, Boolean[][] usedPositions) {
		String[] directions = {"E", "S", "W", "N"};
		if(!isPosLegal(position.row + rowIt, position.column + columnIt, rowMax, columnMax, usedPositions)) {
			if(isPosLegal(position.row - columnIt, position.column + rowIt, rowMax, columnMax, usedPositions)) {
				position.row -= columnIt;
				position.column += rowIt;
				position.direction = directions[(dirIndex - 1 + directions.length) % directions.length];
				usedPositions[position.row][position.column] = true;
			} else if(isPosLegal(position.row + columnIt, position.column - rowIt, rowMax, columnMax, usedPositions)){
				position.row += columnIt;
				position.column -= rowIt;
				position.direction = directions[(dirIndex + 1) % directions.length];
				usedPositions[position.row][position.column] = true;
			} else {
				return false;
			}
		} else {
			position.row += rowIt;
			position.column += columnIt;
			usedPositions[position.row][position.column] = true;
		}
		return true;
	}
	
	public boolean isPosLegal(int row, int column, int rowMax, int columnMax, Boolean[][] rockPositions) {
		return row < rowMax && row >= 0 && column < columnMax && column >= 0 && (!rockPositions[row][column]);
	}
	
	
	private class GasStation implements Comparable<GasStation>{
		public int position;
		public int gas;
		public boolean cw;
		public boolean ccw;

		@Override
		public int compareTo(GasStation g) {
			return position - g.position;
		}

		public GasStation(int position, int gas) {
			this.position = position;
			this.gas = gas;
			cw = true;
			ccw = true;
		}
	}
	
	public String tankALot(GasStation[] stations, int totalGas) {
		String ret = "";
		boolean[] cw = new boolean[stations.length];
		boolean[] ccw = new boolean[stations.length];
		Arrays.fill(cw, true);
		Arrays.fill(ccw, true);
		
		int lastGas = totalGas - stations[stations.length - 1].position + stations[0].position;

		for(int i=0; i<stations.length; i++) {
			int currentPos = i;
			int gasInTank = 0;
			for(int j=0; j<stations.length; j++) {
				int gasNeeded = 0;
				if(currentPos + 1 == stations.length) {
					gasNeeded = lastGas;
				} else {
					gasNeeded = stations[currentPos + 1].position - stations[currentPos].position;
				}
				gasInTank += stations[currentPos].gas;
				if(gasInTank < gasNeeded) {
					cw[i] = false;
					break;
				}
				gasInTank -= gasNeeded;
				currentPos++;
				currentPos %= stations.length;
			}
		}
		
		for(int i=0; i<stations.length; i++) {
			int currentPos = i;
			int gasInTank = 0;
			for(int j=0; j<stations.length; j++) {
				int gasNeeded = 0;
				if(currentPos - 1 == -1) {
					gasNeeded = lastGas;
				} else {
					gasNeeded = stations[currentPos].position - stations[currentPos - 1].position;
				}
				gasInTank += stations[currentPos].gas;
				if(gasInTank < gasNeeded) {
					ccw[i] = false;
					break;
				}
				gasInTank -= gasNeeded;
				currentPos--;
				currentPos = (currentPos + stations.length) % stations.length;
			}
		}
		
		for(int i=0; i<stations.length; i++) {
			if(cw[i] && ccw[i]) {
				ret += stations[i].position + " CCC ";
			} else if(cw[i]) {
				ret += stations[i].position + " C ";
			} else if(ccw[i]) {
				ret += stations[i].position + " CC ";
			}
		}
		
		return ret.trim();
	}
	
	
	public String[] lcr(int playerNo, String diceRoll) {
		String[] ret = new String[playerNo + 1];
		int[] chips = new int[playerNo + 1];
		Arrays.fill(chips, 3);
		chips[playerNo] = 0;
		int currentPlayer = 0;
		int winner = -1;
		
		for(int i=0; i<playerNo; i++) {
			ret[i] = "Player " + (i + 1) + ":";
		}
		ret[playerNo] = "Center:";
		
		for(int i=0; i<diceRoll.length();) {
			int tmp = i + (chips[currentPlayer] > 3 ? 3 : chips[currentPlayer]);
			if(tmp > diceRoll.length()) {
				break;
			}
			
			for(; i<tmp; i++) {
				if(diceRoll.charAt(i) == 'L') {
					chips[currentPlayer]--;
					chips[(currentPlayer + 1) % playerNo]++;
				} else if(diceRoll.charAt(i) == 'R') {
					chips[currentPlayer]--;
					chips[(currentPlayer - 1 + playerNo) % playerNo]++;
				} else if(diceRoll.charAt(i) == 'C') {
					chips[currentPlayer]--;
					chips[playerNo]++;
				}
			}
			
			boolean gotWinner = true;
			boolean firstNotZero = false;
			int tmpWinner = -1;
			for(int j=0; j<playerNo; j++) {
				if(chips[j] != 0 && !firstNotZero) {
					firstNotZero = true;
					tmpWinner = j;
				} else if(chips[j] != 0) {
					gotWinner = false;
					break;
				}
			}
			if(gotWinner) {
				winner = tmpWinner;
				currentPlayer = -1;
				break;
			}
			
			currentPlayer++;
			currentPlayer %= playerNo;
		}
		
		int nextPlayer = currentPlayer;
		if(winner == -1) {
			for(int i=0; i<playerNo; i++) {
				if(chips[nextPlayer] != 0) {
					break;
				}
				nextPlayer++;
				nextPlayer %= playerNo;
			}
		}
		
		for(int i=0; i<playerNo; i++) {
			ret[i] += chips[i];
			if(winner == i) {
				ret[i] += "(W)";
			} else if(nextPlayer == i) {
				ret[i] += "(*)";
			}
		}
		ret[playerNo] += chips[playerNo];
		
		return ret;
	}
	
	public boolean guessSudoku(Integer[][] input) {
		boolean zeroFound = false;
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				if(input[i][j] == 0) {
					zeroFound = true;
					for(int k=1; k<=9; k++) {
						Integer[][] copy = new Integer[9][9];
						copyTwoDimArray(input, copy);
						copy[i][j] = k;
						if(guessSudoku(copy)) {
							copyTwoDimArray(copy, input);
							return true;
						}
					}
				}
			}
		}
		
		if(!zeroFound) {
			return testSudoku(input);
		}
		
		return false;
	}
	
	public <T> void copyTwoDimArray(T[][] input, T[][] output) {
		for(int i=0; i<input.length; i++) {
			output[i] = Arrays.copyOf(input[i], input[i].length);
		}
	}
	
	public boolean testSudoku(Integer[][] input) {
		for(int i=0; i<9; i++) {
			Set<Integer> nums1 = new HashSet<Integer>();
			Set<Integer> nums2 = new HashSet<Integer>();
			for(int j=0; j<9; j++) {
				nums1.add(input[i][j]);
				nums2.add(input[j][i]);
			}
			if(nums1.size() < 9 || nums2.size() < 9) {
				return false;
			}
		}
		
		for(int i=0; i<3; i+=3) {
			for(int j=0; j<3; j+=3) {
				Set<Integer> nums = new HashSet<Integer>();
				for(int k=i; k<i+3; k++) {
					for(int l=j; l<j+3; l++) {
						nums.add(input[k][l]);
					}
				}
				if(nums.size() < 9) {
					return false;
				}
			}
		}
		
		return true;
	}
	
	public int deceifulWar(List<Double> naomi, List<Double> ken) {
		int ret = 0;
		List<Double> naomiCopy = new ArrayList<Double>(naomi);
		List<Double> kenCopy = new ArrayList<Double>(ken);
		Collections.sort(naomiCopy);
		Collections.sort(kenCopy);
		for(Double k : kenCopy) {
			for(Double n : naomiCopy) {
				if(n > k) {
					naomiCopy.remove(n);
					ret++;
					break;
				}
			}
		}
		return ret;
	}
	
	public int war(List<Double> naomi, List<Double> ken) {
		int ret = 0;
		Collections.sort(naomi);
		Collections.sort(ken);
		for(Double n : naomi) {
			for(Double k : ken) {
				if(k > n) {
					ken.remove(k);
					ret++;
					break;
				}
			}
		}
		return naomi.size() - ret;
	}
	
	public double cookieFarm(double farmValue, double farmYield, double goal, double cookieSpeed) {
		double time = 0;
		while(goal/cookieSpeed > farmValue / cookieSpeed + goal / (cookieSpeed + farmYield)) {
			time += farmValue /cookieSpeed;
			cookieSpeed += farmYield;
			//cookieFarm(farmValue, farmYield, goal, cookieSpeed + farmYield, time + farmValue/cookieSpeed);
		}
		
		return time + goal/cookieSpeed;
	}
	
	public String magician(int[][] first, int firstRow, int[][] second, int secondRow) {
		int selected = -1;
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				if(first[firstRow][i] == second[secondRow][j]) {
					if(selected != -1) {
						return "Bad magician!";
					} else {
						selected = first[firstRow][i];
					}
				}
			}
		}
		if(selected == -1) {
			return "Volunteer cheated!";
		} else {
			return Integer.toString(selected);
		}
	}
	
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
    	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    	if(num.length == 2) {
    		ArrayList<Integer> tmp = new ArrayList<Integer>();
    		tmp.add(num[0]);
    		tmp.add(num[1]);
    		ArrayList<Integer> tmp1 = new ArrayList<Integer>();
    		tmp1.add(num[1]);
    		tmp1.add(num[0]);
    		ret.add(tmp);
    		ret.add(tmp1);
    	} else {
    		ArrayList<ArrayList<Integer>> tmp = permute(Arrays.copyOf(num, num.length-1));
    		for(ArrayList<Integer> list : tmp) {
    			for(int i=0; i<num.length; i++) {
    				ret.add(new ArrayList<Integer>(list));
    			}
    		}

    		for(int i=0; i<tmp.size(); i++) {
    			for(int j=0; j<num.length; j++) {
    				ret.get(j + i*num.length).add(j, num[num.length-1]);
    			}
    		}
    	}
    	return ret;
    }
	
	public class TreeLinkNode {
		int val;
		TreeLinkNode left, right, next;
		TreeLinkNode(int x) { val = x; }
	}
	
    public void populatingNextRightPointersInEachNode(TreeLinkNode root) {
        root.next = null;
        populatingNextRightPointers(root.left);
        populatingNextRightPointers(root.right);
    }
    
    public void populatingNextRightPointers(TreeLinkNode node) {
    	if(node.left == null) {
    		return;
    	}
        node.left.next = node.right;
        if(node.next != null) {
        	node.right.next = node.next.left;
        } else {
        	node.right.next = null;
        }
        populatingNextRightPointers(node.left);
        populatingNextRightPointers(node.right);
    }
	
	private class RobotPos {
		public int x;
		public int y;
		public RobotDir dir;
		
		public RobotPos(int x, int y, RobotDir dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	};
	
	enum RobotDir {
		North,
		South,
		East,
		West
	};
	
	private void robotMaze(String[][] maze, RobotPos last) {
		RobotPos next = new RobotPos(last.x, last.y, last.dir);
		switch(last.dir) {
		case North:
			next.y--;
			break;
		case South:
			next.y++;
			break;
		case East:
			next.x++;
			break;
		case West:
			next.x--;
			break;
		}
	}
	
	private RobotPos nextStep(RobotPos last) {
		RobotPos ret = new RobotPos(last.x, last.y, last.dir);
		switch(last.dir) {
		case North:
			ret.y--;
			break;
		case South:
			ret.y++;
			break;
		case East:
			ret.x++;
			break;
		case West:
			ret.x--;
			break;
		}
		
		return ret;
	}
	
	private void sortBooks(int[] dadOrder) {
		List<Integer> oddBooks = new ArrayList<Integer>();
		List<Integer> evenBooks = new ArrayList<Integer>();
		for(int value : dadOrder) {
			if(value % 2 != 0) {
				oddBooks.add(value);
			} else {
				evenBooks.add(value);
			}
		}
		
		Collections.sort(oddBooks);
		Collections.sort(evenBooks);
		Collections.reverse(evenBooks);
		Iterator<Integer> oddIt = oddBooks.iterator();
		Iterator<Integer> evenIt = evenBooks.iterator();
		
		for(int i=0; i<dadOrder.length; i++) {
			if(dadOrder[i] % 2 != 0) {
				dadOrder[i] = oddIt.next();
			} else {
				dadOrder[i] = evenIt.next();
			}
		}
	}
	
	private void parseLinuxWarningFile() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\warnings\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\warnings\\out.txt"));
		BufferedWriter statisticWriter = new BufferedWriter(new FileWriter("C:\\warnings\\statistic.csv"));
		BufferedReader fileFilter = new BufferedReader(new FileReader("C:\\warnings\\fileFilter.txt"));
		BufferedReader typeFilter = new BufferedReader(new FileReader("C:\\warnings\\typeFilter.txt"));
		
		final String vsMarker = "): warning C";
		final String gccMarker = " [-Werror=";
		
		Set<String> cppFiles = new HashSet<String>();	
		while(true) {
			String line = fileFilter.readLine();
			if(line == null) {
				break;
			}
			if(!line.trim().isEmpty()) {
				cppFiles.add(line.trim().toLowerCase());
			}
		}
		
		Map<String, Integer> warningTypes = new TreeMap<String, Integer>();	
		while(true) {
			String line = typeFilter.readLine();
			if(line == null) {
				break;
			}
			if(!line.trim().isEmpty()) {
				warningTypes.put(line.trim().toLowerCase(), 0);
			}
		}
		
		Set<String> outputLines = new LinkedHashSet<String>();
		while(true) {
			String line = reader.readLine();
			if(line == null) {
				break;
			}

			if(line.indexOf('>') != -1 && line.indexOf('>') < 5) {
				line = line.substring(line.indexOf('>') + 1);
			}
			
			if(!line.startsWith(" ") && (line.contains(vsMarker) || line.contains(gccMarker))) {
				if(doesStringIncluded(cppFiles, line) && doesStringIncluded(warningTypes.keySet(), line)) {
					outputLines.add(line);
				}
			}
		}
		
		Map<String, String> examples = new HashMap<String, String>();	
		for(String line : outputLines) {
			String warningType = "";
			if(line.contains(vsMarker)) {
				int begin = line.indexOf(vsMarker) + 11;
				int end = line.indexOf(':', begin);
				warningType = line.substring(begin, end).toLowerCase();
			} else if(line.contains(gccMarker)) {
				int begin = line.indexOf(gccMarker) + 10;
				int end = line.indexOf(']', begin);
				warningType = line.substring(begin, end).toLowerCase();
			} else {
				continue;
			}
			
			if(warningTypes.containsKey(warningType)) {
				warningTypes.put(warningType, warningTypes.get(warningType) + 1);
			} else {
				warningTypes.put(warningType, 1);
			}
			
			if(!examples.containsKey(warningType)) {
				examples.put(warningType, line);
			}
			
			writer.write(line + "\n");
		}
		
		statisticWriter.write("WarningType,Number,Example\n");
		for(Entry<String, Integer> pair : warningTypes.entrySet()) {
			statisticWriter.write(pair.getKey() + "," + pair.getValue() + ",\"" + examples.get(pair.getKey()) + "\"\n");
		}
		statisticWriter.write("Total," + outputLines.size() + "\n");
		
		reader.close();
		writer.close();
		fileFilter.close();
		typeFilter.close();
		statisticWriter.close();
	}
	
	private boolean doesStringIncluded(Set<String> cppFiles, String line) {
		if(cppFiles.size() != 0) {
			for(String cppFile : cppFiles) {
				if(line.toLowerCase().contains(cppFile)) {
					return true;
				}
			}
		} else {
			return true;
		}
		return false;
	}
	
	private void parseWarningFile2() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt"));
		BufferedReader ref = new BufferedReader(new FileReader("C:\\share\\warnings\\ref2.txt"));
		
		List<String> warnings = new ArrayList<String>();
		
		while(true) {
			String line = ref.readLine();
			if(line == null) {
				break;
			}
			warnings.add(line);
		}
		
		while(true) {
			String line = reader.readLine();
			if(line == null) {
				break;
			}
			
			boolean breakout = false;
			for(String warning : warnings) {
				if(line.contains(warning)) {
					breakout = true;
					break;
				}
			}
			
			if(!breakout) {
				writer.write(line + "\n");
			}
		}
		
		ref.close();
		reader.close();
		writer.close();
	}
	
	private void parseWarningFile() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt"));
		
//		BufferedReader ref = new BufferedReader(new FileReader("C:\\share\\ref.txt"));	
//		List<String> warnings = new ArrayList<String>();	
//		while(true) {
//			String line = ref.readLine();
//			if(line == null) {
//				break;
//			}
//			warnings.add(line.trim());
//		}
//		String[] checkFiles = new String[warnings.size()];
//		warnings.toArray(checkFiles);
		
		String[] checkFiles = {"EuExecUnit", "EuExtMath", "EuFpu", "EuFpuEmBase", "EuGa", "EuJEu", "EuKernelPerf", "EuManager", "EuMessageSend", "EuTc", "EuUtility", "DecodeInst"};

		for(int i=0; i<checkFiles.length; i++) {
			checkFiles[i] = checkFiles[i].toLowerCase();
		}
		
//		boolean doesWrite = false;
		
		while(true) {
			String line = reader.readLine();
			if(line == null) {
				break;
			}
			
//			if(line.contains("error")) {
//				for(String checkFile : checkFiles) {
//					if(line.toLowerCase().contains(checkFile)) {
//						writer.write(line + "\n");
//						break;
//					}
//				}
//			}
		

			if(line.indexOf('>') != -1 && line.indexOf('>') < 5) {
				line = line.substring(line.indexOf('>') + 1);
			}
			
			if(!line.startsWith(" ") && line.contains("warning")) {
				for(String checkFile : checkFiles) {
					if(line.toLowerCase().contains(checkFile)) {
						writer.write(line + "\n");
						break;
					}
				}
			}
			
//			if(!line.startsWith(" ")) {
//				for(String checkFile : checkFiles) {
//					if(line.toLowerCase().contains(checkFile)) {
//						if(!line.contains("in switch of enum") && !line.contains("conversion from") && !line.contains("is not defined as a preprocessor macro")
//								&& !line.contains("unreferenced inline function has been removed") && !line.contains("bytes padding added after data member")
//								&& !line.contains("conditional expression is constant") && !line.contains("signed/unsigned mismatch")) {
//							writer.write(line + "\n");
//							break;
//						}
//					}
//				}
//			}
			
//			if(!line.matches(".*(\\d.).*") && doesWrite) {
//				writer.write(line);
//			} else if(line.matches(".*(\\d.).*")) {
//				doesWrite = false;
//				for(String checkFile : checkFiles) {
//					if(line.toLowerCase().contains(checkFile)) {
//						doesWrite = true;
//						writer.write("\n" + line);
//						break;
//					}
//				}
//			}
		}
		
		reader.close();
		writer.close();
	}
	
	private void recursiveCopyDir(File src, File dst) throws IOException {
		Files.copy(src.toPath(), dst.toPath());
		if(src.isDirectory()) {
			for(String fileName : src.list()) {
				recursiveCopyDir(new File(src, fileName), new File(dst, fileName));
			}
		}
	}
	
	private BufferedWriter getFpuDumpWritter(int subfix, String exampleTcPath) throws IOException {
		String tmp = exampleTcPath;
		if(subfix >= 10) {
			tmp = exampleTcPath.substring(0, exampleTcPath.length() - 1);
		}
		recursiveCopyDir(new File(exampleTcPath), new File(tmp + subfix));
		return new BufferedWriter(new FileWriter(tmp + subfix + "/fd3d/EuGaEmFpu.txt"));
	}
	
	private void valgrindParse() throws IOException {
		final int max = 100000;
		int subfix = 1;
		String exampleTcPath = "C:/share/eu_op_pln_coverage_00";
		BufferedReader reader = new BufferedReader(new FileReader("C:/share/pln.txt"));
		List<String> paders = new ArrayList<String>();
		List<List<String>> testNums = new ArrayList<List<String>>();
		for(int i=0; i<5; i++) {
			testNums.add(new ArrayList<String>());
		}
		
		boolean notFinish = true;
		while(notFinish) {
			int lineCount = 0;
			while(lineCount != max) {
				String line = reader.readLine();
				if(line == null) {
					notFinish = false;
					break;
				}

				if(line.charAt(0) == '#') {
					continue;
				}
				lineCount++;
				String[] tokens = line.split(" ");
				for(int i=0; i<5; i++) {
					testNums.get(i).add(tokens[i+2]);
				}
			}
			
			if(lineCount == 0) {
				break;
			}
			
			BufferedWriter writer = getFpuDumpWritter(subfix++, exampleTcPath);
			writeFpuDumpComment(writer, paders);
			for(int i=0; i<testNums.get(0).size()/4; i++) {
				for(int j=0; j<5; j++) {
					writer.write(paders.get(j));
					writer.write("00000000000000000000000000000000");
					for(int k=0; k<4; k++) {
						if(j == 0) {
							writer.write(testNums.get(4).get(i*4+k));
						} else {
							writer.write(testNums.get(j-1).get(i*4+k));	
						}
					}
					writer.write(" ");
				}
				writer.write(paders.get(5) + "\n");
			}
			writer.write("END");
			writer.close();

			for(int k=0; k<5; k++) {
				testNums.get(k).clear();
			}
		}
		
		reader.close();
	}

	private void writeFpuDumpComment(BufferedWriter writer, List<String> paders) throws FileNotFoundException, IOException {
		boolean doesWritePad = paders.size() == 0;
		BufferedReader commentReader = new BufferedReader(new FileReader("C:/share/EuGaEmFpu10.txt"));
		while(true) {
			String line = commentReader.readLine();
			if(!line.startsWith("--")) {
				String[] tokens = line.split(" ");
				String acc = "";
				for(String token : tokens) {
					if(token.length() < 60) {
						acc += token + " ";
					}
					else if(doesWritePad) {
						paders.add(acc);
						acc = "";
					}
				}
				if(doesWritePad) {
					paders.add(acc);
				}
				break;
			}
			writer.write(line + "\n");
		}
		commentReader.close();
	}
	
	private void giantCount(String res) {
		int w = 0;
		for(int i=0; i<res.length(); i++) {
			char c = res.charAt(i);
			if(c == 'W') {
				w++;
			}
		}
		System.out.print("Win %:");
		System.out.println((double)w/res.length());
	}
	
	private void giantParsing(String res, int play) {
		Queue<Character> games = new LinkedList<Character>();
		int lose = 0;
		int maxLose = 0;
		String ls = "";
		for(int i=0; i<res.length(); i++) {
			char c = res.charAt(i);
			games.add(c);
			if(c == 'L') {
				lose++;
			}
			
			if(i + 1 > play) {
				if(games.remove() == 'L') {
					lose--;
				}
				if(lose > maxLose) {
					maxLose = lose;
					Iterator<Character> it = games.iterator();
					ls = "";
					while(it.hasNext()) {
						ls += it.next();
					}
				}
			} else if(i + 1 == play) {
				maxLose = lose;
			}
		}
		
		System.out.print("Min Win %: ");
		System.out.println(((double)play - maxLose) / play);
		System.out.println(ls);
		
		/*List<Integer> resList = new ArrayList<Integer>();
		int i=0, sum=0;
		while(true) {
			while(i < res.length() && res.charAt(i) == 'W') {
				i++;
				sum++;
			}
			if(i != 0) {
				resList.add(sum);
				sum = 0;
			}
			if(i == res.length()) {
				break;
			}
			while(i < res.length() && res.charAt(i) == 'L') {
				i++;
				sum--;
			}
			if(i != 0) {
				resList.add(sum);
				sum = 0;
			}
			if(i == res.length()) {
				break;
			}
		}*/
	}

	
	private void parseRegression() throws IOException {
//		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\test.csv"));
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\CHV_regression_stat ww12_2.csv"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.csv"));
		
		String title[] = {"MovInst","Flt2Int", "Int2Flt", "MixFloat", "MixInt", "Compacted","Compressed", "AlignMode", "RndMode", "DenormModeHp", "DenormModeSp",
				"DenormModeDp", "Saturate", "Simd8ShootDown","AccuSrc", "AccuDstImp", "AccuDstExp", "Src0Denorm", "Src1Denorm", "DstDenorm", "SrcModUsed", "CondModUsed",
				"PredicateUsed", "PredCtrl","NumberSources","ImmediateSrc","SrcRepCtrl","DstType", "Src0Type", "Src1Type", "Src2Type", "DstIndexed", "Src0Indexed",
				"Src1Indexed", "DstRegFile", "Src0RegFile", "Src1RegFile", "DstGrfAligned", "Src0GrfAligned", "Src1GrfAligned","Src0Grfs", "Src1Grfs", "Underflow",
				"Overflow", "Inexact", "InvalidOp", "DivByZero","ExecutionSize","FromPrevIpCount","ToNextIpCount","ExecutionCount"};
		
		List<String> outputTitles = new ArrayList<String>(Arrays.asList(title));
		Set<String> additionalTitles = new TreeSet<String>();

		reader.readLine();
		String cline = "";
		while((cline = reader.readLine()) != null) {
			String[] tokens = cline.split(",");
			if(tokens.length < 3) {
				continue;
			}
			for(int i=0; i<title.length; i++) {
				if(tokens.length <= i+3) {
					break;
				}
				try {
					Integer.parseInt(tokens[i+3]);
				} catch(NumberFormatException e) {
					additionalTitles.add(title[i] + "_" + tokens[i+3]);
				}
			}
		}
		reader.close();
		
		for(Iterator<String> it = additionalTitles.iterator(); it.hasNext(); ) {
			outputTitles.add(it.next());
		}
		
//		writer.write("Op,");
//		for(Iterator<String> it = outputTitles.iterator(); it.hasNext(); ) {
//			writer.write(it.next() + ",");
//		}

//		reader = new BufferedReader(new FileReader("C:\\share\\test.csv"));
		reader = new BufferedReader(new FileReader("C:\\share\\CHV_regression_stat ww12_2.csv"));
		Map<String, int[]> opMaps = new HashMap<String, int[]>();
		
		reader.readLine();
		while((cline = reader.readLine()) != null) {
			String[] tokens = cline.split(",");
			if(tokens.length < 3) {
				continue;
			}
			
			if(!opMaps.containsKey(tokens[2])) {
				opMaps.put(tokens[2], new int[outputTitles.size()]);
			}
			
			for(int i=0; i<title.length; i++) {
				if(tokens.length <= i+3) {
					break;
				}
				try {
					opMaps.get(tokens[2])[i] += Integer.parseInt(tokens[i+3]);
				} catch(NumberFormatException e) {
					try {
						String tmp = title[i] + "_" + tokens[i+3];
						for(int j=0; j<outputTitles.size(); j++) {
							if(outputTitles.get(j).equals(tmp)) {
								opMaps.get(tokens[2])[j]++;
								break;
							}
						}
					} catch(NullPointerException e1) {
						e1.printStackTrace();
					}
				}
			}
		}
		
		writer.write("Op,");
		for(String t : outputTitles) {
			writer.write(t + ",");
		}
		writer.write("\n");
		
		for (Iterator<String> iterator = opMaps.keySet().iterator(); iterator.hasNext();) {
		    String key = (String) iterator.next();
		    int[] properties = opMaps.get(key);
		    writer.write(key + ",");
		    for(int property : properties) {
		    	writer.write(property + ",");
		    }
		    writer.write("\n");
		}
		writer.close();
		reader.close();
	}
	
	private void addTwoNewFieldsToDump() throws IOException {
		File example = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\EU_Weekly\\basic\\eu_pln_f_mp_mp_f_p\\fd3d\\EuGaEmFpu.txt");
		BufferedReader exampleReader = new BufferedReader(new FileReader(example));
		List<String> exampleLines = new ArrayList<String>();
		String cline = "";
		while((cline = exampleReader.readLine()) != null) {
			if(cline.startsWith("--")) {
				exampleLines.add(cline);
			}
		}
		exampleReader.close();
		
		File topDir = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\EU_Weekly\\basic");
		File[] secondDirs = topDir.listFiles();
		for(File secondDir : secondDirs) {
			File inputFile = new File(secondDir.getPath() + "\\fd3d\\EuGaEmFpu.txt");
			BufferedReader reader = new BufferedReader(new FileReader(inputFile));
			List<String> inputLines = new ArrayList<String>();
			while((cline = reader.readLine()) != null) {
				if(!cline.startsWith("--") && !cline.contains("END")) {
					inputLines.add(cline.trim());
				}
			}
			reader.close();
			
			BufferedWriter writer = new BufferedWriter(new FileWriter(inputFile));
			for(String exampleLine : exampleLines) {
				writer.write(exampleLine + "\n");
			}
			for(String inputLine :inputLines) {
				writer.write("  " + inputLine.substring(0, 78) + "0 0 " + inputLine.substring(78) + " 00 0 1\n");
			}
			writer.write("END");
			writer.close();
		}
	}
	
	private void refactorEM() throws IOException {
		File topDir = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\em_basic_10");
		//File topDir = new File("C:\\basic");
		File[] secondDirs = topDir.listFiles();
		for(File secondDir : secondDirs) {
			if(!secondDir.getName().endsWith("hf") && !secondDir.getName().endsWith("hf_f")) {
				continue;
			}
			
			
			FilenameFilter nameFilter = new FilenameFilter() {
				public boolean accept(File dir, String fileName) {
					return fileName.endsWith(".asm") && (!fileName.endsWith("su.asm")) && (!fileName.endsWith("vs.asm"));
				}
			};
			File[] inputs = secondDir.listFiles(nameFilter);
			if(inputs.length == 0) {
				continue;
			}
			File input = secondDir.listFiles(nameFilter)[0];
//			boolean isChanen = secondDir.getName().contains("chanen");
			
			BufferedReader reader = new BufferedReader(new FileReader(input));
			List<String> lines = new ArrayList<String>();
			String cline = "";
			while((cline = reader.readLine()) != null) {
				lines.add(cline);
			}
			reader.close();
			
			BufferedWriter writer = new BufferedWriter(new FileWriter(input));			
//			boolean skip = false;
//			boolean skipDone = false;
			for(int i=0; i<lines.size(); i++) {
				String line = lines.get(i);
//				if(line.equals("//############################################################")) {
//					if(!skip && !skipDone) {
//						i += 2;
//						skip = true;
//						continue;
//					} else {
//						skip = false;
//						skipDone = true;
//					}
//				} else if(skip) {
//					continue;
//				}
				
				if(line.matches(".*// *send.*r\\d.*r\\d.*")) {
					line = line.replaceFirst("//.*", "");
				} else if(line.matches(".*// *Gen6.*")) {
					line = line.replaceFirst("//.*", "");
				}
				
				if(line.matches(".*\\.\\d:hf.*")) {
					line = line.replaceFirst(":hf", "<1>:hf");
				} else if(line.matches(".*-.*any\\dh.*")) {
					line = line.replaceFirst("any", "all");
				}
				
//				if(!isChanen) {
//					if(line.matches(".*\\(\\d\\).*")) {
//						line = line.replaceFirst("\\(\\d\\)", "(8)");
//					} else if(line.matches(".*any\\dh.*")) {
//						line = line.replaceFirst("any\\dh", "all8h");
//					}
//				}	
				writer.write(line + "\n");
			}
			writer.close();
		}
	}
	
	private class pogoPath {
		public int x;
		public int y;
		public int pow;
		public String path;
		
		public pogoPath(int x, int y, int pow, String path) {
			this.x = x;
			this.y = y;
			this.pow = pow;
			this.path = path;
		}
	}

	private String pogo(int dstX, int dstY) {
		Queue<pogoPath> queue = new LinkedList<pogoPath>();
		queue.add(new pogoPath(0, 0, 0, ""));
		char[] fourDir = {'N', 'S', 'E', 'W'}; 
		while(true) {
			pogoPath node = queue.remove();
			if(pogoCheck(dstX, dstY, node)) {
				return node.path;
			}
			for(int i=0; i<4; i++) {
				queue.add(new pogoPath(node.x, node.y, node.pow + 1, node.path + fourDir[i]));
			}
		}
	}

	private boolean pogoCheck(int dstX, int dstY, pogoPath node) {
		if(node.path.length() != 0) {
			char dir = node.path.charAt(node.path.length()-1);
			int pow = node.pow;
	
			switch(dir) {
			case 'E':
				node.x += pow;
				break;
			case 'W':
				node.x -= pow;
				break;
			case 'N':
				node.y += pow;
				break;
			case 'S':
				node.y -= pow;
				break;
			}
		}
		if(node.x == dstX && node.y == dstY) {
			return true;
		}
		return false;
	}
	
	private boolean pogoCheck(int dstX, int dstY, String path) {
		int x=0, y=0, pow=1;
		for(int i=0; i<path.length(); i++) {
			switch(path.charAt(i)) {
			case 'E':
				x += pow;
				break;
			case 'W':
				x -= pow;
				break;
			case 'N':
				y += pow;
				break;
			case 'S':
				y -= pow;
				break;
			}
			pow++;
		}
		if(x == dstX && y == dstY) {
			return true;
		}
		return false;
	}

	private int energyUse(int in, int out, int left, int right, int[] values, int e, int r) {
		int maxE = in - out;
		if(left != values.length-1) {
			maxE += r;
		}

		if(left == right) {
			if(maxE > in) {
				maxE = in;
			}
			int v = maxE * values[left];
			return v < 0 ? 0 : v;
		} else if(right < left) {
			return 0;
		}

		int max = 0;
		int maxIndex = 0;
		for(int i=left; i<=right; i++) {
			if(values[i] > max) {
				max = values[i];
				maxIndex = i;
			}
		}

		if((maxIndex-left) * r + in > e) {
			maxE = e;
		} else if(maxE > e) {
			maxE = e;
		}

		return energyUse(in, maxE, left, maxIndex-1, values, e, r) + max * maxE + energyUse(r, out, maxIndex+1, right, values, e, r);
	}

	private boolean is_palindrome(Long orig) {
		long reversed = 0, n = orig;

		while (n > 0)
		{
			reversed = reversed * 10 + n % 10;
			n /= 10;
		}

		return orig == reversed;
	}

	private boolean lawnmover(int position[][], Integer nums[], int N, int M) {
		for(int num : nums) {
			for(int j=0; j<N; j++) {
				for(int k=0; k<M; k++) {
					if(position[j][k] == num) {
						boolean breakout = false;
						for(int i=0; i<N; i++) {
							if(position[i][k] > num) {
								breakout = true;
								break;
							}
						}
						if(!breakout) {
							continue;
						}

						breakout = false;
						for(int i=0; i<M; i++) {
							if(position[j][i] > num) {
								breakout = true;
								break;
							}
						}

						if(breakout) {
							return false;
						}
					}
				}
			}
		}
		return true;
	}

	private boolean checkPosition(char checkChar, char position[][]) {
		for(int i=0; i<4; i++) {
			boolean breakout = false;
			for(int j=0; j<4; j++) {
				if(position[i][j] != checkChar && position[i][j] != 'T') {
					breakout = true;
					break;
				}
			}
			if(!breakout) {
				return true;
			}

			breakout = false;
			for(int j=0; j<4; j++) {
				if(position[j][i] != checkChar && position[j][i] != 'T') {
					breakout = true;
					break;
				}
			}
			if(!breakout) {
				return true;
			}
		}

		boolean breakout = false;
		for(int i=0; i<4; i++) {
			if(position[i][i] != checkChar && position[i][i] != 'T') {
				breakout = true;
				break;
			}
		}
		if(!breakout) {
			return true;
		}

		breakout = false;
		for(int i=0; i<4; i++) {
			if(position[i][3-i] != checkChar && position[i][3-i] != 'T') {
				breakout = true;
				break;
			}
		}
		if(!breakout) {
			return true;
		}

		return false;
	}



	private class CarPos {
		public double pos;
		public double time;

		public CarPos(double pos, double time) {
			this.pos = pos;
			this.time = time;
		}
	}

	private class Interval {
		public double start;
		public double end;
		public double startTime;
		public double endTime;
		public double speed;
		public double length;
		public double time;

		public Interval(double start, double end, double startTime, double endTime) {
			this.start = start;
			this.end = end;
			this.startTime = startTime;
			this.endTime = endTime;
			speed = (end - start) / (endTime - startTime);
			length = this.end - this.start;
			time = this.endTime - this.startTime;
		}
	}

	private double getB(List<CarPos> positions, double acc, double D) {
		List<Interval> intervals = new ArrayList<Interval>();

		Interval in = new Interval(0.0, positions.get(0).pos, 0.0, positions.get(0).time);
		intervals.add(in);

		for(int i=0; i<positions.size()-1; i++) {
			intervals.add(new Interval(positions.get(i).pos, positions.get(i+1).pos, positions.get(i).time, positions.get(i+1).time));
		}

		double speed = 0;
		double pos = 0;
		double t = 0;
		for(Interval interval : intervals) {
			double maxSpeed = speed + acc * interval.time;
			if(maxSpeed <= interval.speed) {
				double down = speed * interval.time + 0.5 * acc * interval.time * interval.time;
				if(down > (D - pos)) {
					double tmp = ((-2) * speed + Math.sqrt( 4 * speed * speed + 8 * acc * (D - pos))) / 2 * acc;
					return t + tmp;
				} else {
					t += interval.time;
					pos = interval.end;
					speed = maxSpeed;
				}
			} else {
				double t1 = (interval.speed - speed) / acc;
				double t1Down = speed * t1 + 0.5 * acc * t1 * t1;
				double t2Down = interval.speed * (interval.time - t1);
				double dPos = D- pos;
				if(dPos < t1Down) {
					double tmp = ((-2) * speed + Math.sqrt( 4 * speed * speed + 8 * acc * (D - pos))) / 2 * acc;
					return t + tmp;
				} else if(dPos < t1Down+t2Down) {
					return t + t1 + (D-pos-t1Down)/interval.speed;
				} else {
					t+= interval.time;
					pos = interval.end;
					speed = interval.speed;
				}

			}
		}

		return -1;
	}

	private class Product {
		public long quantity;
		public int type;
		public int order;

		public Product(long quantity, int type, int order) {
			this.quantity = quantity;
			this.type = type;
			this.order = order;
		}
	}

	private long getB(List<Product> boxes, LinkedList<Product> toys) {
		long ret = Integer.MIN_VALUE;
		LinkedList<Product> boxesBackup = new LinkedList<Product>(boxes);
		LinkedList<Product> toyBackup = new LinkedList<Product>(toys);

		ArrayList<ArrayList<Product>> orders = new ArrayList<ArrayList<Product>>();
		Set<Integer> types = new HashSet<Integer>();

		for(Product box : boxes) {
			for(Product toy : toys) {
				if(box.type == toy.type) {

				}
			}
		}

		for(Product box : boxes) {
			types.add(box.type);
		}

		int index = 0;
		for(int type : types) {
			orders.add(new ArrayList<Product>());
			for(Product toy : toys) {
				if(toy.type == type) {
					orders.get(index).add(toy);
				}
			}
			index++;
		}

		return ret;
	}

	private String getA(List<ClassNode> nodes) {
		for(ClassNode node : nodes) {
			if(node.childrenNum < 2) {
				continue;
			}
			if(travelNode(nodes, node)) {
				return "Yes";
			}

			for(ClassNode node1 : nodes) {
				node1.visited = false;
			}
		}
		return "No";
	}

	private boolean travelNode(final List<ClassNode> nodes, ClassNode node) {
		if(node.visited) {
			return true;
		}
		node.visited = true;
		if(node.childrenNum == 0) {
			return false;
		}
		for(int cnIndex : node.children) {
			if(travelNode(nodes, nodes.get(cnIndex))) {
				return true;
			}
		}
		return false;
	}

	private class ClassNode {
		public List<Integer> children;
		public int childrenNum;
		public boolean visited;

		public ClassNode() {
			children = new ArrayList<Integer>();
			visited = false;
			childrenNum = 0;
		}
	}

	private void getC(List<Long> nums, List<Long> s1, List<Long> s2) {
		long pos = (long)Math.pow(2, nums.size());
		long sum1 = 0;
		long sum2 = 0;
		for(long i=1; i<pos-1; i++) {
			sum1 = 0;
			String b1 = getBinaryNum(i, nums.size());
			for(int j=0; j<b1.length(); j++) {
				if(b1.charAt(j) == '1') {
					sum1 += nums.get(j);
				}
			}

			for(long j=1; j<pos-1; j++) {
				String b2 = getBinaryNum(j, nums.size());
				sum2 = 0;
				for(int k=0; k<b2.length(); k++) {
					if(b2.charAt(k) == '1') {
						if(b1.charAt(k) == '1') {
							break;
						}
						sum2 += nums.get(k);
						if(sum1 == sum2) {
							for(int l=0; l<b1.length(); l++) {
								if(b1.charAt(l) == '1') {
									s1.add(nums.get(l));
								}
							}

							for(int l=0; l<b2.length(); l++) {
								if(b2.charAt(l) == '1') {
									s2.add(nums.get(l));
								}
							}
							return;
						} else if(sum2 > sum1) {
							break;
						}
					}
				}
			}
		}
	}

	private LinkedList<Double> getA(List<Integer> scores) {
		Integer sum = 0;
		for(Integer score : scores) {
			sum += score;
		}

		return getAHelper(scores, sum * 2);
	}

	private LinkedList<Double> getAHelper(List<Integer> scores, int points) {
		LinkedList<Double> ret = new LinkedList<Double>();
		Double avg = new Double(points) / scores.size();

		Integer sum = 0;
		for(Integer score : scores) {
			sum += score;
		}

		for(int i=0; i<scores.size(); i++) {
			if(avg <= scores.get(i)) {
				points -= scores.get(i);
				scores.remove(i);
				ret = getAHelper(scores, points);
				ret.add(i, new Double(0));
				return ret;
			}
		}
		for(Integer score : scores) {
			ret.add((avg - new Double(score)) / new Double(points - sum) * new Double(100));
		}
		return ret;
	}

	private int getSwitchForBooleanTree(BooleanTreeNode node, int value) {
		if(node.And == -1 || !node.change) {
			return node.value == value ? 0 : -1;
		} else {
			int left1 = getSwitchForBooleanTree(node.left, 1);
			int left0 = getSwitchForBooleanTree(node.left, 0);
			int right1 = getSwitchForBooleanTree(node.right, 1);
			int right0 = getSwitchForBooleanTree(node.right, 0);
			int and = -1;
			int or = -1;

			if(value == 1) {
				and = getSwitchForBooleanTreeHelper(left1, right1);
				if(right1 == -1) {
					or = left1;
				} else if(left1 == -1) {
					or = right1;
				} else {
					or = min(right1, left1);
				}
			} else if(value == 0) {
				if(right0 == -1) {
					and = left0;
				} else if(left0 == -1) {
					and = right0;
				} else {
					and = min(right0, left0);
				}
				or = getSwitchForBooleanTreeHelper(left0, right0);
			}

			if(!node.change) {
				return node.And == 1 ? and : or;
			} else {
				if(node.And == 1) {

				}
			}
		}
		throw new RuntimeException("It's not scientific!");
	}

	private int getSwitchForBooleanTreeHelper(int i, int j) {
		if(i == -1 || j == -1) {
			return -1;
		}
		return i + j;
	}

	private class BooleanTreeNode {
		public int value;
		public int And;
		public boolean change;
		public BooleanTreeNode left;
		public BooleanTreeNode right;

		public BooleanTreeNode(int value, int and) {
			this.value = value;
			this.And = and;
			change = false;
			left = null;
			right = null;
		}
	}

	private List<Integer> getPrimeNum(int max) {
		List<Integer> ret = new ArrayList<Integer>();
		boolean[] nums = new boolean[max+1];
		Arrays.fill(nums, true);
		for(int i=2; i<nums.length/2; i++) {
			int tmp = 2 * i;
			while(tmp < nums.length) {
				nums[tmp] = false;
				tmp += i;
			}
		}
		for(int i=2; i<nums.length; i++) {
			if(nums[i]) {
				ret.add(i);
			}
		}
		return ret;
	}

	private String format(String pattern, double value) {
		DecimalFormat myFormatter = new DecimalFormat(pattern);
		return myFormatter.format(value);
	}

	private int[] getMilkShake(int N, List<Customer> customers) {
		int[] ret = new int[N];
		Arrays.fill(ret, 0);
		boolean flag = true;
		while(flag) {
			flag = false;
			for(Customer customer : customers) {
				if(!customer.getMalt && customer.unmaltNum == 0) {
					if(customer.malt == -1) {
						return null;
					}

					int turnMalted = customer.malt;
					ret[turnMalted] = 1;
					customer.getMalt = true;

					for(Customer customer1 : customers) {
						if(customer1.malt == turnMalted) {
							customer1.getMalt = true;
						} else if(customer1.unmalt.contains(turnMalted)) {
							customer1.unmaltNum--;
						}
					}
					flag = true;
					break;
				}
			}
		}
		return ret;
	}

	private class Customer {
		public int malt;
		public List<Integer> unmalt;
		public boolean getMalt;
		public int unmaltNum;

		public Customer(int malt, List<Integer> unmalt) {
			this.malt = malt;
			this.unmalt = new ArrayList<Integer>(unmalt);
			getMalt = false;
			unmaltNum = unmalt.size();
		}

		public Customer(List<Integer> unmalt) {
			this(-1, unmalt);
		}
	}

	private long getMinScalarProduct(long[] xs, long[] ys) {
		Arrays.sort(xs);
		Arrays.sort(ys);
		long min = 0;
		for(int i=0; i<xs.length; i++) {
			min += xs[i] * ys[xs.length - 1 - i];
		}
		return min;
	}

	private int getB(LinkedList<Level> levels) {
		Collections.sort(levels);
		int star = 0;
		int trial = 0;
		boolean flag = false;

		while(!levels.isEmpty()) {
			if(levels.get(0).bi <= star) {
				if(levels.get(0).doneA) {
					star++;
				} else {
					star += 2;
				}
				trial++;
				levels.removeFirst();
			} else {
				for(int i= levels.size()-1; i>=0; i--) {
					if(levels.get(i).ai <= star && !levels.get(i).doneA) {
						star += 1;
						trial++;
						levels.get(i).doneA = true;
						flag = true;
						break;
					}
				}
				if(flag) {
					flag = false;
					continue;
				}
				return -1;
			}
		}

		return trial;
	}

	private class Level implements Comparable<Level>{
		public int ai;
		public int bi;
		public boolean doneA;

		@Override
		public int compareTo(Level o) {
			return bi - o.bi;
		}

		public Level(int ai, int bi) {
			this.ai = ai;
			this.bi = bi;
			doneA = false;
		}
	}

	private Double getA(int A, int B, List<Double> possibs) {
		Double third = new Double(A + B + 1);
		Double forth = new Double(B + 2);
		Double min = third > forth ? forth : third;
		for(int i=0; i<A; i++) {
			Double sum = new Double(1);

			Double pos1 = possibs.get(A - i);
			if(i > 0) {
				pos1 += possibs.get(A);
			}
			int key1 = i + B - A + i + 1;

			Double pos2 = new Double(1) - pos1;
			int key2 = key1 + B + 1;

			sum = pos1 * key1 + pos2 * key2;

			if(sum < min) {
				min = sum;
			}
		}
		return min;
	}

	private List<Double> getPossibility(List<Double> Ais) {
		List<Double> times = new ArrayList<Double>();
		times.add(new Double(1));
		for(int i=0; i<Ais.size(); i++) {
			times.add(times.get(i) * Ais.get(i));
		}

		List<Double> poss = new ArrayList<Double>();
		for(int i=0; i<Ais.size(); i++) {
			poss.add( (1-Ais.get(i)) * times.get(i) );
		}
		poss.add(times.get(Ais.size()));

		return poss;
	}

	private int getSwitchRowNum(int[][] matrix) {
		int ret = 0;
		int[] line = new int[matrix.length];
		Arrays.fill(line, 0);
		for(int i=0; i<matrix.length; i++) {
			for(int j=matrix.length-1; j>=0; j--) {
				if(matrix[i][j] == 1) {
					line[i] = j;
					break;
				}
			}
		}

		boolean flag = true;
		while(flag) {
			flag = false;
			for(int i=0; i<line.length; i++) {
				if(line[i] > i) {
					for(int j=i+1; j<line.length; j++) {
						if(line[j] <= i) {
							for(int k=j; k>i; k--) {
								swap(line, k, k-1);
							}
							ret += j - i;
							flag = true;
							break;
						}
					}
				}
			}
		}

		return ret;
	}

	private void swap(int[] line, int i, int j) {
		int tmp = line[i];
		line[i] = line[j];
		line[j] = tmp;
	}

	private long minBase(String msg) {
		Map<Character, Character> charMap = new HashMap<Character, Character>();
		charMap.put(msg.charAt(0), '1');
		int index = 0;
		String ret = "1";

		for(int i=1; i<msg.length(); i++) {
			char c = msg.charAt(i);
			if(!charMap.containsKey(c)) {
				if(index > 9) {
					charMap.put(c, (char)('a' + index-10));
				} else {
					charMap.put(c, (char)('0' + index));
				}
				if(index == 0) {
					index += 2;
				} else {
					index++;
				}
			}
			ret += charMap.get(c);
		}
		return stringToLong(ret, index < 2 ? 2 : index);
	}

	private double getPossibility(FeatureTree root, HashSet<String> features) {
		//tree ::= (weight [feature tree tree])
		double ret = root.weight;
		if(!root.feature.equals("")) {
			if(features.contains(root.feature)) {
				ret *= getPossibility(root.left, features);
			} else {
				ret *= getPossibility(root.right, features);
			}
		}
		return ret;
	}

	private class FeatureTree {
		public FeatureTree(double weight) {
			this.weight = weight;
			feature = "";
			left = null;
			right = null;
		}

		public FeatureTree(double weight, String feature, FeatureTree left, FeatureTree right) {
			this.weight = weight;
			this.feature = feature;
			this.left = left;
			this.right = right;
		}

		public double weight;
		public String feature;
		public FeatureTree left;
		public FeatureTree right;
	}

	private FeatureTree parseFeatureTree(BufferedReader reader) throws IOException {
		String token = getToken(reader, '[');
		if(token.equals("(")) {
			token = getToken(reader, '[');
		} else {
			token = token.substring(1);
		}

		if(token.endsWith(")")) {
			return new FeatureTree(Double.parseDouble(token.substring(0, token.length()-1)));
		}
		String token1 = getToken(reader, ')');
		if(token1.equals(")")) {
			return new FeatureTree(Double.parseDouble(token.substring(0, token.length())));
		} else {
			FeatureTree ret = new FeatureTree(Double.parseDouble(token), token1, parseFeatureTree(reader), parseFeatureTree(reader));
			getToken(reader, ')');
			return ret;
		}
	}

	private String getToken(BufferedReader reader, char stopChar) throws IOException {
		char c = (char)reader.read();
		for(; c == ' ' || c == '\n'; c = (char)reader.read()) {}
		String ret = "";
		for(; c != ' ' && c != '\n'; c = (char)reader.read()) {
			ret += c;
			if(c == stopChar) {
				break;
			}
		}
		return ret;
	}

	private String getNextNum(String num) {
		for(int i=num.length()-1; i>0; i--) {
			if(num.charAt(i) > num.charAt(i-1)) {
				int j = i;
				for(; j+1 < num.length() && num.charAt(j+1) > num.charAt(i-1); j++) {}
				if(j != num.length()-1) {
					return num.substring(0, i-1) + num.charAt(j) + sortString(num.substring(i-1, j) + num.substring(j+1));
				} else {
					return num.substring(0, i-1) + num.charAt(j) + sortString(num.substring(i-1, num.length()-1));
				}
			}
		}
		if(num.length() == 1) {
			return num + "0";
		} else {
			String ret = sortString(num);
			if(ret.startsWith("0")) {
				for(int i=1; i<ret.length(); i++) {
					if(ret.charAt(i) != '0') {
						if(i+1 <ret.length()) {
							num = ret.charAt(i) + ret.substring(0, i) + ret.substring(i+1);
						} else {
							num = ret.charAt(i) + ret.substring(0, i);
						}
						return num.charAt(0) + "0" + num.substring(1);
					}
				}
			} else {
				return ret.charAt(0) + "0" + ret.substring(1);
			}
		}
		return "";
	}

	private String sortString(String str) {
		char[] tmp = str.toCharArray();
		Arrays.sort(tmp);
		return String.valueOf(tmp);
	}

	private int getRecycleNum(int A, int B) {
		//A <= n < m <= B
		int ret = 0;
		Set<Integer> tmp = new HashSet<Integer>();
		for(int num=A; num<=B; num++) {
			String numStr = Integer.toString(num);
			int length = numStr.length();
			for(int i=0; i<length-1; i++) {
				String numStr2 = numStr.substring(1, numStr.length()) + numStr.charAt(0);
				int num2 = Integer.parseInt(numStr2);
				if(num2 <= B && num2 > num && !tmp.contains(num2)) {
					ret++;
				}
				tmp.add(num2);
				numStr = numStr2;
			}
			tmp.clear();
		}
		return ret;
	}

	private int getNumOfGoogler(int S, int p, List<Integer> points) {
		if(p == 0) {
			return points.size();
		}
		int ret = 0;
		for(int point : points) {
			if(point >= 3 * p - 2) {
				ret++;
			} else if(point >= 3 * p - 4 && S > 0 && p > 1) {
				S--;
				ret++;
			}
		}
		return ret;
	}


	Map<Character, Character> map = new HashMap<Character, Character>();

	private String getTranslation(String gs) {
		String ret = "";
		for(int i=0; i<gs.length(); i++) {
			ret += map.get(gs.charAt(i));
		}
		return ret;
	}

	private void getTranslation() {
		String gs1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		String gs2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		String gs3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

		String str1 = "our language is impossible to understand";
		String str2 = "there are twenty six factorial possibilities";
		String str3 = "so it is okay if you want to just give up";
		map.put('q', 'z');
		map.put('z', 'q');
		getTranslation(gs1, str1);
		getTranslation(gs2, str2);
		getTranslation(gs3, str3);
	}

	private void getTranslation(String gs, String str) {
		for(int i=0; i<gs.length(); i++) {
			map.put(gs.charAt(i), str.charAt(i));
		}
	}

	private int getHappyNum(List<Integer> bases) {
		for(int i=bases.get(0); ; i++) {
			boolean breakOut = false;
			for(int base : bases) {
				if(!isNumHappy(i, base)) {
					breakOut = true;
					break;
				}
			}
			if(!breakOut) {
				return i;
			}
		}
	}

	private boolean isNumHappy(int num, int base) {
		int sum = 0;
		List<String> previous = new ArrayList<String>();
		while(sum != 1) {
			sum = 0;
			String numStr = intToString(num, base);
			if(previous.contains(numStr)) {
				return false;
			}
			previous.add(numStr);
			for(int i=0; i<numStr.length(); i++) {
				sum += Math.pow(numStr.charAt(i) - '0', 2);
			}
			num = sum;
		}
		return true;
	}

	/**
	 * Accept 0~9 a~z
	 * @param str
	 * @param base
	 * @return
	 */
	private long stringToLong(String str, int base) {
		long ret = 0;
		long pow = 1;
		for(int i=str.length()-1; i>=0; i--) {
			if(str.charAt(i) >= 'a') {
				ret += (str.charAt(i) - 'a' + 10) * pow;
			} else {
				ret += (str.charAt(i) - '0') * pow;
			}
			pow *= base;
		}
		return ret;
	}

	private String intToString(int i, int base) {
		return intToString(i, base, 0);
	}

	private String intToString(int i, int base, int length) {
		String ret = "";
		while(i != 0) {
			ret = i % base + ret;
			i /= base;
		}
		if(ret.length() < length) {
			ret = new String(new char[length - ret.length()]).replace("\0", "0") + ret;
		}
		return ret;
	}

	private int getTicketFair(int P, int M[], int price[]) {
		int min = Integer.MAX_VALUE;
		int teamNum = (int)Math.pow(2, P);
		int gameNum = teamNum - 1;
		int possibility = (int)Math.pow(2, gameNum);
		for(int i=0; i<possibility; i++) {
			String buy = getBinaryNum(i, gameNum);
			int sum = 0;
			if(doesTeamWork(M, buy)) {
				for(int k=0; k<gameNum; k++) {
					if(buy.charAt(k) == '1') {
						sum += price[k];
					}
				}
			}
			if(sum != 0 && sum < min) {
				min = sum;
			}
		}
		return min;
	}

	private boolean doesTeamWork(int M[], String buy) {
		for(int i=0; i<M.length; i++) {
			int index = i / 2;
			int indexPlus = (buy.length() + 1) / 2;
			int sum = 0;
			int gameNum = 0;
			while(index < buy.length()) {
				if(buy.charAt(index) == '1') {
					sum++;
				}
				gameNum++;
				index = indexPlus + i / (int)Math.pow(2, gameNum+1);
				indexPlus = indexPlus + indexPlus / 2;
			}
			if(gameNum - M[i] > sum) {
				return false;
			}
		}
		return true;
	}

	private String getBinaryNum(long i, int length) {
		String ret = Long.toBinaryString(i);
		if(ret.length() < length) {
			return new String(new char[length - ret.length()]).replace("\0", "0") + ret;
		}
		return ret;
	}

	private class Chick {
		Chick(int b, int t, int x, int v) {
			T = t;
			B = b;
			X = x;
			V = v;
			arrive = (B - X) / (double)V <= T;
		}

		private int T;
		private int B;
		private int X;
		private int V;
		private boolean arrive;
	}

	private int getSwapNum(List<Chick> chicken, int K) {
		int ret = 0;
		for(int i=chicken.size()-1; i>=0; i--) {
			if(K == 0) {
				break;
			}
			if(!chicken.get(i).arrive) {
				ret += K;
			} else {
				K--;
			}
		}
		if(K != 0) {
			return -1;
		}
		return ret;
	}

	private class Directory {
		Directory(String n) {
			name = n;
			dirs = new ArrayList<Directory>();
		}

		Directory getChild(String name) {
			for(Directory dir : dirs) {
				if(dir.name.equals(name)) {
					return dir;
				}
			}
			return null;
		}

		private String name;
		private List<Directory> dirs;
	}

	private int getNumOfMkdir(Directory root, List<List<String>> newDirs) {
		int ret = 0;
		Directory curr, pre;
		for(List<String> newDir : newDirs) {
			curr = root;
			for(String folder : newDir) {
				pre = curr;
				curr = curr.getChild(folder);
				if(curr == null) {
					ret++;
					pre.dirs.add(new Directory(folder));
					curr = pre.getChild(folder);
				}
			}
		}
		return ret;
	}

	private List<String> getDirNames(String dir) {
		List<String> ret = new ArrayList<String>(Arrays.asList(dir.split("/")));
		ret.remove(0);
		return ret;
	}

	private String rotate(int K, char[][] position) {
		char[][] rotated = new char[position.length][position.length];
		for(int i=0; i<position.length; i++) {
			for(int j=0; j<position.length; j++) {
				rotated[j][position.length-1-i] = position[i][j];
			}
		}
		for(int j=0; j<position.length; j++) {
			int tmp = position.length - 1;
			for(int i=position.length-1; i>=0; i--) {
				if(rotated[i][j] != '.') {
					rotated[tmp][j] = rotated[i][j];
					tmp--;
				}
			}
			for(; tmp>=0; tmp--) {
				rotated[tmp][j] = '.';
			}
		}

		boolean r = checkColor('R', K, rotated);
		boolean b = checkColor('B', K, rotated);

		if(r && b) {
			return "Both";
		} else if(r) {
			return "Red";
		} else if(b) {
			return "Blue";
		} else {
			return "Neither";
		}
	}

	private boolean checkColor(char color, int K, char[][] rotated) {
		int num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				if(rotated[i][j] == color) {
					num++;
					if(num == K) {
						return true;
					}
				} else {
					num = 0;
				}
			}
			num = 0;
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				if(rotated[j][i] == color) {
					num++;
					if(num == K) {
						return true;
					}
				} else {
					num = 0;
				}
			}
			num = 0;
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				for(int k=0; k<K; k++) {
					if(i+k >=rotated.length || j+k >= rotated.length) {
						break;
					}
					if(rotated[i+k][j+k] == color) {
						num++;
						if(num == K) {
							return true;
						}
					} else {
						break;
					}
				}
				num = 0;
			}
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				for(int k=0; k<K; k++) {
					if(i+k >=rotated.length || j-k < 0) {
						break;
					}
					if(rotated[i+k][j-k] == color) {
						num++;
						if(num == K) {
							return true;
						}
					} else {
						break;
					}
				}
				num = 0;
			}
		}

		return false;
	}

	private class WalkWay implements Comparable<WalkWay>{
		WalkWay(int b, int e, int w) {
			B = b;
			E = e;
			W = w;
		}

		private int B;
		private int E;
		private int W;

		@Override
		public int compareTo(WalkWay o) {
			if(W == o.W) {
				return 0;
			}
			return W < o.W ? -1 : 1;
		}
	}

	private Double getMinTimeForWalkWay(int X, int S, int R, Double t, List<WalkWay> walkWays) {
		int walkWayNum = walkWays.size();
		int tmp = 0;
		for(int i=0; i<X; i++) {
			if(tmp >= walkWayNum) {
				walkWays.add(new WalkWay(i, X, 0));
				break;
			}
			if(i < walkWays.get(tmp).B) {
				walkWays.add(new WalkWay(i, walkWays.get(tmp).B, 0));
				i = walkWays.get(tmp).E - 1;
				tmp++;
			} else if(i == walkWays.get(tmp).B) {
				i = walkWays.get(tmp).E - 1;
				tmp++;
			}
		}
		Collections.sort(walkWays);

		Double ret = new Double(0);
		for(WalkWay walkWay : walkWays) {
			if(t > 0) {
				Double ideaT = (new Double(walkWay.E) - walkWay.B) / (walkWay.W + R);
				if(t >= ideaT) {
					t -= ideaT;
					ret += ideaT;
				} else {
					Double pass = t * (walkWay.W + R);
					ret += t + (new Double(walkWay.E) - pass - walkWay.B) / (walkWay.W + S);
					t = new Double(-1);
				}
			} else {
				ret += (new Double(walkWay.E) - walkWay.B) / (walkWay.W + S);
			}
		}

		return ret;
	}

	private String getPerfertHarmony(Long L, Long H, List<Long> frequencise) {
		boolean flag = true;
		for(long i=L; i<=H; i++) {
			flag = true;
			for(Long frequency : frequencise) {
				if(i % frequency != 0 && frequency % i != 0) {
					flag = false;
					break;
				}
			}
			if(flag) {
				return "" + i;
			}
		}
		return "NO";
	}

	private Long getRocketTime(Long L, Long t, Long N, List<Long> distance) {
		Long sum = new Long(0);
		List<Long> singleDis = new ArrayList<Long>();
		for(Long dis : distance) {
			sum += dis;
		}
		Long nRound = N / distance.size();
		Long nRemain = N % distance.size();
		Long time = nRound * sum;
		for(int i=0; i<nRemain; i++) {
			time += distance.get(i);
			singleDis.add(distance.get(i));
		}
		time *= 2;

		if(t >= time || L == 0) {
			return time;
		}

		Long pass = t/2;
		Long passRound = pass / sum;
		Long passRemain = pass % sum;
		Long passRoundRemain = nRound - passRound;

		if(t != 0) {
			for(int i=0; i<distance.size(); i++) {
				if(passRemain > 0) {
					passRemain -= distance.get(i);
				} else {
					singleDis.add(distance.get(i));
				}
			}
			if(passRemain != 0) {
				singleDis.add(-passRemain);
			}
			passRoundRemain--;
		}

		Collections.sort(distance);
		Collections.sort(singleDis);

		Long minus = new Long(0);
		int singleDisIndex = singleDis.size()-1;
		for(int i=distance.size()-1; i>=0; i--) {
			while(singleDisIndex >= 0 && singleDis.get(singleDisIndex) >= distance.get(i)) {
				minus += singleDis.get(singleDisIndex);
				singleDisIndex--;
				L--;
			}
			if(L <= passRoundRemain) {
				minus += L * distance.get(i);
				break;
			} else {
				minus += passRoundRemain * distance.get(i);
				L -= passRoundRemain;
			}
		}

		return time - minus;
	}

	private char[][] tiles;
	private boolean test() {
		for(int i=0; i<tiles.length; i++) {
			for(int j=0; j<tiles[i].length; j++) {
				if(tiles[i][j] == '#') {
					if(i+1 >= tiles.length || j+1 >= tiles[i+1].length || tiles[i][j+1] != '#' || tiles[i+1][j] != '#' || tiles[i+1][j+1] != '#') {
						return false;
					}
					tiles[i][j] = '/';
					tiles[i+1][j] = '\\';
					tiles[i][j+1] = '\\';
					tiles[i+1][j+1] = '/';
				}
			}
		}
		return true;
	}

	private String test1(List<String> words, String seq) {
		int maxScore = -1;
		String maxString = "";

		for(String word : words) {
			int score = -1;
			StringBuilder wildCard = new StringBuilder(new String(new char[word.length()]).replace("\0", "_"));
			List<String> words2 = new ArrayList<String>(words);
			int words2Size = words.size();

			for(int i=0; i<seq.length(); i++) {
				Character seqChar = seq.charAt(i);
				int j=0;

				while(j<words2Size) {
					if(words2.get(j).indexOf(seqChar) != -1) {
						break;
					}
					j++;
				}

				if(j == words2Size) {
					continue;
				}

				if(word.indexOf(seqChar) == -1) {
					score++;
				} else {
					int beginIndex = 0;
					while(true) {
						beginIndex = word.indexOf(seqChar, beginIndex);
						if(beginIndex == -1) {
							break;
						}
						wildCard.setCharAt(beginIndex, seqChar);
						beginIndex++;
					}

					for(j=0; j<words2Size; j++) {
						if(!killerWordWildCard(words2.get(j), wildCard.toString(), seqChar)) {
							words2.remove(words2.get(j));
							words2Size--;
							j--;
						}
					}

					if(words2Size == 1) {
						break;
					}
				}
			}
			if(score > maxScore) {
				maxScore = score;
				maxString = word;
			}
		}
		return maxString;
	}

	private boolean killerWordWildCard(String word, String wildCard, Character notIn) {
		if(!wildCardMatch(word, wildCard)) {
			return false;
		} else if(notIn != null) {
			int begin = -1;
			while(true) {
				if(begin+1 >= word.length()) {
					break;
				}
				begin = word.indexOf(notIn, begin + 1);
				if(begin == -1) {
					break;
				}
				if(wildCard.charAt(begin) != notIn) {
					return false;
				}
			}
			//			wildCard.indexOf(notIn);
		}
		return true;
	}

	private boolean wildCardMatch(String str1, String str2) {
		if(str1.length() != str2.length()) {
			return false;
		}
		for(int i=0; i<str1.length(); i++) {
			if(str2.charAt(i) != '_' && str1.charAt(i) != str2.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	private Integer max(Integer... numbers) {
		int max = numbers[0];

		for(Integer number : numbers) {
			if(number > max) {
				max = number;
			}
		}
		return max;
	}

	private Double max(Double... numbers) {
		Double max = numbers[0];

		for(Double number : numbers) {
			if(number > max) {
				max = number;
			}
		}
		return max;
	}

	private Integer min(Integer... numbers) {
		Integer min = numbers[0];

		for(Integer number : numbers) {
			if(number < min) {
				min = number;
			}
		}
		return min;
	}

	private Double min(Double... numbers) {
		Double min = numbers[0];

		for(Double number : numbers) {
			if(number < min) {
				min = number;
			}
		}
		return min;
	}

	private int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}

	private int gcd(int a, int b) {
		while(a != b) {
			if(a > b) {
				a -= b;
			} else {
				b -= a;
			}
		}
		return a;
	}
}
