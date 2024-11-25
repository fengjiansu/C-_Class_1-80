#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // ���ѣ��洢��С��һ��
    priority_queue<int, vector<int>, greater<int>> minHeap; // ��С�ѣ��洢�ϴ��һ��

public:
    // ��������
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);//����Ѵ洢����С�ڵ�����λ������
        else minHeap.push(num);//С���Ѵ洢���д�����λ������
        //��������
        /* 
         Ŀ����ż����ʱ��,����һ����
         ������ʱ��,��߶�һ��,������Ѷ�һ��
         */
        if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // ��ȡ��λ��
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            return maxHeap.top();
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // ��� 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl; // ��� 2
    return 0;
}
