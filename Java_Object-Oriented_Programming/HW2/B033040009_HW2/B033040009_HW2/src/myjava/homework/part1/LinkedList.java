/*
 名稱 : HW2 - List
 學號 : B033040009
 系級 : 資工系 二年級
 姓名 : 蔡宜勳
*/

package myjava.homework.part1;

public class LinkedList<T> {
	protected int count;
	protected Node<T> head;
	protected Node<T> rear;
	
	public LinkedList() {
		this.count = 0;
		this.head = null;
		this.rear = null;
	}
	
	public LinkedList(Node<T> one_element) {
		this.count = 1;
		this.head = one_element;
		this.rear = one_element;
	}
	
	public LinkedList (Node<T> _head, Node<T> _rear) {
		this.count = 2;
		this.head = _head;
		this.head.setNext(this.rear);
		this.rear = _rear;
	}
	
	public Node<T> getFisrt() {
		return this.head;
	}
	
	public Node<T> getLast() {
		return this.rear;
	}
	
	public int getSize() {
		return count;
	}
	
	public Node<T> getPrevNode(Node<T> currentNode) {
		if(currentNode == this.head) {
			return null;
		}
		
		else {
			Node<T> prevNode = this.head;
			while (prevNode != null) {
				if(currentNode == prevNode.getNext())
					break;
				prevNode = prevNode.getNext();
			}
			return prevNode;
		}
	}
	
	public Node<T> toSpecNode(int _number) {
		int count = 1;
		Node<T> iterator = this.getFisrt();
		while(count < _number) {
			iterator = iterator.getNext();
			++count;
		}
		return iterator;
	}
	
	public void addFirst(T _data) {
		Node<T> newNode = new Node<T>(_data);
		if(this.count == 0) {
			this.head = newNode;
			this.rear = newNode;
		}
		
		else {
			newNode.setNext(this.head);
			this.head = newNode;
		}
		++this.count;
	}
	
	public void addLast(T _data) {
		Node<T> newNode = new Node<T>(_data);
		if(this.count == 0) {
			this.head = newNode;
			this.rear = newNode;
		}
		else {
			this.rear.setNext(newNode);
			this.rear = newNode;
		}
		++this.count;
	}
	
	public void addBefore(Node<T> currentNode, T _data) {
		if(this.head == currentNode) {
			this.addFirst(_data);
		}
		else {
			Node<T> newNode = new Node<T>(_data);
			Node<T> prevNode = this.getPrevNode(currentNode);
			prevNode.setNext(newNode);
			newNode.setNext(currentNode);
			++this.count;
		}
	}
	
	public void addAfter(Node<T> currentNode, T _data) {
		if(this.rear == currentNode) {
			this.addLast(_data);
		}
		else {
			Node<T> newNode = new Node<T>(_data);
			Node<T> nextNode = currentNode.getNext();
			currentNode.setNext(newNode);
			newNode.setNext(nextNode);
			++this.count;
		}
	}
	
	public void removeFirst() {
		if(this.count == 0)
			throw new ArrayIndexOutOfBoundsException();
		
		else if(this.count == 1) {
			this.head = null;
			this.rear = null;
		}
		
		else {
			Node<T> temp = this.head.getNext();
			this.head.setNext(null);
			this.head = temp;
		}
		--this.count;
	}
	
	public void removeLast() {
		if(this.count == 0)
			throw new ArrayIndexOutOfBoundsException();
		else if(this.count == 1) {
			this.head = null;
			this.rear = null;
		}
		
		else {
			Node<T> temp = this.getPrevNode(rear);
			temp.setNext(null);
			this.rear = temp;
		}
		--this.count;		
	}
	
	public void remove(Node<T> targetNode) {
		if(targetNode == this.head) {
			this.removeFirst();
		}
		
		else if(targetNode == this.rear) {
			this.removeLast();
		}
		
		else {
			Node<T> prevNode = this.getPrevNode(targetNode);
				if(prevNode == null)
					throw new ArrayIndexOutOfBoundsException();
				prevNode.setNext(targetNode.getNext());
				targetNode.setNext(null);
				--this.count;
		}
	}
	
}
