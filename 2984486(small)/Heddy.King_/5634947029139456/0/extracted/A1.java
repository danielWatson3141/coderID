package org.sjtu.cj.shell.modules;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;
import java.util.Map.Entry;

import org.sjtu.cj.shell.objs.InputObj;
import org.sjtu.cj.shell.objs.OutputObj;

public class A1 extends AbstractModule{

	@Override
	public void process(){
		int pos=0;
		int num=Integer.valueOf(InputObj.input1.get(pos));
		pos++;

		for(int k=1; k<=num; k++){
			int N=Integer.valueOf(InputObj.input2.get(pos).get(0));
			int L=Integer.valueOf(InputObj.input2.get(pos).get(1));
			pos++;
			List<String> outlets=InputObj.input2.get(pos);
			pos++;
			List<String> devices=InputObj.input2.get(pos);
			pos++;

			System.out.println(N);
			System.out.println(L);
			System.out.println(outlets);
			System.out.println(devices);

			List<List<List<Integer>>> arr=new ArrayList<List<List<Integer>>>();
			Set<List<Integer>> set=new HashSet<List<Integer>>();
			for(String s1:outlets){
				List<List<Integer>> list0=new ArrayList<List<Integer>>();
				for(String s2:devices){
					List<Integer> list1=new ArrayList<Integer>();
					for(int p=0;p<L;p++){
						if(s1.charAt(p)!=s2.charAt(p)){
							list1.add(p);
						}
					}
					list0.add(list1);
					set.add(list1);
				}
				arr.add(list0);
			}

//			System.out.println(set);
//			System.out.println(arr);

			List<List<Integer>> list=new ArrayList<List<Integer>> (set);
			Collections.sort(list, new Comparator<List<Integer>>(){

				@Override
				public int compare(List<Integer> o1, List<Integer> o2) {
					if(o1.size()<o2.size()) return -1;
					else if(o1.size()>o2.size()) return 1;
					return 0;
				}
			});

			System.out.println(list);

			String result="NOT POSSIBLE";
			for(List<Integer> cur:list){
				String problem="";
				for(int i=0;i<N;i++){
					for(int j=0;j<N;j++){
						if(arr.get(i).get(j).equals(cur)){
							problem+="("+i+","+j+") ";
						}
					}
				}
				problem=problem.substring(0,problem.length()-1);
//				System.out.println(problem);
				List<List<String>> check=matchByFlow(problem);
//				System.out.println(check);
				if(check.size()==N){
					result=String.valueOf(cur.size());
					break;
				}
			}
			
//			System.out.println(result+"####");
			OutputObj.output.add(result);
		}
	}

	public static List<List<String>> matchByFlow(String problem){
		String[] pairs=problem.split(" ");
		Set<String> vertex=new HashSet<String>();
		Map<List<String>,Integer> edge=new HashMap<List<String>,Integer>();
		for(String pair:pairs){
			String[] flags=pair.replace(")","").replace("(","").split(",");
			vertex.add("x"+flags[0]);
			vertex.add("y"+flags[1]);
			edge.put(Arrays.asList(new String[]{"x"+flags[0],"y"+flags[1]}),1);
			edge.put(Arrays.asList(new String[]{"s","x"+flags[0]}),1);
			edge.put(Arrays.asList(new String[]{"y"+flags[1],"t"}),1);
		}

		List<List<String>> result=new ArrayList<List<String>>();
		Map<List<String>,Integer> raw=flow(new ArrayList<String>(vertex),edge);
		for(List<String> list:raw.keySet()){
			if(list.get(0).contains("x")&&list.get(1).contains("y")){
				result.add(Arrays.asList(new String[]{list.get(0).replace("x", ""),list.get(1).replace("y", "")}));
			}
		}

		return result;
	}

	public static Map<List<String>,Integer> flow(List<String> vertex, Map<List<String>,Integer> edge){
		Map<List<String>,Integer> result=new HashMap<List<String>,Integer>();
		List<String> vertexL=new ArrayList<String>();
		Map<List<String>,Integer> edgeL=new HashMap<List<String>,Integer>();

		for(String str:vertex){
			vertexL.add(str);
		}
		for(Entry<List<String>,Integer> entry:edge.entrySet()){
			edgeL.put(new ArrayList<String>(entry.getKey()), entry.getValue());
		}
		List<String> path=findPath(vertexL,edgeL,"s","t");

		while(path!=null){
			int min=999999999;
			for(int k=1;k<path.size();k++){
				String v1=path.get(k-1);
				String v2=path.get(k);
				List<String> l=Arrays.asList(new String[]{v1,v2});
				Integer i=edgeL.get(l);
				min=Math.min(i, min);
			}
			for(int k=1;k<path.size();k++){
				String v1=path.get(k-1);
				String v2=path.get(k);
				List<String> l1=Arrays.asList(new String[]{v1,v2});
				List<String> l2=Arrays.asList(new String[]{v2,v1});
				Integer i1=edgeL.get(l1);
				Integer i2=edgeL.get(l2);
				if(i1==min){
					edgeL.remove(l1);
				}
				else{
					edgeL.put(l1, i1-min);
				}
				if(i2==null){
					edgeL.put(l2, min);
				}
				else{
					edgeL.put(l2, min+i2);
				}

				Integer orgin1=result.get(l1);
				Integer orgin2=result.get(l2);
				if(orgin1!=null){
					result.put(l1, orgin1+min);
				}
				else if(orgin2!=null){
					if(orgin2>min){
						result.put(l2,orgin2-min);
					}
					else if(orgin2<min){
						result.remove(l2);
						result.put(l1,min-orgin2);
					}
					else{
						result.remove(l2);
					}
				}
				else{
					result.put(l1, min);
				}
			}
			path=findPath(vertexL,edgeL,"s","t");
		}

		return result;
	}

	public static List<String> findPath(List<String> vertex,Map<List<String>,Integer> edge,String source,String target){
		List<String> nodes=new ArrayList<String>();

		Stack<List<String>> stack=new Stack<List<String>>();
		stack.add(Arrays.asList("",source));

		while(!stack.isEmpty()){
			List<String> top=stack.pop();
			if(nodes.size()==0){
				nodes.add(source);
				for(List<String> list:edge.keySet()){
					if(list.get(0).equals(source)){
						stack.add(list);
					}
				}
			}
			else{
				String n1=top.get(0);
				String n2=top.get(1);
				int ind1=nodes.indexOf(n1);
				int ind2=nodes.indexOf(n2);
				if(ind1==-1) break;
				else if((ind2>ind1)||(ind2==-1)){
					int n=nodes.size();
					for(int k=n-1;k>ind1;k--){
						nodes.remove(k);
					}
					nodes.add(ind1+1, n2);

					String end=nodes.get(nodes.size()-1);
					if(end.equals(target)){
						return nodes;
					}
					else{
						for(List<String> list:edge.keySet()){
							if(list.get(0).equals(end)){
								stack.add(list);
							}
						}
					}
				}
			}
		}
		return null;
	}
}
