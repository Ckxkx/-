#include <iostream>
#include <cstdlib>
//#include <windows.h>

// 缺少 using namnspace std; 命名空间
using namespace std;

int& function(int v, int *p, int &r)
{
	v = (*p)++;
	*p = 100;
	p = new int;
	*p = 1000;
	r = 2 + (*p)++;

	cout << "*p = " << *p << endl;
	cin >> r;

// 返回值与函数类型不符合，直接返回 r
	// return v;
    delete p;
    return r;
}


/******************** 主函数 ********************/

int main()
{

	cout << "---------------------------" << endl;

	//1. 传值，传址和传引用分析
	int a,b,c;
    //类型不对，新增一个指针*p来保存 b 的地址
    int *p = &b;
    cout << "请输入整型变量a, b, c的数值：";

// 输入不能使用 endl 输出流换行符
    // cin >> a >> b >> c >> endl;
    cin >> a >> b >> c;

    cout << "---------------------------" << endl;
	cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    //将传入的形参改为指针类型  b -> p

    // 没有接受、使用function返回值
	// function(a, p, c);
    int &ans = function(a, p, c);

    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;


	//2. 引用规律分析
	int &r = a;
	r = a + b + c;
	a = r + a + b + c;

    // 引用不允许重定义
    //int &r = b;
    int &l = b;

    cout << "r = " << r << endl;
	cout << "a = " << a << endl;

	cout << "&r = " << &r << endl;
	cout << "&a = " << &a << endl;


	cout << "---------------------------" << endl;

	//3. 局部变量存储分析
	int i = 10, j = 20, k = 30;

	cout << "变量a的地址：" << &a << endl;
	cout << "变量b的地址：" << &b << endl;
	cout << "变量c的地址：" << &c << endl;


	//4. 动态内存申请分析

    // 申请动态内存错误
	// int *p1 = new int（10）;
    int *p1 = new int[10];
    int *p2 = new int[10]{10, 20, 30};

// 指针意义理解错误，上下交换

// 变量本身的地址
	cout << "变量p1地址：" << &p1 << endl;
	cout << "变量p2地址：" << &p2 << endl;

// 变量所指向的数组的首地址
	cout << "变量p1指向的地址：" << p1 << endl;
	cout << "变量p2指向的地址：" << p2 << endl;

    delete[] p1;
    delete[] p2;

    //cin.get();
    system("pause");
}