#include <bits/stdc++.h>
using namespace std;
int a[] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888, 1088, 1888, 2008, 2088, 2888, 6888, 8888, 10888, 18888, 20088, 20888, 28888, 68888, 88888, 108888, 188888, 200888, 208888, 288888, 688888, 888888, 1088888, 1888888, 2008888, 2088888, 2888888, 6888888, 8888888, 10888888, 18888888};
void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << 8;
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    /* a[1] = -1;
    a[2] =1;
    a[3] =7;
    a[4] =4;
    a[5] =2;
    a[6] =6;
    a[7] =8;
    a[8] =10; // 1 第一个数为1 第二个数为0
    a[9] =18;  //2 首位变1
    a[10] =22 ;//3  第一个为2 后面两个为0
    a[11]=20;// 4 第一个数字为2第二个为0
    a[12]= 28;//5  第一位变2
    a[13]=68;// 第一位变6
    a[14]=88; */
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 50)
        {
            cout << a[n] << endl;
        }
        else
        {
            int x = n % 7;
            switch (x)
            {
            case 1:
                cout << 10;
                print((n-8)/7);
                break;
            case 2:
                cout << 1;
                print((n-2)/7);
                break;
            case 3:
                cout << 200;
                print((n-17)/7);
                break;
            case 4:
                cout << 20;
                print((n-11)/7);
                break;
            case 5:
                cout << 2;
                print((n-5)/7);
                break;
            case 6:
                cout << 6;
                print((n-6)/7);
                break;
            default:
                print(n/7);
                break;
            }
        }
    }
    return 0;
}
