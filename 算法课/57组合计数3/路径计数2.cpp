#include <bits/stdc++.h>
using namespace std;
int a[55];
int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0; i <= n; i++)
    {
        if (x < a[i])
            break;
        j++;
    }
    for (int i = n - 1; i >= j; i--)
    {
        a[i + 1] = a[i];
    }
    a[j] = x;
    for (int i = 0; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
