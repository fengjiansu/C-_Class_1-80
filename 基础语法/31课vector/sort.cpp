#include <bits/stdc++.h>

using namespace std;


int main()
{
   
   int a[10] = {1,3,2,9,7,8,6,5,4,0};
   sort(a,a+10);
    vector<int> ivec = {1,3,2,9,7,8,6,5,4,0};
    //sort(ivec.begin(),ivec.end());
    sort(ivec.begin()+1,ivec.begin()+4);
    for(int i = 0;i<10;i++)
    {
        cout<<ivec[i]<<" ";
    }
   return 0;
}
