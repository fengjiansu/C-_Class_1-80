#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n), b(n), diff(n);
    
    // ���� a ���� (���ϳԵ�����ֵ)
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // ���� b ���� (���ϳԵ�����ֵ)
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // ��������ֵ�� diff[i] = a[i] - b[i]
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }

    // ���ɿ�����������ֵ��ֵ����
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }
    
    sort(idx.begin(), idx.end(), [&](int i, int j) {//lambda ���ʽ 
        return diff[i] > diff[j];  // ���ݲ�ֵ�Ӵ�С����
    });
    
    // �����������ֵ
    long long max_sweetness = 0;
    
    // ѡ��ǰ k ���ɿ��������ϳ�
    for (int i = 0; i < k; i++) {
        max_sweetness += a[idx[i]];
    }
    
    // ʣ����ɿ��������ϳ�
    for (int i = k; i < n; i++) {
        max_sweetness += b[idx[i]];
    }
    
    // ����������ֵ
    cout << max_sweetness << endl;
    
    return 0;
}
/* 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����ṹ��洢ÿ���ɿ���������ֵ
struct Chocolate {
    int morning_sweetness;  // ���ϵ�����ֵ
    int evening_sweetness;  // ���ϵ�����ֵ
    int diff;               // ����ֵ�� a[i] - b[i]
};

// �Զ�������������������ֵ��Ӵ�С����
bool compare(const Chocolate &a, const Chocolate &b) {
    return a.diff > b.diff;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Chocolate> chocolates(n);

    // ����ÿ���ɿ�������������ֵ
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i].morning_sweetness;
    }

    // ����ÿ���ɿ�������������ֵ
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i].evening_sweetness;
        // ��������ֵ��
        chocolates[i].diff = chocolates[i].morning_sweetness - chocolates[i].evening_sweetness;
    }

    // ��������ֵ��Ӵ�С����
    sort(chocolates.begin(), chocolates.end(), compare);

    long long max_sweetness = 0;

    // ѡ��ǰ k ���ɿ��������ϳԣ�ʣ�µ��ɿ��������ϳ�
    for (int i = 0; i < k; i++) {
        max_sweetness += chocolates[i].morning_sweetness;
    }
    for (int i = k; i < n; i++) {
        max_sweetness += chocolates[i].evening_sweetness;
    }

    // ����������ֵ
    cout << max_sweetness << endl;

    return 0;
}


 */
