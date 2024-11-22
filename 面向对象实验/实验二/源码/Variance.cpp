#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

void GenerateRandNumbers(int l, int r, int acc, int cnt, double &mean, double &variance) {
    random_device rd;
    mt19937 gen(rd());

    // 控制范围
    uniform_real_distribution<double> dis(l, r);

    // 生成随机数并计算均值和方差
    double sum = 0.0;
    double sum_sq_diff = 0.0;
    mean = 0.0;
    variance = 0.0;
    int ans = 0;
    for (int i = 0; i < cnt; ++i) {
        double random_number = dis(gen);
        sum += random_number;
        sum_sq_diff += (random_number * random_number);

        // 控制小数位并输出
        cout << fixed << setprecision(acc) << random_number << ' ';
        ans++;
        if (ans % 5 == 0)
            puts("");
            
        }

    // 计算均值
    mean = sum / cnt;

    // 计算方差
    variance = (sum_sq_diff / cnt) - (mean * mean);
}

int main() {
    int a, b, c, num;
    double mean, variance;
    cout << "--------随机数生成器--------" << endl;
    
    cout << "*请输入数值区间a和b:";
    cin >> a >> b;
    cout << "*请输入数值精度位数:";
    cin >> c;
    cout << "*请输入随机数的数目:";
    cin >> num;

    cout << "随机数如下:" << endl;
    
    GenerateRandNumbers(a, b, c, num, mean, variance);
    
    cout << "----------------------" << endl;
    cout << "均值: " << fixed << setprecision(c) << mean << endl;
    cout << "方差: " << fixed << setprecision(c) << variance << endl;

    return 0;
}
