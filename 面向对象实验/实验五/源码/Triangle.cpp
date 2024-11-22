#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Triangle {
private:
	int a,b,c;
	double Area;


public:
	void Sets(int x,int y,int z) {
		a = x;
		b = y;
		c = z;
	}
	double getArea() {
		double ans = (a + b + c) / 2;
		//cout << ans;
		return sqrt(ans * (ans - a) * (ans - b) * (ans - c));
	}

	void getShape() {
		if ((a * a + b * b) < (c * c)) {
			cout << "钝角三角形" << endl;
		}
		else if ((a * a + b * b) > (c * c)) {
			if (a == b && a == c) {
				cout << "等边三角形" << endl;
				return;
			}
			cout << "锐角三角形" << endl;
		}
		else {
			cout << "直角三角形" << endl;
		}
	}
	
};

int main() {

	Triangle res;
	int cn[3];
	cout << "请输入三角形的三边:";
	for (int i = 0; i < 3; i++) {
		cin >> cn[i];
	}
	sort(cn, cn + 3);
	res.Sets(cn[0], cn[1], cn[2]);
	double Area = res.getArea();
	cout << "三角形的面积:" << Area << endl;
	cout << "三角形的形状是:" ;
	res.getShape();

	return 0;
}