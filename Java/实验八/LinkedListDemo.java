package Homework08;
import java.util.Scanner;

class Node {
	int data;
	Node next;

	public Node(int data) {
		this.data = data;
		this.next = null;
	}
}
class LinkedList {
	private Node head;
	Scanner sc = new Scanner(System.in);

//	初始化构造函数
	public LinkedList(){
		this.head = null;
	}
//	创建
	public void addLinkedList(int x){
		if (x < 2){
			System.out.println("链表长度必须大于等于2");
			return;
		}
		System.out.println("请依次输入链表数据：");
		for (int i = 0;i < x;i++){
			int val = sc.nextInt();
			Node newNode = new Node(val);
			if (head == null){
				head = newNode;
			} else {
				Node temp = head;
				while (temp.next != null){
					temp = temp.next;
				}
				temp.next = newNode;
			}
		}
	}
//	删除元素
	public void deleteLinkedList(int pos){
		if (head == null){
			System.out.println("链表为空，无法删除！");
			return ;
		}
		if (pos == 0){
			head = head.next;
		} else {
			Node temp = head;
			for (int i = 0;i < pos - 1; i++){
				if (temp == null || temp.next == null){
					System.out.println("删除位置无效!");
					return;
				}
				temp = temp.next;
			}
			if (temp.next != null){
				temp.next = temp.next.next;
			}
		}

	}
////	查询元素
	public int queryLinkedList(int pos){
		Node newNode = head;
		for (int i = 0;i < pos;i++){
			newNode = newNode.next;
		}
		return newNode.data;
	}
//	插入元素
	public void insertLinkedList(int pos,int val){
		Node newNode = new Node(val);
		if (pos == 0){
			newNode.next = head;
			head = newNode;
		} else {
			Node temp = head;
			for (int i = 0;i < pos - 1;i ++){
				if (temp == null || temp.next == null){
					System.out.println("插入位置无效!");
					return ;
				}
				temp = temp.next;
			}
			newNode.next = temp.next;
			temp.next = newNode;
		}
	}
//	打印
	public void display(){
		Node temp = head;
		while (temp != null){
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}


}

public class LinkedListDemo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		LinkedList list = new LinkedList();

		System.out.println("请输出一个整数n，表示链表长度（n >= 2）：");
		int n = sc.nextInt();
		list.addLinkedList(n);

		System.out.println("打印链表数据：");
		list.display();

		System.out.println("请输入删除的位置：");
		int deletePos = sc.nextInt();
		list.deleteLinkedList(deletePos);

		System.out.println("打印链表数据：");
		list.display();
		
		System.out.println("请输入要查询的位置：");
		int queryPos = sc.nextInt();
		int i = list.queryLinkedList(queryPos);
		System.out.println(i);

		System.out.println("请输入插入的数据和插入的位置：");
		int insertVal = sc.nextInt();
		int insertPos = sc.nextInt();
		list.insertLinkedList(insertPos,insertVal);

//		System.out.println("打印链表数据：");
		list.display();
	}
}
