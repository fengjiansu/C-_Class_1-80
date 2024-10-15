#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

using namespace std;

string generate_name(int length) {
    string name;
    for (int i = 0; i < length; ++i) {
        name += (rnd.next(0, 1) == 0) ? rnd.next('a', 'z') : rnd.next('A', 'Z');
    }
    return name;
}

long long generate_proficiency() {
     // 50% 的数据较小，50% 的数据较大
    if (rnd.next(0, 1) == 0) {
        return rnd.next(1LL, 100LL); // 较小的数值范围
    } else {
        return rnd.next(100LL, 100000LL); // 较大的数值范围
    }
}

void generate_test_case(int n, int m, const string& filename) {
    ofstream out(filename, ios::out | ios::binary);
    // out.imbue(locale("en_US.UTF-8"));
out << n << " " << m << "\n";

    for (int i = 0; i < n; ++i) {
        string name = generate_name(rnd.next(3, 9));
        long long proficiency = generate_proficiency();
        out << name << " S " << proficiency << "\n";
    }

    for (int i = 0; i < m; ++i) {
        string name = generate_name(rnd.next(3, 9));
        long long proficiency = generate_proficiency();
        out << name << " H " << proficiency << "\n";
    }

    out.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <n> <m> <output_file>\n";
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    string filename = argv[3];

    generate_test_case(n, m, filename);

    cout << "Test case generated and saved to " << filename << "\n";
    return 0;
}