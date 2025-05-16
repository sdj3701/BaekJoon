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
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		func2++;
	}

	cout << func1 << " " << func2;

	return 0;
}