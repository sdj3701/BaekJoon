#include <iostream>

using namespace std;

// 데이터 형 int 에서 longlong으로 변경 
// 이유 : 피보나치 수열을 사용하기 때문에 데이터 크기가 너무 커지고 반복이 심함
long long arr[101] = { 0,1,1 };

long long func(int n)
{
	if (n < 3)
		return arr[n];
	else if (arr[n] == 0)
		arr[n] = func(n - 2) + func(n - 3);
	return arr[n];
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << func(n) << "\n";
	}
	
	return 0;
}

/*
점화식
P(1) = 1
P(2) = 1
P(3) = 1
P(4) = 2 ( P(1) + P(2) )
P(5) = 2 ( P(2) + P(3) )
P(6) = 3 ( P(3) + P(4) )
P(7) = 4 ( P(4) + P(5) )
*/