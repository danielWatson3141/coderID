import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.TreeMap;
import java.util.Comparator;



public class ProblemA {
	// need to add inputs
	public ProblemA(int N, int L, ArrayList<String> initialFlow,
								ArrayList<String> reqFlow){
		this.N = N;
		this.L = L;
		this.initial = initialFlow;
		this.req = reqFlow;
	}
	
	// need to add return type
	public int solve(){
		ElectricNode start = new ElectricNode(initial, 0, L, N);
		
		ArrayList<ElectricNode> openSet = new ArrayList<ElectricNode>();
		openSet.add(start);
		ArrayList<ElectricNode> closedSet = new ArrayList<ElectricNode>();
		while(!openSet.isEmpty()){
			
			/**
			 * Comparator to sort nodes
			 */
			Collections.sort(openSet, new Comparator<ElectricNode>(){
				@Override
				public int compare(ElectricNode e1, ElectricNode e2){
					int g_score1 = e1.getNumSwitches();
					int g_score2 = e2.getNumSwitches();
					int h_score1 = e1.getHScore(req);
					int h_score2 = e2.getHScore(req);
					
					int f_score1 = g_score1 + h_score1;
					int f_score2 = g_score2 + h_score2;
					
					if(f_score1 < f_score2){
						return -1;
					}else if(f_score1 > f_score2){
						return 1;
					}else{
						return 0;
					}
				}
			});
			/**
			 * FINISH comparator
			 */
			
			ElectricNode current = openSet.get(0);
			if(current.isGoal(req)){
				return current.getNumSwitches();
			}
			
			
			openSet.remove(0);
			closedSet.add(current);
			
			ArrayList<ElectricNode> childrenCurr = current.getChildren();
			for(int i = 0; i < childrenCurr.size(); i++){
				ElectricNode currChild = childrenCurr.get(i);
				
				
				if(contains(closedSet, currChild)){
					continue;
				}
				
				int tent_g_score = current.getNumSwitches() + 1;
				ElectricNode sameState = getSameState(openSet, currChild);
				
				if(sameState == null){
					openSet.add(currChild);
				}else if(sameState.getNumSwitches() > tent_g_score){
					sameState.setNumSwitches(tent_g_score);
				}
			}
			
		}
		return -1;
	}
	
	
	public boolean contains(ArrayList<ElectricNode> set, ElectricNode state){
		boolean same;
		for(ElectricNode e : set){
			same = true;
			for(int i = 0; i < N; i++){
				if(!(e.curr.get(i).equals(state.curr.get(i)))){
					same = false;
					break;
				}
			}
			if (same == true){
				return true;
			}
		}
		return false;
	}
	
	
	
	
	public ElectricNode getSameState(ArrayList<ElectricNode> set, ElectricNode state){
		boolean same;
		for(ElectricNode e : set){
			same = true;
			for(int i = 0; i < N; i++){
				if(!(e.curr.get(i).equals(state.curr.get(i)))){
					same = false;
					break;
				}
			}
			if (same == true){
				return e;
			}
		}
		return null;
	}
	
	
	
	// need to add fields
	public int N;
	public int L;
	public ArrayList<String> initial;
	public ArrayList<String> req;
}
