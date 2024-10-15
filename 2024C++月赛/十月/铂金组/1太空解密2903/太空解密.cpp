#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    string input;
    getline(cin, input);

    // 第 1 个提示
    string hint1 = input;
    for (char &c : hint1) {
        if (isalpha(c)) {
            c = '.';
        }
    }
    cout << hint1 << endl;

    // 第 2 个提示
    int letterCount = 0;
    for (char c : input) {
        if (isalpha(c)) {
            letterCount++;
        }
    }
    int N = round(letterCount / 3.0);
    string hint2 = hint1;
    int count = 0;
    for (int i = 0; i < input.size(); i++) {
        if (isalpha(input[i])) {
            if (count < N) {
                hint2[i] = input[i];
                count++;
            }
        }
    }
    cout << hint2 << endl;

    // 第 3 个提示
    string hint3 = hint2;
    bool hasVowel = false;
    for (int i = 0; i < input.size(); i++) {
        if (isalpha(input[i]) && isVowel(input[i]) && hint2[i] == '.') {
            hint3[i] = input[i];
            hasVowel = true;
        }
    }
    if (!hasVowel) {
        int twoThirds = round(2.0 * letterCount / 3.0);
        count = 0;
        for (int i = 0; i < input.size(); i++) {
            if (isalpha(input[i])) {
                if (count < twoThirds) {
                    hint3[i] = input[i];
                    count++;
                }
            }
        }
    }
    cout << hint3 << endl;

    return 0;
}