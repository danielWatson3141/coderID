import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class ChargingChaos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if(args.length>0)
			try {
				System.setIn(new FileInputStream(args[0]));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
			Scanner in = new Scanner(System.in);
		
			int T = in.nextInt();
			
			for(int iCase=1;iCase<=T;iCase++){
				String ans ="";
				int N=in.nextInt(),L=in.nextInt();
				String flow[]=new String[N];
				String goal[]=new String[N];
				for(int i=0;i<N;i++) flow[i]=in.next();
				for(int i=0;i<N;i++) goal[i]=in.next();
				
				int min = -1;
				String end=Integer.toString(Integer.MAX_VALUE,2).substring(0, L);
				
				String s="";
				
				// z=iteration number
outerLoop:		for(int z=0;end.compareTo(s)!=0;z++){
					
					int count = 0;

					//create the switches
					s=String.format("%"+L+"s", Integer.toString(z,2)).replace(' ', '0');
					for(char c:s.toCharArray()) if(c=='1') count++;
					
//System.out.println(s);
					for(int i=0;i<N;i++){
						boolean match=false;
innerLoop:				for(int j=0;j<N;j++){
							for(int k=0;k<L;k++){
								if((s.charAt(k)=='0'?flow[i].charAt(k):flow[i].charAt(k)=='0'?'1':'0')!=goal[j].charAt(k))
									continue innerLoop;//if modified flow != goal then try next goal
							}
							match=true;//if this point is reached goal = modified flow
							break;
						}
						if(!match) continue outerLoop;
					}
					
					//this point can only be reached if solution was found
					if(count<min||min<0) min=count;
				}
				
				if(min<0)
					ans="NOT POSSIBLE";
				else
					ans=Integer.toString(min);
				
				System.out.println("Case #" + iCase + ": "+ ans);
			}
	}

}
