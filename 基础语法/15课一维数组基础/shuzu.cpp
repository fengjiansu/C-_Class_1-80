#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a[10]; //定义时指定数组长度 ,数组下标从0开始
    // 默认初始化 在函数内部定义内置类型的数组
    // 默认初始化会令数组含有未定义的值 依赖于环境
    //初始化是创建变量时赋值 赋值的含义是把当前值擦除,以新值代替
    //显式初始化
    int a1[] = {0,1,2};//编译器会自动根据初始值推算
    int a2[5] = {0,1,2};// 等价于 a2[5] = {0,1,2,0,0}
    int a3[2] = {0,1,2}; //错误,初始值过多
    int a4[5] = {};//把所有元素初始化为 0 占用栈空间

    //访问数组元素,注意下标不能越界
    //不能拷贝和赋值
    return 0;
}
