package javaHomework01;

import java.util.Scanner;

class QuadraticEquation {
	private double a;  // 系数 a
	private double b;  // 系数 b
	private double c;  // 系数 c
	
	// 构造方法，接收 a, b, c
	public QuadraticEquation(double a, double b, double c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	// 获取系数 a
	public double getA() {
		return a;
	}
	
	// 获取系数 b
	public double getB() {
		return b;
	}
	
	// 获取系数 c
	public double getC() {
		return c;
	}
	
	// 计算判别式
	public double getDiscriminant() {
		return b * b - 4 * a * c;
	}
	
	// 计算第一个根
	public double getRoot1() {
		double discriminant = getDiscriminant();
		if (discriminant >= 0) {
			return (-b + Math.sqrt(discriminant)) / (2 * a);
		} else {
			return 0;  // 如果判别式为负，返回0
		}
	}
	
	// 计算第二个根
	public double getRoot2() {
		double discriminant = getDiscriminant();
		if (discriminant >= 0) {
			return (-b - Math.sqrt(discriminant)) / (2 * a);
		} else {
			return 0;  // 如果判别式为负，返回0
		}
	}
}

class TestQuadraticEquation {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		// 获取用户输入的 a, b, c 值
		System.out.print("Enter a, b, c: ");
		double a = input.nextDouble();
		double b = input.nextDouble();
		double c = input.nextDouble();
		
		// 创建 QuadraticEquation 对象
		QuadraticEquation equation = new QuadraticEquation(a, b, c);
		
		// 根据判别式输出结果
		double discriminant = equation.getDiscriminant();
		if (discriminant > 0) {
			System.out.println("The roots are " + equation.getRoot1() + " and " + equation.getRoot2());
		} else if (discriminant == 0) {
			System.out.println("The root is " + equation.getRoot1());
		} else {
			System.out.println("The equation has no roots.");
		}
		
		input.close();
	}
} 