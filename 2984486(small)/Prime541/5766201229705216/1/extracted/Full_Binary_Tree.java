
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Vector;

/*
 * Google code jam 2014 Round 1A, problem B
 */
public class Full_Binary_Tree extends AbstractCodejamProblem {
	
	@Override
	protected void executeInput() {
		try {
			int aPreviousLineNb = -1;
			int aCaseNb = 0;
			
			int aSetSize = -1;
			int aRow = -1;
			int aCol = -1;
			
			StreamTokenizer aStrTokoniser = new StreamTokenizer(getInput());
			while (aStrTokoniser.nextToken() != StreamTokenizer.TT_EOF) {
				if (isVerbose()) System.out.println("token: " + aStrTokoniser.lineno() + ", " + aStrTokoniser.ttype + ", " + aStrTokoniser.sval + ", " + aStrTokoniser.nval + ", " + (int)aStrTokoniser.nval);
				if (aStrTokoniser.lineno() == 1) {
					if (isVerbose()) System.out.println("Nb of cases: " + (int)aStrTokoniser.nval);
					setCaseNoExpected((int)aStrTokoniser.nval);
				} else if (aStrTokoniser.lineno() > 1) {
					if (aSetSize < 1) {
						++aCaseNb;
						startCaseNo(aCaseNb);
						aSetSize = (int)aStrTokoniser.nval;
						setDimension(aSetSize);
					} else {
						++aCol;
						if (aPreviousLineNb != aStrTokoniser.lineno()) {
							++aRow;
						}
						pushData(aCol, aRow, (int)aStrTokoniser.nval);
						if (aCol + 1 >= 2) {
							aCol = -1;
							if (aRow + 1 >= aSetSize - 1) {
								printResult();
								aRow = -1;
								aSetSize = -1;
							}
						}
					}
				}
				
				aPreviousLineNb = aStrTokoniser.lineno();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private class Node {
		public int _value = -1;
		public Vector<Integer> _edges = new Vector<Integer>();
	}
	
	private Vector<Node> _tree = new Vector<Node>(1000);
	private int _setSize = -1;
				
	public void setDimension(int iSize) {
		_setSize = iSize;
		_tree.ensureCapacity(_setSize);
		for (int i = 0 ; i < _setSize ; ++i) {
			Node aNode = null;
			if (i >= _tree.size()) {
				aNode = new Node();
				aNode._value = i + 1;
				_tree.add(aNode);
			} else {
				aNode = _tree.elementAt(i);
				aNode._edges.clear();
			}
		}
	}
	
	private int _leftValue = -1;
	public void pushData(int iColIdx, int iRowIdx, int iValue) {
		if (iColIdx == 0) {
			_leftValue = iValue;
		} else {
			_tree.elementAt(_leftValue - 1)._edges.add(iValue);
			_tree.elementAt(iValue - 1)._edges.add(_leftValue);
		}
	}

	public void startCaseNo(int iCaseNo) {
		setCaseNo(iCaseNo);
		_setSize = -1;
	}
	
	protected int solve() {
		int aMinScore = -1;
		for (int i = 0 ; i < _setSize ; ++i) {
			int aScore = -1;
			Node aRoot = _tree.elementAt(i);
			switch (aRoot._edges.size()) {
			case 0:
				return 0;
			case 1:
				aScore = _setSize - 1;
				break;
			case 2:
				aScore = solve(aRoot, aRoot._edges.elementAt(0)) + solve(aRoot, aRoot._edges.elementAt(1));
				break;
//			case 3:
//				int aSolve1 = solve(aRoot, aRoot._edges.elementAt(0));
//				int aSolve2 = solve(aRoot, aRoot._edges.elementAt(1));
//				int aSolve3 = solve(aRoot, aRoot._edges.elementAt(2));
//				int aDelete1 = delete(aRoot, aRoot._edges.elementAt(0));
//				int aDelete2 = delete(aRoot, aRoot._edges.elementAt(1));
//				int aDelete3 = delete(aRoot, aRoot._edges.elementAt(2));
//				int aScore1 = aSolve1 + aSolve2 + aDelete3;
//				int aScore2 = aSolve1 + aDelete2 + aSolve3;
//				int aScore3 = aDelete1 + aSolve2 + aSolve3;
//				if (aScore < 0 || aScore1 < aScore) {
//					aScore = aScore1;
//				}
//				if (aScore < 0 || aScore2 < aScore) {
//					aScore = aScore2;
//				}
//				if (aScore < 0 || aScore3 < aScore) {
//					aScore = aScore3;
//				}
//				break;
			default:
				// try removing n-2 edges
				Vector<Integer> aDeleteVec = new Vector<Integer>(aRoot._edges.size());
				Vector<Integer> aSolveVec = new Vector<Integer>(aRoot._edges.size());
				int aDeleteSum = 0;
				for (int j = 0 ; j < aRoot._edges.size() ; ++j) {
					int aRes = delete(aRoot, aRoot._edges.elementAt(j));
					aDeleteSum += aRes;
					aDeleteVec.add(aRes);
					aRes = solve(aRoot, aRoot._edges.elementAt(j));
					aSolveVec.add(aRes);
				}
				for (int j = 0 ; j < aRoot._edges.size() ; ++j) {
					for (int k = j + 1 ; k < aRoot._edges.size() ; ++k) {
						int aTryScore = aDeleteSum - aDeleteVec.elementAt(j) - aDeleteVec.elementAt(k) + aSolveVec.elementAt(j) + aSolveVec.elementAt(k);
						if (aScore < 0 || aTryScore < aScore) {
							aScore = aTryScore;
						}
					}
				}
			}
			if (aScore == 0) {
				return 0;
			} else if (aMinScore < 0 || aScore < aMinScore) {
				aMinScore = aScore;
			}
		}
		if (aMinScore < 0) {
			return 0;
		}
		return aMinScore;
	}
	
	protected int solve(Node iParent, int iValue) {
		int aMinScore = -1;
		Node aNode = _tree.elementAt(iValue - 1);
		if (aNode._edges.size() <= 1) {
			return 0;
		}
		switch (aNode._edges.size() - 1) {
		case -1:
		case 0:
			return 0;
		case 1:
			if (aNode._edges.elementAt(0) != iParent._value) {
				return delete(aNode, aNode._edges.elementAt(0));
			} else {
				return delete(aNode, aNode._edges.elementAt(1));
			}
		case 2:
			if (aNode._edges.elementAt(0) == iParent._value) {
				return solve(aNode, aNode._edges.elementAt(1)) + solve(aNode, aNode._edges.elementAt(2));
			} else if (aNode._edges.elementAt(1) == iParent._value) {
				return solve(aNode, aNode._edges.elementAt(0)) + solve(aNode, aNode._edges.elementAt(2));
			} else {
				return solve(aNode, aNode._edges.elementAt(0)) + solve(aNode, aNode._edges.elementAt(1));
			}
//		case 3:
//			if (aNode._edges.elementAt(0) == iParent._value) {
//				int aSolve1 = solve(aNode, aNode._edges.elementAt(3));
//				int aSolve2 = solve(aNode, aNode._edges.elementAt(1));
//				int aSolve3 = solve(aNode, aNode._edges.elementAt(2));
//				int aDelete1 = delete(aNode, aNode._edges.elementAt(3));
//				int aDelete2 = delete(aNode, aNode._edges.elementAt(1));
//				int aDelete3 = delete(aNode, aNode._edges.elementAt(2));
//				int aScore1 = aSolve1 + aSolve2 + aDelete3;
//				int aScore2 = aSolve1 + aDelete2 + aSolve3;
//				int aScore3 = aDelete1 + aSolve2 + aSolve3;
//				if (aMinScore < 0 || aScore1 < aMinScore) {
//					aMinScore = aScore1;
//				}
//				if (aMinScore < 0 || aScore2 < aMinScore) {
//					aMinScore = aScore2;
//				}
//				if (aMinScore < 0 || aScore3 < aMinScore) {
//					aMinScore = aScore3;
//				}
//			} else if (aNode._edges.elementAt(1) == iParent._value) {
//				int aSolve1 = solve(aNode, aNode._edges.elementAt(0));
//				int aSolve2 = solve(aNode, aNode._edges.elementAt(3));
//				int aSolve3 = solve(aNode, aNode._edges.elementAt(2));
//				int aDelete1 = delete(aNode, aNode._edges.elementAt(0));
//				int aDelete2 = delete(aNode, aNode._edges.elementAt(3));
//				int aDelete3 = delete(aNode, aNode._edges.elementAt(2));
//				int aScore1 = aSolve1 + aSolve2 + aDelete3;
//				int aScore2 = aSolve1 + aDelete2 + aSolve3;
//				int aScore3 = aDelete1 + aSolve2 + aSolve3;
//				if (aMinScore < 0 || aScore1 < aMinScore) {
//					aMinScore = aScore1;
//				}
//				if (aMinScore < 0 || aScore2 < aMinScore) {
//					aMinScore = aScore2;
//				}
//				if (aMinScore < 0 || aScore3 < aMinScore) {
//					aMinScore = aScore3;
//				}
//			} else if (aNode._edges.elementAt(2) == iParent._value) {
//				int aSolve1 = solve(aNode, aNode._edges.elementAt(0));
//				int aSolve2 = solve(aNode, aNode._edges.elementAt(1));
//				int aSolve3 = solve(aNode, aNode._edges.elementAt(3));
//				int aDelete1 = delete(aNode, aNode._edges.elementAt(0));
//				int aDelete2 = delete(aNode, aNode._edges.elementAt(1));
//				int aDelete3 = delete(aNode, aNode._edges.elementAt(3));
//				int aScore1 = aSolve1 + aSolve2 + aDelete3;
//				int aScore2 = aSolve1 + aDelete2 + aSolve3;
//				int aScore3 = aDelete1 + aSolve2 + aSolve3;
//				if (aMinScore < 0 || aScore1 < aMinScore) {
//					aMinScore = aScore1;
//				}
//				if (aMinScore < 0 || aScore2 < aMinScore) {
//					aMinScore = aScore2;
//				}
//				if (aMinScore < 0 || aScore3 < aMinScore) {
//					aMinScore = aScore3;
//				}
//			} else {
//				int aSolve1 = solve(aNode, aNode._edges.elementAt(0));
//				int aSolve2 = solve(aNode, aNode._edges.elementAt(1));
//				int aSolve3 = solve(aNode, aNode._edges.elementAt(2));
//				int aDelete1 = delete(aNode, aNode._edges.elementAt(0));
//				int aDelete2 = delete(aNode, aNode._edges.elementAt(1));
//				int aDelete3 = delete(aNode, aNode._edges.elementAt(2));
//				int aScore1 = aSolve1 + aSolve2 + aDelete3;
//				int aScore2 = aSolve1 + aDelete2 + aSolve3;
//				int aScore3 = aDelete1 + aSolve2 + aSolve3;
//				if (aMinScore < 0 || aScore1 < aMinScore) {
//					aMinScore = aScore1;
//				}
//				if (aMinScore < 0 || aScore2 < aMinScore) {
//					aMinScore = aScore2;
//				}
//				if (aMinScore < 0 || aScore3 < aMinScore) {
//					aMinScore = aScore3;
//				}
//			}
//			break;
		default:
			// try removing n-2 edges
			Vector<Integer> aDeleteVec = new Vector<Integer>(aNode._edges.size());
			Vector<Integer> aSolveVec = new Vector<Integer>(aNode._edges.size());
			int aDeleteSum = 0;
			for (int j = 0 ; j < aNode._edges.size() ; ++j) {
				if (aNode._edges.elementAt(j) != iParent._value) {
					int aRes = delete(aNode, aNode._edges.elementAt(j));
					aDeleteSum += aRes;
					aDeleteVec.add(aRes);
					aRes = solve(aNode, aNode._edges.elementAt(j));
					aSolveVec.add(aRes);
				} else {
					aDeleteVec.add(0);
					aSolveVec.add(0);
				}
			}
			for (int j = 0 ; j < aNode._edges.size() ; ++j) {
				if (aNode._edges.elementAt(j) != iParent._value) {
					for (int k = j + 1 ; k < aNode._edges.size() ; ++k) {
						if (aNode._edges.elementAt(k) != iParent._value) {
							int aTryScore = aDeleteSum - aDeleteVec.elementAt(j) - aDeleteVec.elementAt(k) + aSolveVec.elementAt(j) + aSolveVec.elementAt(k);
							if (aMinScore < 0 || aTryScore < aMinScore) {
								aMinScore = aTryScore;
							}
						}
					}
				}
			}
		}
		return aMinScore;
	}
	
	protected int delete(Node iParent, int iValue) {
		int aScore = 1;
		Node aNode = _tree.elementAt(iValue - 1);
		for (int i = 0 ; i < aNode._edges.size() ; ++i) {
			if (aNode._edges.elementAt(i) != iParent._value) {
				aScore += delete(aNode, aNode._edges.elementAt(i));
			}
		}
		return aScore;
	}
	
	public void printResult() {
		if (getCaseNo() < 1) return;
				
		PrintWriter aOut = new PrintWriter(getOutput());
		aOut.print("Case #" + getCaseNo() + ':');
		if (isVerbose()) System.out.print("Case #" + getCaseNo() + ':');
		
		int aScore = solve();
		aOut.print(' ');
		if (isVerbose()) System.out.print(' ');
		aOut.print(aScore);
		if (isVerbose()) System.out.print(aScore);
		
		aOut.println();
		if (isVerbose()) System.out.println();
	}

}

