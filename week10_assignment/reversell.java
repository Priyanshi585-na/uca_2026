class Node {
	int data;
	Node next;

	Node(int data)
	{
		this.data = data;
		this.next = null;
	}
}

public class LinkedList{
	static Node reverseList(Node head)
	{
		if(head == null || head.next == null)
			return head;

		Node newHead = reverseList(head.next);
		head.next.next = head;
		head.next = null;

		return newHead;
	}
}
