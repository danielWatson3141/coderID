package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.TreeSet;

public class Charging {

	
	public Charging(){
	}
	
	public boolean correct_check(ArrayList<String> sockets,TreeSet<String> devices){
		for (String each : sockets){
			if (! devices.contains(each)){
				return false;
			}
		}
		return true;
	}
	
	public String bitflip(String s,int index){
		char curr=s.charAt(index);
		if (curr=='1'){
			curr='0';
		}
		else{
			curr='1';
		}
		return s.substring(0,index)+curr+s.substring(index+1);
	}
	
	public String multiple_flips(String s, ArrayList<Integer> moves){
		for (int move : moves){
			s=bitflip(s, move);
		}
		return s;
	}
	
	public int helper(String NL,String s_flow_have,String s_flow_req){
		HashMap<String,Boolean> done=new HashMap<String,Boolean>();;
		ArrayList<ArrayList<Integer>> new_queue=new ArrayList<ArrayList<Integer>>();
		ArrayList<ArrayList<Integer>> old_queue=new ArrayList<ArrayList<Integer>>();
		ArrayList<String> sockets=new ArrayList<String>();
		ArrayList<String> new_sockets=new ArrayList<String>();
		ArrayList<String> old_sockets=new ArrayList<String>();
		TreeSet<String> devices=new TreeSet<String>();
		ArrayList<Integer> moves=new ArrayList<Integer>();
		ArrayList<Integer> Q_moves_copy;
		int steps=0;
		
		int N=0;
		int L=0;
		String temp;
		
		for (int i=0;i<NL.length();i++){
			if (NL.charAt(i)==' '){
				N=Integer.parseInt(NL.substring(0,i));
				L=Integer.parseInt(NL.substring(i+1));
			}
		}
		
		for (int i=0;i<N;i++){
			temp=s_flow_have.substring((L+1)*i,(L+1)*i+L);
			sockets.add(temp);
		}
		
		for (int i=0;i<N;i++){
			temp=s_flow_req.substring((L+1)*i,(L+1)*i+L);
			devices.add(temp);
		}
		
		if (correct_check(sockets,devices)) return steps;
		
		steps++;
		
		String s_move;
		for (int i=0;i<L;i++){ //step 1: flip 1 at i
			new_sockets=new ArrayList<String>();
			old_sockets=new ArrayList<String>(sockets);
			for (String each : old_sockets){
				each=bitflip(each,i);
				new_sockets.add(each);
			}
			if (correct_check(new_sockets,devices)) return steps;
			moves=new ArrayList<Integer>();
			moves.add(i);
			old_queue.add(moves);
			Collections.sort(moves);
			s_move="";
			for (int move : moves){
				s_move+=move;
			}
			//check first
			done.put(s_move, true);
		}
		
		steps++;
		while(steps<=L){
			new_queue=new ArrayList<ArrayList<Integer>>();
			for (int i=0;i<L;i++){ //step "steps": flip at i
				for (ArrayList<Integer> Q_moves : old_queue){
					//check repeat
					if (Q_moves.contains(i)) continue;
					//add new move
					Q_moves_copy=new ArrayList<Integer>( Q_moves);
					Q_moves_copy.add(i);
					//hash done
					Collections.sort(Q_moves_copy);
					s_move="";
					for (int move : Q_moves_copy){
						s_move+=move;
					}
					if (done.containsKey(s_move)) continue;
					else {done.put(s_move, true);}
					// flipping
					new_sockets=new ArrayList<String>();
					for (String each : sockets){
						each=multiple_flips(each,Q_moves_copy);
						new_sockets.add(each);
					}
					
					if (correct_check(new_sockets,devices)) return steps; //correct
					else new_queue.add(Q_moves_copy);//wrong
				}
			}
			old_queue=new_queue;
			steps++;
		}
		return -1;
	}
	
	public static void main(String[] args) throws IOException{
		//////////////////////////////////////////////////////////
		String filename="A-small-attempt0.in";///////////////////////////////////////
		//////////////////////////////////////////////////////////

		BufferedReader br=null;
		BufferedWriter writer = null;

		try{
			br=new BufferedReader(new FileReader(filename));
			writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("out.txt"), "utf-8"));
			
			String line=br.readLine();
			int T=Integer.parseInt(line);
			
			String NL;
			String s_flow_have;
			String s_flow_req;
			int ans;
			Charging solver=new Charging();
			for (int i=0;i<T;i++){
				NL=br.readLine();
				s_flow_have=br.readLine();
				s_flow_req=br.readLine();
				ans=solver.helper(NL,s_flow_have,s_flow_req);
				if (ans==-1){
					writer.write("Case #"+(i+1)+": "+"NOT POSSIBLE");
				}
				else{
					writer.write("Case #"+(i+1)+": "+ans);
				}
				writer.newLine();
				
			}


		} catch (Exception e){
			e.printStackTrace();
		} finally{
			br.close();
			try {writer.close();} catch (Exception ex) {}
		}
	}

}
