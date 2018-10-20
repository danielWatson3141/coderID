package contest;

import java.util.Arrays;

public class TaskB {

    boolean[][] graph;
    int N;
    boolean[] absent;
    boolean[] dfsVis;
    int[] ord;

    public String solve(CodeJamMainClass.InputReader in) {
        N = in.nextInt();
        graph = new boolean[N][N];
        ord = new int[N];
        for (int i = 0; i < N-1; i++) {
            int X = in.nextInt() - 1;
            int Y = in.nextInt() - 1;

            graph[X][Y] = true;
            graph[Y][X] = true;
            ord[X]++;
            ord[Y]++;
        }

        int res = N - 1;
        for (int i = 0; i < (1 << N) - 1; i++) {
            if (isPossible(i)) {
                int cur = 0;
                for (int j = 0; j < N; j++) {
                    if(absent[j]){
                        cur++;
                    }
                }
                res = Math.min(res, cur);
            }
        }

        return String.valueOf(res);
    }

    private boolean isPossible(int del) {
        absent = new boolean[N];
        for (int i = 0; i < N; i++) {
            if ((del & (1 << i)) != 0) {
                absent[i] = true;
            }
        }

        return isBinaryTree();
    }

    private boolean isBinaryTree() {
        //check is connected
        dfsVis = Arrays.copyOf(absent, N);

        int ver = -1;
        for (int i = 0; i < N; i++) {
            if (!dfsVis[i]) {
                ver = i;
                break;
            }
        }

        dfs(ver);
        for (boolean vv : dfsVis) {
            if (!vv) {
                return false;
            }
        }

        int[] ordCopy = updateOrd();

        Arrays.sort(ordCopy);
        if (ordCopy[N - 1] > 3) {
            return false;
        }


        int[] nums = new int[4];
        for (int i = 0; i < ordCopy.length; i++) {
            nums[ordCopy[i]]++;
        }

        if (nums[2] != 1) {
            return false;
        }

        return true;
    }

    private void dfs(int cur) {
        for (int i = 0; i < N; i++) {
            if (graph[cur][i]) {
                if (!dfsVis[i]) {
                    dfsVis[i] = true;
                    dfs(i);
                }
            }
        }
    }

    private int[] updateOrd() {
        int[] ordCopy = Arrays.copyOf(ord, N);

        for (int i = 0; i < N; i++) {
            if (absent[i]) {
                ordCopy[i] = 0;
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (absent[j] && graph[i][j]) {
                    ordCopy[i]--;
                }
            }
        }
        return ordCopy;
    }
}
