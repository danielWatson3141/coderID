package com.badal.util;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public abstract class AbstractProblem {

	protected List<String> output = new ArrayList<>();
	
	public List<String> getOutput(){
		return this.output;
	}
	
	public void generateOutputForInput(String fileName) throws Exception{
		this.solve(new BufferedReader(new FileReader(new File(fileName))));
		
		File outputFile = new File(fileName + ".out");
		
		FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
		BufferedWriter bw = new BufferedWriter(fw);
		for (String str : this.output) {
			bw.append(str);
			bw.newLine();
		}
		bw.flush();
		bw.close();
	}

	public abstract void solve(BufferedReader bufferedReader) throws Exception;
}
