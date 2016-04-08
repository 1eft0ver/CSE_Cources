/*
 �W�� : HW2 - List
 �Ǹ� : B033040009
 �t�� : ��u�t �G�~��
 �m�W : ���y��
*/

package myjava.homework.part1;

public class Node<T> {
	private Node<T> prev;
	private Node<T> next;
	private T data;
	
	public Node() {
		this.prev = null;
		this.next = null;
		this.data = null;
	}
	
	public Node(T _data) {
		this.prev = null;
		this.next = null;
		this.data = _data;
	}
	
	public Node<T> getPrev() {
		return this.prev;
	}
	
	public Node<T> getNext() {
		return this.next;
	}
	
	public T getData() {
		return this.data;
	}
	
	public void setPrev(Node<T> _prev) {
		this.prev = _prev;
	}
	
	public void setNext(Node<T> _next) {
		this.next = _next;
	}
	
	public void setData(T _data){
		this.data = _data;
	}
	
	
}