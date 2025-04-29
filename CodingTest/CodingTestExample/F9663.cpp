#include "iostream"

using namespace std;

int n;
int arr[15];
int num = 0;

void func(int cnt)
{
	if(cnt == n)
		num++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr[cnt] = i;
			bool can = true;
			for (int j = 0; j < cnt; j++)
			{
				if (arr[cnt] == arr[j] || abs(arr[cnt] - arr[j]) == cnt - j)
				{
					can = false;
					break;
				}
			}
			if (can)
				func(cnt + 1);
		}
	}
}

int main()
{
	cin >> n;
	
	func(0);

	cout << num;

	return 0;
}