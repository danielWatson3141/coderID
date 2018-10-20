
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by lin on 4/15/14.
 */
public class InputHandler {
    public static void main(String[] args) {
        try {
            BufferedReader br =
                    new BufferedReader(new InputStreamReader(System.in));
            String line = br.readLine();

            int caseCount = 1;

            while ((line = br.readLine()) != null) {
                line = br.readLine();
                String[] tokens = line.split(" ");
                List<StringBuilder> outlets = new ArrayList<StringBuilder>();
                List<String> devices = new ArrayList<String>();

                for(String token : tokens) {
                    outlets.add(new StringBuilder(token));
                }

                line = br.readLine();
                tokens = line.split(" ");
                for(String token : tokens) {
                    devices.add(token);
                }

                int ret = ASolution.solve(outlets, devices);


                if(ret >=0 ) {
                    System.out.println("Case #" + caseCount + ": " + ret );
                } else {
                    System.out.println("Case #" + caseCount + ": NOT POSSIBLE" );

                }
                caseCount++;

            }

        } catch (IOException io) {
            io.printStackTrace();
        }
    }
}
