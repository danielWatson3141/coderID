import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.regex.Pattern;

import org.apache.commons.math3.Field;

import static java.lang.Math.*;





public class Main extends Util {
	

	
	public static void main(String[] args){
		(new Main()).mainA();
	}
	

	public class V{
		List<E> edges;
		int idx;

		public V(int idx) {
			edges=new ArrayList<E>();
			this.idx=idx;
		}

		@Override
		public String toString() {
			return "V[idx=" + idx + "]";
		}
		
		
		
	}
	
	public V nullNode=new V(-1);
	
	public class E{
		V v1,v2;
		int wb1,vc1;
		int wb2,vc2;

		public E(V v1, V v2) {
			super();
			this.v1 = v1;
			this.v2 = v2;
			v1.edges.add(this);
			v2.edges.add(this);
			wb1=wb2=-1;
			vc1=vc2=-1;
		}
		
		public E(V v){
			this.v1=v;
			this.v2=nullNode;
			wb1=wb2=-1;
			vc1=vc2=-1;
		}
		
		
		
		@Override
		public String toString() {
			return "E[v1=" + v1 + ", v2=" + v2 + "]";
		}

		public int getWeight(V from){
			int wb;
			V n;
			if (from==v1){
				n=v2;
				wb=wb1;
			}else if (from==v2){
				n=v1;
				wb=wb2;
			}else{
				throw new RuntimeException("asdkasdk");
			}
			if (wb>=0){
				return wb;
			}else{
				if ((from!=nullNode && n.edges.size()==1)||(from==nullNode && n.edges.size()==0)){
					wb=0;
				}else if((from!=nullNode && n.edges.size()==2)||(from==nullNode && n.edges.size()==1)){
					wb=vertCount(from)-1;
				}else{
					List<int[]> cw=new ArrayList<int[]>();
					for (E e:n.edges){
						if (e!=this){
							int w=e.getWeight(n);
							int v=e.vertCount(n);
							cw.add(new int[]{v-w,w,v});
						}
					}
					Collections.sort(cw, new Comparator<int[]>() {
						@Override
						public int compare(int[] o1, int[] o2) {
							return -o1[0]+o2[0];
						}
					});
					
//					showln("%d %d",cw.get(0)[0],cw.get(1)[0]);
					wb=cw.get(0)[1]+cw.get(1)[1];
					for (int j=2;j<cw.size();j++){
						wb+=cw.get(j)[2];
					}
				}
			}
			if (from==v1){
				wb1=wb;
			}else if (from==v2){
				wb2=wb;
			}
//			showln("weight from %s [%s,%s]: %d",from.toString(),v1.toString(),v2.toString(),wb);
			return wb;
		}
		
		public int vertCount(V from){
			int vc;
			V n;
			if (from==v1){
				n=v2;
				vc=vc1;
			}else if (from==v2){
				n=v1;
				vc=vc2;
			}else{
				throw new RuntimeException("asdkasdk");
			}
			if (vc>=0){
				return vc;
			}else{
				vc=1;
				for (E e:n.edges){
					if (e!=this){
						vc+=e.vertCount(n);
					}
				}
			}
			if (from==v1){
				vc1=vc;
			}else if (from==v2){
				vc2=vc;
			}
//			showln("count from %s [%s,%s]: %d",from.toString(),v1.toString(),v2.toString(),vc);
			return vc;
		}
		
		
	}
	
	public void mainA(){
		scanFile("B-large.in");
		s.useDelimiter(Pattern.compile("\\s"));
		outputInFile("Bl.out");
//		showln("This %s.","works");
		int T=s.nextInt();
		for (int i=0;i<T;i++){
			int N=s.nextInt();
			List<V> vertices=new ArrayList<V>();
			List<E> edges=new ArrayList<E>();
			for (int j=0;j<N;j++){
				vertices.add(new V(j));
			}
			for (int j=0;j<N-1;j++){
				int v1=s.nextInt();
				int v2=s.nextInt();
				edges.add(new E(vertices.get(v1-1),vertices.get(v2-1)));
			}
			int min=-1;
			V mv=null;
			for (V v:vertices){
				E e=new E(v);
				int w=e.getWeight(nullNode);
				if (min==-1||(min>w)){
					min=w;
					mv=v;
				}
			}
//			if (i==6){
//				showln("%s",edges);
//			}
//			showln("%s", mv);
			showln("Case #%d: %d",i+1,min);
		}
	}


}
