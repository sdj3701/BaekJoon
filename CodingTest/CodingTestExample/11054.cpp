#include <iostream>

using namespace std;

int arr[1001];
int dp1[1001];
int dp2[1001];

int main()
{
	int n, ans = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < n; i++)
	{
		dp1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		dp2[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int sum = dp1[i] + dp2[i];
		if(sum > ans)
			ans = sum;
	}

	cout << ans - 1;

	return 0;
}