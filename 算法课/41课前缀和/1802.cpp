/*
��Ŀ����



(1802) Napoleon Cake

Arkady��Ҫ�����⡣���������n��,���ƻ��ڵ�i���ai������,��Щ���ͻ��ʪ����(������i��)��ai��,
����֪��,���������ĵ����ÿһ���Ƿ������͡�
����
�����������,��һ������t���������������,������ÿһ�������������n������Ĳ���,������һ��n
��������ai,����:t��200,1��n��2��105,0��ai��n,��֤���в������ݵ�n֮�Ͳ�����2��105��
���
����ÿ���������,���һ��n����,ÿ����Ϊ0��1,�ֱ�����i���Ƿ������͡�
��������
3
6
0 3 0 0 1 3
10
0 0 0 1 0 5 0 0 0 2
3
000
�������
1 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 0 0

 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // ������������
    cin >> t;
    while (t--)
    {
        int n; // �������
        cin >> n;
        vector<int> a(n); // �洢ÿ�����͵�����
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> result(n, 0); // �洢ÿ���Ƿ�������
        int cream = 0;            // ��ǰ���͵ĸ��Ǻ��

        // �Ӻ���ǰ����
        for (int i = n - 1; i >= 0; i--)
        {
            cream = max(cream, a[i]); // ���µ�ǰ������͸��Ǻ��(̰���㷨)
            if (cream > 0)
            {
                result[i] = 1; // ��ǰ��������
                cream--;       // ���ٸ��Ǻ��
            }
        }

        // ������
        for (int i = 0; i < n; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*

#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[200005], b[200005];

void solve() {
    cin >> n;
    // ���� b ���飬ȷ��ÿ�ζ����������
    for (int i = 1; i <= n; i++) b[i] = 0;

    // ��ȡ���벢��������Ӱ�췶Χ
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i - a[i] + 1; // ��ʾ��ǰ�������Ӱ�췶Χ
    }

    int left_bound = 200000; // ��ʼ��һ���ϴ�ķ�Χ
    // �Ӻ���ǰ��������������Ӱ�췶Χ
    for (int i = n; i >= 1; i--) {
        left_bound = min(left_bound, a[i]); // ȡ����ķ�Χ
        if (left_bound <= i) { // �����ǰ����Ӱ�췶Χ��
            b[i] = 1; // ���Ϊ������
        }
    }

    // ������
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

 */