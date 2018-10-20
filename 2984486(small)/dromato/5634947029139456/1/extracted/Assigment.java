package assigment;

import java.io.IOException;

public class Assigment {

	public static void main(String[] args) throws IOException {
		ConcreteTestCaseIO testCaseIO = new ConcreteTestCaseIO("D:\\codejam\\a1\\A-large.in", "D:\\codejam\\a1\\output.txt");
		testCaseIO.doStuff();
	}

}
