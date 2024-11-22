int slidingWindow(vector<int>& nums, int condition) {
    int n = nums.size();
    int l = 0;           // �������ڵ���߽�
    int cur = 0;        // ���ڵ�״̬����͡��������ȣ�
    int res = 0;         // ���Ž����

    for (int r = 0; r < n; r++) { // �ұ߽��ƶ�
        // ����ǰԪ�ؼ��봰�ڣ����´���״̬
        cur += nums[r];

        // ��鴰��״̬�Ƿ���������������������������߽�
        while (!isValid(cur, condition)) { 
            cur -= nums[l];
            l++;
        }

        // ���½��
        res = max(res, r - l + 1);
    }

    return res;
}
