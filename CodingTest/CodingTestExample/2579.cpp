#include <iostream>

using namespace std;

int arr[501];
int dp[501];

int main()
{
	int n; 
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	dp[3] = max(dp[1] + arr[3], dp[2] + arr[3]);

	for (int i = 4; i <= n; i++)
	{
		int a = dp[i - 3] + arr[i - 1];
		int b = dp[i - 2] + arr[i - 1] + arr[i];
		dp[i] = max(a, b);
	}

	cout << dp[n];

	return 0;
}


/*
1번 계단을 반드시 밟는 경우: 1
2번 계단을 반드시 밟는 경우: 1-2
3번 계단을 반드시 밟는 경우: 1-3, 2-3
4번 계단을 반드시 밟는 경우: 1-2-4, 1-3-4, 2-4
5번 계단을 반드시 밟는 경우: 1-2-4-5, 1-3-5, 2-3-5

여기서 다시 정리하면,

score[1] = stair[1]
score[2] = score[1] + stair[2]
score[3] = score[1] + stair[3] 또는 score[2] + stair[3] (둘 중 최댓값)
1,2,3 은 이렇게 정의되고

score[4]
1-2-4: score[2] + stair[4]  ( score[2] = score[1] + stair[2] )
1-3-4: score[1] + stair[3] + stair[4]
score[5]
1-3-5와 2-3-5: score[3] + stair[5]  ( score[3] 에서의 최댓값 + stair[5] )
1-2-4-5: score[2] + stair[4] + stair[5]
4,5는 이렇게 정의된다.

계단의 수를 N이라고 했을 때, 이를 점화식으로 일반화시키면 다음 두 가지 식이 나온다.

score[N] = score[N-2] + stair[N]
score[N] = score[N-3] + stair[N-1] + stair[N]

*/