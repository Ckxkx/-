#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* str;  // 动态分配的字符数组
    int len;    // 字符串的长度，使用int类型

public:
    // 默认构造函数
    MyString() : str(nullptr), len(0) {
        str = new char[1];  // 空字符串
        str[0] = '\0';
    }

    // 构造函数，初始化字符串
    MyString(const char* s) {
        if (s) {
            len = strlen(s);
            str = new char[len + 1];  
            strcpy(str, s);
        } else {
            str = new char[1];  // 空字符串
            str[0] = '\0';
            len = 0;
        }
    }

    // 拷贝构造函数
    MyString(const MyString& other) {
        len = other.len;
        str = new char[len + 1];  
        strcpy(str, other.str);
    }

    // 析构函数
    ~MyString() {
        delete[] str;
    }

    // 获取字符串的长度
    int length() const {
        return len;
    }

    // 字符串拼接
    MyString operator+(const MyString& other) const {
        MyString newStr;
        newStr.len = len + other.len;
        newStr.str = new char[newStr.len + 1];
        
        strcpy(newStr.str, str);           // 先拷贝当前字符串
        strcat(newStr.str, other.str);     // 拼接另外一个字符串
        
        return newStr;
    }

    // 字符串大小比较
    int compare(const MyString& other) const {
        return strcmp(str, other.str);
    }

    // 查找字符
    int find(char c) const {
        for (int i = 0; i < len; i++) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;  // 找不到返回-1
    }

    // 替换字符
    void replace(char oldChar, char newChar) {
        for (int i = 0; i < len; i++) {
            if (str[i] == oldChar) {
                str[i] = newChar;
            }
        }
    }

    // 输出字符串
    void print() const {
        cout << str << endl;
    }

    // 获取底层的字符数组
    const char* getCStr() const {
        return str;
    }
};

// 测试函数
int main() {
    MyString str1("I prefer c++");
    MyString str2(" to java !");
    MyString str3 = str1 + str2;  // 字符串拼接

    str3.print();  

    cout << "Length of str3: " << str3.length() << endl;  // 输出 22

    cout << "Comparing str1 and str2: " << str1.compare(str2) << endl;  // 输出正数，表示str大于str2

    int pos = str3.find('W');
    if (pos != -1) {
        cout << "'W' found at position: " << pos << endl;
    }

    str3.replace('!', '?');
    str3.print();  // 输出 " I prefer c++ to java ?"

    return 0;
}
