#include <iostream>
#include <vector>

using namespace std;

int n;
int score[20][20] = { 0 };
bool isteam[20] = { false };
int checkmin = 9999999;

void func(int idx,int cnt)
{
	vector<int> start;
	vector<int> link;
	int startscore = 0;
	int linkscore = 0;

	if (cnt == (n / 2))
	{
		for (int i = 0; i < n; i++)
		{
			if (isteam[i] == true)
				start.push_back(i);
			else
				link.push_back(i);
		}

		for (int i = 0; i < (n / 2); i++)
		{
			for (int j = 0; j < (n / 2); j++)
			{
				startscore += score[start[i]][start[j]];
				linkscore += score[link[i]][link[j]];
			}
		}
		if (abs(startscore - linkscore) < checkmin)
			checkmin = abs(startscore - linkscore);

		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isteam[i])
			continue;
		else
		{
			isteam[i] = true;
			func(i, cnt + 1);
			isteam[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> score[i][j];

	func(0, 0);

	cout << checkmin;

	return 0;
}