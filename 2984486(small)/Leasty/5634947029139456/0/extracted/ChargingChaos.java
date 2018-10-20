/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;
import java.util.*;
import java.lang.*;
/**
 *
 * @author Tom
 */
public class ChargingChaos {
    private int number;
    private int length;
    private String[] current;
    private String[] goal;
    
    public static ChargingChaos[] readFile(Scanner input) {
        ChargingChaos[] puzzles = new ChargingChaos[input.nextInt()];
        
        for(int i = 0; i < puzzles.length; ++i) {
            int number = input.nextInt();
            int length = input.nextInt();
            input.nextLine();
            String[] current = input.nextLine().split(" ");
            String[] goal = input.nextLine().split(" ");
            puzzles[i] = new ChargingChaos(number, length, current, goal);
            System.out.println(number + " " + length);
            for(int j = 0; j < current.length; ++j) {
                System.out.println('"' + current[j] + '"');
            }

            for(int j = 0; j < goal.length; ++j) {
                System.out.println('"' + goal[j] + '"');
            }
        }
        
        return puzzles;
    }
    
    private ChargingChaos(int number, int length, String[] current, String[] goal) {
        this.number = number;
        this.length = length;
        this.current = current;
        this.goal = goal;
    }
    
    public String solve() {
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < (int)Math.pow(2, length); ++i) {
            int temp = i;
            int count = 0;
            char[][] currentChar = new char[number][length];
            for(int j = 0; j < current.length; ++j) {
                currentChar[j] = current[j].toCharArray();
            }
            for(int j = 0; j < length; ++j) {
                if((temp & 1) != 0) {
                    ++count;
                    for(int k = 0; k < currentChar.length; ++k) {
                        if(currentChar[k][j] == '0') {
                            currentChar[k][j] = '1';
                        } else {
                            currentChar[k][j] = '0';
                        }
                    }
                }
                temp /= 2;
            }
            
            String[] test = new String[number];
            boolean possible = true;
            for(int j = 0; j < number && possible; ++j) {
                test[j] = new String(currentChar[j]);
                boolean found = false;
                for(int k = 0; k < number && !found; ++k) {
                    found = test[j].equals(goal[k]);
                }
                possible = found;
            }
            
            if(possible) {
                min = Math.min(min, count);
            }
        }
        
        if(min != Integer.MAX_VALUE) {
            return "" + min;
        }
        
        return "NOT POSSIBLE";
    }
}
