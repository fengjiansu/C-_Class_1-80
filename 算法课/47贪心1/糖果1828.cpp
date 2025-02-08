#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 /* 
 
 
  */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long x;
    cin >> n >> x;
    
    vector<long long> a(n);
    long long total = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }
    
    // b[i] ��ʾ���պ��� i �������ǹ���
    vector<long long> b(n, 0);
    // �� 1 ����������ܱ��� min(a[0], x) ��
    b[0] = min(a[0], x);
    // �ӵ� 2 �����ӿ�ʼ���±� 1��������ǰһ�����ӵı�����ȷ����ǰ���ӵ��Ͻ�
    for (int i = 1; i < n; i++){
        b[i] = min(a[i], x - b[i-1]);
    }
    
    long long sum_b = 0;
    for (int i = 0; i < n; i++){
        sum_b += b[i];
    }
    
    // �Ե����ǹ��� = ԭ������ - ����ܱ������ǹ���
    cout << total - sum_b << "\n";
    return 0;
}
