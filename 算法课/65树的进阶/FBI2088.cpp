#include <bits/stdc++.h>
using namespace std;
char fun(string &s,int l ,int r)
{
    //什么时候退出
    if(l==r)
    {
        char c = s[l]=='0'?'B':'I';
        cout<<c;// 当到达叶子节点时，函数需要返回该叶子节点的类型（B 或 I）
        //，并输出该类型。这是递归的基础。
        return c;
    }
    int mid = l+(r-l)/2;
    char lc = fun(s,l,mid);
    char rc = fun(s,mid+1,r);
    
    //当前节点的类型根据左右子树的类型判断
    char root;
    if(lc == rc)
    {
        root = lc;//左右孩子相等时父节点和子节点类型一样
    }
    else
    {
        root = 'F';
    }
    cout<<root;
    return root;
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    fun(s,0,s.size()-1);
    cout<<endl;
    return 0;
}