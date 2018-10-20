package round1a;

public class Pair<K,E> {

	private K left;
	private E right;
	
	public Pair() {
		
		left = null;
		right = null;
		
	}
	
	public Pair(K left, E right) {
		
		this.left = left;
		this.right = right;
		
	}
	
	public Pair(Pair<K,E> p) {
		
		left = p.getLeft();
		right = p.getRight();
		
	}
	
	public boolean equals(Object o) {
		
		Pair<K,E> p = (Pair<K,E>) o;
		return left.equals(p.getLeft()) && right.equals(p.getRight());
		
	}

	public K getLeft() {
		return left;
	}

	public void setLeft(K left) {
		this.left = left;
	}

	public E getRight() {
		return right;
	}

	public void setRight(E right) {
		this.right = right;
	}
	
	
	
}
