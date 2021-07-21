#include <iostream>
using namespace std;

int N, M, K, NUM = 1;
long long TABLE[2097152];

long long sum(int _l, int _r, int _a, int _b, int _num) {
	if ((_l == _a && _r == _b) || _a == _b)
		return TABLE[_num];
	
	int mid_left = (_a + _b - 1) / 2, list_num_left = _num * 2 + 1;

	if (_r <= mid_left)
		return sum(_l, _r, _a, mid_left, list_num_left);
	else if (mid_left < _l)
		return sum(_l, _r, mid_left + 1, _b, list_num_left + 1);
	else
		return sum(_l, mid_left, _a, mid_left, list_num_left) + 
		       sum(mid_left + 1, _r, mid_left + 1, _b, list_num_left + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	int finish, start;
	while (NUM < N) NUM *= 2;
	start = NUM - 1;
	finish = start * 2;
	
	for (int i = start; i < start + N; ++i)
		cin >> TABLE[i];
	
	for (int i = start + N; i <= finish; ++i) {
		TABLE[i] = 0;
	}

	for (int i = start - 1; i >= 0; --i) {
		int num = i * 2 + 1;
		TABLE[i] = TABLE[num] + TABLE[num + 1];
	}

	for (int i = 0; i < M + K; ++i) {
		int first, second;
		cin >> first >> second;

		if (first == 1) {
			long long third;
			cin >> third;
			int number = start + second - 1;
			long long gap = third - TABLE[number];
			while (true) {
				TABLE[number] += gap;
				if (number == 0)
					break;
				number = (number - 1) / 2;
			}
		}
		else {
			int third;
			cin >> third;
			cout << sum(second, third, 1, NUM, 0) << "\n";
		}
	}

	return 0;
}
