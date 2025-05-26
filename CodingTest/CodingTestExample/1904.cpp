#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 규칙이 피포나치 수열 처럼 이전 두 항의 합이 다음 항의 값이 되는것
	// N = 2일 때 : 11,00 2가지 경우가 있다.
	// N = 3일 때 : 001, 100, 111 3가지 경우가 있다
	// N = 4일 때 : 0000, 0011, 1001, 1100, 1111 5가지 경우가 있다.
	// N = 5일 때 : 00001, 10000, 00100, 00111, 10011, 11001, 11100, 11111 8가지 경우가 있다.
	// 그런데 그냥 피보나치 수열을 구하면 정수 범위를 초과하니 항상 15746으로 나누어 사용
	int* arr = new int[n + 1];
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	cout << arr[n];

	return 0;
}