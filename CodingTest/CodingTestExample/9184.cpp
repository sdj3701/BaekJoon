#include <iostream>

using namespace std;
int memory[21][21][21] = { 0 };

int func(int a,int b, int c)
{
	// 조건 TOP - DOWN
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return func(20, 20, 20);
	else if (memory[a][b][c] != 0) // 이미 저장된 값이면 반환
		return memory[a][b][c];
	else if (a < b && b < c)
		memory[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c); // 저장안된값
	else
		memory[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);

	return memory[a][b][c];
		
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int A, B, C;
	while (1)
	{
		cin >> A >> B >> C;
		if (A == -1 && B == -1 && C == -1)
			break;

		cout << "w(" << A << ", " << B << ", " << C << ") = " << func(A, B, C) << "\n";
	}
	return 0;
}