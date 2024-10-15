#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int count = 0;
    for (char c : s) {
        if (isalnum(c)) { // 判断是否是字母或数字
            count++;
        }
    }

    cout << count << endl;
    return 0;
}