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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)
//增量构造法 一次选出一个元素放到集合中 ,默认A中从小到大
void print_subset(vector<int> &A,int n)
{
    
    /* RFOR(it,A){
        cout<<it<<" ";}
    if(A.size())cout<<endl; */
    
     
    //如果A为空，那么从1开始
 
    //如果A不为空，那么从A的最后一个元素的下一个开始
    int s = A.size()?A.back()+1:1;//
    //通过循环控制递归
    REP(i,s,n+1)//当A中的元素不能再添加时 递归结束
    {
        A.push_back(i);
        print_subset(A,n);
        A.pop_back();
    }
    RFOR(it,A){
        cout<<it<<" ";}
    if(A.size())cout<<endl;
}
int b[20];
// 位向量法 构造位向量B[i] = 1 i在集合A中
//由于每个位置仅有两种可能状态，因此称为位向量。实际上，在许多算法中也会直接使用位运算来表示这样的选择状态
void print_subset_b(int n,int cur)
{
    if(cur==n)
    {
        REP(i,0,cur)
        {
            if(b[i])
            cout<<i+1<<" ";
        }
        
        cout<<endl;
        return;
    }

    b[cur] = 1;
    print_subset_b(n,cur+1);
    //显示的把对应位置变化
    b[cur] = 0;//完成了回溯操作
    //即使这个位置不被选择也会输出
    print_subset_b(n,cur+1);
    

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vi A;
    //print_subset_b(n,0);
    print_subset(A,n);
    return 0;
}
