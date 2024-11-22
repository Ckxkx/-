#include <iostream>

using namespace std;

bool isPrimeNumber(int x){
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x;i++){
        if (x % i == 0)
            return false;
    }
    return true;
}
int main(){

    int m;
    cout << "请输入任意一个整数:";
    cin >> m;
    
    // 使用流操纵器来控制输出的是false和true 
    cout << boolalpha <<"整数17是素数:"<< isPrimeNumber(m) << endl;

    return 0;
}
