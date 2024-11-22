#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000;
int s[N];
int top = -1;
//bool empty = false;
class mystack {
public:
	void push(int x) {
		s[++top] = x;
	}
	void pop() {
		top--;
	}
	void empty() {
		if (top == -1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	void query() {
		cout << s[top] << endl;
	}
};

int main() {

	mystack ms;
	
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			cout << "入栈:" << endl;
			int a;
			cin >> a;
			ms.push(a);
		}
		else if (s == "pop") {
			cout << "出栈:" << endl;
			ms.pop();
		}
		else if (s == "query") {
			cout << "查询" << endl;
			ms.query();
		}
		else {
			cout << "判空:" << endl;
			ms.empty();
		}
	}
	

	return 0;
}