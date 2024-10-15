#include <bits/stdc++.h>
using namespace std;

const int MAX_ELEMENT = 1000000; // ��Ŀ��Ԫ�ص����ֵΪ 999999


int main()
{
    int t, cnt = 1;
    while (cin >> t && t != 0)
    {
        cout << "Scenario #" << cnt++ << endl;
        // ���������洢ÿ��Ԫ���������Ŷӱ��
        int team[MAX_ELEMENT + 1];
        deque<int> q; //�洢�Ŷӱ�ŵ�˳��
        vector<deque<int>> v(t); // ͨ���±����
        // ��ǵ�ǰ�Ŷ��Ƿ��ڶ����У������ظ����
        bool f[t];
        //fill ������memset���滻
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
                int id = q.front(); //�����Ŷӱ��

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
