#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    // �ѱ�Ŵ浽������
    deque<int> monkeys;
    for (int i = 1; i <= n; i++)
    {
        monkeys.push_back(i);
    }
    int index = 1;
    while (monkeys.size() > 1)
    {
        if (index > k)
        {
            index = 1;
        }
        if (index == k)
        {
            monkeys.pop_front();
        }
        else
        {
            monkeys.push_back(monkeys[0]);
            monkeys.pop_front();
        }
        index ++;
    }
    cout << monkeys[0] << endl;
    return 0;
}
