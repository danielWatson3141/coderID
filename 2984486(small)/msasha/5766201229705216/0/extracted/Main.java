import java.io.*;
import java.util.*;


public class Main{
	
	
	private static class Pair{
		public int size;
		public int remove;
		
		public Pair(int size, int remove){
			this.size = size;
			this.remove = remove;
		}
		
		public Pair(){
			
		}
	}
	
	private static class Vertex{
		
		public final int n;
		public final ArrayList<Vertex> neighbours = new ArrayList<Vertex>();
		
		public Vertex(int n){
			this.n = n;	
		}
		
	}
	
	
	private static Pair calc(Vertex v, Vertex parent){
		ArrayList<Pair> list = new ArrayList<Pair>();
		for (Vertex u : v.neighbours){
			if (u == parent)
				continue;
				
			list.add(calc(u, v));
		}
		
		if (list.isEmpty()){
//			System.out.printf("For0 v=%d, parent=%d: size=%d, remove=%d\n", v.n, 
//				parent == null ? 0 : parent.n, 1, 0);
			
			return new Pair(1, 0);
		}
		else if (list.size() == 1){
			Pair p = list.get(0);
//			System.out.printf("For1 v=%d, parent=%d: size=%d, remove=%d\n", v.n, 
//				parent == null ? 0 : parent.n, 1+p.size, p.size);
			
			return new Pair(1+p.size, p.size);
		}
		else{
			int size = 0;
			int minRemove = Integer.MAX_VALUE;
			
			for (int i = 0; i < list.size(); ++i){
				Pair pi = list.get(i);
				size += pi.size;
				
				for (int j = i+1; j < list.size(); ++j){
					Pair pj = list.get(j);
					
					int remove = 0;
					remove += pi.remove + pj.remove;
					
					for (int k = 0; k < list.size(); ++k){
						if ((k != i) && (k != j))
							remove += list.get(k).size;
					}
					
					if (remove < minRemove)
						minRemove = remove;
				}
			}
			
//			System.out.printf("For v=%d, parent=%d: size=%d, remove=%d\n", v.n, 
//				parent == null ? 0 : parent.n, 1+size, minRemove);
			return new Pair(1 + size, minRemove);
		}
	}
	
	public static void main(String[] args){
		FastReader in = FastReader.SYSTEM_READER;
		int t = in.nextUnsignedInt();
		
		for (int tc = 1; tc <= t; ++tc){
			int n = in.nextUnsignedInt();
			
			ArrayList<Vertex> g = new ArrayList<Vertex>();
			g.add(null);
			for (int i = 1; i <= n; ++i)
				g.add(new Vertex(i));
				
			for (int i = 0; i < n-1; ++i){
				Vertex u = g.get(in.nextUnsignedInt());
				Vertex v = g.get(in.nextUnsignedInt());
				
				u.neighbours.add(v);
				v.neighbours.add(u);
			}
			
			int minRemove = Integer.MAX_VALUE;
			for (int i = 1; i <= n; ++i){
				Vertex v = g.get(i);
				Pair p = calc(v, null);
//				System.out.printf("For v=%d: size=%d, remove=%d\n", i, p.size, p.remove);
				if (p.remove < minRemove)
					minRemove = p.remove;
			}
			
			System.out.printf("Case #%d: %d\n", tc, minRemove);
		}
	}	
	
}

final class FastReader{
	
	public static final FastReader SYSTEM_READER = new FastReader(System.in);
	
	private final InputStream in;
	private final byte[] buffer = new byte[1<<16];
	private int pos, count;
	
	public FastReader(InputStream in){
		this.in = in;
		pos = count = 0;
	}
	
	public int nextUnsignedInt(){
		int c;
		while ((c = read()) < '0');
		
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10*result + c;
		return result;
	}
	
	public int nextInt(){
		int c;
		while (((c = read()) < '0') && (c != '-'));
		
		boolean isNegative = false;
		if (c == '-'){
			isNegative = true;
			c = read();
		}
		
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10*result + c;
		return isNegative ? -result : result;
	}
	
	
	public String nextUnspacedString(){
		StringBuilder s = new StringBuilder();
		int c;
		while ((c = read()) < 33);
		s.append((char)c);
		while ((c = read()) >= 33)
			s.append((char)c);
		return s.toString();
	}
	
	public char nextNonWhitespaceChar(){
		int c;
		while ((c = read()) < 33);
		return (char)c;
	}
	
    
	private boolean fillBuffer(){
		try{
			return (count = in.read(buffer, pos = 0, buffer.length)) > 0;
		} catch (Exception e){
			return false;
		}
	}
	
	
	public int read(){
		if (pos == count)
			if (!fillBuffer())
				return -1;
		return buffer[pos++];
	}
	
}

