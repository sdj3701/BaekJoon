#include "iostream"

using namespace std;

int n;
int fbo[4];
int* arr = new int[n];
int temp;

int Min = 1000000000, Max = -1000000000;

void func(int plus, int minus, int multiple, int divide, int cnt, int sum)
{
	if (cnt == n - 1)
	{
		if (sum < Min) Min = sum;
		if (sum > Max) Max = sum;
	}
	
	if (plus > 0)		func(plus - 1	, minus		, multiple		, divide		, cnt + 1, sum + arr[cnt + 1]);
	if (minus > 0)		func(plus		, minus - 1	, multiple		, divide		, cnt + 1, sum - arr[cnt + 1]);
	if (multiple > 0)	func(plus		, minus		, multiple - 1	, divide		, cnt + 1, sum * arr[cnt + 1]);
	if (divide > 0)		func(plus		, minus		, multiple		, divide - 1	, cnt + 1, sum / arr[cnt + 1]);

}

int main()
{
	cin >> n;


	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 4; i++)
		cin >> fbo[i];
	
	func(fbo[0], fbo[1], fbo[2], fbo[3], 0, arr[0]);

	cout << Max << "\n" << Min;

	
	return 0;
}