#include <iostream>
#include <vector>
using namespace std;

int table[14][14];
int N, num = 0;

void put(int _x, int _y) {
	if (table[_x][_y] > 0)
		return;
	if (_x == N - 1) {
		num++;
		return;
	}
	int plus = _x + _y, minus = _y - _x;
	for (int i = 0; i < N; ++i) {
		++table[_x][i];
		++table[i][_y];
		int new_y = plus - i;
		if (0 <= new_y && new_y < N) {
			++table[i][new_y];
		}
			
		new_y = minus + i;
		if (0 <= new_y && new_y < N) {
			++table[i][new_y];
		}
			
	}
	
	for (int i = 0; i < N; ++i)
		put(_x + 1, i);

	for (int i = 0; i < N; ++i) {
		--table[_x][i];
		--table[i][_y];
		int new_y = plus - i;
		if (0 <= new_y && new_y < N)
			--table[i][new_y];
		new_y = minus + i;
		if (0 <= new_y && new_y < N)
			--table[i][new_y];
	}
	return;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		put(0, i);

	cout << num;
	return 0;
}
