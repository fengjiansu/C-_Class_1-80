#include <bits/stdc++.h>

using namespace std;
struct Person {
    int age;
    string name;

    // 重载 < 操作符，按年龄比较
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

// 按名字比较
bool compareByName(const Person& p1, const Person& p2) {
    return p1.name < p2.name;
}

// 按年龄比较
bool compareByAge(const Person& p1, const Person& p2) {
    return p1.age < p2.age;
}

int main() {
    std::vector<Person> people = {{25, "Alice"}, {30, "Bob"}, {22, "Charlie"}};
    std::sort(people.begin(), people.end());  // 自动按年龄排序

    for (const auto& person : people) {
        std::cout << person.name << " " << person.age << std::endl;
    }
    sort(people.begin(), people.end(), compareByName);  // 按名字排序
    for (const auto& person : people) {
        std::cout << person.name << " " << person.age << std::endl;
    }
    return 0;
}
