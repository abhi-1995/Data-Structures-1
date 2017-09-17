package myPackage1;
import java.util.LinkedList;
import java.util.Queue;


public class LevelOrder {

	static class Node{
		int data;
		Node left;
		Node right;
		
		Node(int data)
		{
			this.data = data;
			left = null;
			right = null;
		}
	}
	
	static void printLevelOrder(Node root){
		if(root == null)
			return;
		//create an empty Queue
		Queue<Node> q = new LinkedList<Node>();
		//Enqueue root
		q.add(root);
		
		while(true){
			int nodeCount = q.size();
			if(nodeCount == 0)
				break;
			/* Dequeue all node of current level and enqueue
			  all nodes of next level*/
			while(nodeCount>0)
			{
				Node node = q.peek();
				System.out.print(node.data + " ");
				q.remove();
				if(node.left != null)
					q.add(node.left);
				if(node.right != null)
					q.add(node.right);
				nodeCount--;
			}
			System.out.println();
		}
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.right = new Node(6);
		
		printLevelOrder(root);

	}

}
