/* #include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

struct Person {
    char gender;  // 'B' for male, 'G' for female
    int skill;
    int index;    // 原始索引，用于记录配对顺序
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

    // 将所有人初始化进链表
    list<Person> dancers;
    for (int i = 0; i < n; ++i) {
        dancers.push_back({genders[i], skills[i], i});
    }

    vector<pair<int, int>> result;  // 存储配对结果 (index1, index2)

    // 开始模拟过程
    while (true) {
        auto it = dancers.begin();
        auto next_it = next(it);
        bool found = false;

        int min_diff = INT_MAX;
        auto best_pair = make_pair(dancers.end(), dancers.end());  // 最佳配对的迭代器

        // 找到最小技能差的异性配对
        while (next_it != dancers.end()) {
            if (it->gender != next_it->gender) {  // 只有异性才配对
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

        if (!found) break;  // 没有找到任何异性配对，退出循环

        // 记录配对的原始索引
        result.push_back({best_pair.first->index, best_pair.second->index});

        // 删除已配对的两个人
        dancers.erase(best_pair.first);
        dancers.erase(best_pair.second);
    }
    cout<<result.size()<<"\n";
    // 输出配对顺序
    for (const auto& p : result) {
        cout << p.first + 1 << " " << p.second + 1 << endl;  // +1 转为1-based索引
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
            return left->index > other.left->index;  // 如果差值相等，选择最左边的
        }
        return diff > other.diff;  // 小根堆：差值小的优先 返回true时第一个元素会被放在后面
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

    // 使用链表存储所有人，方便进行删除操作
    list<Person> dancers;
    for (int i = 0; i < n; ++i) {
        dancers.push_back({genders[i], skills[i], i + 1});  // index 从 1 开始
    }

    // 优先级队列（小根堆），存储所有相邻异性配对
    priority_queue<Pair> pq;

    // 初始化优先级队列，加入所有初始的相邻异性配对
    //next 函数用于从当前迭代器向前（或向后）移动一定步数，并返回新的迭代器。
    //相邻两个元素的信息时通过迭代器访问
    for (auto it = dancers.begin(); next(it) != dancers.end(); ++it) {
        auto next_it = next(it);
        if (it->gender != next_it->gender) {
            int diff = abs(it->skill - next_it->skill);
            pq.push({it, next_it, diff});
        }
    }

    vector<pair<int, int>> result;  // 存储跳舞的配对结果

    // 模拟过程
    while (!pq.empty()) {
        Pair p = pq.top();
        pq.pop();

        // 如果左右两人已不再相邻，跳过该配对
        if (next(p.left) != p.right) continue;

        // 记录配对结果
        int left_index = p.left->index;
        int right_index = p.right->index;
        if (left_index > right_index) swap(left_index, right_index);
        result.push_back({left_index, right_index});

        // 删除配对的两人
        //考虑在队首的情况
        auto new_left = (p.left == dancers.begin()) ? dancers.end() : prev(p.left);
        auto new_right = next(p.right);

        dancers.erase(p.left);
        dancers.erase(p.right);

        // 如果新产生的相邻元素是异性，将其加入优先级队列
        if (new_left != dancers.end() && new_right != dancers.end() &&
            new_left->gender != new_right->gender) {
            int new_diff = abs(new_left->skill - new_right->skill);
            pq.push({new_left, new_right, new_diff});
        }
    }

    // 输出配对结果
    cout << result.size() << "\n";
    for (const auto& p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

这道题的目标是模拟一个舞蹈配对的过程，每次从队伍中找到技能差最小的相邻异性，并让他们出列。为了实现这一目标，我们使用了链表和优先级队列的结合来有效地进行模拟。

1. **链表的使用**：
   - 链表被用来存储所有的参与者，这样在每次删除出列的配对时，可以高效地完成删除操作，避免数组的频繁移动。

2. **优先级队列的使用**：
   - 我们使用一个优先级队列（小根堆）来存储所有相邻的异性配对，并根据它们的技能差进行排序。
   - 优先级队列的排序规则是技能差值较小的配对优先出列，如果技能差值相同，则选择位置更靠左的配对。

3. **初始化和模拟过程**：
   - 首先，将所有相邻的异性配对加入优先级队列。
   - 在每次模拟过程中，取出技能差最小的配对，并将这对从链表中删除。
   - 删除后，检查新形成的相邻元素是否为异性，如果是，则将新的配对加入优先级队列。
   - 这一过程持续到没有更多可以配对的相邻异性为止。

4. **跳过无效配对**：
   - 由于优先级队列中的配对可能在后续操作中失效（即其中一个或两个元素已经被删除），因此在取出一个配对时需要检查它们是否仍然相邻。

### 时间复杂度：
- 初始化优先级队列的时间复杂度为 \(O(n \log n)\)。
- 每次删除和更新操作的复杂度为 \(O(\log n)\)。
- 因此，总体复杂度为 \(O(n \log n)\)，适合大规模输入。

