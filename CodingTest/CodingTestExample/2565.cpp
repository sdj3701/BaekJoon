#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int dp[501];
int n;

void func()
{
	int count = 0;

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[j].second < v[i].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}

		count = max(count, dp[i]);
	}

	cout << n - count;
}

int main()
{
	cin >> n;
	int a, b;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	func();

	return 0;
}

/*
점화식 유추
위에서부터 차례대로 번호
교차하지 않는 것
i j


*/