public class List<T extends Comparable<T>> {
	private Node<T> head = null;
	private Node<T> tail = null;

	public void append( T x ) {
		if( head == null ) {
			head = new Node<T>(x);
			tail = head;
		} else {
			tail.append( x );
			tail = tail.next;
		}
	}

	public void insert( T x ) {
                head = new Node<T>( x, head );
		if( tail == null )
			tail = head;
        }

	public void insort( T x ) {
		if( head == null || head.x.compareTo(x) > 0 ) {
			Node<T> n = new Node<>(x);
			n.next = head;
			head = n;
			if( tail == null)
				tail = head;
		} else {
			head.insert(x);
			if( tail.next != null )
				tail = tail.next;
		}
	}

	public String toString() {
		if( head == null )
			return "";
		else {
			StringBuilder sb = new StringBuilder();
			Node<T> it = head;
			while( it != tail ) {
                                sb.append(it.x).append('\n');
				it = it.next;
			}
			sb.append(tail.x);
			return sb.toString();
		}
	}

	public T getTail() {
		return tail.x;
	}

	private class Node<T extends Comparable<T>> {
		private T x;
		private Node<T> next;

		Node( T x ) {
			this.x = x;
			this.next = null;
		}

		Node( T x, Node<T> nxt ) {
			this.x = x;
			this.next = nxt;
		}

		void insert( T x ) {
			Node<T> it = this;
			while( it.next != null && it.next.x.compareTo(x) <= 0 )
				it = it.next;
			Node<T> n = new Node<>(x);
			n.next = it.next;
			it.next = n;
	        }	

		void append( T x ) {
			if( next == null )
				next = new Node<>(x);
			else {
				Node<T> it = this;
				while( it.next != null )
					it = it.next;
				it.next = new Node<T>(x);
			}
		}

		public String toString() {
			return x.toString();
		}
		
	}

	public static void main( String [] args ) {
		List<String> ls = new List<>();
		List<String> rs = new List<>();
		List<String> ss = new List<>();
		for( String a : args ) {
			ls.append( a );
			rs.insert( a );
			ss.insort( a );
		}

		System.out.println( ls ); System.out.println( "Ogonek: " + ls.getTail() );
		System.out.println( rs ); System.out.println( "Ogonek: " + rs.getTail() );
		System.out.println( ss ); System.out.println( "Ogonek: " + ss.getTail() );

		List<Integer> li = new List<>();
		for( int i = 0; i < 100000; i++ )
			li.append( i );
	}
}
