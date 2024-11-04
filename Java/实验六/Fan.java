package Homework6;

import java.util.Scanner;

public class Fan {
	public int SLOW = 1;
	public int MEDIUM = 2;
	
	public int FAST = 3;

	private int speed = SLOW;
	private boolean on = false;
	private double radius = 5;
	private String color = "blue";

	public Fan() {
	}
	
	public String toString(){
		if (on == true)
			return "speed: " + speed + ", color: " + color + ", radius: " + radius;
		else
			return "fan is off, color: " + color + ", radius: " + radius;
	}
	public static void main(String[] args) {
		Fan f1 = new Fan();
		String s1 = f1.toString();
		Fan f2 = new Fan();

		System.out.println("Enter properties for Fan 2:");
		System.out.print("Is the fan on? (true/false): ");
		Scanner sc = new Scanner(System.in);
		f2.on = sc.nextBoolean();
		System.out.print("Enter speed (1: SLOW, 2: MEDIUM, 3: FAST): ");
		f2.speed = sc.nextInt();
		System.out.print("Enter radius: ");
		f2.radius = sc.nextDouble();
		System.out.print("Enter color: ");
		f2.color = sc.next();
		String s2 = f2.toString();
		
		System.out.println("Fan 1: " + s1);
		System.out.println("Fan 2: " + s2);
	}
}
