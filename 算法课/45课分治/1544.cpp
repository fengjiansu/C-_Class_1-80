/*
��Ŀ����

��������
4
1231

(1544)��ֵı���

��2��ֻ�����з������һ��ٰ���һ��ʯͷ����������������һ����ֵı���,��Ϊ����ֻ���ʯͷ,
�зֻ�������,������ֻ�������Ϊ���ñ������������,�������ǻ���������˵�˳��,���Һ���
Ϊ1~2n,Ȼ��ʼ����������������̭��:
1.��1�ź�2�ű���,3�ź�4�ű���,��
2.1�ź�2�ŵ�ʤ����3�ź�4�ŵ�ʤ�߱���,5�ź�6�ŵ�ʤ����7�ź�8�ŵ�ʤ�߱���,��
һֱ���ھ����֡�
�������������������ͬһ�ֶ���,��ô���ǹ涨��Ŵ�Ļ�ʤ��
����
��һ������2��,�ڶ���2����,1�����Ǵ���,2�������з,3���������ܡ�n��13��
���
���ʤ�ߵı��
�������
3



 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)

int match(vi &v, int a, int b)
{
    // ʯͷʤ����������ʤ������ʤʯͷ
    if ((v[a] == 1 && v[b] == 2) || // ʯͷʤ����
        (v[a] == 2 && v[b] == 3) || // ����ʤ��
        (v[a] == 3 && v[b] == 1))
    { // ��ʤʯͷ
        return a;
    }
    else if (v[a] == v[b])
    {
        // ͬ�ද���������Ŵ�Ļ�ʤ
        return max(a, b);
    }
    else
    {
        return b;
    }
}

// �ҳ���ʤ��
int win(vi &v, int l, int r)
{
    if (l == r)
    {
        return l; // ��ֻ��һ��������ʱ��ֱ�ӷ�������
    }
    int mid = l + (r - l) / 2;
    int winnerLeft = win(v, l, mid);            // �����ʤ��
    int winnerRight = win(v, mid + 1, r);       // �Ұ���ʤ��
    return match(v, winnerLeft, winnerRight); // ����ʤ�߶Ծ�����������ʤ��
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi v(n + 1);
    REP(i, 1, n + 1) // ʹ��1��2n�ı��
    {
        cin >> v[i];
    }
    cout << win(v, 1, n);
    return 0;
}
