#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

void baekjoon()
{

}


int main() 
{
    baekjoon();
    return 0;
}

#pragma region 주의점
// 수백개 On2			2중for문
// 수만개 ONlogN
// 수백만 이상 OlogN		이분 탐색

// endl 보다 \n을 사용하자


#pragma endregion

void baekjoon28279()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	deque<int> d;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x == 1)
		{
			int front;
			cin >> front;
			d.push_front(front);
		}
		else if (x == 2)
		{
			int back;
			cin >> back;
			d.push_back(back);
		}
		else if (x == 3)
		{
			if (!d.empty())
			{
				cout << d.front() << "\n";
				d.pop_front();
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (x == 4)
		{
			if (!d.empty())
			{
				cout << d.back() << "\n";
				d.pop_back();
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (x == 5)
		{
			cout << d.size() << "\n";
		}
		else if (x == 6)
		{
			if (d.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (x == 7)
		{
			if (!d.empty())
			{
				cout << d.front() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (x == 8)
		{
			if (!d.empty())
			{
				cout << d.back() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
	}

}

void baekjoon28279()
{
	int n, k;
	cin >> n >> k;
	queue<int>q;
	int i;
	for (i = 1; i <= n; i++)
		q.push(i);		//	큐에 n까지 삽입
	cout << "<";
	while (q.size() != 0)		//	큐가 빌 때까지 반복
	{
		for (i = 1; i < k; i++)
		{
			q.push(q.front());		//	k-1번째 원소를 맨 뒤에 삽입
			q.pop();			// 	맨 앞에 있던 원소는 삭제
		}
		cout << q.front();		//	k번째 원소가 맨 앞에 오게 됨.
		if (q.size() != 1)
			cout << ", ";
		q.pop();		//	k번째 원소 출력 후 삭제
	}
	cout << ">";
}

void baekjoon2164()
{
	int n;
	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1)
	{
		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << q.front();
}

void baekjoon18258()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	string str;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (str == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (str == "size")
		{
			cout << str.size() << "\n";
		}
		else if (str == "empty")
		{
			if (q.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (str == "front")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (str == "back")
		{
			if (!q.empty())
			{
				cout << q.back() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
	}
}

void baekjoon12789()
{
	int n;
	cin >> n;
	int num;
	stack<int> wait;
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == count)
		{
			count++;

			while (!wait.empty() && wait.top() == count)
			{
				wait.pop();
				count++;
			}
		}
		else
		{
			wait.push(num);
		}


	}

	if (wait.empty())
		cout << "Nice";
	else
		cout << "Sad";
}

void baekjoon4949()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	getline(cin, str);
	vector<string> output;
	bool ischeck = false;
	while (1)
	{
		if (ischeck)
			getline(cin, str);

		if (str == ".")
			break;

		ischeck = true;
		bool check = false;
		stack<char> ps;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				ps.push(str[i]);
			else if (str[i] == ')' || str[i] == ']')
			{
				if (!ps.empty() && ps.top() == '(' && str[i] == ')')
					ps.pop();
				else if (!ps.empty() && ps.top() == '[' && str[i] == ']')
					ps.pop();
				else
				{
					check = true;
					output.push_back("no");
					break;
				}
			}
		}

		if (ps.empty() && !check)
			output.push_back("yes");
		else if (ps.empty() && !check)
			output.push_back("no");

	}

	for (size_t i = 0; i < output.size(); i++)
	{
		cout << output[i] << "\n";
	}

	/*
	string word;

	while (true)
	{
		getline(cin, word);
		if (word == ".")
			break;
		stack<char> s;

		bool isValid = true;

		for (auto c : word)
		{
			if (c == '(' || c == '[') s.push(c);
			else if (c == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					isValid = false;
					break;
				}
				s.pop();
			}
			else if (c == ']')
			{
				if (s.empty() || s.top() != '[') {
					isValid = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) isValid = false;
		if (isValid) cout << "yes\n";
		else cout << "no\n";

	}
	*/
}

void baekjoon9012()
{
	int n;
	cin >> n;
	string* vps = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> vps[i];
	}

	for (int i = 0; i < n; i++)
	{
		bool check = false;
		stack<string> ps;
		for (int j = 0; j < vps[i].size(); j++)
		{
			if (vps[i][j] == '(')
			{
				ps.push("(");
			}
			else
			{
				if (!ps.empty())
					ps.pop();
				else
				{
					check = true;
					cout << "NO" << "\n";
					break;
				}
			}
		}
		if (!check && ps.empty())
		{
			cout << "YES" << "\n";
		}
		else if (!check && !ps.empty())
		{
			cout << "NO" << "\n";
		}
	}


}

void baekjoon10773()
{
	int n, num;
	cin >> n;
	stack<int> count;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num != 0)
		{
			count.push(num);
		}
		else
		{
			count.pop();
		}
	}

	int sum = 0;
	if (!count.empty())
	{
		while (!count.empty())
		{
			sum += count.top();
			count.pop();
		}
		cout << sum;
	}
	else
	{
		cout << "0";
	}

}

void baekjoon28278()
{
	int x, n;
	cin >> x;
	stack<int> num;
	vector<int> story;
	for (int i = 0; i < x; i++)
	{
		cin >> n;
		if (n == 1)
		{
			int count;
			cin >> count;
			num.push(count);
		}
		else if (n == 2)
		{
			if (num.size() == 0)
				story.push_back(-1);
			else
			{
				story.push_back(num.top());
				num.pop();
			}
		}
		else if (n == 3)
		{
			story.push_back(num.size());
		}
		else if (n == 4)
		{
			if (num.empty())
				story.push_back(1);
			else
				story.push_back(0);
		}
		else if (n == 5)
		{
			if (!num.empty())
				story.push_back(num.top());
			else
				story.push_back(-1);
		}
	}

	for (int i = 0; i < story.size(); i++)
	{
		cout << story[i] << "\n";
	}

}

void baekjoon11478()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	set<string> word;
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = i; j < str.size(); j++)
		{
			word.insert(str.substr(i, j + 1 - i));
		}
	}
	cout << word.size();
}

void baekjoon1269()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<int, int> atomic;

	int n, m;
	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		atomic[num] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		atomic[num] += 1;
	}

	int count = 0;

	for (auto& it : atomic)
	{
		if (it.second == 1)
		{
			count += 1;
		}
	}

	cout << count;
}

void baekjoon1764()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, bool> listname;
	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		listname[name] = false;
	}

	int count = 0;
	vector<string> check;
	for (int i = 0; i < m; i++)
	{
		cin >> name;
		if (listname.count(name) > 0)
		{
			check.push_back(name);
			count++;
		}
	}

	cout << count << "\n";
	sort(check.begin(), check.end());

	for (int i = 0; i < check.size(); i++)
	{
		cout << check[i] << "\n";
	}
}

void baekjoon10816()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	int cardnum;
	unordered_map<int, int> deck;
	for (int i = 0; i < n; i++)
	{
		cin >> cardnum;
		deck[cardnum]++;
	}

	cin >> m;
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> cardnum;
		cout << deck[cardnum] << " ";
	}
}

void baekjoon1620()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	string testname[100001];
	string str;
	unordered_map<string, int> Encyclopedia;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		testname[i] = str;
		Encyclopedia[str] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> str;

		// 이터레이터 도는 방법이 잘못 된거 같다. 답은 맞지만 O(n)
		/*for (auto it : Encyclopedia)
		{
			if (str == it.first)
			{
				cout << it.second << "\n";
				break;
			}
			else if(atoi(str.c_str()) == it.second)
			{
				cout << it.first << "\n";
				break;
			}
		}*/

		// 숫자인지 판별하는 함수 (숫자이면 0이 아닌 수) / (숫자아닌수면 0을 반환)  O(log n)
		if (isdigit(str[0]))
			cout << testname[stoi(str)] << "\n";
		else
			cout << Encyclopedia.find(str)->second << "\n";
	}

}

void baekjoon7785()
{
	int n;
	cin >> n;

	// 현재 회사에 있는 사람의 이름을 사전 순의 역순으로 한 줄에 한 명씩 출력한다.
	// 조건 때문에 greater<string>을 사용
	map<string, string, greater<string>> office_attendance;
	for (int i = 0; i < n; i++)
	{
		string name, commute;
		cin >> name >> commute;
		if (commute == "enter")
			office_attendance[name] = commute;
		else
			office_attendance.erase(name);
	}

	for (auto it : office_attendance)
	{
		cout << it.first << "\n";
	}
}

int test(const vector<string> arr, const string target)
{
	int start = 0;
	int end = arr.size() - 1;

	int count = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == target)
		{
			return 1;
		}

		if (arr[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return 0;
}

void baekjoon14425()
{
	int n, m;
	cin >> n >> m;

	vector<string> str;

	for (int i = 0; i < n; i++)
	{
		string str1;
		cin >> str1;
		str.push_back(str1);
	}

	sort(str.begin(), str.end());

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		string str1;
		cin >> str1;
		count += test(str, str1);
	}
	cout << count;

	// AI 답변
	/*
	unordered_map<string, bool> wordMap;

	// 맵 채우기
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		wordMap[word] = true;
	}

	// 조회하기
	int count = 0;
	for (int i = 0; i < m; i++) {
		string query;
		cin >> query;
		if (wordMap.count(query) > 0) {
			count++;
		}
	}

	cout << count;

	*/

}

void make_binary_search(vector<int> arr,int target)
{
	int start = 0, end = arr.size() - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == target)
		{
			cout << "1 ";
			return;
		}

		if (arr[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << "0 ";
}

void baekjoon10815()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> arr;

	int n;
	cin >> n;
	// 데이터 삽입
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}

	// 이분 탐색을 위한 정렬
	sort(arr.begin(), arr.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int cardnum;
		cin >> cardnum;
		make_binary_search(arr, cardnum);
	}
}

void Oldbaekjoon()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;

	vector<int> narr, marr;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		narr.push_back(num);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		marr.push_back(num);
	}

	vector<int> checkarr;
	checkarr.resize(m);
	// 최적화 50만 * 50만 = 2500억
	// 그래서 logN을 사용해야함 => 이분 탐색
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (narr[j] == marr[i])
			{
				checkarr[i] = 1;
				break;
			}
			else
			{
				checkarr[i] = 0;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << checkarr[i] << " ";
	}

}

void baekjoon18870()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v, back;
	int N, input;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
		back.push_back(input);
	}

	// 정렬
	sort(v.begin(), v.end());
	// unique 함수는 인접한 중복 요소들을 벡터의 끝으로 이동시키고, 중복이 없는 부분이 끝나는 위치를 가리키는 반복자를 반환합니다.
	v.erase(unique(v.begin(), v.end()), v.end());


	for (int i = 0; i < N; i++) {
		// back 원본 v 정렬
		// 2 4 -10 4 -9 원본 back
		// -10 -9 2 4	정렬 v
		// (v[2]) - v.begin() = 2
		cout << lower_bound(v.begin(), v.end(), back[i]) - v.begin() << " ";
	}
}

bool compare(pair<int, string> str1, pair<int, string> str2)
{
	return str1.first < str2.first;
}

void baekjoon10814()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, age;
	string name;
	vector<pair<int, string>> oldname;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		oldname.push_back({ age, name });
	}

	// 정렬
	// sort : 같은 값을 가진 요소들의 상대적 순서가 보존되지 않음
	// 질문에서 가입한 순서대로 정렬을 하라고 했음
	// 그렇기 때문에 sort를 사용하면 string 값이 순서를 알 수 없음
	// 그래서 stable_sort를 사용하여 같은 값을 가진 요소들의 상대적 순서가 보존되도록 하게한다
	// sort와 stable_sort의 차이점은 퀵과 병합 차이이다.
	stable_sort(oldname.begin(), oldname.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << oldname[i].first << " " << oldname[i].second << "\n";
	}

}

int cmp(string a, string b) {
	// 1. 길이가 같다면, 사전순으로
	if (a.length() == b.length()) {
		return a < b;
	}
	// 2. 길이가 다르다면, 짧은 순으로 
	else {
		return a.length() < b.length();
	}
}

void baekjoon1181()
{
	string str[20000];

	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	sort(str, str + N, cmp);

	for (int i = 0; i < N; i++) {
		// 중복된 경우 한번만 출력
		if (i > 0 && str[i] == str[i - 1]) {
			continue;
		}
		cout << str[i] << "\n";
	}
}

//bool compare(pair<int, int> a, pair<int, int> b)
//{
//	/*compare(a, b)가 true를 반환하는 경우 :
//	std::sort는 a가 b보다 앞에 와야 한다고 판단합니다.
//		즉, 정렬된 결과에서 a는 b보다 더 작은 위치에 놓입니다.
//
//	compare(a, b)가 false를 반환하는 경우 :
//	std::sort는 a가 b보다 앞에 와야 하는 조건이 아니다 라고 판단합니다.
//		이는 여러 가지 상황을 포함할 수 있습니다.*/
//	if (a.second == b.second)
//		return a.first < b.first;
//	return a.second < b.second;
//}

//void baekjoon11651()
//{
//	int n;
//	cin >> n;
//
//	vector<pair<int, int>> arr;
//
//	for (int i = 0; i < n; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		arr.push_back(make_pair(a, b));
//	}
//
//	sort(arr.begin(), arr.end(), compare);
//
//	for (int i = 0; i < arr.size(); i++)
//	{
//		cout << arr[i].first << " " << arr[i].second << "\n";
//	}
//}

void baekjoon11650()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
		arr[i].resize(2);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}

	// std::sort를 사용하여 2차원 벡터 정렬 (첫 번째 열 기준 오름차순, 같으면 두 번째 열 기준)

	sort(arr.begin(), arr.end()); // 별도의 비교 함수 없이 sort 사용 시 기본적으로 첫 번째 요소 기준으로 정렬
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void baekjoon1427()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = i + 1; j < str.size(); j++)
		{
			if (str[i] < str[j])
			{
				char temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	cout << str << endl;
}

void baekjoon10989()
{
	// 계수 정렬이라는 방법으로 해결
// 처음에는 merge를 사용해서 정렬을 했는데 메모리 초과 int가 4byte이고 1천만개 들어면 10^6이 MB(1백만개)
// 하지만 문제에서 원하는 메모리 제한이 8MB 그냥 병합정렬로 풀면 40MB 메모리를 사용하기 때문에
// 메모리 초과
// 문제에 수가 10,000보다 작거나 같은 자연수라는 힌트
// 그래서 배열의 크기를 10000보다 큰 10001로 잡고 입력 받은 인덱스에 개수를 증가 시켜 출력하는 방법
// 그래도 시간 초과가 나온다 입출력이 실행 속도에서 차지하는 비중이 크기 때문에 빠른 입출력을 할수 있게 코드 추가
// C 표준 스트림 버퍼와의 동기화를 끊는다는 것 이에 따라 C++ 만의 독립적인 버퍼를 갖게 됨

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt[10001] = { 0 };
	int n, count;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> count;
		cnt[count]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < cnt[i]; j++)
			cout << i << '\n';
}

void baekjoon2751()
{
	int arr[1000000];

	// 입력
	int n;
	cin >> n;

	// 배열 입력
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// 내장된 sort는 퀵 정렬이므로 최악O(n^2)이고 최선 logn 평균O(n log n)
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
}

void baekjoon25305()
{
	int N, cut;
	cin >> N >> cut;

	vector<int> a;
	a.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (a[i] > a[j])
			{
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	cout << a[N - cut] << endl;

}

void baekjoon2587()
{
	vector<int> a;
	a.resize(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (a[i] > a[j])
			{
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}


	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += a[i];
	}
	sum /= 5;

	cout << sum << endl << a[2] << endl;

}

void baekjoon2750()
{
	int N;
	cin >> N;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (a[i] > a[j])
			{
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << a[i] << endl;
	}

}

void baekjoon2839()
{
	// 정확하게 N킬로그램을 배달
	// 하지만 봉지는 3,5킬로 뿐
	// 상근이는 적은 봉지로 가지고 가고 싶다.
	// 3 <= N <= 5000

	int N;
	cin >> N;

	// 예외 처리부터 구현
	// 나누는 것 구현 일단 5로 다 나눠 본다
	// 그리고 나눠지지 않은 부분 3으로 나눠
	// 정확히 떨어지지 않으면 return -1
	int keep = 0, max_five = N / 5, temp;

	// 최대한 5로 나눠보고 5킬로 봉지를 하나씩 포기하면서 3킬로 봉지로도 나눠지는지 확인 나눠지면 그게 답
	while (1)
	{
		if ((N - (max_five * 5)) % 3 == 0)
		{
			temp = N - (max_five * 5);
			keep = (max_five + temp / 3);

			cout << keep << endl;
			break;
		}
		else
		{
			max_five--; // 5kg 봉투 개수를 하나 줄임

			if (max_five < 0) // 5kg 봉투를 0개까지 줄여도 안되면 -1 출력
			{
				cout << -1 << endl;
				break;
			}
		}
	}

}

void baekjoon1436()
{
	// 1 -> 666 2 -> 1666 
	// 종말의 수 어떤 수에 666 적어도 3개 이상 연속으로 들어가는 수

	int N, cnt = 0;
	cin >> N;
	// 하나씩 증가해서 666으로 숫자를 찾음
	for (int i = 666;; i++) {
		int tmp = i;
		while (tmp >= 666) {
			// 나머지가 666이면 증가
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		}
		if (N == cnt) {
			std::cout << i;
			break;
		}
	}
}

void baekjoon1018()
{
	char wboard[8][8] =
	{
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W'
	};

	char bboard[8][8] =
	{
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B'
	};

	int N, M;
	cin >> N >> M;

	// 2차원 배열 선언 및 초기화
	char** board = new char* [N];
	for (int i = 0; i < N; i++)
		board[i] = new char[M];

	// 입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	int min = 999999;

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			// 새로운 변경점 찾기 위해서 여기서 초기화
			int wcount = 0, bcount = 0;

			// 보드와 다른점 찾기
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (wboard[k][l] != board[k + i][l + j])
						wcount++;
					if (bboard[k][l] != board[k + i][l + j])
						bcount++;
				}
			}

			// min보다 작은게 있으면 넣기
			if (min > wcount || min > bcount)
			{
				if (wcount > bcount)
					min = bcount;
				else if (wcount < bcount)
					min = wcount;
				else
					min = wcount;
			}
		}
	}

	cout << min << endl;
}

void baekjoon19532()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int x = 0, y = 0;

	// 연립방정식 소거법 사용
	x = (c * e - b * f) / (a * e - b * d);
	y = (c * d - a * f) / (b * d - a * e);

	cout << x << " " << y;

	/*
		int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if ((a * x + b * y == c) && (d * x + e * y == f))
			{
				cout << x << " " << y;
				break;
			}
		}
	}

	*/
}

void baekjoon2231()
{
	int N;
	cin >> N;

	// 분해합 
	int x = 1, count = 0;
	while (N / x != 0)
	{
		x *= 10;
		count++;
	}

	int cpyn = max(1, N - (9 * count)); // 탐색 시작점 개선 (최소 1부터)
	int generator = 0; // 생성자를 저장할 변수, 초기값 0 (생성자 없을 경우 0 출력)
	while (cpyn < N)
	{
		int cpcpy = cpyn, sum = 0;
		vector<int> data;
		for (int i = pow(10, count - 1); i > 0; i /= 10)
		{
			data.push_back(cpcpy / i);
			cpcpy %= i;
		}

		for (int i = 0; i < data.size(); i++)
		{
			sum += data[i];
		}

		if (N == cpyn + sum)
		{
			generator = cpyn; // 생성자를 찾으면 저장
			break;
		}
		cpyn++;
	}

	cout << generator << endl; // 생성자 (찾았으면 값, 없으면 0) 출력

}

void baekjoon2798()
{
	int N, M;
	cin >> N >> M;

	vector<int> data;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		data.push_back(a);
	}

	int sum = 0;

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			for (int k = j + 1; k < N; k++)
			{
				int test = data[i] + data[j] + data[k];
				if (test <= M)
					if (sum <= test)
						sum = test;
			}
			
	cout << sum << endl;

}

void baekjoon11653()
{
	int N;
	cin >> N;

	vector<int> data;
	int de = 2;
	while (N != 0)
	{
		if (N == 1)
			break;

		if (N % de == 0)
		{
			data.push_back(de);
			N /= de;
		}
		else
			de++;

	}
	if (data.size() != 0)
		for (int i = 0; i < data.size(); i++)
			cout << data[i] << endl;
	else
		return;
}

void baekjoon2581()
{
	int M, N;
	cin >> M >> N;

	int sum = 0;
	vector<int> num;
	for (int i = M; i <= N; i++)
	{
		int count = 0;
		// 소수 찾기 자기 수 까지
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				count++;

			// 2개 초과면 탈출
			if (count > 2)
				break;
		}
		if (count == 2)
			num.push_back(i);
	}

	// 소수 합
	for (int i = 0; i < num.size(); i++)
		sum += num[i];


	// 크기가 없으면 제외
	if (num.size() != 0)
		cout << sum << endl << num[0] << endl;
	else
		cout << -1 << endl;
}

void baekjoon1978()
{
	int n;
	cin >> n;

	// 동적할당 데이터 저장
	int* N = new int[n];
	int data = 0;
	// 입력과 동시에 비교
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		cin >> N[i];
		// 2이상의 수만 소수로 하기 때문에
		if (N[i] >= 2)
			for (int j = 1; j <= N[i]; j++)
				if (N[i] % j == 0)
					count++;
		// 소수이면 count 업	
		if (count == 2)
			data++;

	}

	cout << data << endl;

}

void baekjoon9506()
{
	int n;
	while (1)
	{
		// 입력
		cin >> n;

		if (n == -1)
			break;

		vector<int> data;
		// 약수 data에 저장
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
				data.push_back(i);
		}

		// data 완전수인지 판단
		int check = 0;
		bool ischeck = false;
		for (int i = 0; i < data.size(); i++)
		{
			check += data[i];
			if (check == n)
				ischeck = true;
			else if (check >= n) // 넘어 갔을 경우 추가
				ischeck = false;
		}

		if (ischeck)
		{
			cout << n << " = ";
			for (int i = 0; i < data.size(); i++)
			{
				// 문자 표현 하기 위해서
				if (i == 0)
				{
					cout << data[i];
				}
				else
				{
					cout << " + " << data[i];
				}
			}
		}
		else
		{
			cout << n << " is NOT perfect.";
		}
		cout << endl;

	}
}

void baekjoon2501()
{
	int N, K;
	cin >> N >> K;

	int count = 1;
	int x = 1;
	int data;
	while (count <= K)
	{
		if (N % x == 0)
		{
			data = x;
			count++;
		}

		// 탈출 조건 
		if (N < x)
		{
			data = 0;
			break;
		}
		x++;
	}

	cout << data << endl;
}

void baekjoon5086()
{
	vector<pair<int, int>> n;

	int frist = 0;

	// 입력
	while (true) {
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		n.push_back({ a, b });
	}

	// 이제 배수 인지 확인 하는 작업
	for (int i = 0; i < n.size(); i++)
	{
		bool factor = false;
		bool multiple = false;
		int fristnum = n[i].first;
		int secondnum = n[i].second;

		if (fristnum != 0)
			factor = secondnum % fristnum == 0;
		multiple = fristnum % secondnum == 0;

		if (factor) {
			cout << "factor" << endl;
		}
		else if (multiple) {
			cout << "multiple" << endl;
		}
		else {
			cout << "neither" << endl;
		}

	}

}

void baekjoon2869()
{
	// 높이가 V 
	// 낮에는 A 올라감
	// 밤에는 B 내려감

	int A, B, V;
	cin >> A >> B >> V;

	// 현재 높이
	double remaining_height = V - A;
	// 하루 순 상승 높이
	double daily_climb = A - B;

	// 필요한 날짜 계산 (올림 처리)
	int days = ceil(remaining_height / daily_climb);

	// 마지막 올라가는 날 + 1
	cout << days + 1 << endl;
}

void baekjoon1193()
{
	int n, x = 1;
	cin >> n;
	int num = 1;

	while (num < n)
	{
		x++;
		num += x;
	}
	int y = num - n;
	int de = x - y, nu = 1 + y;

	// 홀
	if (x % 2 == 1)
	{
		// TODO : 홀수일 경우 분모가 높게 시작 1/4
		cout << nu << "/" << de << endl;
	}
	else // 짝
	{
		// TODO : 짝수일 경우 분모가 작게 시작 4/1
		cout << de << "/" << nu << endl;
	}

}

void baekjoon2292()
{
	// 입력
	int n;
	cin >> n;

	int count = 1;
	int bee = 1;

	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}

	// 접근 : 1 -> 7 -> 19 -> 37
	// 6 -> 12 -> 18 6의 배수로 증가하는 것을 볼 수 있음
	// 방 지나는 데이터 : count 라고 지정
	// 계산
	while (bee < n)
	{
		bee += (6 * count);
		count++;
	}

	cout << count << endl;

}

void baekjoon2903()
{
	int n;
	// 입력
	cin >> n;

	// 범위 처리
	if (!(1 <= n && n <= 15))
	{
		cout << "not n" << endl;
		return;
	}

	// 계산
	// 처음에는 2n + 1 로 접근함 틀림 -> 2제곱n + 1 수정
	int data = pow(2, n) + 1;
	data *= data;

	cout << data << endl;
}

void baekjoon2720() {
	int input;
	cin >> input;

	int cent[4] = { 25, 10, 5, 1 }; // 센트로 표현

	for (int i = 0; i < input; i++) {
		int change;
		cin >> change; // 센트 단위로 입력 받음

		for (int j = 0; j < 4; j++) {
			int output = change / cent[j]; // 나눗셈 연산으로 몫 계산
			change %= cent[j];           // 나머지 연산으로 잔액 업데이트
			cout << output << " ";
		}
		cout << endl;
	}
}

void baekjoon11005()
{
	int input, num;
	string str;

	cin >> input >> num;

	while (input > 0)
	{
		char to_char;
		if (0 <= input % num && 9 >= input % num)
		{
			to_char = input % num + '0';
		}
		else
		{
			to_char = input % num + 'A' - 10;
		}
		str = to_char + str;
		input /= num;
	}

	cout << str << endl;
}

void baekjoon2745()
{
	string str;
	int num;

	// 입력
	cin >> str >> num;

	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int ch = 0;
		// 숫자
		if ('0' <= str[i] && '9' >= str[i])
			ch = (str[i] - '0');
		else // 문자
			ch = str[i] - 'A' + 10;

		int j = str.size() - 1 - i;

		sum += (ch * pow(num, j));
	}

	cout << sum << endl;
}

void baekjoon2563()
{
	int board[100][100];
	int angle;
	int anglesum = 100;

	// 사각형 갯수
	cin >> angle;

	// 좌표 입력
	for (int i = 0; i < angle; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> board[i][j];
		}
	}

	int sumboard = 0;

	// TODO : 좌표사용해서 가로 세로 10인 사각형 생성 후 다른 사각형이랑 겹치는지 확인
	for (int i = 0; i < angle; i++)
	{
		// 비교 인자
		int x = board[i][0];
		int y = board[i][1];
		// 비교하기 위한 반복문
		for (int j = i + 1; j < angle; j++)
		{
			// 초기화
			int keepx = 0;
			int keepy = 0;
			// x < board[j][0] ~ board[j][0] + 10 < x+10 사이 수가 있는가?
			if (x <= board[j][0] && x + 10 >= board[j][0])
			{
				keepx = x + 10 - board[j][0];
				if (y <= board[j][1] && y + 10 >= board[j][1])
				{
					keepy = y + 10 - board[j][1];
				}
				else if (y <= board[j][1] + 10 && y + 10 >= board[j][1] + 10)
				{
					keepy = board[j][1] + 10 - y;
				}

			}
			else if (x <= board[j][0] + 10 && x + 10 >= board[j][0] + 10)
			{
				keepx = board[j][0] + 10 - x;
				if (y < board[j][1] && y + 10 > board[j][1])
				{
					keepy = y + 10 - board[j][1];
				}
				else if (y <= board[j][1] + 10 && y + 10 >= board[j][1] + 10)
				{
					keepy = board[j][1] + 10 - y;
				}
			}

			sumboard += (keepx * keepy);
		}
	}
	anglesum *= angle;
	anglesum -= sumboard;
	cout << anglesum << endl;
}

void baekjoon2566()
{
	// 데이터 저장
	int row = 0, col = 0, max = 0;

	// 동적 할당
	int** matrix = new int* [9];

	// input;
	for (int i = 0; i < 9; i++)
	{
		matrix[i] = new int[9];
		for (int j = 0; j < 9; j++)
		{
			cin >> matrix[i][j];
		}
	}

	// 값 비교
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (max < matrix[i][j])
			{
				max = matrix[i][j];
				row = i;
				col = j;
			}
		}
	}

	// 메모리 삭제
	for (int i = 0; i < 9; i++)
		delete[] matrix[i];

	delete[] matrix;



	cout << max << endl;
	cout << row + 1 << " " << col + 1 << endl;

}

void baekjoon2738()
{
	int rownum, colnum;
	cin >> rownum >> colnum;
	int** matrix = new int* [rownum];
	int** matrix2 = new int* [rownum];
	int** matrixsum = new int* [rownum];
	for (int i = 0; i < rownum; i++)
	{
		matrix[i] = new int[colnum];
		for (int j = 0; j < colnum; j++)
		{
			int matrixnum;
			cin >> matrixnum;
			matrix[i][j] = matrixnum;
		}
	}
	for (int i = 0; i < rownum; i++)
	{
		matrix2[i] = new int[colnum];
		for (int j = 0; j < colnum; j++)
		{
			int matrixnum;
			cin >> matrixnum;
			matrix2[i][j] = matrixnum;
		}
	}
	for (int i = 0; i < rownum; i++)
	{
		matrixsum[i] = new int[colnum];
		for (int j = 0; j < colnum; j++)
		{
			matrixsum[i][j] = matrix[i][j] + matrix2[i][j];
			cout << matrixsum[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rownum; i++)
	{
		delete[] matrix[i];
		delete[] matrix2[i];
		delete[] matrixsum[i];
	}

	delete[] matrix;
	delete[] matrix2;
	delete[] matrixsum;
}

void baekjoon25206()
{
	string name, grade;
	double credit;
	double sumCredit = 0.0;
	double sumGradePoint = 0.0;

	for (int i = 0; i < 20; i++) {
		cin >> name >> credit >> grade;

		if (grade == "P") continue;

		double gradePoint = 0.0;
		if (grade == "A+") gradePoint = 4.5;
		else if (grade == "A0") gradePoint = 4.0;
		else if (grade == "B+") gradePoint = 3.5;
		else if (grade == "B0") gradePoint = 3.0;
		else if (grade == "C+") gradePoint = 2.5;
		else if (grade == "C0") gradePoint = 2.0;
		else if (grade == "D+") gradePoint = 1.5;
		else if (grade == "D0") gradePoint = 1.0;
		else if (grade == "F") gradePoint = 0.0;

		sumCredit += credit;
		sumGradePoint += credit * gradePoint;
	}

	cout << sumGradePoint / sumCredit << endl;
}

void baekjoon2941() {
	string str;
	int alpha = 0;

	// 입력
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		// 'c', 'd', 'l', 'n', 's', 'z' 같은 알파벳은 두 글자일 수 있음
		if (str[i] == 'c') {
			if (i + 1 < str.size() && (str[i + 1] == '=' || str[i + 1] == '-')) {
				i++; // "c=" 또는 "c-" 처리
			}
		}
		else if (str[i] == 'd') {
			if (i + 2 < str.size() && str[i + 1] == 'z' && str[i + 2] == '=') {
				i += 2; // "dž=" 처리
			}
			else if (i + 1 < str.size() && str[i + 1] == '-') {
				i++; // "d-" 처리
			}
		}
		else if (str[i] == 'l' || str[i] == 'n') {
			if (i + 1 < str.size() && str[i + 1] == 'j') {
				i++; // "lj" 또는 "nj" 처리
			}
		}
		else if (str[i] == 's' || str[i] == 'z') {
			if (i + 1 < str.size() && str[i + 1] == '=') {
				i++; // "s=" 또는 "z=" 처리
			}
		}

		// 나머지 문자는 하나씩 세기
		alpha++;
	}

	cout << alpha << endl;
}

void baekjjon1157()
{
	string str;
	int a[26] = { 0 };
	int max = 0;
	int check = 0;
	cin >> str;

	// 소문자를 대문자로 변경
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;

		a[str[i] - 'A']++;
	}

	// 문자가 여러개 이면 ?
	// 많이 사용된 문자 출력
	for (int i = 0; i < 26; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			check = 0;
		}
		else if (a[i] == max)
			check++;
	}

	if (check != 0)
		cout << "?" << endl;
	else
	{
		for (int i = 0; i < 26; i++)
		{
			if (a[i] == max)
			{
				cout << (char)(i + 'A') << endl;
			}
		}
	}
}


void merge(vector<int>& arr, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;

	// 정렬된 임시 저장 공간 생성
	vector<int> temp(right - left + 1);

	while (i <= mid && j < right)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}

	while (j <= right)
	{
		temp[k++] = arr[j++];
	}

	for (i = left, k = 0; i <= right; i++, k++)
	{
		arr[i] = temp[k];
	}

}

void merge_sort(vector<int>& arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}