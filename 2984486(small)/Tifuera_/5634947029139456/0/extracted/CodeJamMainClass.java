package contest;

import java.io.*;

public class CodeJamMainClass {

    private final static String IN_FOLDER = "cj";
    private final static String IN_SUFFIX = ".in";

    public static void main(String[] args) throws IOException {

        InputStreamReader inputStream = getInFile();

        InputReader in = new InputReader(inputStream);

        final int T = in.nextInt();
        String[] result = new String[T];

        for (int i = 0; i < T; i++) {
            result[i] = new TaskA().solve(in);
        }

        File outFile = new File(IN_FOLDER, "result.out");

        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(outFile)))) {
            for (int i = 0; i < T; i++) {
                pw.println(String.format("Case #%s: %s", i + 1, result[i]));
            }
        }
    }

    private static InputStreamReader getInFile() throws FileNotFoundException {
        File inFolder = new File(IN_FOLDER);

        File[] inFiles = inFolder.listFiles(new InFileFilter());

        if (inFiles.length != 1) {
            throw new RuntimeException("Illegal number of in files " + inFiles.length);
        }

        return new InputStreamReader(new FileInputStream(inFiles[0]));
    }


    private static class InFileFilter implements FilenameFilter {

        @Override
        public boolean accept(File dir, String name) {
            return name.endsWith(IN_SUFFIX);
        }
    }

    public static class InputReader {
        public BufferedReader reader;
        private String[] currentArray;
        int curPointer;

        public InputReader(InputStreamReader inputStreamReader) {
            reader = new BufferedReader(inputStreamReader);
        }

        public String next() {
            try {
                currentArray = null;
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public int nextInt() {
            if ((currentArray == null) || (curPointer >= currentArray.length)) {
                try {
                    currentArray = reader.readLine().split(" ");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                curPointer = 0;
            }
            return Integer.parseInt(currentArray[curPointer++]);
        }

        public long nextLong() {
            if ((currentArray == null) || (curPointer >= currentArray.length)) {
                try {
                    currentArray = reader.readLine().split(" ");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                curPointer = 0;
            }
            return Long.parseLong(currentArray[curPointer++]);
        }

        public double nextDouble() {
            if ((currentArray == null) || (curPointer >= currentArray.length)) {
                try {
                    currentArray = reader.readLine().split(" ");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                curPointer = 0;
            }
            return Double.parseDouble(currentArray[curPointer++]);
        }
    }
}
