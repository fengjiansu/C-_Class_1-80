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
        // ��������a �±��0��ʼa[i]��ʾ�ܴ� ��i - a[i]�� a[i]
        // ����������1
        vector<int> b(n,0);
        for(int i = 0; i < n; i++)
        {
            int l = max(i - a[i]+1,0);
            //ע���Ҷ˵�Ҳ���ܳ���Χ
            int r = i;
            //int r = min(i+1,n-1);
            b[l] += 1;
            if(r+1 < n)
            {
                b[r+1] -= 1;
            }
            
        }
        /* 
        0 0 0 0 0 0
        2 -1 -1
         */
        int sum = 0;
        for(int i = 0; i <n; i++)
        {
            sum += b[i];
            if(sum == 0) cout<<0<<" ";
            else cout<<1<<" ";
        }
        cout<<"\n";
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