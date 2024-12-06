#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RFOR(it, c) for (auto &it : c)
/*
输入整数n,按字典序从小到大的顺序输出前n个数的所有排列
先输出以1开头的序列,后面是2-9的序列
以2开头的序列,后面是1,3-9的序列
前面的序列确定了之后,后面的问题转化为前面序列出现过的不能再选
已经确定的前缀序列 A
待选择的集合S
伪代码:
void print_permutation(序列A,集合S)
{
    if(S为空) 输出A;
    else 按照从小到大的顺序依次考虑s中的每个元素v
    {
    print_permutation(A+v, S-{v});
    }

}
序列A 用数组vector表示
集合S 不需要保存 它是由A得到的-A中没有出现的元素
*/

void print_permutation(vector<int> &A, int n)
{
    if (A.size() == n)
    {
        RFOR(it, A)
        cout << it << " ";
        cout << "\n";
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            /* if(find(A.begin(),A.end(),i)==A.end())
            {
                A.PB(i);
                print_permutation(A,n);
                A.pop_back();
            } */
            bool ok = 1;
            for (int j = 0; j < A.size(); j++)
            {
                if (A[j] == i)
                    ok = 0;
            } //这个时候的时间复杂度是n*k 优化一下 把这个循环优化掉
            if (ok)
            {
                A.PB(i);
                print_permutation(A, n);
                A.pop_back(); // 可以先不写这段代码,展示一下,然后再问递归的时候返回到上一层比如找到123了之后是不是要回到12,之后再回到1
            }
        }
    }
}

/*

针对上面的代码,可以引入回溯法,回溯是一种特殊的DFS,它会在发现路径无效或不符合条件时回溯,返回到上一个节点重新选择,
它针对于所有符合条件的解或找到特定的解,在搜索的过程中排除不符合条件的路径.
回溯法另一个区别在于在DFS的基础上加上了剪枝策略,在每个节点上判断是否满足条件,
不满足的就不进行递归,就像把多余的枝干剪掉一样,称为剪枝策略.
回溯法是有模板的,回溯法是特殊的DFS,是递归函数
返回值和参数 返回值一般是void,参数随着逻辑分析确定
终止条件    存放答案
遍历过程    for循环来实现遍历所有节点,在for循环里面做递归调用

void backtracking(参数)
{
    //这里可以让同学来写
    if(终止条件) {存放结果;return;}

    for(选择要遍历的元素)
    {
        处理节点;
        backtracking(参数);
        撤销操作;
    }
}

 */

int a[15], n;
void dfs(int k)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << "";
        cout << endl;
        return;

        for (int i = 1; i <= n; i++)
        { // 枚举所有能填的数
            int ok = 1;
            for (int j = 1; j < k; j++)
            { // 这个数如果在a[1]到a[k-1]中出现过了,则不能再选
                if (a[j] == i)
                    ok = 0;

                if (ok)
                {
                    a[k] = i;   // 把数i填到k这个位置上
                    dfs(k + 1); // 递归搜索下一层
                }
            }
        }
    }
}
/* 
第一个版本的代码不需要显式的回溯是因为它在使用一个固定大小的数组 a[15] 来存储当前的排列序列，并且在每次递归调用时，通过 a[k] = i 将当前数字填入位置 k。在递归调用 dfs(k + 1) 后，并没有显式地将 a[k] 恢复为之前的状态，因为：

固定位置的直接覆盖：在递归返回到上一层时，程序继续尝试下一个未使用的数字直接覆盖 a[k] 的值，因此无需显式撤销之前的操作。递归调用只改变当前的位置 a[k]，不影响其他位置的内容。

下标递增特性：dfs 函数通过 k 参数控制填入的位置，每次进入下一层递归时，总是填入 a[k]，而不会影响 a[1] 到 a[k-1] 的内容。因此，回溯时只需返回到 k - 1 位置并继续枚举下一个数。

不需要动态调整数组长度：由于数组是固定大小，不需要在每次填入或移除元素时调整其长度，所以不需要像 vector 那样调用 pop_back。
                                                   
 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    print_permutation(a, 3);
    return 0;
}