/* 

С����һλð���ߣ�����Ϸ����Ҫ�ռ���Դ������װ������Ŀǰ�Ѿ��ռ���X��λ����Դ������Ҫ����װ������Ҫ�ﵽY��λ��Դ��

ÿ�죬С������ѡ���������ַ�ʽ���ռ���Դ��

��ͨ�ɼ������1��λ��Դ��
ǿ���ɼ������K��λ��Դ����ֻ���ڵ�ǰ��Դ������K��������ʱʹ�á�
����Ҫ����С�����㣬������Ҫ���������ʹ��Դ�����ﵽY��

���磬X=3��Y=11��K=2�� ��һ�죬��Դ����Ϊ3��ֻ��ѡ����ͨ�ɼ�����Դ������Ϊ4�� �ڶ��죬ѡ��ǿ���ɼ�����Դ������Ϊ6�� �������ƣ�������ÿ�춼����ʹ��ǿ���ɼ�����������ﵽ�ɼ�Ŀ�ꡣ

����
�����ÿո������������X��Y��K��1 �� X < Y �� 10^8 , 2 �� K < Y������ʾС����ǰ����Դ������Ŀ����Դ�������Լ�ǿ���ɼ�ʱ�ɲɼ�����Դ������

���
һ����������ʾС��������Ҫ���ѵ�������
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long x, y, k;
    cin >> x >> y >> k;

    long long days = 0;
    while (x < y) {
        if (x % k == 0) {
            // ����ʣ�����ͨ�� k �Ĳ������� y ������
            days += (y - x + k - 1) / k; // �ȼ��� ceil((y - x) / k)
            break;
        } else {
            // ��������һ�� k �ı���
            long long days_to_adjust = k - (x % k);
            if (x + days_to_adjust > y) {
                // �����������Ŀ�� y���������1����
                days += (y - x);
                break;
            }
            x += days_to_adjust;
            days += days_to_adjust;
        }
    }

    cout << days << endl;
    return 0;
}
��һ���߼�
#include <iostream>
using namespace std;

int main() {
    long long x, y, k;
    cin >> x >> y >> k;

    // ���Ѵﵽ�򳬹�Ŀ��
    if (x >= y) {
        cout << 0 << "\n";
        return 0;
    }

    long long days = 0;
    // �ҵ����ڵ��� x ����С k �ı���
    long long next_multiple = ((x + k - 1) / k) * k;

    // �����һ�� k �ı����� y ������ôֱ����һ��һ���ߵ� y
    if (next_multiple > y) {
        days = y - x;
    } else {
        // ���ߵ���һ�� k �ı���
        days += (next_multiple - x);
        // ����� k �ı������� k Ϊ�������� y
        long long remain = y - next_multiple;
        days += (remain + k - 1) / k; // �൱������ȡ���ĳ���
    }

    cout << days << "\n";
    return 0;
}
