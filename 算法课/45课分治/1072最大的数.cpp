/* 
��Ŀ����

(1072)������

����n,������n������,�����n����������������
����
��һ�� ����һ������n(n <= 100)��
�ڶ�������n������,�ÿո����,��Щ����������(-2147483648,2147483647)��
���
���һ������,��ʾ��������
��������
8
26387154
�������
8

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

// �ݹ麯��������������ֵ
int findMax(const vector<int>& arr, int left, int right) {
    // ��׼������������ֻ��һ��Ԫ�أ����ظ�Ԫ��
    if (left == right) {
        return arr[left];
    }

    // �ҵ��м��
    // �� l �� r ���Ǻܴ��������ʱ�����ֱ����� (l + r)��
    //���ܻᵼ���������
    int mid = left + (right - left) / 2;

    // �ݹ������벿�ֺ��Ұ벿�ֵ����ֵ
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);

    // ���������нϴ��һ��
    return max(maxLeft, maxRight);
}
/* 
int findMax(int l,int r){


    if(r-l == 1) return a[l];
    int mid=(l+r)/2;
    int Imax=findMax(l,mid);
    int rmax=findMax(mid,r);
    return max(lmax,rmax);

}
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    //�÷��η���˼����
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout<<findMax(v,0,n-1);
    return 0;
}
