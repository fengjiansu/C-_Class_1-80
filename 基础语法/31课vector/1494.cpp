#include <bits/stdc++.h>

using namespace std;

struct nm
{
    int num;
    int id;
    int rank;
} x;
bool cmp1(nm a, nm b)
{
    return a.num < b.num;
}
bool cmp2(nm a, nm b)
{
    return a.id < b.id;
}
int main()
{
    int n;
    cin>>n;
    deque<nm> dq;
    for (int i = 0; i < n; i++)
    {
        cin >> x.num;
        x.id = i;
        dq.push_back(x);
    }
    sort(dq.begin(), dq.end(), cmp1);
    dq.pop_front();
    for(int i = 0; i < dq.size(); i++)
    {
        dq[i].rank = i + 1;
    }
    sort(dq.begin(), dq.end(), cmp2);
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i].rank << " ";
    }
    return 0;
}
