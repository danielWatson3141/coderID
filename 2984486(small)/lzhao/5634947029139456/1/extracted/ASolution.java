import java.util.*;

/**
 * Created by lin on 4/23/14.
 */
public class ASolution {

    /**
     * Before step are possible. What of the rest?
     *
     * @param outlets
     * @param devices
     * @param step
     * @return
     */
    private static int solveHelper(List<StringBuilder> outlets, List<String> devices, int step) {
        //System.out.println(Arrays.toString(outlets.toArray()) + " " + Arrays.toString(devices.toArray()));

        if (step >= outlets.get(0).length()) {
            Set<String> dSet = new HashSet<String>();
            Set<String> oSet = new HashSet<String>();
            for (StringBuilder out : outlets) {
                oSet.add(out.toString());

            }

            for (String d : devices) {
                if (!oSet.contains(d)) {
                    return -100;
                }
            }
            return 0;

        }

        if(step > 0) {
            Set<String> oSet = new HashSet<String>();
            for(StringBuilder sb : outlets) {
                oSet.add(sb.substring(0, step));
            }
            for(String s : devices) {
                if(!oSet.contains(s.substring(0, step))) {
                    return -100;
                }
            }


        }

        int oOnes = 0;
        int dOnes = 0;
        for (int i = 0; i < outlets.size(); ++i) {
            if (outlets.get(i).charAt(step) == '1') {
                oOnes++;

            }

            if (devices.get(i).charAt(step) == '1') {
                dOnes++;
            }
        }

        if (oOnes == dOnes) {
            int ret = solveHelper(outlets, devices, step + 1);

            //Doesn't need to switch this one.
            if (oOnes * 2 == outlets.size()) {
                //May swap
                List<StringBuilder> copiedOutlets = new ArrayList<StringBuilder>(outlets);
                for (int j = 0; j < copiedOutlets.size(); ++j) {
                    char oChar = outlets.get(j).charAt(step);
                    char nChar = oChar == '1' ? '0' : '1';
                    StringBuilder newSB = new StringBuilder(outlets.get(j));
                    newSB.setCharAt(step, nChar);
                    copiedOutlets.set(j, newSB);
                }

                int ret1 = solveHelper(copiedOutlets, devices, step + 1);
                if (ret1 >= 0 && (ret < 0 || ret1 + 1 < ret)) {
                    ret = ret1 + 1;
                }

            }

            return ret;

        } else if (outlets.size() - oOnes == dOnes) {
            //Can do a switch
            List<StringBuilder> copiedOutlets = new ArrayList<StringBuilder>(outlets);
            for (int j = 0; j < copiedOutlets.size(); ++j) {
                char oChar = outlets.get(j).charAt(step);
                char nChar = oChar == '1' ? '0' : '1';
                StringBuilder newSB = new StringBuilder(outlets.get(j));
                newSB.setCharAt(step, nChar);
                copiedOutlets.set(j, newSB);
            }

            int ret1 = solveHelper(copiedOutlets, devices, step + 1);
            if (ret1 >= 0) {
                return ret1 + 1;
            } else {
                return ret1;
            }

        }


        return -100;
    }

    public static int solve(List<StringBuilder> outlets, List<String> devices) {
        return solveHelper(outlets, devices, 0);
    }
}
