/* 
��Ŀ����

(1129)���������

����һ������Ϊn����������A1,A2,��,An,����������͡�
���仰˵,Ҫ�ҵ�1��isj��n,ʹ��Ai+Ai+1+ ��. +Aj������

����
��һ���������г���n,n��105���ڶ�����������n������(��Χ-1000~1000)��

���
һ������,��������͡�

��������
8
1 -3 7 -5 8 -3 -2 6

�������
11
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
#define REP(i,a,b) for(int i=a;i<b;i++)

// ���η�������������
int maxCross( vector<int>& arr, int left, int mid, int right) {
    // ���м�����������
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    // ���м�����������
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    // ���ؿ�Խ�м������
    return leftSum + rightSum;
}
// ����& ���ڴ泬�� ��Ϊÿ�ε��ö��Ὺ���µĿռ�
int maxSum(vi& v, int l, int r)
{
    if (l == r)
    {
        return v[l];
    }
    int mid = l + (r - l) / 2;
    int maxLeft = maxSum(v, l, mid);
    int maxRight = maxSum(v, mid + 1, r);
    // �����Խ�м������
    int crossMax = maxCross(v, l, mid, r);
    /* 
    max({leftMax, rightMax, crossMax}) �����÷��� C++11 �����ϰ汾�� std::max ���������ذ汾�������Խ���һ����ʼ���б����ڱȽ϶��ֵ�����������е����ֵ��

������ͣ�
{leftMax, rightMax, crossMax} ��һ����ʼ���б���ʾ��������ֵ����һ�������С�
max �����ڽ��ܳ�ʼ���б�ʱ����������е�����Ԫ�أ��������е����ֵ��
�����﷨ʹ�����ǿ������ɱȽ϶��ֵ��������ҪǶ�׵� max �������á�
     */
    return max({maxLeft, maxRight,crossMax});
}

int fun(vi& v, int l,int mid, int r)
{
    if(l == r) return v[l];
    fun(v, l, mid, mid);
    // ���м�����������
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= l; i--) {
        sum += v[i];
        leftSum = max(leftSum, sum);
    }

    // ���м�����������
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += v[i];
        rightSum = max(rightSum, sum);
    }
    // ���ؿ�Խ�м������
    return leftSum + rightSum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi v(n);
    REP(i, 0, n)
    {
        cin >> v[i];
    }
    cout<<maxSum(v, 0, n - 1);
    return 0;
}
