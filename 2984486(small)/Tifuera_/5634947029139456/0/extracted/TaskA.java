package contest;

import java.util.Arrays;

public class TaskA {

    public String solve(CodeJamMainClass.InputReader in) {
        int N = in.nextInt();
        int L = in.nextInt();

        String[] initialStr = in.next().split(" ");
        String[] devicesStr = in.next().split(" ");

        int[] initial = new int[N];
        int[] device = new int[N];
        for (int i = 0; i < N; i++) {
            initial[i] = Integer.parseInt(initialStr[i], 2);
            device[i] = Integer.parseInt(devicesStr[i], 2);
        }
        Arrays.sort(device);
        int res = Integer.MAX_VALUE;

        for (int i = 0; i < (1 << L); i++) {
            int[] initialModified = Arrays.copyOf(initial, N);

            int cur = 0;
            for (int j = 0; j < L; j++) {
                if ((i & (1 << j)) != 0) {
                    cur++;

                    for (int k = 0; k < N; k++) {
                        initialModified[k] = initialModified[k] ^ (1 << j);
                    }
                }
            }

            if (cur < res) {
                Arrays.sort(initialModified);
                if (Arrays.equals(initialModified, device)) {
                    res = cur;
                }
            }
        }

        if (res < Integer.MAX_VALUE) {
            return String.valueOf(res);
        } else {
            return "NOT POSSIBLE";
        }
    }
}
