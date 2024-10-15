#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string name;
    char academy;
    long long proficiency;
};

bool compareProficiency(const Student& a, const Student& b) {
    return a.proficiency > b.proficiency;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Student> silverlightAcademy;
    vector<Student> hallowcrestAcademy;

    for (int i = 0; i < n + m; ++i) {
        Student student;
        cin >> student.name >> student.academy >> student.proficiency;
        if (student.academy == 'S') {
            silverlightAcademy.push_back(student);
        } else {
            hallowcrestAcademy.push_back(student);
        }
    }

    // Sort the students by proficiency in descending order to ensure the strongest students are prioritized during the ban and pick phases
    sort(silverlightAcademy.begin(), silverlightAcademy.end(), compareProficiency);
    sort(hallowcrestAcademy.begin(), hallowcrestAcademy.end(), compareProficiency);

    // Ban Phase: Select the students to be banned based on the proficiency rankings
    vector<Student> silverlightBanned(silverlightAcademy.begin(), silverlightAcademy.begin() + min(5, static_cast<int>(silverlightAcademy.size())));
    vector<Student> hallowcrestBanned(hallowcrestAcademy.begin(), hallowcrestAcademy.begin() + min(2, static_cast<int>(hallowcrestAcademy.size())));

    // Remove the banned students from the available pool
    silverlightAcademy.erase(silverlightAcademy.begin(), silverlightAcademy.begin() + min(5, static_cast<int>(silverlightAcademy.size())));
    hallowcrestAcademy.erase(hallowcrestAcademy.begin(), hallowcrestAcademy.begin() + min(2, static_cast<int>(hallowcrestAcademy.size())));

    // Pick Phase: Select the students to represent each academy
    if (!hallowcrestAcademy.empty()) {
        cout << hallowcrestAcademy[0].name << endl;
    }

    for (int i = 0; i < min(4, static_cast<int>(silverlightAcademy.size())); ++i) {
        cout << silverlightAcademy[i].name << endl;
    }

    return 0;
}