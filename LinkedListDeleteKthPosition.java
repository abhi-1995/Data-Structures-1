package myPackage1;

import java.util.Scanner;

public class LinkedListDeleteKthPosition {
	Node head;
	class Node{
		int data;
		Node next;
		Node(int d)
		{
			data = d;
			next = null;
		}
	}
	/* Insert a new node at front of the list*/
	public void push(int new_data){
		Node new_node = new Node(new_data);
		new_node.next = head;
		head = new_node;
	}
	//Delete method
	void deleteNode(int pos){
		if(head==null)
			return;
		Node temp = head;
		if(pos==0){
			head = temp.next;
			return;
		}
		for(int i=0;temp!=null && i<pos-1;i++)
			temp = temp.next;
		
		if(temp==null || temp.next==null)
			return;
		Node next = temp.next.next;
		temp.next = next;
		
	}
	public void printList(){
		Node tnode = head;
		while(tnode != null){
			System.out.print(tnode.data+ " ");
			tnode = tnode.next;
		}
		System.out.println();
	}
	
	public static void main(String[] args){
		LinkedListDeleteKthPosition llist = new LinkedListDeleteKthPosition();
		Scanner sc = new Scanner(System.in);
		int position = sc.nextInt();
		
		llist.push(7);
		llist.push(8);
		llist.push(1);
		llist.push(9);
		llist.push(3);
		llist.push(2);
		
		System.out.println("Created Linked List is : ");
		llist.printList();
		
		llist.deleteNode(position);
		
		System.out.println("Linked list after Deletion at position " + position);
		llist.printList();
		
		sc.close();
	}

}
