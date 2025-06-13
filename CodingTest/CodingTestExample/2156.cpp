#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int dp[10001];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// 초기값 설정
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++)
	{
		// {} 사용한 이유 : 초기화 리스트를 사용
		// 기존 방식 (두 개씩만 비교 가능)
		//max(a, max(b, c))
		// 새로운 방식 (여러 개 한번에 비교)
		//max({ a, b, c })
		dp[i] = max({ dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i], dp[i - 1] });
	}

	cout << dp[n];

	return 0;
}

/*

접근 (점화식)
1. i-3번째를 마시고 i-1,i번째를 마신다.
2. i-2번째를 마시고 i번째를 마신다.
3. i-1번째를 마시고 i번째를 마시지 않는다.
*/