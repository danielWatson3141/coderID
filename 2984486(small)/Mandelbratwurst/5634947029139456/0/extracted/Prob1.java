package problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

import io.FrontJam;
//Mike Heald


public class Prob1 {
	FrontJam problemSet;
	int n;
	int eL;
	
	int cur[];
	int des[];
	
	String curStr[];
	String desStr[];
	
	int curOnes[];
	int desOnes[];

	
	int curFinal[];
	
	public Prob1(String file){
		problemSet = new FrontJam(file, 3);
	}
	

	
	public void solveSet(){
		for(int i = 0; i <problemSet.getNumberOfCases();i++){
			loadNextProblem();
			String answer = solve();
			problemSet.answerCurrentProblem(""+answer);
		}
		problemSet.closeFileOut();
	}
	
	public String solve(){
		//two cases when it is NOT POSSIBLE
		//1 - when not enough L to represent N so, 2^L<N not possible
		//2 - when the digits in each place are not equal or opposite in diversity... or something
		
		if(1<<eL < n){
			return "NOT POSSIBLE";
		}
		if(!checkCalcuble()){
			return "NOT POSSIBLE";
		}
		
		//how many steps?
		
		//could it just be # of mismatched places?
		int guess = bruteForce();
		
		
		if(!checkAnswer()){
			System.out.println("WRONG");
		}
		
		return guess+"";
	}
	
	public int bruteForce(){
		//try all flips 0 to 2^eL
		int min = 1<<eL+1;

		int tempCur[] = new int[n];
		tempCur = Arrays.copyOf(cur, n);
		for(int i = 0; i <1<<eL;i++){
			//i is the mask
			//flip all the numbers
			for(int j = 0; j < n; j++){
				tempCur[j] = applyNot(tempCur[j],i);
			}
			if(checkAnswer(tempCur)){
				if(countOnes(i) < min){
					min = countOnes(i);
					curFinal = tempCur;
				}
			}
			tempCur = Arrays.copyOf(cur, n);
			
		}
		
		cur = curFinal;
		if(min == 1<<eL+1){
			return 0;
		}
		return min;
	}
	
	
	public int countOnes(int in){
		
		return Integer.bitCount(in);
	}
	
	
	
	public int applyNot(int in, int mask){
		return in ^ mask;
	}
	
	public boolean checkAnswer(int cu[]){
		Arrays.sort(cu);
		Arrays.sort(des);
		
		return Arrays.equals(cu, des);
	}
	
	public boolean checkAnswer(){
		Arrays.sort(cur);
		Arrays.sort(des);
		
		return Arrays.equals(cur, des);
	}
	
	
	public int checkIdea(){
		int count = 0;
		for(int i = 0; i < eL; i++){
			if(curOnes[i] != desOnes[i]){
				count++;
			}
		}
		
		return count;
	}
	
	public boolean checkCalcuble(){
		for(int i = 0; i < eL; i++){
			if(curOnes[i] != desOnes[i] && curOnes[i] != Math.abs(n-desOnes[i])){
				return false;
			}
		}
		
		return true;
	}
	
	public void countOnes(){
		int cur1 = 0;
		int des1 = 0;
		for(int i = 0 ; i < eL; i ++){
			for(int j = 0 ; j < n; j++){
				if(curStr[j].charAt(i) == '1'){
					cur1++;
				}
				if(desStr[j].charAt(i) == '1'){
					des1++;
				}
			}
			curOnes[i] = cur1;
			desOnes[i] = des1;
			cur1=0;
			des1=0;
		}
	}
	
	public void loadNextProblem(){
		String prob = problemSet.getNextProblem();
		String splitSet[] = prob.split("\n");
		String splitNL[] =splitSet[0].split(" ");
		n = Integer.parseInt(splitNL[0]);
		eL = Integer.parseInt(splitNL[1]);
		
		String splitCur[] = splitSet[1].split(" ");
		String splitDes[] = splitSet[2].split(" ");
		curStr = splitCur;
		desStr = splitDes;
		cur = new int[n];
		des = new int[n];
		curOnes = new int[eL];
		desOnes = new int[eL];
		curFinal = new int[n];
		//convert to integer
		for(int i = 0; i < n; i++){
			cur[i] = Integer.parseInt(splitCur[i],2);
			des[i] = Integer.parseInt(splitDes[i],2);
		}
		countOnes();
	}
}
