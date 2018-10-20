import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class R1AProblemA {

	private static int l,n;
	private static String Outlet,Required;
	public static void main(String[] args) {
		Scanner a = new Scanner(System.in);
		
		int test = a.nextInt();
		
		for(int i=1;i<=test;i++){
			n = a.nextInt();
			l = a.nextInt();
			a.nextLine();
			Outlet = a.nextLine();
			Required = a.nextLine();
			System.out.print("Case #"+i+": ");
			solve();
			
		}
	}
	
	private static void  solve(){
		List<Long> outletList = new ArrayList<Long>();
		for(String s : Outlet.split(" "))
			outletList.add(getDecimalFromBinary(s));
		Collections.sort(outletList);
				
		List<Long> requiredList = new ArrayList<Long>();
		for(String s : Required.split(" "))
			requiredList.add(getDecimalFromBinary(s));
		Collections.sort(requiredList);
		
		//System.out.println(outletList);
		//System.out.println(requiredList);
		
		long minAns = Long.MAX_VALUE;
		for(long i=0;i<Math.pow(2, l);i++){
		List<Long> newConf = new ArrayList<Long>();
			newConf.clear();
			for(int j=0;j<n;j++){
				newConf.add(outletList.get(j) ^ i);
			}
			Collections.sort(newConf);
			//System.out.println("For i "+i+" list: "+newConf);
			boolean ans = newConf.equals(requiredList);//checkWithNewConf(newConf,requiredList);
			if(ans){	
//				System.out.println("Found Equal "+newConf);
				if(minAns > Long.bitCount(i))
					minAns = Long.bitCount(i);				
			}
			
		}
		if(minAns != Long.MAX_VALUE){
			//System.out.println(Long.toBinaryString(minAns));
			System.out.println(minAns);
		}else
		System.out.println("NOT POSSIBLE");
	}
	
	private static boolean checkWithNewConf(List<Long> newConf,
			List<Long> requiredList) {
		//System.out.println("Compare "+newConf+"  ----  "+requiredList);
		for(int i=0;i<n;i++){
			if(newConf.get(i) != requiredList.get(i))
				return false;
		}
		return true;
	}

	private static long getDecimalFromBinary(String b){
        long binary = Integer.parseInt(b);
        long decimal = 0;
        int power = 0;
        while(true){
            if(binary == 0){
                break;
            } else {
                long tmp = binary%10;
                decimal += tmp*Math.pow(2, power);
                binary = binary/10;
                power++;
            }
        }
        return decimal;
    }
}
