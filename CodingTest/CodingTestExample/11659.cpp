#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int *dp = new int[n + 1];
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		int ans = dp[end] - dp[start - 1];
		cout << ans << "\n";
	}

	delete[] dp;
	return 0;
}