package com.my.algo.gcj2014.r1a;

import java.util.*;
import java.io.*;

public class A {
	class Node {
		boolean[] mark;
		HashSet<Long> outlets;
		int startIndex;
		
		Node(int length, int startIndex, HashSet<Long> outlets){
			this.mark = new boolean[length + 1];			
			this.outlets = outlets;
			this.startIndex = startIndex;
		}
	}
	
    final static String PROBLEM_NAME = "A";
    final static String WORK_DIR = "D:\\GCJ\\2014\\r1a\\" + PROBLEM_NAME + "\\";
    final static String INPUT_FILE = "A-small-attempt0.in";

    void solve(Scanner sc, PrintWriter pw) {
    	HashSet<Long> outlets = new HashSet<Long>();
    	HashSet<Long> devices = new HashSet<Long>();
    	HashSet<Long> tmp;
    	int numOfDevices = sc.nextInt();
    	int length = sc.nextInt();
    	int numOfFlips = 0;
    	Deque<Node> queue = new LinkedList<Node>();
    	
    	for(int i = 0; i < numOfDevices; i++){
    		outlets.add(Long.valueOf(sc.next(), 2));
    	}
    	
    	for(int i = 0; i < numOfDevices; i++){
    		devices.add(Long.valueOf(sc.next(), 2));
    	}
    	
    	//No flips
    	if(outlets.equals(devices)){
			System.out.println("0");
			pw.println("0");
			return;
		}
    	
    	//1 flip
    	for(int i = 1; i <= length; i++){
    		tmp = negateIthBitForWholeSet(outlets, i);
    		if(tmp.equals(devices)){
    			System.out.println("1");
    			pw.println("1");
    			return;
    		} else {
    			Node node = new Node(length, i, tmp);
    			node.mark[i] = true;
    			queue.addLast(node);
    		}
    	}
    	
    	while(!queue.isEmpty()){
    		Node node = queue.removeFirst();
    		for(int i = node.startIndex + 1; i <= length; i++){
    			if(node.mark[i] == false){
    				tmp = negateIthBitForWholeSet(node.outlets, i);
    				if(tmp.equals(devices)){
    					int counter = 0;
    					for(int j = 1; j <= length; j++){
    						if(node.mark[j] == true){
    							counter++;
    						}
    					}
    					System.out.println(counter + 1);
    					pw.println(counter + 1);
    					return;
    				} else {
    					Node newNode = new Node(length, node.startIndex, tmp);
    					newNode.mark = Arrays.copyOf(node.mark, length + 1);
    					newNode.mark[i] = true;
    					queue.addLast(newNode);
    				}
    			}
    		}
    		
    	}
    	
    	System.out.println("NOT POSSIBLE");
    	pw.println("NOT POSSIBLE");
    }
    
    HashSet<Long> negateIthBitForWholeSet(HashSet<Long> set, int i){
    	HashSet<Long> newSet = new HashSet<Long>();
    	
    	for(Long l: set){
    		newSet.add(negateIthBit(l, i));
    	}
    	
    	return newSet;
    }
    
    long negateIthBit(long l, int i){
    	long result = -1;
    	
    	if(i == 0){
    		result = l;
    	} else if (i > 0){
    		result = l ^ (1 << (i - 1));
    	}
    	
    	return result;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + INPUT_FILE));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new A().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}