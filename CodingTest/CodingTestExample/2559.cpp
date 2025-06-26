#include <iostream>

using namespace std;

int arr[100002];
int dp[100002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, ans = -99999;
	cin >> n >> k;

	arr[0] = dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < n - k + 1; i++)
	{
		for (int j = i; j < i + k; j++)
		{
			dp[i] += arr[j];
		}
		ans = max(dp[i], ans);
	}

	cout << ans;

	return 0;
}