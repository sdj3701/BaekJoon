#include <iostream>

using namespace std;

#define MAX 9
int arr[MAX] = { 0 };
bool visited[MAX] = { false };
int n, m;

void func(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			if (cnt == 0 || arr[cnt - 1] < arr[cnt])
				func(cnt + 1);
			visited[i] = false;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	func(0);

	return 0;
}