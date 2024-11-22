#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 函数用于找出具有最大数值总和的连续子序列
void FindMaxSumSequence(int* array, int n, int& startIndex, int& endIndex, int& maxSum) {
    maxSum = array[0];
    int currentSum = array[0];
    startIndex = 0;
    endIndex = 0;
    int tempStart = 0;
    for (int i = 1; i < n; i++) {
        currentSum += array[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
            startIndex = tempStart;
            endIndex = i;
        }
        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }
}

int main() {
    const int n = 10001;  // 数组大小大于10000
    int array[n];
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; i++) {
        // 生成[-1000, 1000]之间的随机数
        array[i] = rand() % 2001 - 1000;  
    }
    int startIndex, endIndex, maxSum;
    FindMaxSumSequence(array, n, startIndex, endIndex, maxSum);
    cout << "具有最大和的连续子序列: ";
    for (int i = startIndex; i <= endIndex; i++) {
        cout << array[i] << " ";
    }
    cout << "\n最大总和: " << maxSum << endl;
    return 0;
}