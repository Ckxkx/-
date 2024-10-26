package Passion;

import java.util.Scanner;

public class numberTest {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int [] arr = new int[10];
		System.out.println("Please enter an integer array:");
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}
		boolean [] vis = new boolean[10];
		for (int i = 0; i < arr.length; i++) {
			vis[arr[i]] = true;
		}
		System.out.println("The result is as follows:");
		for (int i = 0; i < arr.length; i++) {
			if (vis[arr[i]]){
				System.out.print(arr[i] + " ");
				vis[arr[i]] = false;
			}
		}
		
		
		
		
		
	}
}
