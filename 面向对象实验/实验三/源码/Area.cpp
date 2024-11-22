#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
// 判断是否能形成三角形
bool isTriangle(int a, int b, int c) {
    // 已经排序，只需要考虑 两条最小边之和是否大于第三条边就行，其实 a + b > c  ==   c - b < a;
    return (a + b > c);
}

// 计算三角形面积
double triangleArea(int a, int b, int c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {

    int m;
    cout << "请输入木棍的数目：" << endl;
    cin >> m;
    vector<int> ans(m);
    cout <<"请输入"<< m << "根木棍长度" << endl;
    for (int i = 0; i < m; i++) {
        cin >> ans[i];
    }

    
    int maxPerimeter = 0;
    double maxArea = 0;

    sort(ans.begin(), ans.end());
    for (int i = m - 1; i >= 2;i --){
        int c = ans[i];
        int l = 0, r = i - 1;

        while (l < r){
            int a = ans[l];
            int b = ans[r];

            if (isTriangle(a,b,c)){
                int Primeter = a + b + c;
                maxPerimeter = max(Primeter, maxPerimeter);
                double Area = triangleArea(a, b, c);
                maxArea = max(maxArea, Area);
                l++;
            } else {
                r--;
            }

        }
    }

        cout << "输出三角形周长最大值：" << maxPerimeter << endl;
    cout << "输出三角形面积的最大值：" << maxArea << endl;
    return 0;
}