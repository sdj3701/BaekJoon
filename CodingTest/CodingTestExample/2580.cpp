#include <iostream>

using namespace std;

#define Max 81
int board[Max];
int col = 9, row = 9;
bool visited[Max] = { false };
int num = 0;

void func(int cnt)
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (!visited[i * col + j])
			{
				visited[i * col + j] = true;
				board[cnt] = j;
				func(cnt + 1);
				visited[i * col + j] = false;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> board[i * col + j];
		}
	}

	func(0);

	return 0;
}