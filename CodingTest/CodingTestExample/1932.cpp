#include <iostream>

using namespace std;

int arr[502][502];
int dp[502][502];
int sum = 0;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	sum = dp[n][1];
	for (int i = 2; i < n + 1; i++)
	{
		sum = max(sum, dp[n][i]);
	}
	
	cout << sum;

	return 0;
}