package round1a;

import java.util.HashMap;
import java.util.Map.Entry;

public class ChargingChaos {
	
	public int solve(int N, int L, String[] init, String req[]) {
		
		HashMap<String, HashMap<String, String>> map = new HashMap<String, HashMap<String,String>>();
		for(String config : init) {
			
			for(String to : req) {
				
				String diff = getDiff(config, to);
				if(map.containsKey(diff)) {
					
					HashMap<String, String> map2 = map.get(diff);
					if(map2.containsKey("-1"))
						continue;
					if(map2.containsKey(to)) {
						
						map2.clear();
						map2.put("-1", "");
						
					}
					else {
						
						map2.put(to, config);
						
					}
					
				}
				else {
					
					HashMap<String, String> map2 = new HashMap<String, String>();
					map2.put(to, config);
					map.put(diff, map2);
					
				}
				
			}
			
		}
		
		int len = 41;
		for(Entry<String, HashMap<String, String>> ent : map.entrySet()) {
			
			String diff = ent.getKey();
			HashMap<String, String> map2 = ent.getValue();
			if(map2.size() == N) {
				
				len = Math.min(len, getCount(diff));
				
			}
			else {
				
				assert(map2.containsKey("-1"));
				
			}
			
		}
		return len;
		
	}
	
	private int getCount(String diff) {
	
		int len = 0;
		for(int i = 0; i < diff.length(); i++) {
			
			if(diff.charAt(i) == '-')
				len++;
			
		}
		return len;
		
	}

	private String getDiff(String con, String to) {
		
		assert(con.length() == to.length());
		String ret = "";
		for(int i = 0; i < con.length(); i++) {
			
			if(con.charAt(i) == to.charAt(i))
				ret += "|";
			else
				ret += "-";
			
		}
		return ret;
		
	}

}
