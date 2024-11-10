package javaHomework01;

import java.util.Scanner;

class RegularPolygon {
	private int n = 3;           // 边数，默认3
	private double side = 1.0;   // 边长，默认1
	private double x = 0.0;      // 中心的x坐标，默认0
	private double y = 0.0;      // 中心的y坐标，默认0
	
	// 无参构造函数
	public RegularPolygon() {
	}
	
	// 带参构造函数
	public RegularPolygon(int n, double side, double x, double y) {
		this.n = n;
		this.side = side;
		this.x = x;
		this.y = y;
	}
	
	// 访问器和修改器
	public int getN() {
		return n;
	}
	
	public void setN(int n) {
		this.n = n;
	}
	
	public double getSide() {
		return side;
	}
	
	public void setSide(double side) {
		this.side = side;
	}
	
	public double getX() {
		return x;
	}
	
	public void setX(double x) {
		this.x = x;
	}
	
	public double getY() {
		return y;
	}
	
	public void setY(double y) {
		this.y = y;
	}
	
	// 计算周长
	public double getPerimeter() {
		return n * side;
	}
	
	// 计算面积
	public double getArea() {
		return (n * side * side) / (4 * Math.tan(Math.PI / n));
	}
}

class TestRegularPolygon {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		// 创建第一个正多边形对象，使用默认构造函数
		RegularPolygon polygon1 = new RegularPolygon();
		
		// 创建第二个正多边形对象，使用用户输入的值
		System.out.print("Enter the number of sides of the second regular polygon: ");
		int n = input.nextInt();
		
		System.out.print("Enter the side length of the second regular polygon: ");
		double side = input.nextDouble();
		
		System.out.print("Enter the x-coordinate of the center point of the second regular polygon: ");
		double x = input.nextDouble();
		
		System.out.print("Enter the y-coordinate of the center point of the second regular polygon: ");
		double y = input.nextDouble();
		
		RegularPolygon polygon2 = new RegularPolygon(n, side, x, y);
		
		// 输出正多边形1的周长、面积和中心点坐标
		System.out.println("Polygon 1 perimeter: " + String.format("%.4f", polygon1.getPerimeter()));
		System.out.println("Polygon 1 area: " + String.format("%.4f", polygon1.getArea()));
		System.out.println("Polygon 1 center point coordinates: (" + polygon1.getX() + "," + polygon1.getY() + ")");
		
		// 输出正多边形2的周长、面积和中心点坐标
		System.out.println("Polygon 2 perimeter: " + String.format("%.4f", polygon2.getPerimeter()));
		System.out.println("Polygon 2 area: " + String.format("%.4f", polygon2.getArea()));
		System.out.println("Polygon 2 center point coordinates: (" + polygon2.getX() + "," + polygon2.getY() + ")");
		
		input.close();
	}
}
