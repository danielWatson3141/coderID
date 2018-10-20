package com.skidson.codejam;

import java.io.BufferedReader;
import java.io.IOException;

public abstract class Test {
	
	protected BufferedReader in;
	
	public Test(BufferedReader in) {
		this.in = in;
	}
	
	public abstract String run() throws IOException;
	
}
