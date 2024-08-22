#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        dq.push_back(i);
    }
    int sum = 0;
    int last = 0;       //  dq 1 2 3 4
    while (!dq.empty())  // v  1 2 1 4 2
                        //last 0 1
                        
    {
        last = dq[0];
        if (v[last] > m)
        {
            v[last] -= m;
            dq.pop_front();
            dq.push_back(last);
        }
        else
        {
            dq.pop_front();
        }
        sum += m;
        //cout << last << " " << sum << endl;
    }
    cout << last+1 << " " << sum << endl;
    return 0;
}
