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
    cin >> n >> h;  // n：马路分段数，h：居民数量
    vector<Interval> intervals(h);
    for (int i = 0; i < h; i++){
        cin >> intervals[i].a >> intervals[i].b;
    }
    
    // 按区间左端点排序
    sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2){
        return i1.a < i2.a;
    });
    
    int trees = 0;  // 最少需要的树数
    // 当前组的公共交集，初始化为第一个区间
    int curL = intervals[0].a;
    int curR = intervals[0].b;
    
    // 遍历后续区间
    for (int i = 1; i < h; i++){
        // 计算与当前区间的交集
        int newL = max(curL, intervals[i].a);
        int newR = min(curR, intervals[i].b);
        if(newL <= newR) {
            // 交集非空，更新当前组交集
            curL = newL;
            curR = newR;
        } else {
            // 交集为空：当前组结束，需要种一棵树
            trees++;
            // 开启新组：当前区间作为新的交集
            curL = intervals[i].a;
            curR = intervals[i].b;
        }
    }
    // 最后一组也需要种树
    trees++;
    
    cout << trees << "\n";
    return 0;
}
