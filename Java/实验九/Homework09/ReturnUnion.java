package Homework09;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class ReturnUnion {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter five integers for list1: ");
		ArrayList<Integer> list1 = new ArrayList<>();
		for (int i = 0;i< 5;i ++){
			list1.add(sc.nextInt());
		}
		System.out.print("Enter five integers for list2: ");
		ArrayList<Integer> list2 = new ArrayList<>();
		for (int i = 0 ;i < 5;i++){
			list2.add(sc.nextInt());
		}
//		求并集
//		list1,list2 是静态static列表，Union函数必须加上static
		ArrayList<Integer> list = Union(list1,list2);
		System.out.print("The combined list is ");
		list.forEach(ch -> System.out.print(ch + " "));
		sc.close();
	}
	public static ArrayList<Integer> Union(ArrayList<Integer> list1, ArrayList<Integer> list2){
		 HashSet<Integer> set = new HashSet<>();
		 ArrayList<Integer> res = new ArrayList<>();
		 
		 for (Integer num : list1){
			 res.add(num);
			 set.add(num);
		 }
		 
		 for (Integer num : list2){
			 if (!set.contains(num)){
				 res.add(num);
				 set.add(num);
			 }
		 }
		 return res;
	}
}
