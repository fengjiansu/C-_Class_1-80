#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int a, b;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, h;
    cin >> n >> h;  // n����·�ֶ�����h����������
    vector<Interval> intervals(h);
    for (int i = 0; i < h; i++){
        cin >> intervals[i].a >> intervals[i].b;
    }
    
    // ��������˵�����
    sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2){
        return i1.a < i2.a;
    });
    
    int trees = 0;  // ������Ҫ������
    // ��ǰ��Ĺ�����������ʼ��Ϊ��һ������
    int curL = intervals[0].a;
    int curR = intervals[0].b;
    
    // ������������
    for (int i = 1; i < h; i++){
        // �����뵱ǰ����Ľ���
        int newL = max(curL, intervals[i].a);
        int newR = min(curR, intervals[i].b);
        if(newL <= newR) {
            // �����ǿգ����µ�ǰ�齻��
            curL = newL;
            curR = newR;
        } else {
            // ����Ϊ�գ���ǰ���������Ҫ��һ����
            trees++;
            // �������飺��ǰ������Ϊ�µĽ���
            curL = intervals[i].a;
            curR = intervals[i].b;
        }
    }
    // ���һ��Ҳ��Ҫ����
    trees++;
    
    cout << trees << "\n";
    return 0;
}
