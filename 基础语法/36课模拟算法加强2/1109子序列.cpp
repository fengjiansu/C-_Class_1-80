/* 
��Ŀ����

(1109)������

���������ַ���s��t,���Ƿ��ܴ�t��ɾ��0�����߶���ַ�(�����ַ�˳�򲻱�),�õ��ַ�
��s������,abcde���Եõ�bce,���޷��õ�dc���ַ������Ȳ�����10�㡣
����
ÿ�������ֱ�Ϊs��t���������롣
���
�������������Yes"���ߡ�No",ÿ������ռһ�С�
��������
sequence subsequence
person compression
VERDI viva VittorioEmanueleReDiltalia
caseDoesMatter CaseDoesMatter

�������
Yes
No
Yes
No

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

// ��t���ҳ�s,ͨ��ɾ���ַ��ķ�ʽ
bool isSubsequence(const string& s, const string& t) {
    int j = 0;  // ָ�� s ��ָ��
    int i = 0;  // ָ�� t ��ָ��
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;  // ���ƥ�䣬i �����ƣ�ƥ�� s ����һ���ַ�
        }
        j++;  // �����Ƿ�ƥ�䣬t ��ָ�붼������
    }
    return i == s.length();  // ��� i ������ s��˵�� s �� t ��������
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    // ʹ�� while ѭ���������������
    while (cin >> s >> t) {
        if (isSubsequence(s, t)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
