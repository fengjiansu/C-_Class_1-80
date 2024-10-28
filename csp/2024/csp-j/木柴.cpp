#include <bits/stdc++.h>
using namespace std;
int wei(int k)
{
    int cnt = 0;
    while(k)
    {
        k/=10;
        cnt++;
    }
    return cnt;
}
int main()
{
   int t;
   map<int,int> n_c={{0,6},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6}};
   int maxn[6] = {1,2,4,6,7,8};
   int lastn[7] = {0,1,2,4,6,7,8};
   while(t--)
   {
    int n;
    cin>>n;
    int res = -1;
    if(n<=7&&n>=2)
    {
        if(n==2) res = 1;
        if(n==3) res = 7;
        if(n==4) res = 4;
        if(n==5) res = 2;
        if(n==6) res = 6;
        if(n==7) res = 8;
    }
    else
    {
        //找最高位放几
        int zui = 0;
        int wei = 0;
        int yu = 0;
        
        for(int i=0;i<6;i++)
        {
            yu = n-n_c[maxn[i]];
            if(yu<=14)
            {
                zui = n_c[maxn[i]];
                wei++;
                break;
            }

        }
        if(zui ==0)
        {
            cout<<res;
            return 0;
        }
        res = zui*10;
        //剩下的
        while(yu)
        {
            for(int i=0;i<=7;i++)
            {

            }
        }
    }
    cout<<res;
   }
   return 0;
}
