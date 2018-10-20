import java.util.ArrayList;

public class ElectricNode {
	public ElectricNode(ArrayList<String> curr, int numSwitches, int L, int N){
		this.curr = curr;
		this.numSwitches = numSwitches;
		this.L = L;
		this.N = N;
	}
	
	public void setNumSwitches(int num){
		numSwitches = num;
	}
	
	public boolean isGoal(ArrayList<String> req){
		ArrayList<String> currCopy = (ArrayList<String>)curr.clone();
		boolean found;
		for(int i = 0; i < N; i++){
			String reqS = req.get(i);
			found = false;
			for(int j = 0; j < currCopy.size(); j++){
				if(reqS.equals(currCopy.get(j))){
					currCopy.remove(j);
					found = true;
					break;
				}
			}
			if (found == false){
				return false;
			}
		}
		
		return true;
	}
	
	public ArrayList<ElectricNode> getChildren(){
		ArrayList<ElectricNode> children = new ArrayList<ElectricNode>();
		
		for(int i = 0; i < L; i++){
			
			ArrayList<String> newStrings = new ArrayList<String>();
			for(String s : curr){
				char value;
				String sNew;
				if(s.charAt(i) == '0'){
					value = '1';
				}else{
					value = '0';
				}
				if(i == 0){
					sNew = value + "" + s.substring(1, L);
				}else if(i == L - 1){
					sNew = s.substring(0, L - 1) + value;
				}else{
					sNew = s.substring(0, i) + value + s.substring(i + 1, L);
				}
				newStrings.add(sNew);
			}
			ElectricNode newChild = new ElectricNode(newStrings, numSwitches + 1, L, N);
			children.add(newChild);
		}
		return children;

	}
	
	
	public int getNumSwitches(){
		return numSwitches;
	}
	
	public int getHScore(ArrayList<String> req){
		return 0;
	}
	public int numSwitches;
	public ArrayList<String> curr;
	public int L;
	public int N;
	
}
