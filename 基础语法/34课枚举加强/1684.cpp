/* 
��Ŀ����

(1684)ͳ�Ʒ���

��һ��nxm���������,���䷽��������������Ρ�������(������������)��

����
һ��,����������n,m(n��50,m��50)��

���
һ��,����������,�ֱ��ʾ����������������Ρ�������(������������)��

��������
23

�������
8 10

 */



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
    /* 
    �����ϣ�����ͬ��ͬ�е����������ȷ��һ������
    ��ѧ��˵һ�����ϽǶ�������½Ƕ��������ֵ�ķ�Χ��
    ��i��j�ֱ��ʾ���ϽǶ��������ֵ��
    p��q�ֱ��ʾ���½Ƕ��������ֵ��

    */
    int n, m;
    cin>>n>>m;
    int x=0,y=0;
    /* ����ѭ���ᳬʱ
        for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int p=i+1;p<=n;p++)
            {
                for(int q=j+1;q<=m;q++)
                {
                    if(abs(i-p) == abs(j-q))
                    {
                        x++;
                    }
                    else
                    {
                        y++;
                    }
                }
            }
        }
    } */
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           if(i==j) x+=(n-i+1)*(m-j+1);
           else y+=(n-i+1)*(m-j+1);
       }
   }
   cout<<x<<" "<<y<<endl;
    return 0;
}
