#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int count = 0;
    for (char c : s) {
        if (isalnum(c)) { // �ж��Ƿ�����ĸ������
            count++;
        }
    }

    cout << count << endl;
    return 0;
}