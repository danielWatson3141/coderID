package assigment;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Arrays;

import codejam.war.TestCaseIO;

public class ConcreteTestCaseIO extends TestCaseIO {

	public ConcreteTestCaseIO(String inputPath, String outputPath) {
		super(inputPath, outputPath);
	}

	@Override
	protected ConcreteTestCase generateTestCase(BufferedReader file) {
		String[] outletsStr = null;
		String[] nAndL = null;
		String[] devicesStr = null;
		try {
			nAndL = file.readLine().split(" ");
			outletsStr = file.readLine().split(" ");
			devicesStr = file.readLine().split(" ");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return new ConcreteTestCase(Integer.valueOf(nAndL[0]), Integer.valueOf(nAndL[1]), devicesStr, outletsStr);
	}

}
