#include <bits/stdc++.h>

using namespace std;

/* ѡ������ */
void selectionSort(vector<int> &nums) {
int n = nums.size();
// ��ѭ����δ��������Ϊ [i, n-1]
for (int i = 0; i < n - 1; i++) {
// ��ѭ�����ҵ�δ���������ڵ���СԪ��
int k = i;
for (int j = i + 1; j < n; j++) {
if (nums[j] < nums[k])
k = j; // ��¼��СԪ�ص�����
}
// ������СԪ����δ����������׸�Ԫ�ؽ���
swap(nums[i], nums[k]);
}
}

int main()
{
   
   return 0;
}
