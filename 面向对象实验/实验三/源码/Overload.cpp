#include <iostream>

// 使用std命名空间，这样就可以直接使用其中的cout等，而无需写std::cout
using namespace std; 

// 交换两个整数
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 交换两个浮点数
void swap(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
}

// 交换两个双精度浮点数
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 5, num2 = 10;
    cout << "交换前（整数类型）：num1 = " << num1 << ", num2 = " << num2 << endl;
    swap(num1, num2);
    cout << "交换后（整数类型）：num1 = " << num1 << ", num2 = " << num2 << endl;

    float float1 = 3.14f, float2 = 6.28f;
    cout << "交换前（单精度浮点数类型）：float1 = " << float1 << ", float2 = " << float2 << endl;
    swap(float1, float2);
    cout << "交换后（单精度浮点数类型）：float1 = " << float1 << ", float2 = " << float2 << endl;

    double double1 = 2.71828, double2 = 3.14159;
    cout << "交换前（双精度浮点数类型）：double1 = " << double1 << ", double2 = " << double2 << endl;
    swap(double1, double2);
    cout << "交换后（双精度浮点数类型）：double1 = " << double1 << ", double2 = " << double2 << endl;
    return 0;
}