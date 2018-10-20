import java.util.Arrays;
import java.util.Scanner;

public class ChargingChaos {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for (int i = 1; i <= cases; i++) {
            int devices = scanner.nextInt();
            int bits = scanner.nextInt();

            int[] outputs = getList(scanner, devices, bits);
            int[] required = getList(scanner, devices, bits);

            Arrays.sort(required);

            System.out.print("Case #" + i + ": ");
            int result = calculate(outputs, required);
            if (result == 999) System.out.println("NOT POSSIBLE");
            else System.out.println(result);
        }
        scanner.close();
    }

    private static int calculate(int[] outputs, int[] required) {
        int steps = 999;
        for (int s : required) {
            for (int output : outputs) {
                int tmp = possible(outputs, required, s ^ output);
                if (tmp < steps) steps = tmp;
            }
        }
        return steps;
    }

    private static int possible(int[] outputs, int[] requried, int diff) {
        int[] switched = new int[outputs.length];
        for (int i = 0; i < outputs.length; i++) {
            switched[i] = outputs[i] ^ diff;
        }
        Arrays.sort(switched);
        if (Arrays.equals(switched, requried)) {
            return countOnes(diff);
        }
        return 999;
    }

    private static int countOnes(int diff) {
        int count = 0;
        while (diff != 0) {
            if ((diff & 0x01) != 0) ++count;
            diff >>= 1;
        }
        return count;
    }

    private static int[] getList(Scanner scanner, int devices, int bits) {
        int[] num = new int[devices];
        for (int j = 0; j < devices; j++) {
            String pattern = scanner.next();
            int tmp = 0;
            for (int i = 0; i < bits; i++) {
                tmp += ((int) pattern.charAt(i) - 48) * Math.pow(2, bits - i - 1);
            }
            num[j] = tmp;
        }
        return num;
    }


}
