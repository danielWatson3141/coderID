import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: yilin
 * Date: 14-4-25
 * Time: 下午8:05
 * To change this template use File | Settings | File Templates.
 */
public class Charging {

    public static int[] checkPossibleSwitch(int[] outlet, int[] charger,int l){
        int n = outlet.length;
        int[] oneInCharger=new int[l];
        int[] oneInOutlet= new int[l];
        int[] switched = new int[l];
        for(int i =l-1;i>=0;i--){
            int num = 1<<i;
            for(int j=0;j<n;j++){
                int temp = charger[j] & num;
                if ( temp!=0){
                    oneInCharger[i]++;
                }
                temp =  outlet[j] & num;
                if (temp !=0){
                    oneInOutlet[i]++;
                }
            }
            if (oneInOutlet[i] == oneInCharger[i]){
                if(oneInOutlet[i] == n-oneInCharger[i]){
                    switched[l-1-i]=2;
                }else{
                    switched[l-1-i]=0;
                }
            }else if (oneInOutlet[i] == n-oneInCharger[i]){
                switched[l-1-i]=1;
            }else{
                return null;
            }
        }
        return switched;
    }

    public static int checkPossbility(int switched, String bigStrCharger ,int[] outlet){
        List<String> outlets = new ArrayList();
        for(int i : outlet){
            outlets.add(Integer.toBinaryString(i^switched));
        }
        Collections.sort(outlets);

        String bitStrOutlet = "";
        for(String i : outlets){
            bitStrOutlet+=i;
        }
        if(bigStrCharger.equals(bitStrOutlet)){
            int k =0;
            for(char c : Integer.toBinaryString(switched).toCharArray()){
                if (c == '1')
                    k++;
            }
            return k;
        }else{
            return -1;
        }

    }

    public static int loopForSwitched(int[] charger, int[] outlet, int l){
        List<String> chargers = new ArrayList();
        for(int i : charger){
            chargers.add(Integer.toBinaryString(i));
        }
        Collections.sort(chargers);
        String bigStrCharger = "";
        for(String i : chargers){
            bigStrCharger+=i;
        }
        int[] switches = checkPossibleSwitch(charger,outlet,l);
        Set<String> pos;
        String swStr = "";
        if(switches == null)
            return -1;
        for(int i : switches){
            swStr+=i;
        }
        pos = checkSwitches(swStr);

        int min = -1;
        for(String str : pos){
            int sw = Integer.parseInt(str,2);
            int k = checkPossbility(sw,bigStrCharger,outlet);
            if( k!= -1){
                if (min == -1 || min >k){
                    min = k;
                }
            }
        }
        return min;

    }

    private static Set<String> checkSwitches(String switches) {
        int pos = switches.indexOf('2');
        Set<String> result = new HashSet<String>();
        if(pos == -1){
            result.add(switches);
            return result;
        }
        for(String str : checkSwitches(switches.substring(pos+1))){
            result.add(switches.substring(0,pos)+'1'+str);
            result.add(switches.substring(0,pos)+'0'+str);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileReader("input"));
        PrintWriter writer = new PrintWriter("result");
        input.nextLine();
        int counter =0;
        while(input.hasNext()){
            counter++;
            int l = Integer.parseInt(input.nextLine().split(" ")[1]);

            String[] outlets = input.nextLine().split(" ");
            String[] chargers = input.nextLine().split(" ");
            int[] ol = new int[outlets.length];
            int[] cg = new int[chargers.length];
            for(int i =0;i< ol.length;i++){
                ol[i] = Integer.parseInt(outlets[i],2);
                cg[i] = Integer.parseInt(chargers[i],2);
            }
            int k = loopForSwitched(cg,ol,l);
            if (k!= -1)
                System.out.println("Case #"+counter+": "+k);
            else
                System.out.println("Case #"+counter+": NOT POSSIBLE");

            //writer.printf("%d %d %d \n",r,c,m);

        }
        //writer.close();
    }
}
