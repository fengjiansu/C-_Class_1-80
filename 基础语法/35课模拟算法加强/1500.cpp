/*

���ڴ�Ҷ���ϲ����������Keeper Chen����һ�ҵ꣬��Ҷ�������������Ϊ�˻�������ѹ������Ҫ��Ʊ25���ҡ�

����ÿ�춼��ͬѧ�Ŷ��������������������ҹ����������ֱ���25��50��100��

���ǽ���ܲ��ɣ�Keeper Chen����ȥ�������Ǵ�Ǯliao�������ζ�ſ�ʼʱ��������ľ�����ҽ�����Ǯ�ġ�

����涨ÿ���Ŷӵ�ͬѧ��ֻ���Լ����Լ�һ���˵�Ʊ�����Ҳ������ƻ�ԭʼ˳����Ʊ�����Keeper Chen����һ��ľ�а취��Ǯ��ͬѧ�����ͬѧ���������ͬѧ�����ܽ��꿴���ˣ��ÿ���Ŷ��

Ȼ�����ʽ���Keeper Chen�ĵ����ܽ�������ͬѧ������

����
��һ�а���һ������N�������Ŷӵ�ͬѧ������

�ڶ�����N����a_ia
i
?
 ??��a_ia
i
?
 �������ڵ�iiλ��ͬѧ�õ����ҵ���N\le100000N��100000

���
���һ�а���һ������������Keeper Chen�ĵ�������ܽ���������ͬѧ������
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int count_25 = 0, count_50 = 0; // ��¼���е�25���Һ�50��������
    int customers = 0; // �ܽ����ͬѧ����

    for (int i = 0; i < n; i++) {
        if (coins[i] == 25) {
            count_25++;
            customers++;
        } else if (coins[i] == 50) {
            if (count_25 > 0) {
                count_25--;
                count_50++;
                customers++;
            } else {
                break; // �޷�����
            }
        } else if (coins[i] == 100) {
            if (count_50 > 0 && count_25 > 0) {
                count_50--;
                count_25--;
                customers++;
            } else if (count_25 >= 3) {
                count_25 -= 3;
                customers++;
            } else {
                break; // �޷�����
            }
        }
    }

    cout << customers << endl;
    return 0;
}
