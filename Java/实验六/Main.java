package javaHomework01;

import java.util.Random;
import java.util.Scanner;

class Point {
	private final double[] coordinates;
	public Point[] neighbors;
	
	public Point(int dimensions, Random random) {
		coordinates = new double[dimensions];
		for (int j = 0; j < dimensions; j++) {
			coordinates[j] = random.nextDouble();
		}
	}
	
	// 计算两点之间的距离
	public double distance(Point other) {
		double sum = 0;
		for (int j = 0; j < coordinates.length; j++) {
			double diff = coordinates[j] - other.coordinates[j];
			sum += diff * diff;
		}
		return Math.sqrt(sum);
	}
	
	// 其他必要的getters和setters
}

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Please enter the number of points:");
		int M = scanner.nextInt();
		
		System.out.println("Please enter the number of dimensions:");
		int N = scanner.nextInt();
		
		System.out.println("Please enter the number of neighbors:");
		int K = scanner.nextInt();
		
		Point[] points = new Point[M];
		
		// 生成点
		for (int i = 0; i < M; i++) {
			Random random = new Random((i + 500) * 6L);
			points[i] = new Point(N, random);
		}
		
		// 找到距离最近的两个点
		double minDistance = Double.MAX_VALUE;
		int minX = 0, minY = 1;
		for (int i = 0; i < M; i++) {
			for (int j = i + 1; j < M; j++) {
				double dist = points[i].distance(points[j]);
				if (dist < minDistance) {
					minDistance = dist;
					minX = i;
					minY = j;
				}
			}
		}
		
		System.out.println("The Nearest two points are: " + minX + " and " + minY);
		
		// 找到每个点的K个最近邻居
		for (int i = 0; i < M; i++) {
			// 对距离进行排序找到最近的K个邻居
			Point[] neighbors = new Point[K];
			int[] neighborIndexes = new int[K];
			for (int k = 0; k < K; k++) {
				double closestDist = Double.MAX_VALUE;
				int closestIdx = -1;
				for (int j = 0; j < M; j++) {
					if (i != j && !isIn(neighborIndexes, j, k)) {
						double dist = points[i].distance(points[j]);
						if (dist < closestDist) {
							closestDist = dist;
							closestIdx = j;
						}
					}
				}
				neighbors[k] = points[closestIdx];
				neighborIndexes[k] = closestIdx;
			}
			points[i].neighbors = neighbors;
			
			// 输出每个点的K个最近邻居
			System.out.print("The " + i + "th Point's " + K + " Nearest Neighbors are: ");
			for (int idx : neighborIndexes) {
				System.out.print(idx + " ");
			}
			System.out.println();
		}
		scanner.close();
	}
	
	// 辅助方法，判断索引是否已经在邻居中
	private static boolean isIn(int[] arr, int value, int limit) {
		for (int i = 0; i < limit; i++) {
			if (arr[i] == value) return true;
		}
		return false;
	}
}