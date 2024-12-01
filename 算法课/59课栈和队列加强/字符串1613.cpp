#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count_substr(const string &s, int k)
{
    int n = s.size(), l = 0, cnt = 0;long long res = 0;
    vector<int> freq(26, 0); // ��¼ÿ����ĸ��Ƶ��
    /*
    ��չ�ұ߽� r��
ÿ�ν� s[r] ���봰�ڣ����� freq �� cnt��
������߽� l��
�� cnt >= k ʱ��������߽磬ֱ�����ڲ�����������
ͬʱ�������� r Ϊ�Ҷ˵�����������������Ӵ�������
     */
    for (int r = 0; r < n; r++)
    {
        if (freq[s[r] - 'a']++ == 0)
            cnt++; // ��������ĸ

        while (cnt >= k)
        {                       // �����������
            res += n - r;       // ������ r Ϊ�Ҷ˵���Ӵ�������
            freq[s[l] - 'a']--; // �Ƴ���߽��ַ�
            if (freq[s[l] - 'a'] == 0)
                cnt--; // ����Ƴ�������������
            l++;       // ��С��߽�
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        int k;
        cin >> s >> k;
        cout << count_substr(s, k) << endl;
    }
    return 0;
}
