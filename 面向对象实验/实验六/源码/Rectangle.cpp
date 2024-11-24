#include <iostream>
using namespace std;

class Rectangle {
private:
    double a, b; 

public:
    // 默认构造函数
    Rectangle() : a(0), b(0) {}

    
    Rectangle(double width, double height) : a(width), b(height) {}

    // 拷贝构造函数
    Rectangle(const Rectangle& rect) : a(rect.a), b(rect.b) {}


    ~Rectangle() {}

  
    double getA() const { return a; }
    double getB() const { return b; }

  
    void setA(double width) { a = width; }
    void setB(double height) { b = height; }

  
    double length() const { return 2 * (a + b); }

 
    double area() const { return a * b; }
};


void ObjectFunc(Rectangle v, Rectangle* p, Rectangle& r) {

    v.setA(10);
    v.setB(20);
    cout << "在 ObjectFunc 函数内部 (按值传递): a = " << v.getA() << ", b = " << v.getB() << endl;

   
    p->setA(10);
    p->setB(20);
    cout << "在 ObjectFunc 函数内部 (指针传递): a = " << p->getA() << ", b = " << p->getB() << endl;

   
    r.setA(10);
    r.setB(20);
    cout << "在 ObjectFunc 函数内部 (引用传递): a = " << r.getA() << ", b = " << r.getB() << endl;
}

int main() {
   
    Rectangle rect1(5, 8);
    Rectangle rect2(4, 6);
    Rectangle rect3(7, 9);

    cout << "调用 ObjectFunc 之前:" << endl;
    cout << "rect1: a = " << rect1.getA() << ", b = " << rect1.getB() << endl;
    cout << "rect2: a = " << rect2.getA() << ", b = " << rect2.getB() << endl;
    cout << "rect3: a = " << rect3.getA() << ", b = " << rect3.getB() << endl;

   
    ObjectFunc(rect1, &rect2, rect3);

    cout << "调用 ObjectFunc 之后:" << endl;
    cout << "rect1: a = " << rect1.getA() << ", b = " << rect1.getB() << " (未改变，按值传递)" << endl;
    cout << "rect2: a = " << rect2.getA() << ", b = " << rect2.getB() << " (已改变，指针传递)" << endl;
    cout << "rect3: a = " << rect3.getA() << ", b = " << rect3.getB() << " (已改变，引用传递)" << endl;

    return 0;
}
