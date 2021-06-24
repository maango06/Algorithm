#include <iostream>
using namespace std;

int table[14];
int N, num = 0;

int abs(int _num) {
	if (_num < 0)
		return -_num;
	return _num;
}

void put(int _x) {

	for (int i = 0; i < N; ++i) {

		bool can = true;

		for (int j = 0; j < _x; ++j) {
			if (table[j] == i || _x - j == abs(i - table[j])) {
				can = false;
				break;
			}
		}

		if (can) {
			if (_x == N - 1) {
				++num;
			}
			else {
				table[_x] = i;
				put(_x + 1);
			}
		}
	}
	return;
}

int main()
{
	cin >> N;

	put(0);

	cout << num;
	return 0;
}
