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
//�������취 һ��ѡ��һ��Ԫ�طŵ������� ,Ĭ��A�д�С����
void print_subset(vector<int> &A,int n)
{
    
    /* RFOR(it,A){
        cout<<it<<" ";}
    if(A.size())cout<<endl; */
    
     
    //���AΪ�գ���ô��1��ʼ
 
    //���A��Ϊ�գ���ô��A�����һ��Ԫ�ص���һ����ʼ
    int s = A.size()?A.back()+1:1;//
    //ͨ��ѭ�����Ƶݹ�
    REP(i,s,n+1)//��A�е�Ԫ�ز��������ʱ �ݹ����
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
// λ������ ����λ����B[i] = 1 i�ڼ���A��
//����ÿ��λ�ý������ֿ���״̬����˳�Ϊλ������ʵ���ϣ�������㷨��Ҳ��ֱ��ʹ��λ��������ʾ������ѡ��״̬
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
    //��ʾ�İѶ�Ӧλ�ñ仯
    b[cur] = 0;//����˻��ݲ���
    //��ʹ���λ�ò���ѡ��Ҳ�����
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
