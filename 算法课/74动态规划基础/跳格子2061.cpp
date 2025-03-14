#include<bits/stdc++.h>
using namespace std;
int a[100005], dp[100005], vis[100005];
int f(int s) {
	if (s == 0) return 0;
	if (s == 1) return a[1];
	if (vis[s]) return dp[s];
	dp[s] = f(s - 1) + a[s];
	if (s % 2 == 0)  dp[s] = max(dp[s], f(s / 2) + a[s]);
	if (s % 3 == 0)  dp[s] = max(dp[s], f(s / 3) + a[s]);
	vis[s] = 1;
	return dp[s];
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << f(n);
	