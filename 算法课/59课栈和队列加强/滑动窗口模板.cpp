int slidingWindow(vector<int>& nums, int condition) {
    int n = nums.size();
    int l = 0;           // 滑动窗口的左边界
    int cur = 0;        // 窗口的状态（如和、种类数等）
    int res = 0;         // 最优解变量

    for (int r = 0; r < n; r++) { // 右边界移动
        // 将当前元素加入窗口，更新窗口状态
        cur += nums[r];

        // 检查窗口状态是否满足条件，若不满足则收缩左边界
        while (!isValid(cur, condition)) { 
            cur -= nums[l];
            l++;
        }

        // 更新结果
        res = max(res, r - l + 1);
    }

    return res;
}
