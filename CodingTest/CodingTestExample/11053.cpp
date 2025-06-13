#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	int n;
	cin >> n;

	dp[0] = arr[0] = 0;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++)
		dp[i] = 1;
	
	// 현제 위치 
	for (int i = 1; i <= n; i++) 
	{
		// 이전 위치 
		for (int j = 1; j < i; j++)
		{
			// 증가 조건 고려
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	// 
	sort(dp, dp + n + 1);
	cout << dp[n];

	return 0;
}

/*
접근 방식

*/