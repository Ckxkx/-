#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char *name;
    int id;
    int age;
    double score;

public:
    // 无参构造函数
    Student() : name(nullptr), id(0), age(0), score(0.0) {}

    // 有参构造函数
    Student(const char *name, int id, int age, double score) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->id = id;
        this->age = age;
        this->score = score;
    }

    // 拷贝构造函数
    Student(const Student &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->id = other.id;
        this->age = other.age;
        this->score = other.score;
    }

    // 获取学生信息
    void getInfo() const {
        cout << "姓名: " << name << ", 学号: " << id << ", 年龄: " << age << ", 成绩: " << score << endl;
    }

    // 修改学生信息
    void setInfo(const char *name, int id, int age, double score) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->id = id;
        this->age = age;
        this->score = score;
    }

    // 析构函数
    ~Student() {
        delete[] name;
    }
};

int main() {
    // 定义对象数组并初始化
    Student students[3] = {
        Student("Alice", 101, 20, 88.5),
        Student("Bob", 102, 21, 91.0),
        Student("Charlie", 103, 22, 85.0)
    };

    // 输出学生信息
    for (int i = 0; i < 3; i++) {
        students[i].getInfo();
    }

    // 使用拷贝构造函数
    Student copyStudent = students[0];
    cout << "\n拷贝构造函数创建的学生对象：" << endl;
    copyStudent.getInfo();

    return 0;
}