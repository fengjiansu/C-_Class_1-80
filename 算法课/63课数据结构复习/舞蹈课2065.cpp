/* #include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

struct Person {
    char gender;  // 'B' for male, 'G' for female
    int skill;
    int index;    // ԭʼ���������ڼ�¼���˳��
};

int main() {
    int n;
    cin >> n;

    string genders;
    cin >> genders;

    vector<int> skills(n);
    for (int i = 0; i < n; ++i) {
        cin >> skills[i];
    }

    // �������˳�ʼ��������
    list<Person> dancers;
    for (int i = 0; i < n; ++i) {
        dancers.push_back({genders[i], skills[i], i});
    }

    vector<pair<int, int>> result;  // �洢��Խ�� (index1, index2)

    // ��ʼģ�����
    while (true) {
        auto it = dancers.begin();
        auto next_it = next(it);
        bool found = false;

        int min_diff = INT_MAX;
        auto best_pair = make_pair(dancers.end(), dancers.end());  // �����Եĵ�����

        // �ҵ���С���ܲ���������
        while (next_it != dancers.end()) {
            if (it->gender != next_it->gender) {  // ֻ�����Բ����
                int diff = abs(it->skill - next_it->skill);
                if (diff < min_diff) {
                    min_diff = diff;
                    best_pair = {it, next_it};
                    found = true;
                }
            }
            ++it;
            ++next_it;
        }

        if (!found) break;  // û���ҵ��κ�������ԣ��˳�ѭ��

        // ��¼��Ե�ԭʼ����
        result.push_back({best_pair.first->index, best_pair.second->index});

        // ɾ������Ե�������
        dancers.erase(best_pair.first);
        dancers.erase(best_pair.second);
    }
    cout<<result.size()<<"\n";
    // ������˳��
    for (const auto& p : result) {
        cout << p.first + 1 << " " << p.second + 1 << endl;  // +1 תΪ1-based����
    }

    return 0;
} */

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;

struct Person {
    char gender;
    int skill;
    int index;
};

struct Pair {
    list<Person>::iterator left, right;
    int diff;
    bool operator<(const Pair& other) const {
        if (diff == other.diff) {
            return left->index > other.left->index;  // �����ֵ��ȣ�ѡ������ߵ�
        }
        return diff > other.diff;  // С���ѣ���ֵС������ ����trueʱ��һ��Ԫ�ػᱻ���ں���
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string genders;
    cin >> genders;

    vector<int> skills(n);
    for (int i = 0; i < n; ++i) {
        cin >> skills[i];
    }

    // ʹ������洢�����ˣ��������ɾ������
    list<Person> dancers;
    for (int i = 0; i < n; ++i) {
        dancers.push_back({genders[i], skills[i], i + 1});  // index �� 1 ��ʼ
    }

    // ���ȼ����У�С���ѣ����洢���������������
    priority_queue<Pair> pq;

    // ��ʼ�����ȼ����У��������г�ʼ�������������
    //next �������ڴӵ�ǰ��������ǰ��������ƶ�һ���������������µĵ�������
    //��������Ԫ�ص���Ϣʱͨ������������
    for (auto it = dancers.begin(); next(it) != dancers.end(); ++it) {
        auto next_it = next(it);
        if (it->gender != next_it->gender) {
            int diff = abs(it->skill - next_it->skill);
            pq.push({it, next_it, diff});
        }
    }

    vector<pair<int, int>> result;  // �洢�������Խ��

    // ģ�����
    while (!pq.empty()) {
        Pair p = pq.top();
        pq.pop();

        // ������������Ѳ������ڣ����������
        if (next(p.left) != p.right) continue;

        // ��¼��Խ��
        int left_index = p.left->index;
        int right_index = p.right->index;
        if (left_index > right_index) swap(left_index, right_index);
        result.push_back({left_index, right_index});

        // ɾ����Ե�����
        //�����ڶ��׵����
        auto new_left = (p.left == dancers.begin()) ? dancers.end() : prev(p.left);
        auto new_right = next(p.right);

        dancers.erase(p.left);
        dancers.erase(p.right);

        // ����²���������Ԫ�������ԣ�����������ȼ�����
        if (new_left != dancers.end() && new_right != dancers.end() &&
            new_left->gender != new_right->gender) {
            int new_diff = abs(new_left->skill - new_right->skill);
            pq.push({new_left, new_right, new_diff});
        }
    }

    // �����Խ��
    cout << result.size() << "\n";
    for (const auto& p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

������Ŀ����ģ��һ���赸��ԵĹ��̣�ÿ�δӶ������ҵ����ܲ���С���������ԣ��������ǳ��С�Ϊ��ʵ����һĿ�꣬����ʹ������������ȼ����еĽ������Ч�ؽ���ģ�⡣

1. **�����ʹ��**��
   - ���������洢���еĲ����ߣ�������ÿ��ɾ�����е����ʱ�����Ը�Ч�����ɾ�����������������Ƶ���ƶ���

2. **���ȼ����е�ʹ��**��
   - ����ʹ��һ�����ȼ����У�С���ѣ����洢�������ڵ�������ԣ����������ǵļ��ܲ��������
   - ���ȼ����е���������Ǽ��ܲ�ֵ��С��������ȳ��У�������ܲ�ֵ��ͬ����ѡ��λ�ø��������ԡ�

3. **��ʼ����ģ�����**��
   - ���ȣ����������ڵ�������Լ������ȼ����С�
   - ��ÿ��ģ������У�ȡ�����ܲ���С����ԣ�������Դ�������ɾ����
   - ɾ���󣬼�����γɵ�����Ԫ���Ƿ�Ϊ���ԣ�����ǣ����µ���Լ������ȼ����С�
   - ��һ���̳�����û�и��������Ե���������Ϊֹ��

4. **������Ч���**��
   - �������ȼ������е���Կ����ں���������ʧЧ��������һ��������Ԫ���Ѿ���ɾ�����������ȡ��һ�����ʱ��Ҫ��������Ƿ���Ȼ���ڡ�

### ʱ�临�Ӷȣ�
- ��ʼ�����ȼ����е�ʱ�临�Ӷ�Ϊ \(O(n \log n)\)��
- ÿ��ɾ���͸��²����ĸ��Ӷ�Ϊ \(O(\log n)\)��
- ��ˣ����帴�Ӷ�Ϊ \(O(n \log n)\)���ʺϴ��ģ���롣

