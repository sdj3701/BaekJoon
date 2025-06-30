#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n, m, t;
	cin >> n >> m;

	int* arr = new int[n + 1];
	int* dp = new int[n + 1];

	long long ans = 0, cnt = 0;
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		ans += t;
		dp[ans % m]++;
	}

	for (int i = 0; i <= m; i++)
	{
		cnt += ((dp[i] * (dp[i] - 1)) / 2);
	}

	cout << dp[0] + cnt;

	delete[] dp;
	return 0;
}