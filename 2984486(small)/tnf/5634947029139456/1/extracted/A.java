import java.util.*;

class A{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int kases = sc.nextInt();
		for(int k = 1; k<=kases; k++){
			int N =sc.nextInt();
			int L = sc.nextInt();
			sc.nextLine();
			long[] source = new long[N];
			long[] target = new long[N];
			String[] sA = sc.nextLine().split("\\s");
			for(int i = 0; i<N; i++){
				long bit = 1;
				for(int j = 0; j<L; j++){
					if(sA[i].charAt(j)=='1') source[i]+=bit;
					bit *= 2;
				}
			}	
			sA = sc.nextLine().split("\\s");
			for(int i = 0; i<N; i++){
				long bit = 1;
				for(int j = 0; j<L; j++){
					if(sA[i].charAt(j)=='1') target[i]+=bit;
					bit *= 2;
				}
			}	
			Map<Long,Integer> map = new HashMap<Long, Integer>();
			for(int i = 0; i<N; i++){
				for(int j = 0; j< N; j++){
					long swtch = source[i]^target[j];
					if(map.containsKey(swtch)){
						map.put(swtch, map.get(swtch)+1);
					}
					else map.put(swtch, 1);
				}
			}
			int max = L+1;
			Set<Map.Entry<Long, Integer>> ent = map.entrySet();
			for(Map.Entry<Long, Integer> pair: ent){
				if(pair.getValue()==N){
					long sw = pair.getKey();
					int count = 0;
					while(sw>0){
						if(sw%2==1) count++;
						sw/=2;
					}
					if(count<max) max = count;
				}
			}
			System.out.println("Case #"+k+": "+(max==L+1?"NOT POSSIBLE": max));
		}
	}
}
