import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;


public class Temp {


   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int numTimes, counter = 0, numLines;
      LinkedList<char[]> nums;
      LinkedList<char[]> volts;
      int num, len;
      int best, moves;
      boolean found = false;
      
      numTimes = sc.nextInt();
      
      
      while(counter++ < numTimes) {
         best = 0;
         found = false;
         num = sc.nextInt();
         len = sc.nextInt();
         volts = new LinkedList<char[]>();
         nums = new LinkedList<char[]>();
         best = len+1;
         
         for(int i = 0; i < num; i++) {
            char[] tmp = ("" + sc.next()).toCharArray();
            volts.add(tmp);
         }
         for(int i = 0; i < num; i++) {
            char[] tmp = ("" + sc.next()).toCharArray();
            nums.add(tmp);
         }
         
         char[] first;
         LinkedList<char[]> check;
         
         for(int i = 0; i < num; i++) {
            moves = 0;
            LinkedList<char[]> revert = new LinkedList<char[]>();
            for(int o = 0; o < num; o ++) {
               revert.add(volts.get(o).clone());
            }
            
            first = revert.getFirst();
            check = new LinkedList<char[]>();

            for(int j = 0; j < len; j++) {
               char[] tmp = nums.get(i);

               if(tmp[j] != first[j]) {
                  moves++;
                  for(int k = 0; k < num; k++) {
                     if(revert.get(k)[j] == '0') {
                        revert.get(k)[j] = '1';
                     } else {
                        revert.get(k)[j] = '0';
                     }
                  }
               }
            }
            
            for(int o = 0; o < num; o ++) {
               check.add(revert.get(o));
            }
            
            for(int t = 0; t < num; t++){
               for(int l = 0; l < check.size(); l++){
                  if(Arrays.equals(check.get(l), nums.get(t))) {
                     check.remove(l);
                     break;
                  }
               }
            }

            if(check.isEmpty()) {
               found = true;
               if(moves <= best) {
                  best = moves;
               }
            }
         }
         if(found == false) {
            System.out.println("Case #"+counter+": NOT POSSIBLE");
         } else {
            System.out.println("Case #"+counter+": " + best);
         }
      
      }

   }

}
