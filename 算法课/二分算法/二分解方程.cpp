#include <iostream>
#include <cmath>

using namespace std;

// ���峣��
double s1 = 1.0, s2 = 1.0, s3 = 1.0, s4 = 1.0;
double a1 = -1.0, a2 = 1.0, a3 = -1.0, a4 = 1.0;

// ���庯�� f(x)
double f(double x) {
    return s1 / (x +a1) + s2 / (x + a2) + s3 / (x +a3) + s4 / (x + a4) - 0.5;
}

// ���ַ����
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
    double l = 0, r = 50;  // ��ʼ����, ����Ը����������
    double root = binary_search(l, r);
    cout << "��Ϊ: " << root << endl;
    return 0;
}
