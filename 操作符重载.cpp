#include <bits/stdc++.h>

using namespace std;
struct Person {
    int age;
    string name;

    // ���� < ��������������Ƚ�
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

// �����ֱȽ�
bool compareByName(const Person& p1, const Person& p2) {
    return p1.name < p2.name;
}

// ������Ƚ�
bool compareByAge(const Person& p1, const Person& p2) {
    return p1.age < p2.age;
}

int main() {
    std::vector<Person> people = {{25, "Alice"}, {30, "Bob"}, {22, "Charlie"}};
    std::sort(people.begin(), people.end());  // �Զ�����������

    for (const auto& person : people) {
        std::cout << person.name << " " << person.age << std::endl;
    }
    sort(people.begin(), people.end(), compareByName);  // ����������
    for (const auto& person : people) {
        std::cout << person.name << " " << person.age << std::endl;
    }
    return 0;
}
