package com.smileyhall;

/**
 *
 * @author Dave
 */
import java.io.*;
import java.util.*;

public class Charging {
  public static String INSTANCE = "sm";
  
  int caseNum;
  String result;
  int N; // num devices
  int L; // num bits
  int[] flow;
  int[] originalFlow;
  int[] device;
  int[] matched;
  
  public Charging(int caseNum, String NL, String flows, String devices) {
    this.caseNum = caseNum;
    String[] NLStr = NL.split(" ");
    this.N = Integer.parseInt(NLStr[0]);
    this.L = Integer.parseInt(NLStr[1]);
    this.matched = new int[N];
    
    String[] flowsStr = flows.split(" ");
    flow = new int[N];
    for (int i=0; i<N; i++) {
      flow[i] = Integer.parseInt(flowsStr[i], 2);
    }
    Arrays.sort(flow);
    originalFlow = Arrays.copyOf(flow, flow.length);
    
    String[] devicesStr = devices.split(" ");
    device = new int[N];
    for (int i=0; i<N; i++) {
      device[i] = Integer.parseInt(devicesStr[i], 2);
    }
    Arrays.sort(device);
    //result = N+", "+L+" ";
    result = "";
    
    /*
    for (int i=0; i<N; i++) {
      System.out.print(flow[i]+" ");
    }
    System.out.println();
    for (int i=0; i<N; i++) {
      System.out.print(device[i]+" ");
    }
    System.out.println("\n--");
    */
  }
  
  public void run() {
    int bitCount = (int)Math.pow(2, L);
    int numBitFlips = bitCount;
    for (int k=0; k<bitCount; k++) { //try 2^N bit flips
      if (Arrays.equals(flow, device) && Integer.bitCount(k)<numBitFlips) numBitFlips = Integer.bitCount(k);
      if (numBitFlips==1) break;
      //System.out.println("--");
      flipBits(k+1);
    }
    if (numBitFlips<bitCount) result = ""+numBitFlips;
    else result = "NOT POSSIBLE";
  }
  
  public void flipBits(int n) {
    
    //System.out.print(" flipBits ("+n+")");
    for (int i=0; i<N; i++) {
      flow[i] = originalFlow[i]^n;
    }
    Arrays.sort(flow);
  }
  
  public int count(int[] b) {
    int count = 0;
    for (int i=0; i<b.length; i++) if (b[i]>0) count++;
    return count;
  }
  
  public String toString() {
    return "Case #"+this.caseNum+": "+result;
  }
  
  public static void main(String[] args) {
    
    try {
      Class currentClass = new Object() { }.getClass().getEnclosingClass();
      String inputFileName = "inputs/"+currentClass.getSimpleName().toLowerCase()+"_"+INSTANCE+".in";
      String outputFileName = "inputs/"+currentClass.getSimpleName().toLowerCase()+"_"+INSTANCE+".out";
      System.out.println(inputFileName);
      //String inputFileName = "C:\\Projects\\CodeJam\\inputs\\cookie_lg.in";
      PrintWriter out = new PrintWriter(outputFileName);
      BufferedReader in = new BufferedReader(new FileReader(inputFileName));
      int numTestCases = Integer.parseInt(in.readLine());
      for (int i=0; i<numTestCases; i++) {
        //System.out.println(line);
        Charging c = new Charging((i+1), in.readLine(), in.readLine(), in.readLine());
        c.run();
        System.out.println(c);
        out.println(c);
      }
      in.close();
      out.close();
      
    } catch(Exception ex) {
      ex.printStackTrace();
    }
  }
  
}
