#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	int size;
	
	size = str.size();

	int prefixSum[200001][26] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			// 데이터 복사 
			prefixSum[i + 1][j] = prefixSum[i][j];
		}
		// 여기서 단어 갯수 증가 전에 있는 데이터를 가지고 증가!
		prefixSum[i + 1][str[i] - 'a']++;
	}

	int q;
	cin >> q;

	while (q--) 
	{
		char alpha;
		int l, r;
		cin >> alpha >> l >> r;

		int alphaIndex = alpha - 'a';
		cout << prefixSum[r + 1][alphaIndex] - prefixSum[l][alphaIndex] << "\n";
	}

	return 0;
}