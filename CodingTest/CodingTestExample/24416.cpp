#include <iostream>

using namespace std;

int func1 = 0, func2 = 0;
int n;
int f[41] = { 0 };

// 피보나치 재귀
int fib(int cnt)
{
	if (cnt == 1 || cnt == 2)
	{
		func1++;
		return 1;
	}
	else
		return fib(cnt - 1) + fib(cnt - 2);
}

int main()
{
	cin >> n;

	fib(n);

	// 동적 계획법
	// 바텀 업 방식
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		func2++;
	}

	cout << func1 << " " << func2;

	return 0;
}

// 탑 다운 방식
/*
int memo[41] = {0};
int fib_memo(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (memo[n] != 0) {  // 이미 계산된 값이 있으면 재사용
		return memo[n];
	}
	// 계산 결과를 저장(메모이제이션)
	return memo[n] = fib_memo(n-1) + fib_memo(n-2);
}
*/