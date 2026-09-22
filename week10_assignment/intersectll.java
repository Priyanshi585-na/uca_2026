class Node{
	int data;
	Node next;

	Node(int data)
	{
		this.data = data;
		this.next = null;
	}	
}


public class Intersection{
	static Node intersection(Node head1, Node head2)
	{
		Node p1 = head1;
		Node p2 = head2;

		Node dummy = new Node(0);
		Node tail = dummy;

		while(p1 != null && p2 != null)
		{
			if(p1.data == p2.data)
			{
				tail.next = new Node(p1.data);
				tail = tail.next;

				p1 = p1.next;
				p2 = p2.next;				
			}

			else if(p1.data < p2.data)
				p1 = p1.next;
		}

		return dummy.next;
	}	
}
