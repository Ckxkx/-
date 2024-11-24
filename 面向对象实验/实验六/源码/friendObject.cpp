#include <iostream>
#include <cmath> 
using namespace std;

class Point {
private:
    double x, y; 

public:
   
    Point() : x(0), y(0) {}

   
    Point(double a, double b) : x(a), y(b) {}

   
    Point(const Point& r) : x(r.x), y(r.y) {}

    // 析构函数
    ~Point() {}

    
    double GetX() const { return x; }
    double GetY() const { return y; }

    
    double& GetX() { return x; }
    double& GetY() { return y; }

    
    void SetX(double ax) { x = ax; }
    void SetY(double ay) { y = ay; }

    // 声明友元函数，计算两点之间的距离
    friend double GetLength(Point& A, Point& B);
};

// 友元函数实现，计算两点之间的欧几里得距离
double GetLength(Point& A, Point& B) {
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}


void SwapAxis(double* xa, double* xb) {
    double temp = *xa;
    *xa = *xb;
    *xb = temp;
}


void SwapAxis(double& ra, double& rb) {
    double temp = ra;
    ra = rb;
    rb = temp;
}

int main() {
   
    Point P1(3, 4);
    Point P2(7, 1);

    cout << "初始状态:" << endl;
    cout << "P1: (" << P1.GetX() << ", " << P1.GetY() << ")" << endl;
    cout << "P2: (" << P2.GetX() << ", " << P2.GetY() << ")" << endl;

    // 计算两点之间的距离
    double distance = GetLength(P1, P2);
    cout << "P1 和 P2 之间的距离: " << distance << endl;

 
    SwapAxis(&P1.GetX(), &P1.GetY()); 
    cout << "指针法交换 P1 的横纵坐标后: (" << P1.GetX() << ", " << P1.GetY() << ")" << endl;


    SwapAxis(P2.GetX(), P2.GetY()); 
    cout << "引用法交换 P2 的横纵坐标后: (" << P2.GetX() << ", " << P2.GetY() << ")" << endl;

    return 0;
}
