package Passion;

import java.util.Scanner;

public class Temporary {
	
	public static void main(String[] args) {

// TODO Auto-generated method stub
		
		Scanner input=new Scanner(System.in);
		
		System.out.println("Enter the dimensions for tensor A (rows, columns, layers):");
		
		
		
		int rowsA=input.nextInt();
		
		int columnsA=input.nextInt();
		
		int layersA=input.nextInt();
		
		System.out.println("Enter the dimensions for tensor B (rows, columns, layers):");
		
		int rowsB=input.nextInt();
		
		int columnsB=input.nextInt();
		
		int layersB=input.nextInt();
		
		int [][][]a=new int[layersA][rowsA][columnsA];
		
		int [][][]b=new int [layersB][rowsB][columnsB];
		
		System.out.println("Enter the elements for tensor A:");
		
		for(int k=0;k<layersA;k++)
		
		{
			
			for(int j=0;j<rowsA;j++)
			
			{
				
				for(int i=0;i<columnsA;i++)
				
				{
					
					a[k][j][i]=input.nextInt();
					
				}
				
			}
			
		}
		
		System.out.println("Enter the elements for tensor B:");
		
		for(int k=0;k<layersB;k++) {
			
			for(int j=0;j<rowsB;j++)
			
			{
				
				for(int i=0;i<columnsB;i++)
				
				{
					
					b[k][j][i]=input.nextInt();
					
				}
				
			}
			
		}
		
		int[][][]array=new int[2][rowsA][columnsB];
		
		int [][]x=new int[rowsA][columnsB];
		
		int [][]y=new int[rowsA][columnsB];
		
		for(int i=0;i<rowsA;i++)
		
		{
			
			for(int j=0;j<columnsA;j++)
			
			{
				
				for(int k=0;k<columnsB;k++)
				
				{
					
					x[i][k]+=a[0][i][j]*b[0][j][k];
					
					y[i][k]+=a[1][i][j]*b[1][j][k];
					
				}
				
			}
			
		}
		
		for(int i=0;i<rowsA;i++)
		
		{
			
			for(int j=0;j<columnsB;j++)
			
			{
				
				array[0][i][j]=x[i][j]+y[i][j];
				
			}
			
		}
		
		int [][]a1=new int[rowsA][columnsA];
		
		int [][]b1=new int[rowsB][columnsB];
		
		
		
		for(int i=0;i<rowsA;i++)
		
		{
			
			for(int j=0;j<columnsA;j++)
			
			{
				
				a1[i][j]=a[1][i][j]-a[0][i][j];
				
			}
		}
		for(int i=0;i<rowsB;i++)
		{
			for(int j=0;j<columnsB;j++)
			{
				b1[i][j]=b[0][i][j]-b[1][i][j];
			}
		}
		for(int i=0;i<rowsA;i++)
		{
			for(int j=0;j<columnsA;j++)
			{
				for(int k=0;k<columnsB;k++)
				{
					array[1][i][k]+=a1[i][j]*b1[j][k];
				}
			}
		}
		for(int i=0;i<rowsA;i++)
		{
			for(int j=0;j<columnsB;j++)
			{
				array[1][i][j]+=array[0][i][j];
			}
		}
		System.out.println("The " + 0 + "th slice is:");
		for(int i=0;i<rowsA;i++)
		{
			for(int j=0;j<columnsB;j++)
			{
				System.out.print(array[0][i][j]);
				System.out.print(" ");
			}
			System.out.print("\n");
		}
		System.out.println("The " + 1 + "th slice is:");
		for(int i=0;i<rowsA;i++)
		{
			for(int j=0;j<columnsB;j++)
			{
				System.out.print(array[1][i][j]);
				System.out.print(" ");
			}
			System.out.print("\n");
		}
	}
}
