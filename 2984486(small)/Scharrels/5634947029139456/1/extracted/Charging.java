import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.*;

public class Charging {
    Scanner input;
    PrintWriter output;
    private String[] devices;
    private String[] outlets;

    public Charging(Scanner input, PrintWriter output){
        this.input = input;
        this.output = output;

    }

    public void solveProblem(int testCase){
        int numOutlets = input.nextInt();
        int numSwitches = input.nextInt();

        devices = new String[numOutlets];
        outlets = new String[numOutlets];

        for(int device = 0; device < numOutlets; device++){
            devices[device] = input.next();
        }
        for(int outlet = 0; outlet < numOutlets; outlet++){
            outlets[outlet] = input.next();
        }

        int minLength = numSwitches + 1;

        // test: flip switches to fit device 1 on outlet n
        for(int outlet = 0; outlet < numOutlets; outlet++){
            String difference = fitToOutlet(devices[0], outlets[outlet]);
            if(numDifferences(difference) >= minLength) continue; // no improvement
            List<String> newOutlets = flipSwitches(difference);
            if(solutionFits(newOutlets)){
                minLength = numDifferences(difference);
            }
        }
        if(minLength > numSwitches){
            output.println("Case #" + testCase + ": NOT POSSIBLE");
        } else {
            output.println("Case #" + testCase + ": " + minLength);
        }
    }

    private boolean solutionFits(List<String> newOutlets){
        for(String device : devices){
            if(newOutlets.contains(device)){
                newOutlets.remove(device);
            } else {
                return false;
            }
        }
        return true;
    }

    private List<String> flipSwitches(String difference) {
        List<String> newOutlets = new ArrayList<>();
        for(int outlet = 0; outlet < outlets.length; outlet++){
            String newOutlet = "";
            for(int i = 0; i < difference.length(); i++){
                if(difference.charAt(i) == '0'){
                    newOutlet += outlets[outlet].charAt(i);
                } else {
                    newOutlet += outlets[outlet].charAt(i) == '0' ? '1' : '0';
                }
            }
//            System.out.print(newOutlet + " ");
            newOutlets.add(newOutlet);
        }
//        System.out.println();
        return newOutlets;
    }

    private int numDifferences(String difference) {
        int count = 0;
        for(int i = 0; i < difference.length(); i++){
            count += difference.charAt(i) == '1' ? 1 : 0;
        }
        return count;
    }

    private String fitToOutlet(String device, String outlet) {
        String difference = "";
        for(int i = 0; i < device.length(); i++){
            difference += device.charAt(i) == outlet.charAt(i) ? '0' : '1';
        }
        return difference;
    }

    public static void main(String[] args){
        final long startTime = System.currentTimeMillis();
        File file = new File("charging.in");
        Scanner input = null;
        try {
            input = new Scanner(file).useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        PrintWriter output = null;
        try {
            output = new PrintWriter("charging.out", "UTF-8");
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        int problems = input.nextInt();
        input.nextLine();
        for(int i = 1; i <= problems; i++){
            new Charging(input, output).solveProblem(i);
        }
        output.close();
        final long endTime = System.currentTimeMillis();
//        System.out.println("Total execution time: " + (endTime - startTime) + " ms");
    }
}
