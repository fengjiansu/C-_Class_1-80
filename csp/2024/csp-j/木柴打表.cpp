#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
//每个数字对应的火柴数
int a[10]={6,2,5,5,4,5,6,3,7,6};

//数字需要的火柴数量
int Count(int n){
        int num = 0;
        while(n>0)
        {
            int rest = n%10;
            num += a[rest];
            n /= 10;
        }
        return num;
}
//火柴数量对应的最小的数字;
map<int,int> mp;
int main()
{
   for(int i=0;;i++)
   {
    int stick_num = Count(i);
    if(!mp[stick_num])mp[stick_num] = i;
    if(stick_num > 50) break;
   }
   /* for(auto&it:mp)
   {
    cout<<"火柴数量:"<<it.first<<" 最小数字:"<<it.second<<endl;
   } */
   for(auto&it:mp)
   {
    cout<<it.second<<",";
   }
   return 0;
}
