#include<bits/stdc++.h>
using namespace std;
int c[5],m[5];
int main()
{
    int c1,m1,c2,m2,c3,m3;
    cin>>c1>>m1>>c2>>m2>>c3>>m3;//用两个数组
    //for(int i=0;i<3;i++ ) cin>>c[i]>>m[i];
    int pour;
    for(int i=0;i<100;i++)
    {
        /*
        i    0  1  2  3   4  5 
    桶序号   1  2  3  1   2  3
        */
        // 随机给一个 i 怎么求桶的序号
        /*
            int pour;
            int j = (i+1)%3;
            if(c[j]-m[j]<m[i%3])
            {
                pour = c[j]-m[j];
            }
            else
            {
                pour = m[i%3];
            }
            m[i%3] -= pour;
            m[j] += pour;]
        */
        if(i%3==0) // 将桶1倒入桶2
        {
            /*
            桶 1有容积c1，代表最多装多少 m1是当前装多少
            桶 2有容积c2，代表最多装多少 m2是当前装多
            桶1倒空或桶2倒满
            */
           if(c2-m2<m1)
           {
            pour = c2-m2;
           }
           else
           {
            pour = m1;
           }
           m1 -= pour;
           m2 += pour;
            
        }
        else if(i%3==1)// 将桶2倒入桶3
        {
           if(c3-m3<m2)
           {
            pour = c3-m3;
           }
           else
           {
            pour = m2;
           }
            m2 -= pour;
            m3 += pour;
        }
        else// 将桶3倒入桶1
        {
            if(c1-m1<m3)
           {
            pour = c1-m1;
           }
           else
           {
            pour = m3;
           }
            m3 -= pour;
            m1 += pour;
        }
    }
    for(int i=0;i<3;i++)
    {
        cout<<m[i]<<endl;
    }
    return 0;
}