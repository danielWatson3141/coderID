import java.util.ArrayList;
import java.util.HashSet;

public class ZuHe {
	private ArrayList<ArrayList<Integer>> resultList;
	
	public void combine(int[] a, int n, ArrayList<ArrayList<Integer>> resultList) {
		this.resultList = resultList;
		if(null == a || a.length == 0 || n <= 0 || n > a.length)
			return;
			
		int[] b = new int[n];
		getCombination(a, n , 0, b, 0);
	}

	private void getCombination(int[] a, int n, int begin, int[] b, int index) {
		
		if(n == 0){
			ArrayList<Integer> my_set = new ArrayList<Integer>();
			for(int i = 0; i < index; i++){
				my_set.add(new Integer(b[i]));
			}
			resultList.add(my_set);
			
			return;
		}
			
		for(int i = begin; i < a.length; i++){
			
			b[index] = a[i];
			getCombination(a, n-1, i+1, b, index+1);
		}
		
	}

}

