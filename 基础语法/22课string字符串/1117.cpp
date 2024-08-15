#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int n, sum;
	cin >> n;
	while (n--)
	{
		sum = 0;
		cin >> s;
		int len = s.size();
		int l = 0;
		for (int i = 0; i < len; i++)
		{

			if (s[i] == 'O')
			{
				l++;
			}
			else
			{
				l = 0;
			}
			sum += l;
		}
		cout << sum << endl;
	}
	return 0;
}