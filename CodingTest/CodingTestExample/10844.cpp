#include <iostream>

using namespace std;
#define mod 1000000000

int dp[101][10];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][0] = dp[i - 1][j + 1]; // 초기 저장한 값 가져와서 새로운 dp에 넣기 [1][1] = 1
			else if (j == 9)
				dp[i][9] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]; // dp[2][1] = dp[1][0] + dp[1][2]; dp[2][1] = 1 + 1         i == 2  j == 1

			dp[i][j] %= mod;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + dp[n][i]) % mod;
	}
	cout << result << "\n";

	return 0;
}

/*
n = 1
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9

n = 2
10 / 21 / 32 / 43 / 54 / 65 .. / 87 / 98
12 / 23 / 34 / 45 / 56 / 67 .. / 89

규칙이 자신의 수 말고 +1 -1 의 수이다

*/