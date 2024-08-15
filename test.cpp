#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	int flag = 1;
	for (int i = 0; i < s.size() - 1; i++)
	{
		string ns = s.substr(i, 3);
		if (ns == "sos")
		{
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}