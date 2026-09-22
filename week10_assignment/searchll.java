class Node{
	int data;
	Node next;

	Node(int data)
	{
		this.data = data;
		this.next = null;
	}
}

public class SearchList{
	static boolean isSubList(Node list1, Node list2)
	{
		if(list1 == null)
			return true;

		Node start = list2;

		while(start != null)
		{
			Node p1 = list1;
			Node p2 = start;

			while(p1 != null && p2 != null && p1.data == p2.data)
			{
				p1 = p1.next;
				p2 = p2.next;
			}

			if(p1 == null)
				return true;

			start = start.next;
		}

		return false;
	}
}
