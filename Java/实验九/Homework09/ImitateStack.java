package Homework09;

import java.util.ArrayList;
import java.util.Scanner;

class simulationStack {
	private final ArrayList<Integer> stack;
	
	simulationStack(){
		stack = new ArrayList<Integer>();
	}
	public void iniStack(ArrayList<Integer> list){
		stack.clear();
//		初始化栈内元素
		stack.addAll(list);
	}
//	入栈
	public void Push(int val){
		stack.add(val);
		System.out.println("元素已入栈");
	}
//	出栈
	public int Pop(){
		if (!stack.isEmpty()){
//			return stack.removeLast();
			return stack.remove(stack.size() - 1);
		}else {
			System.out.println("出栈:\n栈为空:无法出栈");
			return -1;
		}
//		代替remove 和 size 的元素
	}
//	查看栈顶元素
	public int Peek(){
		if (!stack.isEmpty()){
//			return stack.getLast();
			return stack.get(stack.size() - 1);
		}else {
			System.out.println("查看栈顶元素:\n栈为空");
			return -1;
		}
	}
	public boolean isEmpty(){
		return stack.isEmpty();
	}
}
public class ImitateStack {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		simulationStack mystack = new simulationStack();
		
		
		System.out.println("初始化栈:\n请输入初始栈的大小N: ");
		int N = sc.nextInt();
		
		if (N >  0){
			System.out.println("请依次输入" + N + "个整数用于初始化栈: ");
		}
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0 ;i < N;i++){
			list.add(sc.nextInt());
		}
//		初始化栈
		mystack.iniStack(list);
//		入栈
		System.out.println("入栈:\n请输入要入栈的整数: ");
		int x = sc.nextInt();
		mystack.Push(x);
		
//		出栈
		int Popflag = mystack.Pop();
		if (Popflag != -1)
			System.out.println("出栈:\n出栈元素: " + Popflag);
//		查看栈顶元素
		int Peekflag = mystack.Peek();
		if (Peekflag != -1)
			System.out.println("查看栈顶元素:\n栈顶元素: " + Peekflag);
		
		sc.close();
	
	}
}
