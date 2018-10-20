import java.util.*;
public class C {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d: %s\n", i, solve());
        }
    }
    public static String solve() {
        int n = s.nextInt();
        int[] aux = new int[1000];
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = s.nextInt();
        }
        if (countInversions(0, 1000, arr, aux) < 245410) {
            return "BAD";
        } else {
            return "GOOD";
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static int countInversions(int lo, int hi, int[] arr, int[] aux) {
        if (hi - lo == 1) {
            return 0;
        }
        int mid = (lo + hi) / 2;
        return countInversions(lo, mid, arr, aux) + countInversions(mid, hi, arr, aux) + merge(lo, mid, hi, arr, aux);
    }

    public static int merge(int lo, int mid, int hi, int[] arr, int[] aux) {
        int i = lo;
        int j = mid;
        int count = 0;
        int nl = mid - lo;
        int rl = hi - mid;
        for (int k = 0; k < nl+rl; k++) {
            if (i != mid && (j == hi || (arr[i] < arr[j]))) {
                aux[k] = arr[i];
                i++;
            } else {
                aux[k] = arr[j];
                j++;
                count += mid - i;
            }
        }
        for (int k = 0; k < (hi - lo); k++) {
            arr[lo+k] = aux[k];
        }
        return count;
    }
}
