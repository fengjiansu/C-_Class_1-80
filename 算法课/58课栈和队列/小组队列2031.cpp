#include <bits/stdc++.h>
using namespace std;

const int MAX_ELEMENT = 1000000; // 题目中元素的最大值为 999999


int main()
{
    int t, cnt = 1;
    while (cin >> t && t != 0)
    {
        cout << "Scenario #" << cnt++ << endl;
        // 用数组来存储每个元素所属的团队编号
        int team[MAX_ELEMENT + 1];
        deque<int> q; //存储团队编号的顺序
        vector<deque<int>> v(t); // 通过下标访问
        // 标记当前团队是否在队列中，避免重复入队
        bool f[t];
        //fill 函数是memset的替换
        fill(f, f + t, false);
        for(int i=0;i<t;i++)
        {
            int m;
            cin>>m;
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                team[x] = i;
            }
        }
        string str;
        while(cin>>str&&str!="STOP")
        {
            if(str=="ENQUEUE")
            {
                int x;
                cin>>x;
                int id = team[x];
                if(!f[id])
                {
                    q.push_back(id);
                    f[id] = true;
                }
                v[id].push_back(x);
            }
            else if(str=="DEQUEUE")
            {
                int id = q.front(); //队首团队编号

                cout<<v[id].front()<<endl;
                v[id].pop_front();
                if(v[id].empty())
                {
                    q.pop_front();
                    f[id] = false;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
