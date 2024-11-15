#include<bits/stdc++.h>
using namespace std;
int c[5],m[5];
int main()
{
 
    for(int i=0;i<3;i++ ) cin>>c[i]>>m[i];
    int pour;
    for(int i=0;i<100;i++)
    {
        /*
        i    0  1  2  3   4  5 
    桶序号   1  2  3  1   2  3
        */
        // 随机给一个 i 怎么求桶的序号
        /* 
        i a  b   a = i%3  b = (i+1)%3 
        0 0  1
        1 1  2
        2 2  0
        3 0  1
        4 1  2
        5 2  0       
        
         */
        int a = i%3;
            int b = (i+1)%3;
            int pour = min(m[a],c[b]-m[b]);
            m[a] -= pour;//
            m[b] += pour;//
    }
    for(int i=0;i<3;i++)
    {
        cout<<m[i]<<endl;
    }
    return 0;
}