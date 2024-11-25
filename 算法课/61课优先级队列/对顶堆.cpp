#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // 最大堆：存储较小的一半
    priority_queue<int, vector<int>, greater<int>> minHeap; // 最小堆：存储较大的一半

public:
    // 插入数据
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);//大根堆存储所有小于等于中位数的数
        else minHeap.push(num);//小根堆存储所有大于中位数的数
        //调整规则
        /* 
         目的是偶数的时候,左右一样多
         奇数的时候,左边多一个,即大根堆多一个
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

    // 获取中位数
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
    cout << mf.findMedian() << endl; // 输出 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl; // 输出 2
    return 0;
}
