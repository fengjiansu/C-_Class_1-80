#include<bits/stdc++.h>
using namespace std;

int main() {
    int c1, m1;  // 第一个桶的容量和牛奶量
    int c2, m2;  // 第二个桶的容量和牛奶量
    int c3, m3;  // 第三个桶的容量和牛奶量

    cin >> c1 >> m1;  // 输入第一个桶的容量和牛奶量
    cin >> c2 >> m2;  // 输入第二个桶的容量和牛奶量
    cin >> c3 >> m3;  // 输入第三个桶的容量和牛奶量

    for(int i = 0; i < 100; i++) {
        if(i % 3 == 0) {  // 第一次或第四次…… 第97次将桶1倒入桶2
            int pour = min(m1, c2 - m2);
            m1 -= pour;
            m2 += pour;
        } else if(i % 3 == 1) {  // 第二次或第五次…… 第98次将桶2倒入桶3
            int pour = min(m2, c3 - m3);
            m2 -= pour;
            m3 += pour;
        } else {  // 第三次或第六次…… 第99次将桶3倒入桶1
            int pour = min(m3, c1 - m1);
            m3 -= pour;
            m1 += pour;
        }
    }

    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;

    return 0;
}