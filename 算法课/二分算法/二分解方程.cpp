#include <iostream>
#include <cmath>

using namespace std;

// 定义常量
double s1 = 1.0, s2 = 1.0, s3 = 1.0, s4 = 1.0;
double a1 = -1.0, a2 = 1.0, a3 = -1.0, a4 = 1.0;

// 定义函数 f(x)
double f(double x) {
    return s1 / (x +a1) + s2 / (x + a2) + s3 / (x +a3) + s4 / (x + a4) - 0.5;
}

// 二分法求解
double binary_search(double l, double r, double epsilon = 1e-6) {
    while (r - l > epsilon) {
        double mid = (l + r) / 2.0;
        if (f(mid) == 0.0) {
            return mid;
        } else if (f(mid) * f(l) < 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return (l + r) / 2.0;
}

int main() {
    double l = 0, r = 50;  // 初始区间, 你可以根据情况调整
    double root = binary_search(l, r);
    cout << "解为: " << root << endl;
    return 0;
}
