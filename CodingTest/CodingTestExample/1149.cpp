#include <iostream>

using namespace std;

int rgb[1001][3];
int dp[1001][3];

int main()
{
	int n;
	cin >> n;

	// RGB »ö Ä¥ÇÏ±â
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			cin >> rgb[i][j];
		}
	}

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;

	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);

	return 0;
}