import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


public class ChargingChaos {
	private static Queue<String> lines = new LinkedList<String>();

	public static void main(String[] args) throws Exception {
		FileInputStream fis = new FileInputStream(new File(args[0]));
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		
		String fileLine = null;
		while ((fileLine = br.readLine()) != null) {
			lines.add(fileLine);
		}
		br.close();
		
		int times = Integer.parseInt(lines.poll());
		PrintWriter writer = new PrintWriter("C:\\Users\\Shaun\\Desktop\\Code_Jam_1A_A-output.txt");
		
		for (int time=1;time<=times;time++) {
			String[] para = lines.poll().split(" ");
			int length = Integer.parseInt(para[1]);
			String maxStr="";
			for (int i=0;i<length; i++) {
				maxStr+="1";
			}
			long max = Long.parseLong(maxStr, 2);
			int numOutlets = Integer.parseInt(para[0]);
			
			System.out.println();
			List<String> iOutlets = Arrays.asList(lines.poll().split(" "));
			List<String> devices = Arrays.asList(lines.poll().split(" "));
			int numSwitches = -1;
			
			for (long switches=max; switches>=0;switches--) {
				char[] switchStr = toCharArray(Long.toBinaryString(switches), length);
				System.out.println(switchStr);
				List<String> outlets = new ArrayList<String>();
				for (String outletStr : iOutlets) {
					char[] outlet = toCharArray(outletStr, length);
					for (int a=0; a<switchStr.length; a++) {
						if (switchStr[a]=='1') {
							outlet[a]=((outlet[a]=='1')?'0':'1');
						}
					}
					outlets.add(String.valueOf(outlet));
				}
				for (int d=0;d<devices.size();d++) {
					for (int o=0;o<outlets.size();o++) {
						if (devices.get(d).equals(outlets.get(o))) {
							outlets.remove(o);
							o=outlets.size();
						}
					}
				}
				if (outlets.size()==0) {
					numSwitches=0;
					for (int a=0; a<switchStr.length; a++) {
						if (switchStr[a]=='1') {
							numSwitches++;
						}
					}
				}
			}
			if (numSwitches>=0) {
				writer.println("Case #"+time+": "+numSwitches);
			}else{
				writer.println("Case #"+time+": NOT POSSIBLE");
			}
		}
		writer.close();
	}
	
	private static char[] toCharArray(String str, int length) {
		char[] oldArray = str.toCharArray();
		char[] array = new char[length];
		int offset = oldArray.length-length;
		for (int i=0; i<length; i++) {
			if (offset+i<0) {
				array[i]='0';
			}else{
				array[i]=oldArray[i+offset];
			}
		}
		return array;
	}

}
