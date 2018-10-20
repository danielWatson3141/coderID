package A1
/**
 * Created by Robert on 12.04.2014.
 */
public class MainA {

    static BufferedWriter out = new File("output.txt").newWriter()

    public static void main(String[] args) {
        List<String> lines = new File("A-small-attempt0.in").text.split("\n").toList().collect { it.trim() }
        List cases = lines.drop(1).collate(3)
        int x = 1
        for (List<String> _case : cases) {
            solveCase(_case, x)
            x++
        }
        out.close()
    }

    static void solveCase(List<String> c, int i) {
        List<String> flow = c[1].split(" ")
        List<String> devices = c[2].split(" ")
        int nDevices = flow.size()
        int flowLength = flow[0].length()

        Map<String, List<SwitchState>> states = [:]
        for (int x = 0; x < nDevices; x++) {
            List<SwitchState> list = []
            for (int y = 0; y < nDevices; y++) {
                list.add(new SwitchState(switchFlow: flow[x], deviceFlow: devices[y]))
            }
            states[flow[x]] = list
        }

        List<SwitchState> result = states.values()[0]
        for (List<SwitchState> list : states.values()) {
            result.retainAll(list)
        }

        if (result.empty) {
            out.writeLine("Case #${i}: NOT POSSIBLE")
        } else {
            out.writeLine("Case #${i}: ${(result*.flippedSwitches*.size()).min()}")
        }
    }

    private static class SwitchState {
        String switchFlow
        String deviceFlow
        private List<Integer> flippedSwitches

        List<Integer> getFlippedSwitches() {
            if (flippedSwitches == null) {
                flippedSwitches = []
                for (int x = 0; x < switchFlow.length(); x++) {
                    if (switchFlow.charAt(x) != deviceFlow.charAt(x))
                        flippedSwitches.add(x)
                }
            }
            return flippedSwitches
        }

        @Override
        public boolean equals(Object o) {
            if (o instanceof SwitchState) {
                return o.flippedSwitches.equals(flippedSwitches)
            }
            return false
        }
    }
}
