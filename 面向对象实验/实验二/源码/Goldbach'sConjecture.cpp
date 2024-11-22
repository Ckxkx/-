#include <iostream>

using namespace std;

int N;
bool isEven(int ans){
    return (ans % 2 == 0);
}
bool isPrimeNumber(int x){
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x;i++){
        if (x % i == 0)
            return false;
    }
    return true;
}
void DecodeEvenToPrime(int num){
    for (int j = 2; j <= num / 2; j++){
        if (isPrimeNumber(j) && isPrimeNumber(num - j)){
            cout << "偶数" << num << "的素数分解结果为:" << num << "=" << j << '+' << num - j << endl;
        }
    }
}

int main(){

    
    cout << "请输入一个整数N(N > 6):";
    cin >> N;
    if (isEven(N)){
         for (int k = N; k >= 6;k -= 2){
            DecodeEvenToPrime(k);
        }
    }
    return 0;
}
